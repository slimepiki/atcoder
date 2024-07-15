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
    //if you use scanf or printf, below line have to be deleted
    ios_base::sync_with_stdio(false);

    static int N, Y;
    static int x, y, z;
    x = y = z = -1;
    cin >> N >> Y;

    for(int i = 0; i <= N; i++)for(int j = 0; j <= N - i; j++)if(i * 10000 + j * 5000 + (N - i - j) * 1000 == Y){
        x = i;y=j;z=N - i - j;
        break;
    }

    cout << x<< ' ' << y << ' ' << z << endl;

    return 0;
}