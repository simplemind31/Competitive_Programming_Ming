#include <bits/stdc++.h>
using namespace std;
int n,m,usa,lui,luj,ini,inj;
char mat[1000][1000];
int pad[1000][1000];
bitset<1000> visited[1000];
bool xd;
string resppp="";
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    stack<pair<int,int>> monster[2],You[2];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            if(mat[i][j]=='M')monster[0].push({i,j});
            if(mat[i][j]=='#' || mat[i][j]=='M')visited[i][j]=true;
            if(mat[i][j]=='A')You[0].push({ini=i,inj=j});
        }
    }
    while((!You[0].empty() || !You[1].empty())&&!xd){
        usa=-1;
        if(!monster[0].empty())usa=0;
        else if(!monster[1].empty())usa=1;
        if(usa!=-1){
            while(!monster[usa].empty()){
                pair<int,int> top=monster[usa].top();
                monster[usa].pop();
                if(top.first+1<n){
                    if(!visited[top.first+1][top.second]){
                        visited[top.first+1][top.second]=true;
                        monster[1-usa].push({top.first+1,top.second});
                    }
                }
                if(top.first>0){
                    if(!visited[top.first-1][top.second]){
                        visited[top.first-1][top.second]=true;
                        monster[1-usa].push({top.first-1,top.second});
                    }
                }
                if(top.second+1<m){
                    if(!visited[top.first][top.second+1]){
                        visited[top.first][top.second+1]=true;
                        monster[1-usa].push({top.first,top.second+1});
                    }
                }
                if(top.second>0){
                    if(!visited[top.first][top.second-1]){
                        visited[top.first][top.second-1]=true;
                        monster[1-usa].push({top.first,top.second-1});
                    }
                }
            }
        }
        if(!You[0].empty())usa=0;
        else usa=1;
        while(!You[usa].empty()){
            pair<int,int> top=You[usa].top();
            You[usa].pop();
            visited[top.first][top.second]=true;
            if(top.first==0 || top.second==0 || top.first==n-1 || top.second==m-1){
                xd=true;
                lui=top.first;
                luj=top.second;
                break;
            }
            if(top.first+1<n){
                if(!visited[top.first+1][top.second]){
                    You[1-usa].push({top.first+1,top.second});
                    pad[top.first+1][top.second]=1;
                }
            }
            if(top.first>0){
                if(!visited[top.first-1][top.second]){
                    You[1-usa].push({top.first-1,top.second});
                    pad[top.first-1][top.second]=2;
                }
            }
            if(top.second+1<m){
                if(!visited[top.first][top.second+1]){
                    You[1-usa].push({top.first,top.second+1});
                    pad[top.first][top.second+1]=3;
                }
            }
            if(top.second>0){
                if(!visited[top.first][top.second-1]){
                    You[1-usa].push({top.first,top.second-1});
                    pad[top.first][top.second-1]=4;
                }
            }
        }
    }
    if(!xd){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    while(lui!=ini || luj!=inj){
        if(pad[lui][luj]==1){
            //ar
            resppp.push_back('D');
            lui--;
        }else if(pad[lui][luj]==2){
            resppp.push_back('U');
            lui++;
        }else if(pad[lui][luj]==3){
            resppp.push_back('R');
            luj--;
        }else{
            resppp.push_back('L');
            luj++;
        }
    }
    cout << resppp.size() << '\n';
    reverse(resppp.begin(),resppp.end());
    cout << resppp;
}