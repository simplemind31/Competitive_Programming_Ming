#include <bits/stdc++.h>
using namespace std;
int n,m,c[300000],a,i,r;
vector<int> o[300000];
int main(){
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>c[i];
        for(int j=0;j<c[i];j++)o[cin>>a,--a].push_back(i);
    }
    for(i=0;i<n;i++){
        for(auto u:o[cin>>a,--a])if(--c[u]==0)r++;
        cout<<r<<'\n';
    }
}