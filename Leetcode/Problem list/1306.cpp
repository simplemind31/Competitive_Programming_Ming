#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start){
        int n=arr.size();
        queue<int> bfs;
        bfs.push(start);
        while(!bfs.empty()){
            int top=bfs.front();
            bfs.pop();
            if(arr[top]==0)return true;
            if(top-arr[top]>=0)bfs.push(top-arr[top]);
            if(top+arr[top]<n)bfs.push(top+arr[top]);
            arr[top]=1e9;
        }
        return false;
    }
};