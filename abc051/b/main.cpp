using namespace std;
#include <bits/stdc++.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    cin.tie(nullptr);
    // if you use scanf or printf, below line have to be deleted
    ios_base::sync_with_stdio(false);

    int K, S, ans;
    ans = 0;
    cin >> K >> S;

    for (int i = 0; i <= K; i++)
        for (int j = 0; j <= K; j++){
            int x = S - i - j;
            if (x <= K && x >= 0) ans++;
        }

    cout << ans;

    return 0;
}