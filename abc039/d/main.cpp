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

#define printA(a, H, W)                   \
    {rep(i, H){rep(j, W){cout << a[i][j]; \
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

constexpr int edir[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0},
                            {1, 0},   {-1, 1}, {0, 1},  {1, 1}};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    char m[H][W];
    rep(i, H) rep(j, W) cin >> m[i][j];

    char pm[H][W];
    rep(i, H) rep(j, W) pm[i][j] = '#';

    rep(i, H) {
        rep(j, W) {
            if (m[i][j] == '.') {
                pm[i][j] = '.';
                continue;
            }
            rep(k, 8) {
                int x = i + edir[k][0], y = j + edir[k][1];
                if (x >= 0 && x < H && y >= 0 && y < W) {
                    if (m[x][y] == '.') {
                        pm[i][j] = '.';
                        break;
                    }
                }
            }
        }
    }

    char sh[H][W];
    rep(i, H) rep(j, W) sh[i][j] = '.';

    rep(i, H) {
        rep(j, W) {
            if (pm[i][j] == '#') {
                sh[i][j] = '#';
            }
            rep(k, 8) {
                if (pm[i][j] == '#') {
                    int x = i + edir[k][0], y = j + edir[k][1];
                    if (x >= 0 && x < H && y >= 0 && y < W) {
                        sh[x][y] = '#';
                    }
                }
            }
        }
    }

    rep(i, H) {
        rep(j, W) {
            if (sh[i][j] != m[i][j]) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }

    if (true) {
        cout << "possible" << endl;
        printA(pm, H, W);
    }

    return 0;
}