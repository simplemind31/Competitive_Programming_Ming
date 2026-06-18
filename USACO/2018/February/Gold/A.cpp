#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,b;
struct dsu{
    vector<int> pad,tam,maxi,mini;
    int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
    bool unite(int x,int y){
        if((x=find(x))==(y=find(y)))return false;
        if(tam[x]<tam[y])swap(x,y);
        tam[pad[y]=x]+=tam[y];
        maxi[x]=max(maxi[x],maxi[y]);
        mini[x]=min(mini[x],mini[y]);
        return true;
    }
    dsu(int x){
        tam.resize(x);
        maxi=mini=pad=tam;
        for(int i=0;i<x;i++)tam[maxi[i]=mini[i]=pad[i]=i]=1;
    }
};
int x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("snowboots.in","r",stdin);
    freopen("snowboots.out","w",stdout);
    cin >> n >> b;
    dsu clav(n);
    int nums[n],res[n];
    memset(res,0,sizeof(res));
    pair<int,int> ord[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
        ord[i]={nums[i],i};
    }
    sort(ord,ord+n);
    reverse(ord,ord+n);
    vector<bool> used(n);
    for(int i=0;i<n;i++){
        used[ord[i].second]=1;
        if(ord[i].second-1>=0 && used[ord[i].second-1])clav.unite(ord[i].second,ord[i].second-1);
        if(ord[i].second+1<n && used[ord[i].second+1])clav.unite(ord[i].second,ord[i].second+1);
        int pad=clav.find(ord[i].second);
        int iz=clav.mini[pad],de=clav.maxi[pad];
        // todos de tamaño de-iz+1 o menor paso necesitan pasar minimamente por ord[i].first
        res[de-iz+1]=max(res[de-iz+1],ord[i].first);
    }
    /*for(int i=0;i<n;i++){
        cout << res[i] << ' ';
    }
    cout << endl;*/
    for(int i=n-2;i>0;i--){
        res[i]=max(res[i+1],res[i]);
    }
    while(b--){
        cin >> x >> y;
        cout << (x>=res[y]) << '\n';
    }
}
/*

*/