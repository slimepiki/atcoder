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

    ll N, ncp;
    cin >> N;
    ncp = N;

    int ans = 0;
    int nm = 0, cp, kake, kazu;

    int dig = 3;
    N /= 100;

    bitset<3> bt = 0;

    while (N) {
        rep(i, pow(3, dig)) {
            cp = i;
            nm = 0;
            kake = 1;
            bt = 0;

            rep(j, dig) {
                if (cp % 3 == 0) {
                    bt[0] = 1;
                    kazu = 3;
                } else if (cp % 3 == 1) {
                    bt[1] = 1;
                    kazu = 5;
                } else {
                    bt[2] = 1;
                    kazu = 7;
                }
                nm += kake * kazu;
                cp /= 3;
                kake *= 10;
            }

            if (nm <= ncp && bt.all()) {
                ans++;
            }
        }
        dig++;
        N /= 10;
    }

    cout << ans << endl;
    return 0;
}