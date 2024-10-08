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

vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;

        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}


// modつきint
constexpr int mod = 1000000007;
class mint {
   public:
    long long x;
    constexpr mint(long long x = 0) : x((x % mod + mod) % mod) {}
    constexpr mint operator-() const { return mint(-x); }
    constexpr mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    constexpr mint& operator-=(const mint& a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    constexpr mint& operator*=(const mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    constexpr mint operator+(const mint& a) const {
        mint res(*this);
        return res += a;
    }
    constexpr mint operator-(const mint& a) const {
        mint res(*this);
        return res -= a;
    }
    constexpr mint operator*(const mint& a) const {
        mint res(*this);
        return res *= a;
    }
    constexpr mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    constexpr mint inv() const { return pow(mod - 2); }
    constexpr mint& operator/=(const mint& a) { return (*this) *= a.inv(); }
    constexpr mint operator/(const mint& a) const {
        mint res(*this);
        return res /= a;
    }
};
ostream& operator<<(ostream& os, const mint& m) {
    os << m.x;
    return os;
}

mint mfactorial(int n) {
    mint ans = 1;
    for (int i = 2; i <= n; i++) ans *= i;
    return ans;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;

    auto primes = prime_factorize(M);
    mint ans = 1;

    for (auto itr = primes.begin(); itr != primes.end(); itr++) {
        auto item = *itr;

        ans *= mfactorial(item.second + N - 1) /
               (mfactorial(item.second) * mfactorial(N - 1));
    }

    cout << ans << endl;

    return 0;
}