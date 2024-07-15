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

    static int N, ans, li, lj, lk;
    static vector<int> l(100);
    ans = 0;

    cin >> N;

    for (int i = 0; i < N; i++) cin >> l[i];

    sort(l.rbegin(), l.rend());
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++)
                if (l[i] != l[j] && l[j] != l[k] && l[i] - l[j] - l[k] < 0)ans++;

    cout << ans << endl;

    return 0;
}