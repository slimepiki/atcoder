using ll = long long;
using namespace std;
#include <bits/stdc++.h>
#define repit(it, a) for(auto it = a.begin(); it != a.end();it++)
template <typename T>
inline bool chmax(T& a, const T& b) {
    bool compare = a < b;
    if (a < b) a = b;
    return compare;
}

//#########################################################

bool IsPrime(int num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0)return false;    
    }
    return true;
}


// 素因数分解
vector<pair<ll, ll> > prime_factorize(ll N) {
    if(N < 0){
        cerr << "input is negative!" << endl;
    }
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


ll powll(ll a, ll b){
    ll ret = 1;
    for(int i = 0; i < b;i++)
        ret *= a;
    

    return ret;
}

//最小公倍数
ll lcm(ll a, ll b){
    auto af = prime_factorize(a);
    auto bf = prime_factorize(b);

    unordered_map<ll, ll> m;
    repit(itr,af){
        m[itr->first] = itr->second;
    }
    repit(itr,bf){
        chmax(m[itr->first],itr->second);
    }

    ll ret = 1;
    repit(itr,m){
        ret *= powll(itr->first, itr->second);
    }
    return ret;
}

// 階乗
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
    constexpr operator ll() const{
        return x;
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
