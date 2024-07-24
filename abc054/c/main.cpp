using namespace std;
using ll = long long;
using ull = unsigned long long;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)

#define ii tuple<int, int>
#define iiget(t, x, y) \
    x = get<0>(t);   \
    y = get<1>(t);
#define iii tuple<int, int, int>
#define iiiget(t, x, y, z) \
    x = get<0>(t);       \
    y = get<1>(t);       \
    z = get<2>(t);
#define vi vector<int>
#define initsvi(a, S, N) static vi a(S, N);
#define vvi vector<vi>
#define initsvvi(a, H, W, N) static vvi a(H, vi(W, N));
#define vll vector<ll>
#define initsvll(a, S, N) static vll a(S, N);

#define vc vector<char>
#define initsvc(a, S, N) static vc a(S, N);
#define vvc vector<vc>
#define initsvvc(a, H, W, N) static vvc a(H, vc(W, N));

#include <bits/stdc++.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    static int N, M,u,v,b,ans,bitans;

    cin >> N >> M;

    ii vb;

    initsvvi(a, N, N, 0);
    rep(i,M){
        cin >> u >> v;
        a[u-1][v-1] = 1;
        a[v-1][u-1] = 1;
    }


    stack<ii> st;

    st.push(ii(0,1));
    ans = 0;

    bitans = 0;

    rep(i, N){
        bitans += (1 << i);
    }

    while(!st.empty()){
        vb = st.top();st.pop();
        iiget(vb, u, b);
        if(b == bitans){
             ans++;
             continue;
             }
        rep(i, N){
            if(a[u][i] == 1 && (b & (1 << i)) == 0)st.push(ii(i, b+ (1 << i)));
        }
    }

    cout << ans << endl;

    return 0;
}