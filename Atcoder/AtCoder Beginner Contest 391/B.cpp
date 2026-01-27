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
int n,m;
string a[50],b[50];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<m;i++)cin >> b[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bool xd=true;
            for(int k=0;k<m && xd;k++){
                for(int l=0;l<m && xd;l++){
                    if(a[i+k][j+l]!=b[k][l])xd=false;
                }
            }
            if(xd){
                cout << i+1 << ' ' << j+1;
                return 0;
            }
        }
    }
}