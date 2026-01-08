#include <bits/stdc++.h>
using namespace std;
int n;
bool cmp(pair<int,pair<string,string>> x, pair<int,pair<string,string>> y){
    if(x.first==y.first){
        return x.second.first>y.second.first;
    }
    return x.first<y.first;
}
class Solution {
public:
    vector<int> countMentions(int numberOfUsers,vector<vector<string>>& events){
        vector<pair<int,pair<string,string>>> ordenado(n=events.size());
        for(int i=0;i<n;i++){
            ordenado[i]={stoi(events[i][1]),{events[i][0],events[i][2]}};
        }
        sort(ordenado.begin(),ordenado.end(),cmp);
        vector<int> cont(numberOfUsers),res(numberOfUsers);
        int last=0;
        for(int i=0;i<n;i++){
            int now=ordenado[i].first;
            for(int j=0;j<numberOfUsers;j++){
                cont[j]=max(cont[j]-(now-last),0);
            }
            last=now;
            if(ordenado[i].second.first=="OFFLINE")cont[stoi(ordenado[i].second.second)]=60;
            else{
                if(ordenado[i].second.second=="ALL"){
                    for(int j=0;j<numberOfUsers;j++){
                        res[j]++;
                    }
                }else if(ordenado[i].second.second=="HERE"){
                    for(int j=0;j<numberOfUsers;j++){
                        if(!cont[j])res[j]++;
                    }
                }else{
                    stringstream help(ordenado[i].second.second);
                    char c;
                    int num;
                    while(help>>c){
                        help>>c;
                        help >> num;
                        res[num]++;
                    }
                }
            }
        }
        return res;
    }
};