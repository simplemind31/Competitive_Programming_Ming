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
int t=1,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> res(n);
        res[0]=1;
        if(n%2==0){
            res[n-1]=n;
            for(int i=1;i<n-1;i++){
                if(i%2){
                    res[i]=i+2;
                }else{
                    res[i]=i;
                }
            }
        }else{
            for(int i=1;i<n;i++){
                if(i%2){
                    res[i]=i+2;
                }else{
                    res[i]=i;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
}