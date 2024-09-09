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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int s1, s2;
    int A, B;
    int r, pr;
    cin >> A >> B;
    int a[1000], b[1000];
    rep(i, A) cin >> a[i];
    rep(i, B) cin >> b[i];

    int dp[1010][1010]{};

    rep(i, A-1) {
        rep(j, B-1) {
            chmax(dp[i + 2][j], dp[i][j] + a[i]);
            chmax(dp[i][j + 2], dp[i][j] + b[j]);
            chmax(dp[i + 1][j + 1], dp[i][j] + max(a[i], b[j]));
        }
    }

    rep(j, B){
        if(a[A-1] > b[j]){
//            if(A >= 3)chmax(dp[A-1][j], dp[A-3][j] + a[A-1])
//            chmax(dp[A][j],dp[A-2][j] + a[A-2]);
            }
        else if(j >= 1 &&(a[A-1] > b[j-1])){
            chmax(dp[A][j], dp[A-1][j-1] + a[A-1]);
        }else if(j >= 1 &&(a[A-1] > b[j])){
            chmax(dp[A][j], dp[A-1][j-1] + b[j-1]);
        }
        if(j >= 2)chmax(dp[A][j], dp[A][j-2] + b[j-2]);
    }

    rep(i, B){
        if(b[B-1] > a[i]){
            chmax(dp[i][B],dp[i][B-2] + b[B-2]);
            }
        else if(i >= 1 &&(b[B-1] > a[i-1])){
            chmax(dp[i][B], dp[i-1][B-1] + b[B-1]);
        }else if(i >= 1 &&(b[B-1] > a[i])){
            chmax(dp[i][B], dp[i-1][B-1] + a[i-1]);
        }
        if(i >= 2)chmax(dp[i][B], dp[i-2][B] + a[i-2]);
    }



    int ans = 0;
    rep(i, A+1) {
        rep(j, B+1) {
            chmax(ans, dp[i][j]);
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }

    chmax(ans, dp[A + 1][B + 1]);
    chmax(ans, dp[A][B + 1]);
    chmax(ans, dp[A + 1][B]);

    cout << ans << endl;

    return 0;
}