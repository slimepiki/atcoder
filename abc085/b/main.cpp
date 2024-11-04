using namespace std;
using ll=long long;
using ull=unsigned long long;

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip> 
#include <string>
#include<algorithm>


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n,a;
    cin >> n;

    unordered_set<int> s;

    rep(i,n){cin >> a;
    s.insert(a);}
    cout << s.size() << endl;
    return 0;
}