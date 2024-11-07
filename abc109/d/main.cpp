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

#define ii pair<int, int>
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

constexpr int tdir[2][2] = {{1, 0}, {0, 1}};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    int a[H][W];

    rep(i,H)rep(j,W)cin >> a[i][j];
    vector<tuple<int,int,int,int>> op;
    int opc = 0;
    rep(i, H) {
        rep(j, W) {
            rep(k, 2) {
                int x = i + tdir[k][0], y = j + tdir[k][1];
                if (x >= 0 && x < H && y >= 0 && y < W) {
                    if(a[i][j] % 2 == 1){
                        a[i][j]--;a[x][y]++;
                        opc++;
                        op.push_back(make_tuple(i+1,j+1,x+1,y+1));
                    }
                }
            }
        }
    }

    cout << opc << endl;
    rep(i,op.size()){
        auto o = op[i];
        printf("%d %d %d %d\n", get<0>(o), get<1>(o), get<2>(o), get<3>(o));
    }

    return 0;
}