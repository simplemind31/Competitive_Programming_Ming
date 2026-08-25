#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1000000;
const int raiz=1000;
int n;
bitset<raiz+1> criba;
vector<int> primes;
int con[MAXN+1];
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    criba[0]=criba[1]=1;
    for(int i=2;i<=raiz;i++){
        if(!criba[i])primes.push_back(i);
        for(int j=0;j<primes.size() && i*primes[j]<=raiz;j++){
            criba[i*primes[j]]=1;
            if(i%primes[j]==0)break;
        }
    }
    cin >> n;
    int nums[n];
    vector<int> descomp[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
        for(int j=0;j<primes.size() && primes[j]*primes[j]<=nums[i];j++){
            if(nums[i]%primes[j]==0){
                while(nums[i]%primes[j]==0)nums[i]/=primes[j];
                descomp[i].push_back(primes[j]);
            }
        }
        if(nums[i]>1)descomp[i].push_back(nums[i]);
    }
    for(int i=0;i<n;i++){
        int tam=descomp[i].size(),nocoprime=0;
        // cuantos no son coprimos?
        for(int j=1;j<(1<<tam);j++){
            int now=1,count=0;
            for(int k=0;k<tam;k++){
                if(j&(1<<k)){
                    now*=descomp[i][k];
                    count++;
                }
            }
            if(count&1)nocoprime+=con[now];
            else nocoprime-=con[now];
            con[now]++;
        }
        res+=i-nocoprime;
    }
    cout << res;
}