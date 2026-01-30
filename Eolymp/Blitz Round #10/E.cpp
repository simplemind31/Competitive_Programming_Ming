#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
bool xd;
int n,k,t,nextpar,nextimpar,cantiimp,cantipar,cantirep;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        cantiimp=(n+1)/2;
        cantipar=n-cantiimp;
        nextpar=xd=0;
        nextimpar=-1;
        cantirep=n/k;
        for(int a=1;a<=cantiimp && !xd;a+=2){
            //uso a impares y k-a pares en cada rep
            int sobraimp=cantiimp-cantirep*a;
            int sobrapar=cantipar-cantirep*(k-a);
            if(sobraimp+sobrapar==(n%k) && sobraimp<=a && sobrapar<=k-a && cantirep*a<=cantiimp && cantirep*(k-a)<=cantipar && sobraimp>=0 && sobrapar>=0){
                //entra
                //primero sobraimp impares en cada rep y cobrapar pares en cada rep y completar el resto
                int primeimp=sobraimp,primepar=sobrapar,compleimp=a-sobraimp,complepar=k-a-sobrapar;
                for(int i=0;i<cantirep;i++){
                    for(int j=0;j<primeimp;j++)cout << (nextimpar+=2) << ' ';
                    for(int j=0;j<primepar;j++)cout << (nextpar+=2) << ' ';
                    for(int j=0;j<compleimp;j++)cout << (nextimpar+=2) << ' ';
                    for(int j=0;j<complepar;j++)cout << (nextpar+=2) << ' ';
                }
                for(int j=0;j<primeimp;j++)cout << (nextimpar+=2) << ' ';
                for(int j=0;j<primepar;j++)cout << (nextpar+=2) << ' ';
                xd=true;
            }
        }
        if(!xd)cout << "-1";
        cout << '\n';
    }
}