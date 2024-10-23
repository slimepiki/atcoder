using namespace std;
using ll = long long;
using ull = unsigned long long;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)

#define ii tuple<int, int>
#define iii tuple<int, int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>

#include <bits/stdc++.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int m[3][3];
    rep(i, 3) rep(j, 3) cin >> m[i][j];

    int a[3], b[3];
    rep(i, 101) {
        a[0] = i;
        b[0] = m[0][0] - a[0];
        b[1] = m[0][1] - a[0];
        b[2] = m[0][2] - a[0];
        a[1] = m[1][0] - b[0];
        a[2] = m[2][0] - b[0];

        bool ok = true;
        rep(j, 1, 3) rep(k, 1, 3) {
            if (m[j][k] != a[j] + b[k]) ok = false;
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}