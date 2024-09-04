using ll = long long;
using namespace std;
#include <bits/stdc++.h>

// 素因数分解
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

// 階乗
int factorial(int n) {
    int ans = 1;
    for (int i = 2; i <= n; i++) ans *= i;
    return ans;
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
//階乗
int factorial(int n) {
    int ans = 1;
    for (int i = 2; i <= n; i++) ans *= i;
    return ans;
}

//modつき階乗
mint mfactorial(ll n) {
    mint ans = 1;
    for (ll i = 2; i <= n; i++) ans *= i;
    return ans;
}