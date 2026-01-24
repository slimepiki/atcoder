#include <cstdint>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>

class UnionFind {
   public:
    UnionFind() = default;
    explicit UnionFind(size_t n) : m_parentsOrSize(n, -1) {}
    int find(int i) {
        if (m_parentsOrSize[i] < 0) {
            return i;
        }
        return (m_parentsOrSize[i] = find(m_parentsOrSize[i]));
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            if (-m_parentsOrSize[a] < -m_parentsOrSize[b]) {
                std::swap(a, b);
            }

            m_parentsOrSize[a] += m_parentsOrSize[b];
            m_parentsOrSize[b] = a;
        }
    }

    bool connected(int a, int b) { return (find(a) == find(b)); }

    int size(int i) { return -m_parentsOrSize[find(i)]; }

   private:
    std::vector<int> m_parentsOrSize;
};

template <typename T>
class IntervalTree {
   private:
    struct Node {
        int lnode = -1;
        int rnode = -1;
        T med;
        std::vector<T, T> l;  // 昇順のmedを含むinteravl
        std::vector<T, T> r;  // 降順のmedを含むinteravl
        Node() {
            lnode = -1;
            rnode = -1;
        }
    };
    std::vector<Node> nodes;

    IntervalTree() {};

   public:
    IntervalTree(std::vector<std::pair<T, T>>& v) {
        std::stack<std::pair<std::vector<T, T>, int>> st;
        st.push(std::make_pair(std::move(v), 0));
        nodes.push_back(Node());
        while (!st.empty()) {
            std::vector<std::pair<T, T>> l, r;
            std::vector<std::pair<T, T>> cv = std::move(st.top().first);
            int idx = st.top().second;
            st.pop();

            Node& n = nodes[idx];
            std::vector<T> vals;
            for (uint32_t i = 0; i < cv.size(); ++i) {
                vals.push_back(cv[i].first);
                vals.push_back(cv[i].second);
            }
            std::sort(vals.begin(), vals.end());

            n.lnode = -1;
            n.rnode = -1;
            n.med = vals[vals.size() / 2 - 1] + vals[vals.size() / 2];

            for (uint32_t i = 0; i < cv.size(); ++i) {
                std::pair<T, T> interv = cv[i];
                if (interv.second < n.med) {
                    l.push_back(interv);
                } else if (n.med < interv.first) {
                    r.push_back(interv);
                } else {
                    n.l.push_back(interv);
                    n.r.push_back(interv);
                    std::sort(n.l.begin(), n.l.end(), [](std::pair<T, T> x, std::pair<T, T> y) { return x.first < y.first; });
                    std::sort(n.r.begin(), n.r.end(), [](std::pair<T, T> x, std::pair<T, T> y) { return x.second > y.second; });
                }
            }

            if (!l.empty()) {
                n.lnode = nodes.size();
                nodes.push_back(std::move(l), nodes.size());
            }

            if (!r.empty()) {
                n.rnode = nodes.size();
                nodes.push_back(std::move(r), nodes.size());
            }
        }
    }

    std::vector<std::pair<T, T>> Query(T val) {
        std::vector<T, T> ret;
        int c = 0;

        while (c >= 0) {
            auto& n = nodes[c];
            if (val <= n.med) {
                // 次のノード
                c = n.lnode;

                // medとvalを含む要素の探索
                for (uint32_t i = 0; i < n.l.size(); ++i) {
                    if (n.l[i] > val) break;
                    ret.push_back(n.l[i]);
                }

            } else {
                // 次のノード
                c = n.rnode;

                // medとvalを含む要素の探索
                for (uint32_t i = 0; i < n.r.size(); ++i) {
                    if (n.r[i] < val) break;
                    ret.push_back(n.r[i]);
                }
            }
        }

        return move(ret);
    }
};