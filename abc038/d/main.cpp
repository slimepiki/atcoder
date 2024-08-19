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

    int N, w, h, r, nr;
    cin >> N;
    int count = 0;
    map<int, vector<int>> b;
    int dp[2][N]{};
    memset(dp, 0x3f, sizeof(int) * N * 2);
    rep(i, N) {
        cin >> w >> h;
        b[w].push_back(h);
    }
    rep(i, b.size()) sort(b[i].begin(), b[i].end());
    // for(auto itr = b.begin();itr != b.end();itr++)rep(j,
    // itr->second.size())debug(itr->first,j,itr->second[j]);

    rep(i, b.size()) {
        r = i % 2;
        nr = (i + 1) % 2;
        count++;

        memcpy(dp[nr], dp[r], N * sizeof(int));

        rep(j, b[i].size()) {
            auto itr = lower_bound(dp[r], dp[r] + N, b[i][j]);
            int index = distance(dp[r], itr);
            debug(index,dp[nr][index], b[i][j]);
            chmin(dp[nr][index], b[i][j]);
        }
    }

    rep(i, N) debug(i, dp[N % 2][i]);

    for (int i = N - 1; i >= 0; i--) {
        if (dp[count % 2][i] < IINF) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}