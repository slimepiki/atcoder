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

// int main() {
//     cin.tie(nullptr);
//     ios_base::sync_with_stdio(false);

//     ll N, K, ans, total, g, l;
//     cin >> N >> K;
//     ans = 0;
//     total = 0;

//     ll dp[N];
//     memset(dp, 0x3f, sizeof(ll) * N);
//     dp[0] = 0;

//     rep(i, N) {
//         rep(j, N) debug(i, j, dp[j]);

//         cin >> g;
//         for (int j = i; j >= 0; j--) {
//             if (dp[j] <= 500010) {
//                 if (j == 0)
//                     l = 1;
//                 else {
//                     l = g * dp[j];
//                     l = (l/total)+1;
//                 }
//                 debug(g, total, l, dp[j], dp[j + 1]);
//                 if(l <= g)chmin(dp[j + 1], dp[j] + l);
//             }
//         }

//         total += g;
//     }
//     ans = 1;
//     if(total == 0){
//         cout << 0 << endl;
//         return 0;
//     }
//     if (total > K) {
//         rep(i, N) {
//             if (dp[i] <= K) ans = i;
//         }
//         rep(i, N) debug(i, dp[i]);

//         cout << ans << endl;
//     }else if(total == K){
//         cout << 1 << endl;
//     }else if(total == 0){
//         cout << 0 << endl;
//     }

//     return 0;
// }

int N, K;
int A[2020];
ll mi[2020][2020];

int main() {
    int i, j, k, l, r, x, y;
    string s;

    rep(x, 2020) rep(y, 2020) mi[x][y] = 1 << 30;

    cin >> N >> K;
    ll sum = 0;
    mi[0][0] = 0;
    rep(i, N) {
        cin >> x;

        if (i == 0) {
            mi[1][1] = 1;
            mi[1][0] = 0;
        } else {
            rep(j, i + 1) if (mi[i][j] < 1 << 30) {
                // good
                ll y = mi[i][j] * x;
                y = (y / sum) + 1;
                if (y <= x)
                    mi[i + 1][j + 1] = min(mi[i + 1][j + 1], mi[i][j] + y);
                // same
                mi[i + 1][j] = min(mi[i + 1][j], mi[i][j]);
            }
        }

        sum += x;
    }

    if (sum == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (sum == K) {
        cout << 1 << endl;
        return 0;
    }

    for (i = N; i >= 0; i--)
        if (mi[N][i] <= K) {
            cout << i << endl;
            return 0;
        }
    return 0;
}