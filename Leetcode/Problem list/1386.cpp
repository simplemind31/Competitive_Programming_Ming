#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,con,res;
    int solve(vector<vector<int>>& nums,int pos){
        vector<bool> posi(10);
        for(int i=pos;i<m && nums[i][0]==nums[pos][0];i++)posi[nums[i][1]-1]=1;
        int suma=0;
        for(int i=1;i<=8;i++)suma+=posi[i];
        if(!suma)return 2;
        suma=0;
        for(int i=1;i<=4;i++)suma+=posi[i];
        if(!suma)return 1;
        suma=0;
        for(int i=5;i<=8;i++)suma+=posi[i];
        if(!suma)return 1;
        suma=0;
        for(int i=3;i<=6;i++)suma+=posi[i];
        if(!suma)return 1;
        return 0;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& nums) {
        m=nums.size(),con=1,res=0;
        sort(nums.begin(),nums.end());
        // solve 0
        res+=solve(nums,0);
        cout << res << ' ';
        for(int i=1;i<m;i++){
            if(nums[i][0]==nums[i-1][0])continue;
            con++;
            res+=solve(nums,i);
            cout << res << ' ';
        }
        res+=2*(n-con);
        return res;
    }
};