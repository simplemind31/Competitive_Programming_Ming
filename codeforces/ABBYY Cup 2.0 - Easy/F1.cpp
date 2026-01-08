#include <bits/stdc++.h>
using namespace std;
int n,k,t,a,b,c,con=1;
int conec[20][20];
map<vector<pair<int,int>>,bool> visited;
map<vector<pair<int,int>>,int> dist;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> t;
    for(int i=0;i<k;i++){
        cin >> a >> b >> c;
        conec[--a][--b]=c;
    }
    set<pair<int,vector<pair<int,int>>>> dij;
    vector<pair<int,int>> vacio;
    dij.insert(make_pair(0,vacio));
    // dist, use bit de hombre, bit de mujer;
    while(!dij.empty()){
        pair<int,vector<pair<int,int>>> top=*dij.begin();
        //while(dij.size()>t)dij.erase(--dij.end());
        dij.erase(dij.begin());
        visited[top.second]=true;
        if(con++==t){
            cout << top.first;
            return 0;
        }
        int used1=0,used2=0;
        for(auto u:top.second){
            used1+=1<<u.first;
            used2+=1<<u.second;
        }
        for(int i=0;i<n;i++){
            if(used1&(1<<i))continue;
            for(int j=0;j<n;j++){
                if(used2&(1<<j))continue;
                if(conec[i][j]==0)continue;
                vector<pair<int,int>> nue=top.second;
                nue.push_back({i,j});
                sort(nue.begin(),nue.end());
                //{dist[nexti][nextj],nexti,nextj}
                if(!visited[nue]){
                    if(dij.find({dist[nue],nue})!=dij.end()){
                        if(top.first+conec[i][j]<dist[nue]){
                            dij.erase({dist[nue],nue});
                            dist[nue]=top.first+conec[i][j];
                            dij.insert({dist[nue],nue});
                        }
                    }else{
                        dij.insert({top.first+conec[i][j],nue});
                        dist[nue]=top.first+conec[i][j];
                    }
                }
            }
        }
    }
}