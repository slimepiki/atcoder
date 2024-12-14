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

ll gdc(ll a, ll b) {
    ll l = max(a, b);
    ll s = min(a, b);
    ll temp;
    while (l % s != 0) {
        temp = s;
        s = l % s;
        l = temp;
    }
    return s;
}

// 最小公倍数
ll lcm(ll a, ll b) { return max(a, b) * (min(a, b) / gdc(a, b)); }

ll acum(ll a, ll b, ll x) {
//    debug(a, b, x);
    ll f, l;
    if (a % x == 0)
        f = a;
    else
        f = a + (x - a % x);

    l = b - b % x;
//    debug(l, f);
    if(l == f) return 1;
    else if(f > l)return 0;
    else return (b - (b % x) - f) / x + 1;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    ll sk = lcm(C, D);

    ll ans = B - A + 1;
    ll acc = acum(A, B, C), acd = acum(A, B, D), acsk = acum(A, B, sk);
//    debug(acc, acd, acsk);
    cout << ans - acc - acd + acsk << endl;

    return 0;
}