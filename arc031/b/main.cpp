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

    static vector<vector<char>> m(10, vector<char>(10, '0'));
    stack<pair<int, int>> st;

    pair<int, int> xy;

    char inum = '0';

    bool ans = false;
    bool temp = false;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) cin >> m[i][j];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (m[i][j] == 'o') {
                st.push(pair(i, j));
                while (!st.empty()) {
                    xy = st.top();
                    st.pop();
                    int x = xy.first;
                    int y = xy.second;

                    m[x][y] = inum;
                    if (x < 9) {
                        if (m[x + 1][y] == 'x')
                            m[x + 1][y] = 'n';
                        else if (m[x + 1][y] == 'o')
                            st.push(pair(x + 1, y));
                    }
                    if (y < 9) {
                        if (m[x][y + 1] == 'x')
                            m[x][y + 1] = 'n';
                        else if (m[x][y + 1] == 'o')
                            st.push(pair(x, y + 1));
                    }
                    if (x > 0) {
                        if (m[x - 1][y] == 'x')
                            m[x - 1][y] = 'n';
                        else if (m[x - 1][y] == 'o')
                            st.push(pair(x - 1, y));
                    }
                    if (y > 0) {
                        if (m[x][y - 1] == 'x')
                            m[x][y - 1] = 'n';
                        else if (m[x][y - 1] == 'o')
                            st.push(pair(x, y - 1));
                    }
                }
                inum++;
            }
        }
    }

    // for (int i = 0; i < 10; i++){
    //     for (int j = 0; j < 10; j++) cout << m[i][j];
    //     cout << endl;
    // }


    if (inum >= '5') {
        cout << "NO" << endl;
        return 0;
    } else {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (m[i][j] == 'n') {
                    vector<char> d4;
                    temp = false;

                    if (i < 9) d4.push_back(m[i + 1][j]);
                    if (j < 9) d4.push_back(m[i][j + 1]);
                    if (i > 0) d4.push_back(m[i - 1][j]);
                    if (j > 0) d4.push_back(m[i][j - 1]);

                    for (char k = '0'; k < inum; k++) {
                        if (find(d4.begin(), d4.end(), k) == d4.end()) {
                            temp = true;
                            break;
                        }
                    }
                    if (temp != true) {
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}