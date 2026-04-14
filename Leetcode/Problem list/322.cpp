#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> monedas,memo;
    // 1 2 5 10 7
    int solve(int x){
        // memo[x]=res=cual es la minima cantidad de monedas que necesito para formar el nuemro x 
        /*int op1=1+solve(x-1);
        int op2=1+solve(x-2);
        int op3=1+solve(x-5);
        int op4=1+solve(x-10);*/
        if(x==0)return 0;
        if(x<0)return 1e8;
        if(memo[x]!=1e9)return memo[x];
        int mini=1e9;
        for(int i=0;i<monedas.size();i++){
            int opi=1+solve(x-monedas[i]);
            mini=min(mini,opi);
        }
        memo[x]=mini;
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        monedas=coins;
        memo.assign(amount+1,1e9);
        int respuesta=solve(amount);
        if(respuesta>=1e6)return -1;
        else return respuesta;
    }
};