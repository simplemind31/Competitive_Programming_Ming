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
int t=1;
ll a,n,imp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a;
        if(a==0){
            cout << "0\n";
            continue;
        }
        n=imp=0;
        vector<int> con(10);
        while(a){
            con[a%10]++;
            a/=10;
            n++;
        }
        for(int i=0;i<10;i++)if(con[i]&1)imp++;
        if(imp>1){
            cout << "-1\n";
            continue;
        }
        string res(n,' ');
        int pos=0;
        for(int i=1;i<10;i++){
            if(con[i]>1){
                res[pos]=res[n-pos-1]=char(i+'0');
                con[i]-=2;
                pos++;
                break;
            }
        }
        for(int i=0;i<10;i++){
            while(con[i]>1){
                res[pos]=res[n-pos-1]=char(i+'0');
                con[i]-=2;
                pos++;
            }
        }
        for(int i=0;i<10;i++){
            if(con[i]==1){
                res[pos]=res[n-pos-1]=char(i+'0');
            }
        }
        if(res[0]=='0')cout << "-1\n";
        else cout << res << '\n';
    }
}