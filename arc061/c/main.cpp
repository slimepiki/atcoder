using namespace std;
using ll = long long;
using ull = unsigned long long;

#include <bits/stdc++.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll ans = 0, temp = 0;
    string s;
    cin >> s;

    for (int i = 0; i < (1 << (s.size() - 1)); i++) {
        temp = int(s[0] - '0');
        for (int j = 1; j < s.size(); j++) {
            if ((i & (1 << (j - 1))) != 0) {//普通にi & (1 << (j - 1))でええやん
                ans += temp;
                temp = int(s[j] - '0');
            } else {
                temp = temp * 10 + s[j] - '0';
            }
        }
        ans += temp;
    }
    cout << ans << endl;
    return 0;
}