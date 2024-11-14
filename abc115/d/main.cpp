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

ll p[55], h[55];

ll getp(int l, ll x){
    debug(l,x)
    if(l == 0) return 1;
    if(x == 1) return 0;
    x--;
    if(x < h[l - 1]) return getp(l-1,x);
    x -= h[l - 1];
    if(x == 0) return p[l-1];
    if(x == 1) return p[l - 1]+1;
    x--;
    if(x < h[l-1])return p[l-1]+1 + getp(l-1,x);
    x -= h[l-1];

    return p[l-1]*2 + 1;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll N,X;

    cin >> N >> X;
    h[0] = 1;
    rep(i,1,N+1) h[i] = h[i-1]*2 + 3;
    p[0] = 1;
    rep(i,1,N+1) p[i] = p[i-1]*2 + 1;

    cout << getp(N,X) << endl;

    return 0;
}