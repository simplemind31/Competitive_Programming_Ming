#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n],app[3*n+1],indice[3*n+1],padre[3*n+1];
    memset(app,0,sizeof(app));
    memset(indice,-1,sizeof(indice));
    memset(padre,-1,sizeof(padre));
    set<int> diff;
    diff.insert(-1);
    for(int i=0;i<n;i++){
        cin >> nums[i];
        for(int j=-1;j<=1;j++)diff.insert(nums[i]+j);
    }
    vector<int> ind(ALL(diff));
    for(int i=0;i<n;i++){
        nums[i]=lower_bound(ALL(ind),nums[i])-ind.begin();
        app[nums[i]]=app[nums[i]-1]+1;
        if(app[nums[i]]>app[maxi])maxi=nums[i];
        indice[nums[i]]=i;
        padre[i]=indice[nums[i]-1];
    }
    cout << app[maxi] << '\n';
    vector<int> res;
    int now=indice[maxi];
    while(now!=-1){
        res.push_back(now);
        now=padre[now];
    }
    reverse(ALL(res));
    for(auto u:res)cout << u+1 << ' ';
}