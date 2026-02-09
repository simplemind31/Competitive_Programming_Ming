#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital){
        int n,res=0;
        vector<pair<int,int>> nums(n=profits.size());
        for(int i=0;i<n;i++)nums[i]={capital[i],profits[i]};
        priority_queue<int> posi;
        sort(nums.begin(),nums.end());
        int i=0;
        posi.push(w);
        k++;
        while(!posi.empty() && k--){
            res+=posi.top();
            posi.pop();
            while(i<n && nums[i].first<=res)posi.push(nums[i++].second);
        }
        return res;
    }
};