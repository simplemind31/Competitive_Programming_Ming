#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t=1,con[3][3],mini=1e9;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    cin >> st;
    if(t%3){
        cout << -1;
        return 0;
    }
    for(int i=0;i<t;i++){
        if(st[i]=='R')con[i%3][0]++;
        else if(st[i]=='G')con[i%3][1]++;
        else con[i%3][2]++;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(i==j || i==k || j==k)continue;
                mini=min(mini,t-con[i][0]-con[j][1]-con[k][2]);
            }
        }
    }
    cout << mini;
}