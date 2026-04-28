#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,MOD;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("exercise.in","r",stdin);
    freopen("exercise.out","w",stdout);
    cin >> n >> MOD;
    // sumatoria de todo k tal que lcm(a1,a2,a3,...,ax)=k ademas n es una combinacion lineal de a1,a2,...,ax
    // -> cada potencia de k aparece en ai como multiplo
    // -> cada ai es mejor que sea potencia de k para la combinacion lineal
    // -> hay a lo mucho log(k) ai
    // para todo k<=n es posible
    // para un n,encontrar ais tal que n es combinacion lineal de ai, k=lcm(ai)
    // warning !! n no necesariamente debe ser combinacion lineal, porque si tengo ciclos de 1 entonces <=n
    // -> a1+a2+a3+...+ax<=n 
    vector<int> primes;
    vector<bool> criba(n+1);
    criba[0]=criba[1]=1;
    for(int i=2;i<=n;i++){
        if(!criba[i])primes.push_back(i);
        for(int j=0;j<primes.size() && i*primes[j]<=n;j++){
            criba[i*primes[j]]=1;
            if(i%primes[j]==0)break;
        }
    }
    ll dp[n+1];
    fill(dp,dp+(n+1),1);
    for(int i=0;i<primes.size();i++){
        for(int j=n;j>=0;j--){
            int temp=primes[i];
            while(j-temp>=0){
                dp[j]=(dp[j]+dp[j-temp]*temp)%MOD;
                temp=temp*primes[i];
            }
        }
    }
    cout << dp[n];
}