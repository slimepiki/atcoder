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

#define vd vector<double>
#define vvd vector<vd>
#define vvvd vector<vvd>
#define vvvvd vector<vvvd>

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    static ll r, nr, N, D;

    initsvi(c, 3, 0);

    cin >> N >> D;

    while (D % 2 == 0) {
        c[0]++;
        D /= 2;
    }
    while (D % 3 == 0) {
        c[1]++;
        D /= 3;
    }
    while (D % 5 == 0) {
        c[2]++;
        D /= 5;
    }

    if (D != 1) {
        cout << 0 << endl;
        return 0;
    }

    // debug(c[0], c[1], c[2]);

    vvvvd dp(2, vvvd(c[0] + 1, vvd(c[1] + 1, vd(c[2] + 1, 0))));

    dp[0][0][0][0] = 1;

    rep(i, 0, N) {
        r = i % 2;
        nr = (i + 1) % 2;
        dp[nr] = vvvd(c[0] + 1, vvd(c[1] + 1, vd(c[2] + 1, 0)));
        rep(j, c[0] + 1) rep(k, c[1] + 1) rep(l, c[2] + 1) {
            // debug(i, j, k, l);
            if (dp[r][j][k][l]) {
                double sum = dp[r][j][k][l] / 6;

                dp[nr][j][k][l] += sum;
                dp[nr][min(j + 1, c[0])][k][l] += sum;
                dp[nr][j][min(k + 1, c[1])][l] += sum;
                dp[nr][min(j + 2, c[0])][k][l] += sum;
                dp[nr][j][k][min(l + 1, c[2])] += sum;
                dp[nr][min(j + 1, c[0])][min(k + 1, c[1])][l] += sum;
            }
        }
    }

    cout << setprecision(30) << dp[N % 2][c[0]][c[1]][c[2]] << endl;

    return 0;
}