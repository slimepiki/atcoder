using namespace std;
using ll=long long;
using ull=unsigned long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip> 
#include <string>
#include<algorithm>


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, a, b,ans = 100000;
    vector<int> t(4);

    cin >> N;
    for(int i = 0; i < N;i++)cin >> t[i];

    for(int i = 0; i < (1 << N);i++){
        a =b= 0;
        for(int j = 0; j < N; j++){
            if(i & (1 << j)) a += t[j];
            else b += t[j];
        }
        ans = min(ans, max(a, b));
    }

    cout << ans << endl;

    return 0;
}