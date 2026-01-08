#include <bits/stdc++.h>
using namespace std;
bitset<100000> know,usado;
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson){
        know=usado=0;
        set<pair<int,int>> ord[100001][2];
        //1 si existe 0 no
        vector<pair<int,int>> unecon[n];
        for(int i=0;i<meetings.size();i++){
            if(meetings[i][0]>meetings[i][1])swap(meetings[i][0],meetings[i][1]);
            if(meetings[i][0]==0 && meetings[i][1]==firstPerson)continue;
            ord[meetings[i][2]][0].insert({meetings[i][0],meetings[i][1]});
            unecon[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
            unecon[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
        }
        ord[0][1].insert({0,firstPerson});
        unecon[0].push_back({firstPerson,0});
        for(int i=0;i<=1e5;i++){
            //primero ord[i][1]
            while(!ord[i][1].empty()){
                pair<int,int> u=*ord[i][1].begin();
                know[u.first]=know[u.second]=1;
                ord[i][1].erase(ord[i][1].begin());
                int temp=u.first;
                if(!usado[temp]){
                    usado[temp]=true;
                    //explorar todos que unen con u.first;
                    for(auto k:unecon[temp]){
                        if(k.second<i)continue;
                        if(ord[k.second][0].find(make_pair(min(temp,k.first),max(temp,k.first)))!=ord[k.second][0].end()){
                            ord[k.second][0].erase(make_pair(min(temp,k.first),max(temp,k.first)));
                            ord[k.second][1].insert(make_pair(min(temp,k.first),max(temp,k.first)));
                        }
                    }
                }
                temp=u.second;
                if(!usado[temp]){
                    usado[temp]=true;
                    //explorar todos que unen con u.first;
                    for(auto k:unecon[temp]){
                        if(k.second<i)continue;
                        if(ord[k.second][0].find(make_pair(min(temp,k.first),max(temp,k.first)))!=ord[k.second][0].end()){
                            ord[k.second][0].erase(make_pair(min(temp,k.first),max(temp,k.first)));
                            ord[k.second][1].insert(make_pair(min(temp,k.first),max(temp,k.first)));
                        }
                    }
                }
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(know[i])res.push_back(i);
        }
        return res;
    }
};