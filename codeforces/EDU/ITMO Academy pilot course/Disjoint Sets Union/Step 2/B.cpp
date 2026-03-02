#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
char t;
int n,m,x;
vector<int> dsu,tam,maxi;
int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
bool unite(int a,int b){
    if((a=find(a))==(b=find(b)))return false;
    if(tam[a]<tam[b])swap(a,b);
    tam[dsu[b]=a]+=tam[b];
    maxi[a]=max(maxi[a],maxi[b]);
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    dsu.resize(2*n+1);
    tam.resize(2*n+1);
    maxi.resize(2*n+1);
    for(int i=0;i<=2*n;i++)tam[maxi[i]=dsu[i]=i]=1;
    for(int i=0;i<n;i++){
        cin >> x;
        x--;
        int pos=maxi[find(x)]%n;
        unite(pos,pos+1);
        unite(pos+n,pos+n+1);
        cout << pos+1 << ' ';
    }
}