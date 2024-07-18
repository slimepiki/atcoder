using namespace std;
using ll=long long;
using ull=unsigned long long;

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip> 
#include <string>
#include<algorithm>


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll ans, temp;
    string s;
    cin >> s;

    ans = 1 << (s.size() - 1);

    for(int i = 0; i < (1 << (s.size() - 1)); i++){
        temp = int(s[0] - '0');
        for(int j = 0; j < s.size() - 1; j++){
            if(i & (1 << j)) temp += int(s[j + 1] - '0');
            else temp -= int(s[j + 1] - '0');
        }
        if(temp == 7) {
            ans = i;
            break;
            }
    }

    for(int i = 0; i < s.size() - 1; i++){
        cout << s[i];
        if(ans & (1 << i)) cout << '+';
        else cout << '-';
    }
    cout << s[s.size() - 1];

    cout << "=7" << endl;

    return 0;
}