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
int n,m,scor[100],maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    string st[n];
    for(int i=0;i<n;i++)cin >> st[i];
    for(int j=0;j<m;j++){
        int con=0;
        for(int i=0;i<n;i++){
            con+=st[i][j]-'0';
        }
        if(con<n-con){
            for(int i=0;i<n;i++){
                if(st[i][j]-'0')scor[i]++;
            }
        }else{
            for(int i=0;i<n;i++){
                if(!(st[i][j]-'0'))scor[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        maxi=max(maxi,scor[i]);
    }
    for(int i=0;i<n;i++){
        if(maxi==scor[i])cout << i+1 << ' ';
    }
}