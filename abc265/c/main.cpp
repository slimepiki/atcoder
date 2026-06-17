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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int H, W;

    cin >> H >> W;

    bool b[H][W]{};
    char m[H][W];

    rep(i, H) rep(j, W) cin >> m[i][j];

    int x = 0, y = 0, dx = 0, dy = 0;

    while (true) {
        dx = 0;
        dy = 0;
        switch (m[x][y]) {
            case 'U':
                dx = -1;
                if (x == 0) {
                    cout << x + 1 << ' ' << y + 1 << endl;
                    return 0;
                }
                break;
            case 'D':
                dx = 1;
                if (x == H - 1) {
                    cout << x + 1 << ' ' << y + 1 << endl;
                    return 0;
                }
                break;
            case 'L':
                dy = -1;
                if (y == 0) {
                    cout << x + 1 << ' ' << y + 1 << endl;
                    return 0;
                }
                break;
            case 'R':
                dy = 1;
                if (y == W - 1) {
                    cout << x + 1 << ' ' << y + 1 << endl;
                    return 0;
                }
                break;
        }
        x += dx;
        y += dy;
        if (b[x][y]) {
            cout << -1 << endl;
            return 0;
        }

        b[x][y] = true;
    }

    return 0;
}