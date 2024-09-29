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

    int N, M;

    cin >> N >> M;

    vector<vector<pair<int, int>>> e(N, vector<pair<int, int>>());
    vector<ll> ans(N, -10e10);

    int u, v, w;

    rep(i, M) {
        cin >> u >> v >> w;
        e[u - 1].push_back(make_pair(v - 1, w));
        e[v - 1].push_back(make_pair(u - 1, -w));
    }

    stack<int> st;
    rep(k, N) {
        if (ans[k] == -10e10) {
            st.push(k);
            ans[k] = 0;
        }
        while (!st.empty()) {
            u = st.top();
            st.pop();
            rep(i, e[u].size()) {
                v = e[u][i].first;
                w = e[u][i].second;
                if (ans[v] == -10e10) {
                    ans[v] = ans[u] + w;
                    st.push(v);
                }
            }
        }
    }

    rep(i, N) {
        cout << ans[i];
        if (i != N - 1) cout << ' ';
    }
    cout << endl;

    return 0;
}