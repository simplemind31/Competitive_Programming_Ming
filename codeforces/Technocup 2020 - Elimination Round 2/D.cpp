#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100000;
int n,k,a;
ll res=0;
vector<pair<int,int>> criba[MAXN+1];
bitset<MAXN+1> compues;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=2;i<=MAXN;i++){
        if(compues[i])continue;
        for(int j=i;j<=MAXN;j+=i){
            compues[j]=true;
            int con=0,temp=j;
            while(temp%i==0){
                temp/=i;
                con++;
            }
            con%=k;
            if(con)criba[j].push_back({i,con});
        }
    }
    map<vector<pair<int,int>>,int> con;
    for(int i=0;i<n;i++){
        cin >> a;
        vector<pair<int,int>> comple=criba[a];
        for(int j=0;j<comple.size();j++){
            comple[j].second=(k-comple[j].second)%k;
        }
        res+=con[comple];
        con[criba[a]]++;
    }
    cout << res;
}