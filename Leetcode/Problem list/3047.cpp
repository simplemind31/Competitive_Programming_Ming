#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
class Solution {
public:
    int n,maxi;
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight){
        vector<pair<pii,pii>> rec(n=bottomLeft.size());
        for(int i=maxi=0;i<n;i++)rec[i]={{bottomLeft[i][0],bottomLeft[i][1]},{topRight[i][0],topRight[i][1]}};
        sort(rec.begin(),rec.end());
        for(int i=0;i<n;i++)for(int j=i+1;j<n && rec[j].first.first<rec[i].second.first;j++)maxi=max(maxi,min(min(rec[i].second.first,rec[j].second.first)-max(rec[i].first.first,rec[j].first.first),min(rec[i].second.second,rec[j].second.second)-max(rec[i].first.second,rec[j].first.second)));
        return 1LL*maxi*maxi;
    }
};