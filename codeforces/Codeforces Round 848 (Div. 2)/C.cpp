#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,k;
ll maxi;
string a,b;
vector<int> posi[11];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<(1<<10);i++)posi[__builtin_popcount(i)].push_back(i);
    cin >> t;
    while(t--){
        int exis=maxi=0;
        cin >> n >> k >> a >> b;
        vector<int> iesimo;
        for(int i=0;i<n;i++){
            if(!(exis&(1<<(a[i]-'a')))){
                exis|=1<<(a[i]-'a');
                iesimo.push_back(a[i]-'a');
            }
        }
        int tama=iesimo.size();
        k=min(k,tama);
        for(int i=0;i<posi[k].size();i++){
            int sepuede=0;
            for(int j=0;j<tama;j++)if(posi[k][i]&(1<<j))sepuede|=(1<<iesimo[j]);
            if(__builtin_popcount(sepuede)<k)continue;
            ll now=0,consec=0;
            for(int j=0;j<n;j++){
                if(sepuede&(1<<(a[j]-'a')) || a[j]==b[j])consec++;
                else{
                    now+=consec*(consec+1)/2;
                    consec=0;
                }
            }
            maxi=max(maxi,now+consec*(consec+1)/2);
        }
        cout << maxi << '\n';
    }
}