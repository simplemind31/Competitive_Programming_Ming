#include <bits/stdc++.h>
using namespace std;
int n,m,r,c,x,y;
bool visited[2000][2000];
pair<int,int> mat[2000][2000];
char carac;
bool operator <(pair<int,int> a,pair<int,int> b){
    return (a.first<b.first && a.second<=b.second) || (a.first<=b.first && a.second<b.second);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> r >> c >> x >> y;
    fill(&mat[0][0],&mat[0][0]+2000*2000,make_pair(-1,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> carac;
            if(carac=='.')mat[i][j]={-1,-1};
            else mat[i][j]={-2,-2};
        }
    }
    r--;c--;
    mat[r][c]={x,y};
    deque<pair<int,int>> cola;
    cola.push_front({r,c});
    visited[r][c]=1;
    int res=0;
    while(!cola.empty()){
        pair<int,int> now=cola.front();
        cola.pop_front();
        res++;
        if(now.first-1>=0 && !visited[now.first-1][now.second] && mat[now.first-1][now.second]!=make_pair(-2,-2)){
            visited[now.first-1][now.second]=1;
            mat[now.first-1][now.second]=mat[now.first][now.second];
            cola.push_front({now.first-1,now.second});
        }
        if(now.first+1<n && !visited[now.first+1][now.second] && mat[now.first+1][now.second]!=make_pair(-2,-2)){
            visited[now.first+1][now.second]=1;
            mat[now.first+1][now.second]=mat[now.first][now.second];
            cola.push_front({now.first+1,now.second});
        }
        if(now.second-1>=0 && !visited[now.first][now.second-1] && mat[now.first][now.second].first && mat[now.first][now.second-1]!=make_pair(-2,-2)){
            visited[now.first][now.second-1]=1;
            mat[now.first][now.second-1]=mat[now.first][now.second];
            mat[now.first][now.second-1].first--;
            cola.push_back({now.first,now.second-1});
        }
        if(now.second+1<m && !visited[now.first][now.second+1] && mat[now.first][now.second].second && mat[now.first][now.second+1]!=make_pair(-2,-2)){
            visited[now.first][now.second+1]=1;
            mat[now.first][now.second+1]=mat[now.first][now.second];
            mat[now.first][now.second+1].second--;
            cola.push_back({now.first,now.second+1});
        }
    }
    cout << res;
}