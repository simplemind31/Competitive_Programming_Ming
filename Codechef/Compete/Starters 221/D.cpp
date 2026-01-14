#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
int t,n;
string A,B,C;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> A >> B >> C;
        vector<vi> con(2,vi(2));
        for(int i=0;i<n;i++){
            if(B[i]==C[i])continue;
            con[A[i]-'0'][B[i]-'0']++;
        }
        int res=max(con[0][1]-min(con[0][0],con[0][1]),con[1][0]-min(con[1][0],con[1][1]))+max(con[0][0]-min(con[0][0],con[0][1]),con[1][1]-min(con[1][0],con[1][1]));
        cout << res << '\n';
    }
}