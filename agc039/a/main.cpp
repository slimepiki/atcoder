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

void lencri(ll &len){
    if(len == 0)len = 2;
    else len++;
}

void sumadd(ll &dst, ll &val){
    dst += val/2;
    val = 0;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    ll K;
    cin >> s >> K;

    bool all = true;
    rep(i,s.size()){
        if(s[0] != s[i]){
            all = false;
            break;
        }
    }
    if(all){
        cout << s.size()*K/2ll << endl;
        return 0;
    }

    // rep(i,s.size()-1){
    //     if(s[i] == s[i+1]){
    //         len++;

    //     }else{
    //         sans += ceil(len/3.0f);
    //         len = 0;
    //     }
    // }
    // sans += ceil(len/3.0f);

    // ll kyo = 0;

    // if(!(s[s.size()-1] == s[s.size()-2]|| s[0] == s[1])&& s[s.size()-1] ==
    // s[0])kyo = K-1; debug(sans,K,kyo); cout << sans * K + kyo << endl;

    //2つ回以降の文字列での変換回数
    // ll sr = 0;
    
    // //連続する要素の長さ
    // ll len = 0;

    // rep(i, s.size() - 1) {
    //     if (s[i] == s[i + 1]) {
    //         lencri(len);
    //     } else {
    //         len = 0;
    //     }
    // }

    // if(s[s.size()-1] == s[0])lencri(len);
    // debug(len)

    // rep(i, s.size() - 1) {
    //     if (s[i] == s[i + 1]) {
    //         if(len == 0)len = 2;
    //         else len++;

    //     } else {
    //         debug(i);
    //         if(i == 0){len = 0;}
    //         else sumadd(sr,len);
    //     }
    // }
    // sumadd(sr,len);
    // ll lr = 0;

    // rep(i,s.size()-1){
    //     if(s[i] == s[i+1]){
    //         lencri;
    //     }else{
    //         debug(i);
    //         sumadd(lr,len);
    //     }
    // }

    // sumadd(lr,len);

    // cout <<  lr + sr * (K-1) << endl;

    ll sum=0,len = 0,hlen = 0,tlen = 0;
    rep(i,s.size()){
        if(s[i] == s[i+1])lencri(len);
        else sumadd(sum,len);
    }
    sumadd(sum,len);

    if(s[0] == s[s.size()-1]){
        len = 2;
        rep(i,1,s.size()){
            if(s[i] == s[0])lencri(hlen);
            else break;
        }
        rep(i,1,s.size()){
            if(s[s.size()-1-i] == s[0])lencri(tlen);
            else break;
        }
    }

    ll htlen = hlen+tlen;
    ll hsum = 0,tsum = 0,htsum = 0;

    sumadd(hsum,hlen);
    sumadd(tsum,tlen);
    sumadd(htsum,htlen);

    cout << sum * K - (hsum+tsum-htsum)*(K-1) << endl;

    return 0;
}