using namespace std;
using ll = long long;
using ull = unsigned long long;

#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <string>

// return <
inline bool Comp(string& s, int k, int l) {
    printf("? %c %c\n", s[k], s[l]);
    fflush(stdout);
    char ans;
    auto x = scanf(" %c", &ans);
    if (ans == '>')return false;
    else return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    static int N, Q, i, j, headA, headB, headM, center, tail;
    static string mergeBoard;

    i = scanf("%d%d", &N, &Q);
    mergeBoard.clear();
    string s;
    for (i = 0; i < N; i++) s += (char)('A' + i);

    for (i = 1; i < N; i *= 2) {
        for (j = 0; j < N; j += i * 2) {
            // marge(j, j + i, j + i, j + 2 * i)
            center = j + i;
            if(center >= N) break;
            headA = j;
            headB = center;
            headM = 0;
            tail = min(N, j + 2 * i);

            if((int)mergeBoard.size() < 2 * i) mergeBoard.resize(i * 2);

            while(headA < center || headB < tail){
                if(Comp(s, headA, headB))mergeBoard[headM++] = s[headA++];
                else mergeBoard[headM++] = s[headB++];
            }

            while(headA < center)mergeBoard[headM++] = s[headA++];
            while(headB < center)mergeBoard[headM++] = s[headB++];

            for(headA = j, headM = 0; headA < tail;)s[headA++] = mergeBoard[headM++];

        }
    }

    printf("! %s\n", s.c_str());
    fflush(stdout);
    return 0;
}