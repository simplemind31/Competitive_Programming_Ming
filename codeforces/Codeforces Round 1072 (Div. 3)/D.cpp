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
int t=1,n,k,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    int choose[32][32];
    for(int i=0;i<32;i++){
        choose[i][0]=choose[i][i]=1;
        for(int j=1;j<i;j++){
            choose[i][j]=choose[i-1][j]+choose[i-1][j-1];
            choose[i][j]=min(choose[i][j],(int)1e9);
        }
    }
    while(t--){
        cin >> n >> k;
        con=0;
        for(int i=0;i<32;i++){
            if(n&(1<<i)){
                if(i+1>k)con++;
                break;
            }
            int sob=max(k-i-1,-1);
            //elsegir minimo sob+1 in i;
            for(int j=sob+1;j<=i;j++){
                // i choose j;
                con+=choose[i][j];
            }
        }
        cout << con << '\n';
    }
}