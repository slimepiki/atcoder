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

    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    int m[N], e[N];

    bool b[N]{};

    rep(i, N) cin >> m[i];
    rep(i, N) cin >> e[i];

    vector<pair<int, ii>> p;

    rep(i, N) { p.push_back(make_pair(i, make_pair(m[i], e[i]))); }

    int x = 0, y = 0, z = 0;

    vector<int> ans;

    sort(p.begin(), p.end(), [](pair<int, ii> u, pair<int, ii> v) {
        if (u.second.first == v.second.first)
            return u.first < v.first;
        else
            return u.second.first > v.second.first;
    });

    rep(i, N) {
        int dare = p[i].first;
        if (x >= X) break;
        if (!b[dare]) {
            b[dare] = true;
            ans.push_back(dare + 1);
            ++x;
        }
    }

    sort(p.begin(), p.end(), [](pair<int, ii> u, pair<int, ii> v) {
        if (u.second.second == v.second.second)
            return u.first < v.first;
        else
            return u.second.second > v.second.second;
    });

    rep(i, N) {
        int dare = p[i].first;
        if (y >= Y) break;
        if (!b[dare]) {
            b[dare] = true;
            ans.push_back(dare + 1);
            ++y;
        }
    }

    sort(p.begin(), p.end(), [](pair<int, ii> u, pair<int, ii> v) {
        if (u.second.first + u.second.second == v.second.first + v.second.second)
            return u.first < v.first;
        else
            return u.second.first + u.second.second > v.second.first + v.second.second;
    });

    rep(i, N) {
        int dare = p[i].first;
        if (z >= Z) break;
        if (!b[dare]) {
            b[dare] = true;
            ans.push_back(dare + 1);
            ++z;
        }
    }

    sort(ans.begin(), ans.end());

    rep(i, ans.size()) { cout << ans[i] << endl; }

    return 0;
}