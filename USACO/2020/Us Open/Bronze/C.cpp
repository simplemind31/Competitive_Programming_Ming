#include <bits/stdc++.h>
using namespace std;
int n,t,mini=1e9,maxi;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("tracing.in","r",stdin);
    freopen("tracing.out","w",stdout);
    cin >> n >> t;
    cin >> st;
    pair<int,pair<int,int>> events[t];
    for(int i=0;i<t;i++){
        cin >> events[i].first >> events[i].second.first >> events[i].second.second;
        events[i].second.first--;
        events[i].second.second--;
    }
    sort(events,events+t);
    vector<bool> posi(n);
    for(int i=0;i<n;i++){
        if(st[i]=='0')continue;
        for(int j=0;j<=t;j++){
            //inicia i y k=j;
            vector<int> sob(n,-1);
            sob[i]=j;
            bool xd=true;
            for(int k=0;k<t && xd;k++){
                if(sob[events[k].second.first]>=0 && sob[events[k].second.second]>=0){
                    sob[events[k].second.first]=max(0,sob[events[k].second.first]-1);
                    sob[events[k].second.second]=max(0,sob[events[k].second.second]-1);
                }else if(sob[events[k].second.first]>0 && sob[events[k].second.second]==-1){
                    if(st[events[k].second.second]=='0')xd=false;
                    sob[events[k].second.second]=j;
                    sob[events[k].second.first]--;
                }else if(sob[events[k].second.first]==-1 && sob[events[k].second.second]>0){
                    if(st[events[k].second.first]=='0')xd=false;
                    sob[events[k].second.second]--;
                    sob[events[k].second.first]=j;
                }
            }
            for(int i=0;i<n && xd;i++){
                if(st[i]=='1' && sob[i]==-1)xd=false;
            }
            if(!xd)continue;
            posi[i]=true;
            mini=min(mini,j);
            maxi=max(maxi,j);
        }
    }
    int con=0;
    for(int i=0;i<n;i++){
        if(posi[i])con++;
    }
    cout << con << ' ' << mini << ' ';
    if(maxi==t)cout << "Infinity";
    else cout << maxi;
}