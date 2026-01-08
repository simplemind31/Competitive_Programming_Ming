#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int con;
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        n=buildings.size();
        vector<pair<int,int>> ordrow(n),ordcol(n);
        for(int i=con=0;i<n;i++){
            ordrow[i]={buildings[i][0],buildings[i][1]};
            ordcol[i]={buildings[i][1],buildings[i][0]};
        }
        sort(ALL(ordrow));
        sort(ALL(ordcol));
        for(int i=0;i<n;i++){
            int p=lower_bound(ALL(ordrow),make_pair(buildings[i][0],buildings[i][1]))-ordrow.begin();
            if(p && p+1<n){
                if(ordrow[p-1].first==ordrow[p].first && ordrow[p].first==ordrow[p+1].first){
                    p=lower_bound(ALL(ordcol),make_pair(buildings[i][1],buildings[i][0]))-ordcol.begin();
                    if(p && p+1<n){
                        if(ordcol[p-1].first==ordcol[p].first && ordcol[p].first==ordcol[p+1].first)con++;
                    }
                }
            }
        }
        return con;
    }
};