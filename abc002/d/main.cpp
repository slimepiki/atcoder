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

    int N, M, x, y, ans, temp;
    cin >> N >> M;
    static vector<vector<int>> r(N, vector<int>(N, 0));

    ans = 1;

    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        r[x - 1][y - 1] = 1;
    }

    for (int i = 0; i < (1 << N); i++) {
        temp = 0;
        int flag = 0;
        vector<int> h;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                h.push_back(j);
                temp++;
            }
        }
        for (int j = 0; j < h.size(); j++) {
            for (int k = j + 1; k < h.size(); k++) {
                if (r[h[j]][h[k]] == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
        }
        if (flag == 0) ans = max(ans, temp);
    }

    cout << ans << endl;

    return 0;
}