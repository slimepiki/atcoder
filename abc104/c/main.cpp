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

    int D, G, ans, temp, score, prob;
    static vector<int> p(10), c(10);

    cin >> D >> G;

    ans = 100000;
    score = G;

    for (int i = 0; i < D; i++) cin >> p[i] >> c[i];

    for (int i = 0; i < (1 << D); i++) {
        temp = 0;
        score = G;
        for (int j = 0; j < D; j++) {
            if (i & (1 << j)) {
                score -= c[j] + 100 * (j + 1) * p[j];
                temp += p[j];
            }
        }
        for (int j = D - 1; j >= 0; j--) {
            if(score <= 0)break;
            if ((i & (1 << j)) == 0) {
                if (score % (100 * (j + 1)) == 0)
                    prob = min(score / (100 * (j + 1)), p[j]);
                else
                    prob = min((score / (100 * (j + 1))) + 1, p[j]);

                score -= 100 * (j + 1) * prob;
                temp += prob;
            }
        }
        ans = min(ans, temp);
    }

    cout << ans << endl;

    return 0;
}