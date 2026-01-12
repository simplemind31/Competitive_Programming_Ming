#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix){
        int res=0,n=matrix.size(),m=matrix.back().size();
        vector<vector<int>> dp(n,vector<int>(m));
        vector<vector<pair<int,int>>> headtailho(n,vector<pair<int,int>>(m)),headtailver=headtailho;
        for(int i=0;i<n;i++)dp[i][0]=matrix[i][0]-'0';
        for(int j=0;j<m;j++)dp[0][j]=matrix[0][j]-'0';
        for(int i=1;i<n;i++)for(int j=1;j<m;j++)dp[i][j]=(matrix[i][j]=='1')?(min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1):0;
        vector<pair<int,int>> nums[201];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                headtailho[i][j]={j,j};
                headtailver[i][j]={i,i};
                nums[dp[i][j]].push_back({i,j});
            }
        }
        for(int i=200;i>0;i--){
            for(int j=0;j<nums[i].size();j++){
                pair<int,int> pos=nums[i][j];
                if(pos.second+1<m){
                    if(dp[pos.first][pos.second+1]>dp[pos.first][pos.second]){
                        pair<int,int> de={pos.first,headtailho[pos.first][pos.second+1].second};
                        headtailho[pos.first][pos.second].second=de.second;
                        headtailho[de.first][de.second].first=pos.second;
                    }
                }
                if(pos.second-1>=0){
                    if(dp[pos.first][pos.second-1]>=dp[pos.first][pos.second]){
                        pair<int,int> de={pos.first,headtailho[pos.first][pos.second].second};
                        pos.second=headtailho[pos.first][pos.second-1].first;
                        headtailho[pos.first][pos.second].second=de.second;
                        headtailho[de.first][de.second].first=pos.second;
                    }
                }
                res=max(res,i*i+i*(headtailho[pos.first][pos.second].second-pos.second));
                pos=nums[i][j];
                if(pos.first+1<n){
                    if(dp[pos.first+1][pos.second]>dp[pos.first][pos.second]){
                        pair<int,int> de={headtailver[pos.first+1][pos.second].second,pos.second};
                        headtailver[pos.first][pos.second].second=de.first;
                        headtailver[de.first][de.second].first=pos.first;
                    }
                }
                if(pos.first-1>=0){
                    if(dp[pos.first-1][pos.second]>=dp[pos.first][pos.second]){
                        pair<int,int> de={headtailver[pos.first][pos.second].second,pos.second};
                        pos.first=headtailver[pos.first-1][pos.second].first;
                        headtailver[pos.first][pos.second].second=de.first;
                        headtailver[de.first][de.second].first=pos.first;
                    }
                }
                res=max(res,i*i+i*(headtailver[pos.first][pos.second].second-pos.first));
            }
        }
        return res;
    }
};