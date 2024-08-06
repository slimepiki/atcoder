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
#define initvi(a, S, N) vi a(S, N);
#define vvi vector<vi>
#define initvvi(a, H, W, N) vvi a(H, vi(W, N));
#define vll vector<ll>
#define initvll(a, S, N) vll a(S, N);
#define vvll vector<vll>
#define initvvll(a, H, W, N) vvll a(H, vll(W, N));

#define vc vector<char>
#define initvc(a, S, N) vc a(S, N);
#define vvc vector<vc>
#define initvvc(a, H, W, N) vvc a(H, vc(W, N));

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

    static int D, N, max, r, pr;
    cin >> D >> N;

    vector<int> d(D, 0);
    rep(i, D) cin >> d[i];
    vvi c(N, vi(3, 0));
    rep(j, N) cin >> c[j][0] >> c[j][1] >> c[j][2];

    int dp[2][N]{};

    rep(i, D) {
        debug(i)
        r = i % 2;
        pr = (i + 1) % 2;

        memset(dp[pr], 0, N * sizeof(int));
        rep(j, N) {

            if (c[j][0] <= d[i] && c[j][1] >= d[i]) {
                if (i == 0)
                    dp[pr][j] = 0;
                else
                    rep(k, N){
                        chmax(dp[pr][j], dp[r][k] + abs(c[k][2] - c[j][2]));
                        debug(dp[pr][j]);

                    }
            } else {
                dp[pr][j] = -1000;
            }
            //debug(dp[pr][j]);
        }
    }
    max = 0;
    rep(i, N) chmax(max, dp[D % 2][i]);
    cout << max << endl;
    return 0;
}