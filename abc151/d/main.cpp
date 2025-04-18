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

constexpr int fdir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    char s[H][W];

    rep(i, H) rep(j, W) cin >> s[i][j];

    int ans = 0;

    rep(i, H) rep(j, W) {
        if (s[i][j] == '.') {
            int stp[H][W]{};
            rep(u, H) rep(v, W) { stp[u][v] = IINF; }

            queue<pair<pair<int, int>, int>> q;
            q.push(make_pair(make_pair(i, j), 0));
            stp[i][j] = 0;

            while (!q.empty()) {
                auto uvp = q.front();
                q.pop();
                auto uv = uvp.first;
                int u = uv.first, v = uv.second, p = uvp.second;
                rep(k, 4) {
                    int x = u + fdir[k][0], y = v + fdir[k][1];
                    if (x >= 0 && x < H && y >= 0 && y < W && s[x][y] == '.' && p + 1 < stp[x][y]) {
                        stp[x][y] = p + 1;
                        q.push(make_pair(make_pair(x, y), p + 1));
                    }
                }
            }
            int temp = 0;
            rep(u, H) rep(v, W) {
                if (s[u][v] == '.') chmax(temp, stp[u][v]);
            }
            chmax(ans, temp);
        }
    }

    cout << ans << endl;

    return 0;
}