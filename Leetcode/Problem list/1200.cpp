#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr){
        int mini=1e7,n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        for(int i=1;i<n;i++)mini=min(mini,arr[i]-arr[i-1]);
        for(int i=1;i<n;i++)if(mini==arr[i]-arr[i-1])res.push_back({arr[i-1],arr[i]});
        return res;
    }
};