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

    static ll N,a,b, x, ans;
    static vector<tuple<ll, ll>> lobo;

    cin >> N;
    rep(i, N){
        cin >> a >> b;
        lobo.push_back(tuple(a-b < 0 ? 0 : a-b, a+b));
    }

    sort(lobo.begin(), lobo.end(), [](tuple<ll, ll> const& l, tuple<ll, ll> const& r){
        return get<1>(l) < get<1>(r);
    });
    x = 0;ans = 0;
    rep(i, N){
        if(get<0>(lobo[i]) >= x){
            ans++;
            x = get<1>(lobo[i]);
        }
    }

    cout << ans << endl;

    return 0;
}