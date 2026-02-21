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

    string s;
    int t;
    cin >> s >> t;

    pair<int, int> mx = make_pair(0, 0), mi = make_pair(0, 0);

    int q = 0;

    rep(i, s.size()) {
        if (s[i] == 'L') {
            ++mx.first;
            ++mi.first;
        } else if (s[i] == 'R') {
            --mx.first;
            --mi.first;
        } else if (s[i] == 'U') {
            ++mx.second;
            ++mi.second;
        } else if (s[i] == 'D') {
            --mx.second;
            --mi.second;
        } else {
            ++q;
        }
    }

    rep(i, q) {
        if (abs(mi.first) >= abs(mi.second)) {
            mi.first += mi.first >= 0 ? -1 : 1;
        } else {
            mi.second += mi.second >= 0 ? -1 : 1;
        }

        if (abs(mx.first) >= abs(mx.second)) {
            mx.first += mx.first >= 0 ? 1 : -1;
        } else {
            mx.second += mx.second >= 0 ? 1 : -1;
        }
    }

    cout << (t == 1 ? abs(mx.first) + abs(mx.second) : abs(mi.first) + abs(mi.second)) << endl;

    return 0;
}