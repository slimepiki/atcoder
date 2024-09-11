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
    int b[2][3],c[3][2];

int dfs(array<int, 9> ar, int count){
    int chocd = 0;
    if(count == 9){
        chocd = 0;
        rep(i, 2)rep(j,3){
            if(ar[i * 3 + j] == ar[(i + 1) * 3 + j])chocd += b[i][j];
        }
        rep(i, 3)rep(j,2){
            if(ar[i * 3 + j] == ar[i * 3 + j + 1])chocd += c[i][j];
        }
    }
    else if(count % 2 == 0){
        chocd = 0;
        rep(i, 9)if(ar[i] == 0){
            array<int, 9> nar = ar;
            nar[i] = 1;
            chmax(chocd, dfs(nar, count + 1));
        }
    }else{
        chocd = IINF;
            rep(i, 9)if(ar[i] == 0){
            array<int, 9> nar = ar;
            nar[i] = -1;
            chmin(chocd, dfs(nar, count + 1));
        }
    }
    //debug(chocd, count);
    //if(chocd != IINF)debug(chocd, count);
    return chocd;
} 

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    rep(i, 6)cin >> b[i/3][i%3];
    rep(i, 6)cin >> c[i/2][i%2];

    int sum = 0;

    rep(i,6)sum += b[i/3][i%3] + c[i/2][i%2];
    
    int chocdmax = dfs({0,0,0,0,0,0,0,0,0},0);

    cout << chocdmax << endl;
    cout << sum - chocdmax << endl;





    //盤面のチェック, 大の得点, 子の得点,マークされた箇所の数
    // stack<tuple<array<int, 9>, int, int, int>> st;

    // st.push(make_tuple(array<int,9>{},0,0,0));
    // while(!st.empty()){
    //     auto item = st.top();st.pop();
    //     auto mark = get<0>(item);
    //     int d = get<1>(item);
    //     int k = get<2>(item);
    //     int count = get<3>(item);

    //     if(count == 9){
    //         if(d > dmax){
    //             dmax = d;
    //             kmax = k;
    //         }if(d == dmax){
    //             chmax(kmax, k);
    //         }
    //     }else{
    //         rep(i, 9)if(mark[i] != 0){
    //             auto nxmark = mark;
    //             int nxd = d;
    //             int nxk = k;
    //             //chokudai更新ゾーン
    //             if(count % 2 == 0){
    //                 nxmark[i] = 1;
                    
    //             }else{//chokuko更新ゾーン
    //                 nxmark[i] = -1;
    //             }
    //             st.push(make_tuple(nxmark,nxd,nxk,count + 1));
    //         }
    //     }
    // }

    return 0;
}