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
#define rrep(i, a, b) for (int i = int(a); i >= int(b); --i)
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

#define IINF 0x3f3f3f3f - 10

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

    int N, M, k, r, nr;
    cin >> N >> M;
    ll A, B, c, d;
    ll ans[2];
    A = 0;B=0;
    rep(i, N) {
        cin >> k;
        A += k;
    }

    rep(i, M) {
        cin >> k;
        B += k;
    }
    ll dp[2][max(A, B) + 1]{};
    dp[0][0] = 1;
    rep(l, 2) {
        if (l == 0) {
            c = N;
            d = B;
        } else {
            c = M;
            d = A;
        }
        rep(i, 1, c+1) {
            r = i % 2;
            nr = (i + 1) % 2;
            rep(j, d+1) {
                if (j >= r)
                    dp[r][j] = (dp[nr][j] + dp[r][j - r]) % 1000000007;
                else
                    dp[r][j] = dp[nr][j];
            }
        }
        ans[l] = dp[c%2][d];
    }
    cout << (ans[0] * ans[1]) % 1000000007 << endl;
    return 0;
}