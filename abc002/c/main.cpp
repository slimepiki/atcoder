using namespace std;
using ll = long long;
using ull = unsigned long long;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)

#include <bits/stdc++.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    static int xa, ya, xb, yb, xc, yc;
    static double ans;

    static double pab, pbc, pac,s;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    pab =(double) pow(xb-xa,2) + pow(yb-ya, 2);
    pbc =(double) pow(xc-xb,2) + pow(yc-yb, 2);
    pac =(double) pow(xc-xa,2) + pow(yc-ya, 2);

    s = (sqrt(pab)+sqrt(pbc)+sqrt(pac))/2;

    ans = sqrt(s * (s - sqrt(pab)) * (s - sqrt(pbc)) * (s - sqrt(pac)));


    cout << std::fixed << std::setprecision(3) << ans<< endl;

    return 0;
}