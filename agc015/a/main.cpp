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
    x = t.first();    \
    y = t.second();
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

ll factorial(ll n) {
    ll ans = 1;
    if(n < 0){
        cerr << "factorial error : n < 0" << endl; 
        return -1;
    }
    for (ll i = 2; i <= n; i++) ans *= i;
    return ans;
}

ll perm(ll n, ll k){
    ll ans = 1;
    if(n < k || k < 0){
        cerr << "perm error : n = " << n << ", k = " << k  << endl; 
        return -1;
    }
    if(k == 0)return 1;
    for(ll i = 0; i < k;i++){
        ans *= (n-i);
    }
    return ans;
}

ll conv(ll n, ll k){
    if(k <= 0){
        cerr << "conv error : k = " << k << endl;
    }
    return perm(n,k)/ factorial(k);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll N, A, B;
    cin >> N >> A >> B;
    if(A > B || (N == 1 && A != B)) cout << 0 << endl;
    else if(B == A) cout << 1 << endl;
    else cout << (B-A)*(N-2)+1 << endl;

    return 0;
}