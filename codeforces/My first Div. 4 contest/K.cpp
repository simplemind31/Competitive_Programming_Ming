#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t=1,n;
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<bool>> mat(n+2,vector<bool>(n+2)),cop;
        vector<vector<int>> cantlibre(n+2,vector<int>(n+2));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> c;
                mat[i][j]=(c=='.');
            }
        }
        set<pair<int,int>> libre[5];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(!mat[i][j])continue;
                int con=mat[i-1][j]+mat[i+1][j]+mat[i][j-1]+mat[i][j+1];
                libre[con].insert({i,j});
                cantlibre[i][j]=con;
            }
        }
        while(!libre[1].empty()){
            pair<int,int> top=*libre[1].begin();
            libre[1].erase(libre[1].begin());
            mat[top.first][top.second]=cantlibre[top.first][top.second]=0;
            if(mat[top.first-1][top.second]){
                libre[cantlibre[top.first-1][top.second]].erase({top.first-1,top.second});
                mat[top.first-1][top.second]=cantlibre[top.first-1][top.second]=0;
                if(mat[top.first-2][top.second]){
                    libre[cantlibre[top.first-2][top.second]].erase({top.first-2,top.second});
                    cantlibre[top.first-2][top.second]--;
                    libre[cantlibre[top.first-2][top.second]].insert({top.first-2,top.second});
                }
                if(mat[top.first-1][top.second-1]){
                    libre[cantlibre[top.first-1][top.second-1]].erase({top.first-1,top.second-1});
                    cantlibre[top.first-1][top.second-1]--;
                    libre[cantlibre[top.first-1][top.second-1]].insert({top.first-1,top.second-1});
                }
                if(mat[top.first-1][top.second+1]){
                    libre[cantlibre[top.first-1][top.second+1]].erase({top.first-1,top.second+1});
                    cantlibre[top.first-1][top.second+1]--;
                    libre[cantlibre[top.first-1][top.second+1]].insert({top.first-1,top.second+1});
                }
            }else if(mat[top.first+1][top.second]){
                libre[cantlibre[top.first+1][top.second]].erase({top.first+1,top.second});
                mat[top.first+1][top.second]=cantlibre[top.first+1][top.second]=0;
                if(mat[top.first+2][top.second]){
                    libre[cantlibre[top.first+2][top.second]].erase({top.first+2,top.second});
                    cantlibre[top.first+2][top.second]--;
                    libre[cantlibre[top.first+2][top.second]].insert({top.first+2,top.second});
                }
                if(mat[top.first+1][top.second-1]){
                    libre[cantlibre[top.first+1][top.second-1]].erase({top.first+1,top.second-1});
                    cantlibre[top.first+1][top.second-1]--;
                    libre[cantlibre[top.first+1][top.second-1]].insert({top.first+1,top.second-1});
                }
                if(mat[top.first+1][top.second+1]){
                    libre[cantlibre[top.first+1][top.second+1]].erase({top.first+1,top.second+1});
                    cantlibre[top.first+1][top.second+1]--;
                    libre[cantlibre[top.first+1][top.second+1]].insert({top.first+1,top.second+1});
                }
            }else if(mat[top.first][top.second-1]){
                libre[cantlibre[top.first][top.second-1]].erase({top.first,top.second-1});
                mat[top.first][top.second-1]=cantlibre[top.first][top.second-1]=0;
                if(mat[top.first][top.second-2]){
                    libre[cantlibre[top.first][top.second-2]].erase({top.first,top.second-2});
                    cantlibre[top.first][top.second-2]--;
                    libre[cantlibre[top.first][top.second-2]].insert({top.first,top.second-2});
                }
                if(mat[top.first+1][top.second-1]){
                    libre[cantlibre[top.first+1][top.second-1]].erase({top.first+1,top.second-1});
                    cantlibre[top.first+1][top.second-1]--;
                    libre[cantlibre[top.first+1][top.second-1]].insert({top.first+1,top.second-1});
                }
                if(mat[top.first-1][top.second-1]){
                    libre[cantlibre[top.first-1][top.second-1]].erase({top.first-1,top.second-1});
                    cantlibre[top.first-1][top.second-1]--;
                    libre[cantlibre[top.first-1][top.second-1]].insert({top.first-1,top.second-1});
                }
            }else{
                libre[cantlibre[top.first][top.second+1]].erase({top.first,top.second+1});
                mat[top.first][top.second+1]=cantlibre[top.first][top.second+1]=0;
                if(mat[top.first][top.second+2]){
                    libre[cantlibre[top.first][top.second+2]].erase({top.first,top.second+2});
                    cantlibre[top.first][top.second+2]--;
                    libre[cantlibre[top.first][top.second+2]].insert({top.first,top.second+2});
                }
                if(mat[top.first+1][top.second+1]){
                    libre[cantlibre[top.first+1][top.second+1]].erase({top.first+1,top.second+1});
                    cantlibre[top.first+1][top.second+1]--;
                    libre[cantlibre[top.first+1][top.second+1]].insert({top.first+1,top.second+1});
                }
                if(mat[top.first-1][top.second+1]){
                    libre[cantlibre[top.first-1][top.second+1]].erase({top.first-1,top.second+1});
                    cantlibre[top.first-1][top.second+1]--;
                    libre[cantlibre[top.first-1][top.second+1]].insert({top.first-1,top.second+1});
                }
            }
        }
        /*if(!libre[0].empty()){
            cout << "NO\n";
            continue;
        }*/
        cop=mat;
        bool xd=true;
        for(int i=1;i<=n && xd;i++){
            for(int j=1;j<=n && xd;j++){
                if(!mat[i][j])continue;
                int consec[2]={0,0};
                queue<pair<int,int>> bfs;
                bfs.push({i,j});
                while(!bfs.empty()){
                    pair<int,int> top=bfs.front();
                    bfs.pop();
                    if(!mat[top.first][top.second])continue;
                    mat[top.first][top.second]=false;
                    consec[(top.first+top.second)%2]++;
                    bfs.push({top.first-1,top.second});
                    bfs.push({top.first+1,top.second});
                    bfs.push({top.first,top.second-1});
                    bfs.push({top.first,top.second+1});
                }
                if(consec[0]!=consec[1])xd=false;
            }
        }
        if(!xd){
            cout << "NO\n";
            continue;
        }
        mat=cop;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                //junto esto con algun vecino;
            }
        }
        cout << "YES\n";
    }
}