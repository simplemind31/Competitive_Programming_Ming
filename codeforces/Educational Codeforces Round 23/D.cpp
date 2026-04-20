#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int n;
ll res=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> nums(n+2);
    nums[0]=nums[n+1]=1e9;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        nums[i]--;
    }
    vector<int> iz(n+2),de(n+2);
    stack<pair<int,int>> ayuda;
    ayuda.push({1e9,0});
    // suponer que nums[i] es el maximo, entonces entontrar el elemento >nums[i] a la izquierda y el >= a la derecha
    for(int i=1;i<=n;i++){
        while(ayuda.top().first<nums[i])ayuda.pop();
        iz[i]=ayuda.top().second;
        ayuda.push({nums[i],i});
    }
    while(!ayuda.empty())ayuda.pop();
    ayuda.push({1e9,n+1});
    for(int i=n;i>=1;i--){
        while(ayuda.top().first<=nums[i])ayuda.pop();
        de[i]=ayuda.top().second;
        ayuda.push({nums[i],i});
    }
    for(int i=1;i<=n;i++)res+=1ll*nums[i]*(i-iz[i])*(de[i]-i);
    // suponer que es minimo
    while(!ayuda.empty())ayuda.pop();
    ayuda.push({-1e9,0});
    // suponer que nums[i] es el maximo, entonces entontrar el elemento >nums[i] a la izquierda y el >= a la derecha
    for(int i=1;i<=n;i++){
        while(ayuda.top().first>=nums[i])ayuda.pop();
        iz[i]=ayuda.top().second;
        ayuda.push({nums[i],i});
    }
    while(!ayuda.empty())ayuda.pop();
    ayuda.push({-1e9,n+1});
    for(int i=n;i>=1;i--){
        while(ayuda.top().first>nums[i])ayuda.pop();
        de[i]=ayuda.top().second;
        ayuda.push({nums[i],i});
    }
    for(int i=1;i<=n;i++)res-=1ll*nums[i]*(i-iz[i])*(de[i]-i);
    cout << res;
}