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
constexpr int fdir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int H, W, K;
    cin >> H >> W >> K;

    char m[H][W];
    rep(i, H) rep(j, W) cin >> m[i][j];

    stack<pair<set<ii>, ii>> st;
    rep(i, H) rep(j, W) {
        if (m[i][j] == '.') st.push(make_pair(set<ii>(), make_pair(i, j)));
    }

    pair<set<ii>, ii> shw;
    set<ii> s;
    ii hw;
    int h, w;
    ll ans = 0;
    while (!st.empty()) {
        shw = st.top();
        st.pop();
        s = shw.first;
        hw = shw.second;
        h = hw.first;
        w = hw.second;
        s.insert(hw);
        rep(k, 4) {
            int x = h + fdir[k][0], y = w + fdir[k][1];
            if (x >= 0 && x < H && y >= 0 && y < W) {
                if (m[x][y] == '.' && s.count(make_pair(x, y)) == 0) {
                    if (s.size() == K) {
                        ans++;
                        continue;
                    }
                    st.push(make_pair(s, make_pair(x, y)));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}