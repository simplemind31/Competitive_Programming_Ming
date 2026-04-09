#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,maxi=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<pair<int,int>> edge(n);
    vector<int> con(2*n),ind(2*n);
    for(int i=0;i<n;i++){
        cin >> edge[i].first >> edge[i].second;
        ind[edge[i].first]=ind[edge[i].second]=i;
        if((edge[i].first+edge[i].second)&1)con[(edge[i].first+edge[i].second)%(2*n)]++;
    }
    for(int i=1;i<2*n;i+=2)if(con[i]>con[maxi])maxi=i;
    cout << n-con[maxi] << '\n';
    for(int i=0;i<n;i++){
        if((edge[i].first+edge[i].second)%(2*n)==maxi)continue;
        cout << i << ' ' << edge[i].second << ' ' << (maxi-edge[i].first+2*n)%(2*n) << '\n';
        edge[i].second=(maxi-edge[i].first+2*n)%(2*n);
        int ante=edge[i].second;
        int pos=ind[edge[i].second];
        while(pos!=i){
            if(edge[pos].first==ante)swap(edge[pos].first,edge[pos].second);
            cout << pos << ' ' << edge[pos].second << ' ' << (maxi-edge[pos].first+2*n)%(2*n) << '\n';
            edge[pos].second=(maxi-edge[pos].first+2*n)%(2*n);
            ante=edge[pos].second;
            pos=ind[edge[pos].second];
        }
    }
}