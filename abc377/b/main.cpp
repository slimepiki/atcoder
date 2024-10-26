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

int nana[4][2] = {{-1,-1},{-1,1},{1,-1}, {1,1}};

bool isIntersect(int x, int y, int kx, int ky){
    if(x == kx || y == ky)return true;
        // rep(i, 8){
        //     rep(j,4){
        //         int dx =kx + i* nana[j][0];
        //         int dy =kx + i* nana[j][1];
        //         if(dx >= 0 && dy >= 00 && dx <= 7 && dy <=7){
        //             if(x == dx && y == dy)return true;
        //         }
        //     } 
        // }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string s;
    vector<vector<int>> k(8,vector<int>());
    rep(i, 8){
        cin >> s;
        rep(j,8){
            if(s[j] == '#')k[i].push_back(j);
        }
    }
    int ans = 0;
    rep(i,8)rep(j,8){
        bool no = false;
        rep(l,8){
            rep(m, k[l].size()){
                no |= isIntersect(i, j, l, k[l][m]);
            }
        }
        if(!no)ans++;
    }
    cout << ans << endl;
    return 0;
}