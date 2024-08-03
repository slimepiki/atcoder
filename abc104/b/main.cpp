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
    static string s;
    static bool c;
    cin >> s;
    c = false;

    if (s[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }

    rep(i, 1, s.size()) {
        if (i >= 2 && i <= s.size() - 2) {
            if (s[i] == 'C') {
                if (c) {
                    cout << "WA" << endl;
                    return 0;
                } else {
                    c = true;
                    continue;
                }
            }
        }
        if (s[i] < 'a' || s[i] > 'z') {
            cout << "WA" << endl;
            return 0;
        }
    }

    if (c)
        cout << "AC" << endl;
    else
        cout << "WA" << endl;

    return 0;
}