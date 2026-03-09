#include <bits/stdc++.h>
#define LsOne(x) x&(-x)
using namespace std;
typedef unsigned long long ull;
ull n,m,q;
struct BIT{
    ull tam;
    vector<ull> fenwick;
    void update(ull pos,ull val){
        while(pos<=tam){
            fenwick[pos]+=val;
            pos+=LsOne(pos);
        }
    }
    ull sum(ull pos){
        ull sum=0;
        while(pos>0){
            sum+=fenwick[pos];
            pos-=LsOne(pos);
        }
        return sum;
    }
    void range(ull l,ull r,ull val){
        if(l<=r){
            update(l,val);
            update(r+1,-val);
        }else{
            update(l,val);
            update(1,val);
            update(r+1,-val);
        }
    }
    BIT(ull x){
        tam=x;
        fenwick.resize(x+1);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    ull ownby[m+1],target[n+1];
    vector<ull> terri[n+1];
    for(ull i=1;i<=m;i++){
        cin >> ownby[i];
        terri[ownby[i]].push_back(i);
    }
    for(ull i=1;i<=n;i++){
        cin >> target[i];
    }
    cin >> q;
    pair<pair<ull,ull>,ull> queries[q];
    for(ull i=0;i<q;i++){
        cin >> queries[i].first.first >> queries[i].first.second >> queries[i].second;
    }
    ull lo[n+1],hi[n+1];
    for(ull i=1;i<=n;i++){
        lo[i]=0;
        hi[i]=q;
    }
    while(true){
        bool change=false;
        vector<ull> bucket[q];
        for(ull i=1;i<=n;i++){
            if(lo[i]<hi[i]){
                change=true;
                bucket[(lo[i]+hi[i])>>1].push_back(i);
            }
        }
        if(!change)break;
        BIT clave(m+2);
        for(ull i=0;i<q;i++){
            clave.range(queries[i].first.first,queries[i].first.second,queries[i].second);
            for(auto u:bucket[i]){
                ull sum=0;
                for(auto v:terri[u])sum+=clave.sum(v);
                if(sum>=target[u])hi[u]=i;
                else lo[u]=i+1;
            }
        }
    }
    for(ull i=1;i<=n;i++){
        if(lo[i]==q)cout << "NIE\n";
        else cout << lo[i]+1 << '\n';
    }
}