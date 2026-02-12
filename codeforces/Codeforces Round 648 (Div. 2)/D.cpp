#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
int t,n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<char>> mat(n+2,vector<char>(m+2,'#'));
        vector<vector<bool>> visited(n+2,vector<bool>(m+2));
        int tot=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> mat[i][j];
                tot+=(mat[i][j]=='G');
            }
        }
        bool xd=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mat[i][j]!='B')continue;
                if(mat[i-1][j]=='.')mat[i-1][j]='#';
                if(mat[i-1][j]=='G')xd=false;
                if(mat[i+1][j]=='.')mat[i+1][j]='#';
                if(mat[i+1][j]=='G')xd=false;
                if(mat[i][j-1]=='.')mat[i][j-1]='#';
                if(mat[i][j-1]=='G')xd=false;
                if(mat[i][j+1]=='.')mat[i][j+1]='#';
                if(mat[i][j+1]=='G')xd=false;
            }
        }
        queue<pair<int,int>> bfs;
        bfs.push({n,m});
        while(!bfs.empty()){
            pair<int,int> top=bfs.front();
            bfs.pop();
            if(mat[top.first][top.second]=='#' || visited[top.first][top.second])continue;
            visited[top.first][top.second]=true;
            if(mat[top.first][top.second]=='G')tot--;
            bfs.push({top.first-1,top.second});
            bfs.push({top.first+1,top.second});
            bfs.push({top.first,top.second-1});
            bfs.push({top.first,top.second+1});
        }
        if(tot==0 && xd)cout << "Yes\n";
        else cout << "No\n";
    }
}