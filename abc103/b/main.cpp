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
#include <string>

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    int i = 0;
    int N = s.size();
    bool flag = true;
    rep(i, N) {
        flag = true;
        rep(j, N) {
            if (s[(i + j) % N] != t[j]) {
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}