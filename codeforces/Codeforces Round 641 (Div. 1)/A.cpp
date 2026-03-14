#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
const int MAXN=200000;
int n,contad[MAXN+1],a;
pair<int,int> res[MAXN+1];
bitset<MAXN+1> criba;
vector<int> primos;
// segundo menor, menor
ll mcd=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    criba[0]=criba[1]=true;
    res[0]=res[1]={1e9,1e9};
    for(int i=2;i<=MAXN;i++){
        res[i]={1e9,1e9};
        if(!criba[i])primos.push_back(i);
        for(int j=0;j<primos.size() && i*primos[j]<=MAXN;j++){
            criba[i*primos[j]]=true;
            if(i%primos[j]==0)break;
        }
    }
    // para cada primo saco el exponente del segundo menor
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        for(auto u:primos){
            if(u*u>a)break;
            int con=0;
            while(a%u==0){
                a/=u;
                con++;
            }
            if(con){
                contad[u]++;
                if(con<res[u].second){
                    res[u].first=res[u].second;
                    res[u].second=con;
                }else if(con<res[u].first){
                    res[u].first=con;
                }
            }
        }
        if(a>1){
            contad[a]++;
            if(1<res[a].second){
                res[a].first=res[a].second;
                res[a].second=1;
            }else if(1<res[a].first){
                res[a].first=1;
            }
        }
        //cout << res[2].first << ' ' << res[2].second << '\n';
    }
    for(auto u:primos){
        if(contad[u]<=n-2)continue;
        if(contad[u]==n-1){
            for(int i=0;i<res[u].second;i++){
                mcd*=u;
            }
        }else{
            for(int i=0;i<res[u].first;i++){
                mcd*=u;
            }
        }
    }
    cout << mcd;
}