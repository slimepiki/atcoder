using namespace std;
using ll = long long;
using ull = unsigned long long;

#include <bits/stdc++.h>
#include <iomanip> 
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    cin.tie(nullptr);
    // if you use scanf or printf, below line have to be deleted
    ios_base::sync_with_stdio(false);

    static int N, i, j;
    static vector<double> p(200);
    static double ans;ans = 0;

    cin >> N;

    for (i = 0; i < N; i++) cin >> p[i * 2] >> p[i * 2 + 1];

    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            ans = max(ans, pow(p[j * 2] - p[i * 2], 2)
                               + pow(p[j * 2 + 1] - p[i * 2 + 1], 2));
        }
    }
    cout << fixed << setprecision(6) << sqrt(ans) << endl;

    return 0;
}