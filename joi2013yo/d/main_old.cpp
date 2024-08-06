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

    static int D, N, maxHade, minHade, a0, a1;
    cin >> D >> N;

    static vector<int> d(D, 0);
    rep(i, D) cin >> d[i];
    static vvi c(N, vi(3, 0));
    rep(j, N) 
        cin >> c[j][0] >> c[j][1] >> c[j][2];

    sort(c.begin(), c.end(), [](vector<int> const& a, vector<int> const& b) {
        return a[2] < b[2];
    });  // 派手さ昇順

    //[0][-] : 始めできるだけ地味,[1][-] :逆
    //[-][0] : トータルスコア, [-][1] :その日の派手さ
    int dp[2][2];
    memset(dp, 0, 4 * sizeof (int));

    rep(i, D) {
        for(int j = 0; j < N;j++){
            if(d[i]>=c[j][0] && d[i] <=c[j][1]){
                minHade = c[j][2];
                break;
            }
        }
        for(int j = N - 1; j >= 0;j--){
            if(d[i]>=c[j][0] && d[i] <=c[j][1]){
                maxHade = c[j][2];
                break;
            }
        }

        a0 = (i % 2) ? minHade : maxHade;
        a1 = (i % 2) ? maxHade : minHade;

        if(i > 0)dp[0][0] += abs(dp[0][1] - a0);
        dp[0][1] = a0;
        if(i > 0)dp[1][0] += abs(dp[0][1] - a1);
        dp[1][1] = a1;
    }

    cout << max(dp[0][0], dp[1][0]) << endl;

    return 0;
}