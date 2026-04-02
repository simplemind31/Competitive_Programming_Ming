#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,vector<int>& healths,string directions){
        int n=positions.size();
        vector<pair<pair<int,int>,pair<int,bool>>> robot(n);
        // posicion, id, health, direccion
        // true Left
        vector<int> vida(n);
        for(int i=0;i<n;i++){
            robot[i]={{positions[i],i},{healths[i],directions[i]=='L'}};
        }
        sort(robot.begin(),robot.end());
        stack<pair<int,int>> irderecha;
        // id health
        for(int i=0;i<n;i++){
            if(robot[i].second.second){
                // pelear con stack
                while(!irderecha.empty() && robot[i].second.first){
                    if(robot[i].second.first>irderecha.top().second){
                        irderecha.pop();
                        robot[i].second.first--;
                    }else if(robot[i].second.first<irderecha.top().second){
                        robot[i].second.first=0;
                        irderecha.top().second--;
                    }else{
                        robot[i].second.first=0;
                        irderecha.pop();
                    }
                }
                vida[robot[i].first.second]=robot[i].second.first;
            }else{
                irderecha.push({robot[i].first.second,robot[i].second.first});
            }
        }
        while(!irderecha.empty()){
            vida[irderecha.top().first]=irderecha.top().second;
            irderecha.pop();
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(vida[i])res.push_back(vida[i]);
        }
        return res;
    }
};