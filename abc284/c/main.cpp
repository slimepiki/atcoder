using namespace std;
using ll = long long;
using ull = unsigned long long;

#include <bits/stdc++.h>

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef __LOCAL
    #define debug(...)                                                                                       \
        cerr << "\033[33m(line:" << __LINE__ << ") " << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); \
        cerr << "\033[m";
#else
    #define debug(...)  //   :)
#endif
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rrep(i, a, b) for (int i = int(a); i >= int(b); --i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define repit(it, a) for (auto it = a.begin(); it != a.end(); it++)

#define ii pair<int, int>
#define iiget(t, x, y) \
    x = t.first();     \
    y = t.second();
#define iii tuple<int, int, int>
#define iiiget(t, x, y, z) \
    x = get<0>(t);         \
    y = get<1>(t);         \
    z = get<2>(t);
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvvi>
#define vll vector<ll>
#define vvll vector<vll>
#define vvvll vector<vvll>

#define vc vector<char>
#define vvc vector<vc>
#define vvvc vector<vvc>

#define IINF 0x3f3f3f3f - 10

#define printa1d(a, W)                   \
    {                                    \
        rep(i, W) {                      \
            cout << a[i];                \
            if (i != W - 1) cout << ' '; \
        }                                \
        cout << endl;                    \
    }

#define printa2d(a, H, W)                 \
    {rep(i, H){rep(j, W){cout << a[i][j]; \
    if (j != W - 1) cout << ' ';          \
    }                                     \
    cout << endl;                         \
    }                                     \
    }

template <typename T>
inline bool chmin(T& a, const T& b) {
    bool compare = a > b;
    if (a > b) a = b;
    return compare;
}
template <typename T>
inline bool chmax(T& a, const T& b) {
    bool compare = a < b;
    if (a < b) a = b;
    return compare;
}

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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    UnionFind uf(N);

    int u, v;

    rep(i, M) {
        cin >> u >> v;

        uf.merge(u - 1, v - 1);
    }

    set<int> st;

    rep(i, N) { st.insert(uf.find(i)); }

    cout << st.size() << endl;

    return 0;
}