using namespace std;
using ll = long long;
using ull = unsigned long long;

#include <bits/stdc++.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

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
#define debug(...) ;
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
#define initsvi(a, S, N) static vi a(S, N);
#define vvi vector<vi>
#define initsvvi(a, H, W, N) static vvi a(H, vi(W, N));
#define vll vector<ll>
#define initsvll(a, S, N) static vll a(S, N);

#define vc vector<char>
#define initsvc(a, S, N) static vc a(S, N);
#define vvc vector<vc>
#define initsvvc(a, H, W, N) static vvc a(H, vc(W, N));

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

void add(int& t, int& k) {
    int a = 0;
    if (k == 0)
        a = 1;
    else
        a = k;
    t += a;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    static int D, r, nr, dig, maxpt;
    static const int WARU = 1000000007;
    static string N;
    cin >> D >> N;

    int dp[2][2][D]{};

    dp[0][1][0] = 1;
    maxpt = 0;

    rep(i, N.size()) {
        r = i % 2;
        nr = (i + 1) % 2;
        memset(dp[nr], 0, 2 * D * sizeof(int));

        rep(k, N[i] - '0') { dp[nr][0][(maxpt + k) % D] += dp[r][1][maxpt]; }

        dp[nr][1][(maxpt + (N[i] - '0')) % D] += dp[r][1][maxpt];
        maxpt += (N[i] - '0');
        maxpt %= D;
        dp[nr][1][maxpt] %= WARU;
        debug(dp[nr][1][maxpt])

            rep(j, D) {
            rep(k, 10) { dp[nr][0][(j + k) % D] += dp[r][0][j]; 
            dp[nr][0][(j + k) % D] %= WARU;
            }
        }

        rep(j, D) dp[nr][0][j] %= WARU;
    }
    //0は除く!!!!!
    cout << dp[N.size() % 2][0][0] + dp[N.size() % 2][1][0] -1 << endl;

    return 0;
}