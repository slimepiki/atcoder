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

    ll N, M, X, a, b, t;

    cin >> N >> M >> X;

    ll w[N];
    rep(i, N) cin >> w[N];

    vector<pair<ll, ll>> aj[N];
    ll dp[N];
    bool c[N];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        q;
    pair<ll, int> tv;
    ll t;
    int v;

    auto getHeight = [&](int v, ll t)-> ll{
        ll h = max(0ll, X - t);
        chmin(h, w[v]);
        return h;
    };

    auto getElpT = [&](int u, int v, ll h, ll )

    rep(i, M) {
        cin >> a >> b >> t;
        aj[a].push_back(make_pair(b, t));
    }
    memset(dp, 0x3f, N * sizeof(ll));
    dp[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        tv = q.top();
        q.pop();
        t = tv.first;v = tv.second;
        if(c[v])continue;
        c[v] = true;



        for()
    }

    return 0;
}