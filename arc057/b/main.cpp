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

    int N, K, ans, total, g, l;
    cin >> N >> K;
    ans = 0;
    total = 0;

    int dp[N];
    memset(dp, 0x3f, sizeof(int) * N);
    dp[0] = 0;

    rep(i, N) {
        debug(i);
        rep(j, N) {
            debug(j);
            debug(dp[j]);
        }
        cin >> g;
        for (int j = i; j >= 0; j--) {
            if (dp[j] <= 500000) {
                if (j == 0)
                    l = 1;
                else
                    l = (float)g * dp[j] / total;
                chmin(dp[j + 1], dp[j] + l);
            }
        }

        total += g;
    }
    ans = 1;
    rep(i, N) {
        if (dp[i] <= K) ans = i;
    }

    cout << ans << endl;

    return 0;
}