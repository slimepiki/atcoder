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
#define repit(it, a) for (auto it = a.begin(); it != a.end(); it++)

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

#define printa1d(a, W)                   \
    {                                    \
        rep(i, W) {                      \
            cout << a[i];                \
            if (i != W - 1) cout << ' '; \
        }                                \
        cout << endl;                    \
    }

#define printa2d(a, H, W)                 \
    {rep(i, H){rep(j, W){cout << a[i][j]; \
    if (j != W - 1) cout << ' ';          \
    }                                     \
    cout << endl;                         \
    }                                     \
    }

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

ll comb(ll n, ll k) {
    ll ret = 1;
    if(n < k)ret = 0;
    for (ll i = n; i >= 0; i--) {
        if (i > (n-k) && i != 0) ret *= i;
        if (i != n && k >= n - i) ret /= (n - i);
    }
    debug(ret);
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll N;
    cin >> N;
    ll ans = 0;

    string s;
    // unordered_map<string, int> m;
    // rep(i,N){
    //     cin >> s;
    //     if(s[0] == 'M' || s[0] == 'A' || s[0] == 'R' || s[0] == 'C' || s[0] == 'H'){
    //         if(m[s] != 0)m[s]++;
    //         else m[s] = 1;
    //     }
    // }

    // int c[3]{};
    // repit(it,m){
    //     c[min(2,it->second-1)]++;
    // }
    // debug(c[0],c[1],c[2]);
    // //all c[0];
    // ans += comb(c[0],3);
    // //c[0] * 2 and (c[1] or c[2]);
    // ans += comb(c[0],2) * (c[1] + c[2]);
    // //c[0]*1 and (c[1] or c[2]) * 2;
    // ans += c[0]*(comb(c[1], 2)+comb(c[2],2));
    // //c[0]*1 and c[1] * 1 and c[2] * 1;
    // ans += c[0]*c[1]*c[2];
    // //c[1]*3;
    // ans += comb(c[1],3);
    // //c[1]*2 and c[2] * 1;
    // ans += comb(c[1],2) * c[2];
    // //c[1]*1 and c[2] * 2;
    // ans += c[1] * comb(c[2],2);
    // //c[3]*3;
    // ans += comb(c[2],3);
    // cout << ans << endl;
    ll c[5]{};
    rep(i,N){
        cin >> s;
        if(s[0] == 'M')c[0]++;
        else if(s[0] == 'A')c[1]++;
        else if(s[0] == 'R')c[2]++;
        else if(s[0] == 'C')c[3]++;
        else if(s[0] == 'H')c[4]++;
    }

    rep(i,5)rep(j,i+1,5)rep(k,j+1,5){
        ans += c[i] * c[j] * c[k];
    }
    cout << ans << endl;
    return 0;
}