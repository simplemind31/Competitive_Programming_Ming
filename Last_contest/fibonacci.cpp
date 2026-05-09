//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <array>
#include <queue>
#include <stack>
#include <map>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,a;
// podemos siempre mantener que distan al menos 2?
map<ll,ll> conta;
void anadir(int x){
    if(x==0){
        anadir(1);
    }else if(x==1 && conta[x]){
        conta[1]--;
        anadir(2);
    }else if(conta[x+1]){
        conta[x+1]--;
        anadir(x+2);
    }else if(conta[x-1]){
        conta[x-1]--;
        anadir(x+1);
    }else if(conta[x]){
        conta[x]--;
        anadir(x+1);
        anadir(x-2);
    }else{
        conta[x]++;
    }
    if(conta[x+1]==0)conta.erase(x+1);
    if(conta[x]==0)conta.erase(x);
    if(conta[x-1]==0)conta.erase(x-1);
    if(conta[x-2]==0)conta.erase(x-2);
}
int main(){
	cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        anadir(a);
        // expando siempre la misma paridad
        /*for(auto u:conta){
            while(u.second--)cout << u.first << ' ';
        }
        cout << '\n';*/
        // todos tienen distancia minimo 2
        vector<ll> nums;
        for(auto u:conta){
            while(u.second--)nums.push_back(u.first);
        }
        vector<pair<ll,ll>> res(nums.size(),{1,1});
        // 0-> no cambia
        // 1 -> cambia
        res[0].first=1;
        res[0].second=((nums[0]-1)/2)%MOD;
        //cout << res << ' ';
        // si uno se hace pequeño en mayor tambien vapoder
        // cambia o no cambia
        for(int j=1;j<nums.size();j++){
            // entre nums[i-1]+1 y nums[i]
            //cout << ((nums[i]-(nums[i-1]+1))/2+1) << ' ';
            res[j].first=res[j-1].first+res[j-1].second;
            res[j].second=res[j-1].first*((nums[j]-(nums[j-1]+1))/2)+res[j-1].second*((nums[j]-(nums[j-1]))/2);
            res[j].first%=MOD;
            res[j].second%=MOD;
        }
        cout << (res[nums.size()-1].first+res[nums.size()-1].second)%MOD << '\n';
    }
}
/*
#1
4
4 1 1 5
2
2
1
2

#2
11
6 7 9 10 3 4 7 11 3 21 15 
3
4
5
8
12
12
13
15
12
60
84



3
4
5
8
12
12
6
6
4
20
24
*/