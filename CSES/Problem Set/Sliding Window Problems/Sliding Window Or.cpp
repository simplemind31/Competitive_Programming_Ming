#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int nums[10000000],n,k,a,b,c,res,con[31],suma[10000000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> nums[0] >> a >> b >> c;
    unordered_map<int,int> visited;
    suma[0]|=nums[0];
    visited[nums[0]]=0;
    for(int j=0;j<31;j++)if(nums[0]&(1<<j))con[j]++;
    for(int i=1;i<k;i++){
        nums[i]=(1ll*a*nums[i-1]+b)%c;
        visited[nums[i]]=i;
        suma[i]=suma[i-1];
        suma[i]|=nums[i];
        int temp=nums[i];
        while(temp){
            int nose=__builtin_ctz(temp);
            con[nose]++;
            temp-=1<<nose;
        }
    }
    res=suma[k-1];
    for(int i=k;i<n;i++){
        nums[i]=(1ll*a*nums[i-1]+b)%c;
        if(visited[nums[i]]-k+1>=0){
            suma[i]=suma[visited[nums[i]]];
            res^=suma[i];
        }
        visited[nums[i]]=i;
        suma[i]=suma[i-1];
        int temp=nums[i-k];
        while(temp){
            int nose=__builtin_ctz(temp);
            if(!--con[nose])suma[i]&=~(1<<nose);
            temp-=1<<nose;
        }
        temp=nums[i];
        while(temp){
            int nose=__builtin_ctz(temp);
            if(++con[nose])suma[i]|=1<<nose;
            temp-=1<<nose;
        }
        res^=suma[i];
    }
    cout << res;
}