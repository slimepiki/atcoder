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
vector<vector<int>> dp(1010, vector<int>(1010, -1));
int A, B;
int a[1000], b[1000];

int dfs(int i, int j, int sum) {
    if (dp[i][j] != -1) return dp[i][j];

    if (i == A && j == B) return 0;
    int res = 0;

    if (i < A) {
        chmax(res, sum - dfs(i + 1, j, sum - a[i]));
    }
        if (j < B) {
        chmax(res, sum - dfs(i, j+1, sum - b[j]));
    }

    return dp[i][j] = res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int s1, s2;
    int r, pr;
    ll sum = 0;
    cin >> A >> B;
    rep(i, A) {cin >> a[i];sum+=a[i];}
    rep(i, B) {cin >> b[i];sum+=b[i];}

    cout << dfs(0,0,sum) << endl;

    return 0;
}