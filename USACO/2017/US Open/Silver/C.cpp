#include <bits/stdc++.h>
using namespace std;
int n,res;
bool cmp(pair<pair<int,int>,pair<int,int>> a,pair<pair<int,int>,pair<int,int>> b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}
template<typename A,typename B> ostream& operator <<(ostream& os,pair<A,B> par){
    cout << par.first << ' ' << par.second;
    return os;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("where.in","r",stdin);
    freopen("where.out","w",stdout);
    cin >> n;
    bool visited[n][n];
    char mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=false;
            cin >> mat[i][j];
        }
    }
    vector<pair<pair<int,int>,pair<int,int>>> posires;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=i;k<n;k++){
                for(int l=j;l<n;l++){
                    vector<int> con(26);
                    int canre1=0,canre2=0;
                    for(int ii=i;ii<=k;ii++){
                        for(int jj=j;jj<=l;jj++){
                            //cout << 2;
                            if(visited[ii][jj])continue;
                            visited[ii][jj]=true;
                            queue<pair<int,int>> bfs;
                            bfs.push({ii,jj});
                            con[mat[ii][jj]-'A']++;
                            while(!bfs.empty()){
                                //cout << 1;
                                pair<int,int> top=bfs.front();
                                bfs.pop();
                                if(!(top.first-1<i)){
                                    if(!visited[top.first-1][top.second] && mat[top.first-1][top.second]==mat[top.first][top.second]){
                                        visited[top.first-1][top.second]=true;
                                        bfs.push({top.first-1,top.second});
                                    }
                                }
                                if(!(top.first+1>k)){
                                    if(!visited[top.first+1][top.second] && mat[top.first+1][top.second]==mat[top.first][top.second]){
                                        visited[top.first+1][top.second]=true;
                                        bfs.push({top.first+1,top.second});
                                    }
                                }
                                if(!(top.second-1<j)){
                                    if(!visited[top.first][top.second-1] && mat[top.first][top.second-1]==mat[top.first][top.second]){
                                        visited[top.first][top.second-1]=true;
                                        bfs.push({top.first,top.second-1});
                                    }
                                }
                                if(!(top.second+1>l)){
                                    if(!visited[top.first][top.second+1] && mat[top.first][top.second+1]==mat[top.first][top.second]){
                                        visited[top.first][top.second+1]=true;
                                        bfs.push({top.first,top.second+1});
                                    }
                                }
                            }
                        }
                    }
                    for(int ii=i;ii<=k;ii++){
                        for(int jj=j;jj<=l;jj++){
                            visited[ii][jj]=false;
                        }
                    }
                    for(int ii=0;ii<26;ii++){
                        if(con[ii]==1)canre1++;
                        else if(con[ii])canre2++;
                    }
                    //if(i==0 && j==0 && k==3 && l==2)cout << canre1 << ' ' << canre2 << '\n';
                    if(canre1==1 && canre2==1){
                        posires.push_back({{i,j},{k,l}});
                        //cout << i << ' ' << j <<' ' << k << ' ' << l << '\n';
                    }
                }
            }
        }
    }
    if(posires.empty()){
        cout << 0;
        return 0;
    }
    sort(posires.begin(),posires.end(),cmp);
    vector<pair<pair<int,int>,pair<int,int>>> fina;
    fina.push_back(posires[0]);
    for(auto u:posires){
        if(fina.back().first.first<=u.first.first && fina.back().first.second<=u.first.second && fina.back().second.first>=u.second.first && fina.back().second.second>=u.second.second)continue;
        fina.push_back(u);
    }
    vector<bool> imposi(fina.size());
    for(int i=0;i<fina.size();i++){
        for(int j=0;j<fina.size();j++){
            if(i==j)continue;
            if(fina[i].first.first<=fina[j].first.first && fina[i].first.second<=fina[j].first.second && fina[i].second.first>=fina[j].second.first && fina[i].second.second>=fina[j].second.second)imposi[j]=true;
        }
    }
    for(int i=0;i<fina.size();i++){
        if(imposi[i])continue;
        res++;
    }
    cout << res;
    /*for(auto u:fina){
        cout << u << '\n';
    }*/
}