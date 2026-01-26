#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
bool mat[22][22];
char c;
int n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> c;
            mat[i][j]=c=='#';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!mat[i][j])continue;
            int can=mat[i-1][j]+mat[i+1][j]+mat[i][j-1]+mat[i][j+1];
            if(can!=2 && can!=4){
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
}