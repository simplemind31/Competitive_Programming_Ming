#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,limite;
vector<int> elementos;
vector<vector<int>> memo;
bool solve(int pos,int sum){
    if(sum==0)return true;
    if(pos==0 && elementos[0]==sum)return true;
    if(sum<0)return false;
    if(pos<0)return false;
    if(memo[pos][sum]!=-1)return memo[pos][sum];
    bool res=false;
    bool op1=solve(pos-1,sum-elementos[pos]);
    bool op2=solve(pos-1,sum);
    if(op1==true || op2==true){
        res=true;
    }
    memo[pos][sum]=res;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    memo.assign(n,vector<int>(1e5+1,-1));
    vector<int> posibles;
    elementos.resize(n);
    for(int i=0;i<n;i++)cin >> elementos[i];
    for(int i=1;i<=1e5;i++){
        if(solve(n-1,i)){
            posibles.push_back(i);
        }
    }
    cout << posibles.size() << '\n';
    for(auto u:posibles)cout << u << ' ';
}
