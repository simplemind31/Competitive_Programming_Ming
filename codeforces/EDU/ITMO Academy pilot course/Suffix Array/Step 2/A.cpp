#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end() 
using namespace std;
string st;
int n;
void radix_sort(vector<pair<pair<int,int>,int>>&a){
    vector<int> con(n);
    for(auto u:a)con[u.first.second]++;
    vector<int> pos(n);
    pos[0]=0;
    for(int i=1;i<n;i++)pos[i]=pos[i-1]+con[i-1];
    vector<pair<pair<int,int>,int>> nuea(n);
    for(auto u:a)nuea[pos[u.first.second]++]=u;
    a=nuea;
    con.assign(n,0);
    for(auto u:a)con[u.first.first]++;
    pos[0]=0;
    for(int i=1;i<n;i++)pos[i]=pos[i-1]+con[i-1];
    nuea.assign(n,{{0,0},0});
    for(auto u:a)nuea[pos[u.first.first]++]=u;
    a=nuea;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    st.push_back('$');
    n=st.size();
    vector<pair<char,int>> a(n);
    vector<int> p(n),c(n);
    for(int i=0;i<n;i++)a[i]={st[i],i};
    sort(ALL(a));
    for(int i=0;i<n;i++)p[i]=a[i].second;
    c[p[0]]=0;
    for(int i=1;i<n;i++)c[p[i]]=c[p[i-1]]+(a[i].first!=a[i-1].first);
    for(int k=0;(1<<k)<n;k++){
        vector<pair<pair<int,int>,int>> a(n);
        for(int i=0;i<n;i++)a[i]={{c[i],c[(i+(1<<k))%n]},i};
        radix_sort(a);
        for(int i=0;i<n;i++)p[i]=a[i].second;
        c[p[0]]=0;
        for(int i=1;i<n;i++)c[p[i]]=c[p[i-1]]+(a[i].first!=a[i-1].first);
    }
    for(int i=0;i<n;i++)cout << p[i] << ' ';
}