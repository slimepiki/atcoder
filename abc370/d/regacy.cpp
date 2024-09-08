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
#define debug(...)                                                      \
    cerr << "\033[33m(line:" << __LINE__ << ") " << "[" << #__VA_ARGS__ \
         << "]:",                                                       \
        debug_out(__VA_ARGS__);                                         \
    cerr << "\033[m";
#else
#define debug(...)  //   :)
#endif
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rrep(i, a, b) for (int i = int(a); i >= int(b); --i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)

#define ii tuple<int, int>
#define iiget(t, x, y) \
    x = get<0>(t);     \
    y = get<1>(t);
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int H, W, Q, r, c;
    cin >> H >> W >> Q;
    ll numwall = H * W;
    map<int, set<int>> m;

    rep(i, H) rep(j, W) m[i].insert(j);

    while (cin >> r >> c) {
        r--; c--;
        auto itr = m[r].find(c);
        if (itr != m[r].end()) {
            debug(r,c)
            m[r].erase(itr);
            numwall--;
        } else {
            auto ritr = upper_bound(m[r].begin(), m[r].end(), c);
            auto litr = upper_bound(m[r].rbegin(), m[r].rend(), c);
            if (ritr != m[r].end()) {
                debug(r, *ritr);
                m[r].erase(ritr);
                numwall--;
            }
            if (litr != m[r].rend()) {
                debug(r, *litr);
                m[r].erase(litr.base());
                numwall--;
            }
            auto mb = m.begin();
            advance(mb, r);
            auto ditr = find_if(mb, m.end(), [&](std::pair<const int, std::set<int> >& s) {
                return s.second.count(c);
            });
            auto me = m.rbegin();
            advance(me, m.size() - r);
            auto uitr = find_if(me, m.rend(), [&](std::pair<const int, std::set<int> >& s) {
                return s.second.count(c);
            });

            if (ditr != m.end()) {
                debug(ditr->first,c);
                ditr->second.erase(c);
                numwall--;
            }
            if (uitr != m.rend()) {
                debug(uitr->first, c);
                uitr->second.erase(c);
                numwall--;
            }
        }
    }

    cout << numwall << endl;

    return 0;
}