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

    int b[3][3];int N,n;
    rep(i, 3)cin >> b[i][0] >> b[i][1] >> b[i][2];
    cin >> N;


    bool h[3][3];
    bool hit = false, bingo = false;
    memset(h, 0, 9 * sizeof(bool));

    set<int> l;
    rep(i,3)rep(j,3)l.emplace(b[i][j]);
    //for(auto it = l.begin();it != l.end();it++)debug(*it);

    while(cin >> n){
        if(l.find(n) != l.end()){
            rep(i,3)rep(j,3){
                if(b[i][j] == n && !h[i][j]){
                    h[i][j] = true;
                    hit = true;
                }
            }

            if(hit){
                rep(i,3){
                    if(h[i][0] && h[i][1] && h[i][2]){bingo = true;break;}
                    if(h[0][i] && h[1][i] && h [2][i]){bingo = true;break;}
                }
                if(h[0][0] && h [1][1] && h [2][2])bingo = true;
                if(h[0][2] && h [1][1] && h [2][0])bingo = true;
                if(bingo){
                    cout << "Yes" << endl;
                    return 0;
                }
                hit = false;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}