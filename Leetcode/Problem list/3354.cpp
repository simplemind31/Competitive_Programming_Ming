#include <bits/stdc++.h>
using namespace std;
short n,suma,iz,con;
class Solution {
public:
    int countValidSelections(vector<int>&nums){
        n=nums.size();
        for(short i=suma=iz=con=0;i<n;i++)suma+=nums[i];
        for(short i=0;i<n;i++){
            iz+=nums[i];
            if(nums[i])continue;
            con+=2*(2*iz==suma);
            con+=abs(2*iz-suma)==1;
        }
        return con;
    }
};