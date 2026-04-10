#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    char mat[n][m];
    int dist[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            dist[i][j]=1e9;
        }
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> dij;
    dist[n-1][m-1]=0;
    dij.push({0,{n-1,m-1}});
    while(!dij.empty()){
        int va=dij.top().first;
        pair<int,int> top=dij.top().second;
        dij.pop();
        if(dist[top.first][top.second]>va)continue;
        if(top.first+1<n && mat[top.first+1][top.second]!='X'){
            va=0;
            switch(mat[top.first+1][top.second]){
                case 'E':
                    va++;
                case 'S':
                    va++;
                case 'W':
                    va++;
            }
            if(dist[top.first+1][top.second]>dist[top.first][top.second]+va){
                dist[top.first+1][top.second]=dist[top.first][top.second]+va;
                dij.push({dist[top.first+1][top.second],{top.first+1,top.second}});
            }
        }
        if(top.second+1<m && mat[top.first][top.second+1]!='X'){
            va=0;
            switch(mat[top.first][top.second+1]){
                case 'N':
                    va++;
                case 'E':
                    va++;
                case 'S':
                    va++;
            }
            if(dist[top.first][top.second+1]>dist[top.first][top.second]+va){
                dist[top.first][top.second+1]=dist[top.first][top.second]+va;
                dij.push({dist[top.first][top.second+1],{top.first,top.second+1}});
            }
        }
        if(top.first-1>=0 && mat[top.first-1][top.second]!='X'){
            va=0;
            switch(mat[top.first-1][top.second]){
                case 'W':
                    va++;
                case 'N':
                    va++;
                case 'E':
                    va++;
            }
            if(dist[top.first-1][top.second]>dist[top.first][top.second]+va){
                dist[top.first-1][top.second]=dist[top.first][top.second]+va;
                dij.push({dist[top.first-1][top.second],{top.first-1,top.second}});
            }
        }
        if(top.second-1>=0 && mat[top.first][top.second-1]!='X'){
            va=0;
            switch(mat[top.first][top.second-1]){
                case 'S':
                    va++;
                case 'W':
                    va++;
                case 'N':
                    va++;
            }
            if(dist[top.first][top.second-1]>dist[top.first][top.second]+va){
                dist[top.first][top.second-1]=dist[top.first][top.second]+va;
                dij.push({dist[top.first][top.second-1],{top.first,top.second-1}});
            }
        }
    }
    if(dist[0][0]==1e9)dist[0][0]=-1;
    cout << dist[0][0];
}