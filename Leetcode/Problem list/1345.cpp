#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minJumps(vector<int>& arr){
        int n=arr.size();
        unordered_map<int,vector<int>> con;
        for(int i=0;i<n;i++)con[arr[i]].push_back(i);
        vector<int> dist(n,1e9);
        dist[0]=0;
        queue<int> bfs;
        bfs.push(0);
        while(!bfs.empty()){
            int top=bfs.front();
            bfs.pop();
            if(top-1>=0 && dist[top-1]==1e9){
                dist[top-1]=dist[top]+1;
                bfs.push(top-1);
            }
            if(top+1<n && dist[top+1]==1e9){
                dist[top+1]=dist[top]+1;
                bfs.push(top+1);
            }
            for(auto u:con[arr[top]]){
                if(dist[u]==1e9){
                    bfs.push(u);
                    dist[u]=dist[top]+1;
                }
            }
            con.erase(arr[top]);
        }
        return dist[n-1];
    }
};