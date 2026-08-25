#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> state(n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i && !state[i];j++){
                state[i]=!state[i-j*j];
            }
        }
        return state[n];
    }
};