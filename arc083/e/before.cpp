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

    int N;
    cin >> N;

    int p[N], x[N];
    int r, nr;
    bool rt[N]{};
    pair<int, int> res[N];

    vector<int> chil[N];
    int unvischil[N];
    int dp[2][5001], v;
    bool use[5001];

    stack<int> st;
    p[0] = 0;
    rep(i, 1, N) cin >> p[i];
    rep(i, N) cin >> x[i];

    rep(i, N) {
        if (i > 0) rt[p[i]] = true;
        chil[p[i]].push_back(i);
        res[i] = make_pair(-1, -1);
    }
    rep(i, N) {
        if (!rt[i]) {
            st.push(i);
            res[i] = make_pair(x[i], 0);
        }
        unvischil[i] = chil[i].size();
    }
    while (!st.empty()) {
        v = st.top();
        st.pop();
        if (unvischil[v] > 0) continue;

        unvischil[v]--;

        memset(dp, 0, N * 2 * sizeof(int));
        dp[0][0] = 0;
        rep(i, chil[v].size()) {
            r = i % 2;
            nr = (i + 1) % 2;
            memset(dp[nr], 0, N * sizeof(int));
            rep(j, x[v]) {
                if (i == 1 || dp[r][j] != 0) {
                    if (j + res[chil[v][i]].first < 5001)
                        if (dp[nr][j + res[chil[v][i]].first] < dp[r][j] + 1) {
                            use[j + res[chil[v][i]].first] = 0;
                            dp[nr][j + res[chil[v][i]].first] = dp[r][j] + 1;
                        }
                    if (j + res[chil[v][i]].second < 5001)
                        if (dp[nr][j + res[chil[v][i]].second] < dp[r][j] + 1) {
                            use[j + res[chil[v][i]].first] = 1;
                            dp[nr][j + res[chil[v][i]].second] = dp[r][j] + 1;
                        }
                }
            }
        }
        if (dp[chil[v].size() % 2][x[v]] != chil[v].size())
            break;
        else {
            int b = 0;
            int w = 0;
            int xv = x[v];
            for (int i = chil[v].size() - 1; i >= 0; i--) {
                if (use[xv]) {
                    b += res[chil[v][i]].second;
                    xv -= res[chil[v][i]].second;
                } else {
                    w += res[chil[v][i]].first;
                    xv -= res[chil[v][i]].first;
                }
            }
            debug(v,b,w);
            res[v] = make_pair(b, w);
        }
        st.push(p[v]);
    }
    debug(res[0].first,res[0].second);
    cout << (((res[0].first == x[0]) || (res[0].second == x[0]))? "POSSIBLE" : "IMPOSSIBLE") << endl;

    return 0;
}