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

    static vector<vector<int>> p(100, vector<int>(100, 0));
    static int N, M, es, ee, ans, v;
    static vector<int> vis(100, 0);
    static bool istree;

    stack<int> st;
    ans = 0;

    fill(vis.begin(), vis.end(), 0);

    

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> es >> ee;
        p[es-1][ee-1] = 1;
        p[ee-1][es-1] = 1;
    }

    for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
            istree = true;
            st.push(i);
            while (!st.empty()) {
                v = st.top();
                st.pop();
                if (vis[v] == 1) {
                    istree = false;
                } else if(vis[v] == 0) {
                    for (int j = 0; j < N; j++) {
                        
                        if (p[v][j] == 1) {
                            st.push(j);
                            p[v][j] = 0;
                            p[j][v] = 0;
                        }
                    }
                    vis[v] = 1;
                }
            }

            if (istree) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}