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

    int N, M, L, X, r, nr;
    cin >> N >> M >> L >> X;
    int a[N];
    rep(i, N) cin >> a[i];

    int dp[2][M];

    memset(dp, 0x3f, 2 * M * sizeof(int));

    rep(i, N) {
        r = i % 2;
        nr = (i + 1) % 2;
        dp[r][0] = 1;
        memset(dp[nr], 0x3f, M * sizeof(int));
        rep(j, M) {
            chmin(dp[nr][j], dp[r][j]);
            if (j + a[i] >= M)
                chmin(dp[nr][(j + a[i]) % M], dp[r][j] + (j + a[i]) / M);
            else
                chmin(dp[nr][(j + a[i]) % M], dp[r][j]);
        }
        debug(i);
        rep(j, M) debug(i, dp[nr][j]);
    }
    debug(dp[N % 2][L]);

    if (dp[N % 2][L] <= X)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}