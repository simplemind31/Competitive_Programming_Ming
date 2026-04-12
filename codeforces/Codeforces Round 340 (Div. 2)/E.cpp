#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,k,l,r,conta[1<<20],coniz[1<<20];
bool cmp(pair<pair<int,int>,int>& a,pair<pair<int,int>,int>& b){
    if(a.first.second==b.first.second)return a.first.first<b.first.first;
    return a.first.second<b.first.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    int nums[n],raiz=sqrt(n-1)+1;
    for(int i=0;i<n;i++)cin >> nums[i];
    ll res[m];
    vector<pair<pair<int,int>,int>> block[raiz];
    // l,r,indi,
    for(int i=0;i<m;i++){
        cin >> l >> r;
        l--;r--;
        block[l/raiz].push_back({{l,r},i});
    }
    conta[0]=1;
    for(int i=0;i<raiz;i++){
        sort(ALL(block[i]),cmp);
        // procesar
        int last=0,poin=(i+1)*raiz;
        ll temp=0;
        for(auto u:block[i]){
            if(u.first.second/raiz==i){
                for(int j=u.first.first;j<=u.first.second;j++){
                    last^=nums[j];
                    temp+=conta[k^last];
                    conta[last]++;
                }
                res[u.second]=temp;
                for(int j=u.first.second;j>=u.first.first;j--){
                    conta[last]--;
                    temp-=conta[k^last];
                    last^=nums[j];
                }
                continue;
            }
            while(poin<=u.first.second){
                // añadir
                last^=nums[poin];
                temp+=conta[k^last];
                conta[last]++;
                poin++;
            }
            // exclusivo para iz
            int lastiz=0;
            ll tempiz=0;
            // mover de (i+1)*raiz-1 al u.f.f
            for(int j=(i+1)*raiz-1;j>=u.first.first;j--){
                lastiz^=nums[j];
                tempiz+=coniz[k^lastiz]+conta[lastiz^k];
                coniz[lastiz]++;
            }
            res[u.second]=temp+tempiz;
            for(int j=u.first.first;j<=(i+1)*raiz-1;j++){
                coniz[lastiz]--;
                tempiz-=coniz[k^lastiz]+conta[lastiz^k];
                lastiz^=nums[j];
            }
        }
        while(poin>(i+1)*raiz){
            poin--;
            conta[last]--;
            temp-=conta[k^last];
            last^=nums[poin];
        }
    }
    for(int i=0;i<m;i++){
        cout << res[i] << '\n';
    }
}