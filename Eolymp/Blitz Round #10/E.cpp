#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,k,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        int cantiimp=(n+1)/2,cantipar=n-cantiimp,sobra=n%k,canrep=n/k;
        bool xd=false;
        int lastpar=0,lastimp=-1;
        vector<int> per(n);
        for(int i=1;i<=k;i++){
            //si hay i par y k-i impar
            if((k-i)%2==0)continue;
            if(i*canrep<=cantipar && cantipar<=i*canrep+i){
                xd=true;
                int fir=cantipar-i*canrep;
                //cout << i << ' ' << fir << endl;
                for(int i=0;i<fir;i++)per[i]=(lastpar+=2);
                for(int j=k-1,con=0;con<i-fir;j--,con++){
                    per[j]=(lastpar+=2);
                }
                for(int i=fir;i<k;i++){
                    if(per[i]!=0)break;
                    per[i]=(lastimp+=2);
                }
                for(int i=k;i<n;i++){
                    if(per[i-k]%2==0)per[i]=(lastpar+=2);
                    else per[i]=(lastimp+=2);
                }
                break;
            }
        }
        if(xd){
            for(int i=0;i<n;i++){
                cout << per[i] << ' ';
            }
            cout << '\n';
        }else cout << "-1\n";
    }
}