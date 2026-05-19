#include <bits/stdc++.h>
using namespace std;
int n,ne[100001],nums[100001],con,tam[100001],dsu[100001];
bool dead[100001];
int find(int x){return x==dsu[x]?x:dsu[x]=find(dsu[x]);}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(tam[x]<tam[y])swap(x,y);
    tam[dsu[y]=x]+=tam[y];
    ne[x]=max(ne[x],ne[y]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> posi;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        nums[i]--;
        ne[i]=dsu[i]=i;
        posi.push_back(i);
        tam[i]=1;
    }
    reverse(posi.begin(),posi.end());
    ne[n]=dsu[n]=nums[n]=n;
    tam[n]=1;
    while(!posi.empty()){
        con++;
        vector<int> temp;
        for(auto u:posi){
            if(dead[u])continue;
            if(nums[u]>nums[ne[find(u+1)]]){
                temp.push_back(u);
                dead[ne[find(u+1)]]=true;
                unite(ne[find(u+1)],ne[find(u+1)]+1);
            }
        }
        posi=temp;
    }
    cout << con-1;
}