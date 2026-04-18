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

bool inside(tuple<int, int, int> a, tuple<int, int, int> mi, tuple<int, int, int> mx) {
    int ax = get<0>(a);
    int ay = get<1>(a);
    int az = get<2>(a);

    if (get<0>(mi) >= ax && ax >= get<0>(mx)) return false;
    if (get<1>(mi) >= ay && ay >= get<1>(mx)) return false;
    if (get<2>(mi) >= az && az >= get<2>(mx)) return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, c, d, e, f, g, h, i, j, k, l;

    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;

    // [a, d], [b, e], [c, f]
    // [g, j], [h, k], [i, l]

    if (a >= j || d <= g) {
        cout << "No" << endl;
        return 0;
    }

    if (b >= k || e <= h) {
        cout << "No" << endl;
        return 0;
    }

    if (c >= l || f <= i) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}