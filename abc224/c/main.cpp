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
    #define debug(...)                                                                                       \
        cerr << "\033[33m(line:" << __LINE__ << ") " << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); \
        cerr << "\033[m";
#else
    #define debug(...)  //   :)
#endif
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rrep(i, a, b) for (int i = int(a); i >= int(b); --i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)

#define ii pair<int, int>
#define iiget(t, x, y) \
    x = t.first();     \
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

ll gcd(ll a, ll b) {
    ll l = max(a, b);
    ll s = min(a, b);
    ll temp;
    while (l % s != 0) {
        temp = s;
        s = l % s;
        l = temp;
    }
    return s;
}

pair<ll, ll> makev(pair<ll, ll> p1, pair<ll, ll> p2) { return make_pair(p2.first - p1.first, p2.second - p1.second); }
pair<ll, ll> nom(pair<ll, ll> p) {
    if (p.first == 0) return make_pair(0, 1);
    if (p.second == 0) return make_pair(1, 0);
    ll d = gcd(abs(p.first), abs(p.second));
    ll sig = (p.first < 0) ? -1 : 1;
    return make_pair(sig * p.first / d, sig * p.second / d);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    pair<ll, ll> p[N];
    ll x, y;
    rep(i, N) {
        cin >> x >> y;
        p[i] = make_pair(x, y);
    }
    ll ans = 0;

    rep(i, N) rep(j, i + 1, N) {
        rep(k, j + 1, N) {
            pair<ll, ll> pij = makev(p[i], p[j]);
            pair<ll, ll> pik = makev(p[i], p[k]);
            pair<ll, ll> pjk = makev(p[j], p[k]);

            pij = nom(pij);
            pjk = nom(pjk);
            pik = nom(pik);

            if (!(pij == pjk && pjk == pik)) ++ans;
            if (N == 4) debug(i, j, k, ans);
            if (N == 4) debug(pij.first, pij.second, pik.first, pik.second, pjk.first, pjk.second);
        }
    }
    cout << ans << endl;
    return 0;
}