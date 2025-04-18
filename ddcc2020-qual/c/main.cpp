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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int H, W, K;
    cin >> H >> W >> K;
    char m[H][W];
    rep(i, H) rep(j, W) cin >> m[i][j];

    int ans[H][W]{};
    int st = 1;

    bool fl[H]{};

    rep(i, H) {
        int bef = 0;
        rep(j, W) {
            if (m[i][j] == '.') {
                if (bef != 0 && ans[i][j] == 0) ans[i][j] = bef;
            } else {
                ans[i][j] = st;
                st++;
                fl[i] = true;
            }
            bef = ans[i][j];
        }

        rep(j, W) {
            int k = W - 1 - j;
            if (m[i][k] == '.') {
                if (bef != 0 && ans[i][k] == 0) ans[i][k] = bef;
            }
            bef = ans[i][k];
        }
    }

    rep(j, W) {
        int bef = 0;
        rep(i, H) {
            if (!fl[i]) {
                if (m[i][j] == '.') {
                    if (bef != 0 && ans[i][j] == 0) ans[i][j] = bef;
                }
            }
            bef = ans[i][j];
        }
        rep(i, H) {
            int k = H - 1 - i;
            if (!fl[k]) {
                if (m[k][j] == '.') {
                    if (bef != 0 && ans[k][j] == 0) ans[k][j] = bef;
                }
            }
            bef = ans[k][j];
        }
    }

    printa2d(ans, H, W);

    return 0;
}