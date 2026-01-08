#include <bits/stdc++.h>
using namespace std;
int n,can;
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals){
        can=0;
        vector<bool> inutil(n=intervals.size());
        vector<pair<int,int>> nue;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(inutil[i])break;
                if(intervals[i][0]<=intervals[j][0] && intervals[j][1]<=intervals[i][1]){
                    inutil[i]=true;
                }else if(intervals[j][0]<=intervals[i][0] && intervals[i][1]<=intervals[j][1]){
                    inutil[j]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!inutil[i])nue.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(nue.begin(),nue.end());
        n=nue.size();
        vector<int> con(n);
        for(int i=0;i<n;i++){
            if(con[i]<2){
                //usar nue[i].second
                for(int j=i+1;j<n;j++){
                    if(nue[j].first>nue[i].second)break;
                    con[j]++;
                }
                can++;
            }
            if(con[i]<1){
                //usar nue[i].second-1;
                for(int j=i+1;j<n;j++){
                    if(nue[j].first>nue[i].second-1)break;
                    con[j]++;
                }
                can++;
            }
        }
        return can;
    }
};