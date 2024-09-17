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
#define debug(...) //   :)
#endif
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rrep(i, a, b) for (int i = int(a); i >= int(b); --i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)

#define ii pair<int, int>
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

#define IINF 0x3f3f3f3f-10

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
    int a,b,c;
    //ii : 辺の接続先、コスト
    vector<vector<pair<int, ll>>> e(N,vector<pair<int, ll>>());
    rep(i, N-1){
        cin >> a >> b >> c;
        e[a-1].push_back(make_pair(b-1, c));
        e[b-1].push_back(make_pair(a-1, c));
    }

    int Q, K;
    cin >> Q >> K;
    
    vector<ll> dist(N,-1);

    {
        queue<int> q;
        dist[K-1] = 0;
        q.push(K-1);

        while(!q.empty()){
            int x = q.front();q.pop();
            for(auto itr = e[x].begin();itr != e[x].end();itr++){
                int next = itr->first;
                if(dist[next] < 0){
                    dist[next] = dist[x] + itr->second;
                    q.push(next);
                }
            }
        }
    }

    int x,y;
    while(cin >> x >> y)cout << dist[x-1] + dist[y-1] << endl;

    return 0;
}