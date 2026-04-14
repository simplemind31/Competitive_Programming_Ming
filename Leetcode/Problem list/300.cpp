#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> numeros,memo;
    int solve(int pos){
        /*
        memo[pos]=solve(pos)=la máxima cantidad de numeros que puedo elegir si solo utilizo 
        los números de posicion del 0 al pos además el último número elegido es pos;
        */
        if(memo[pos]!=0)return memo[pos];
        int maxi=0;
        for(int i=0;i<pos;i++){
            if(numeros[i]<numeros[pos]){
                int opcion=solve(i);
                maxi=max(maxi,opcion);
            }
        }
        memo[pos]=maxi+1;
        return maxi+1;
    }
    int lengthOfLIS(vector<int>& nums) {
        numeros=nums;
        int n=nums.size();
        memo.resize(n);
        int respuesta=0;
        for(int i=0;i<n;i++){
            respuesta=max(respuesta,solve(i));
        }
        return respuesta;
    }
};