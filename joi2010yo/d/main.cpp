using namespace std;
using ll = long long;
using ull = unsigned long long;

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
#include <set>
#include <string>

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    static int N, K, n, b;
    static string s;

    set<string> r;

    stack<pair<ii, string>> st;

    pair<ii, string> item;

    cin >> N >> K;
    vector<string> c(10);

    rep(i, N) { cin >> c[i]; }

    st.push(pair(ii(0, 0), ""));
    while (!st.empty()) {
        item = st.top();
        st.pop();
        s = item.second;
        n = get<0>(item.first);
        b = get<1>(item.first);

        if(n >= K){
            r.insert(s);
            continue;
            }


        rep(i, N) {
            if((b & (1 << i)) == 0)st.push(pair(ii(n+1,b + (1 << i)), s+c[i]));
        }
    }

    cout << r.size()<< endl;

    return 0;
}