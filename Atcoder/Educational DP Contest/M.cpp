#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,k,x,sobra[100001],psum[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    sobra[0]=1;
    psum[0]=sobra[0];
    for(int j=1;j<=100000;j++){
        psum[j]=(sobra[j]+psum[j-1])%MOD;
    }
    for(int i=0;i<n;i++){
        cin >> x;
        for(int j=100000;j>=0;j--){
            // doy 0 -> j=j-x+0;
            // doy 1 -> j=j-x+1;

            // doy x -> j=j-x+x
            //sobra[j]+=sobra[j-x]+...+sobra[j];
            int suma=0;
            sobra[j]=(psum[j]-((j-x<=0)?0:psum[j-x-1])+MOD)%MOD;
            /*for(int l=max(j-x,0);l<=j;l++){
                suma+=sobra[l];
            }
            sobra[j]=suma;*/
        }
        psum[0]=sobra[0];
        for(int j=1;j<=100000;j++){
            psum[j]=(sobra[j]+psum[j-1])%MOD;
        }
    }
    cout << sobra[k];
}