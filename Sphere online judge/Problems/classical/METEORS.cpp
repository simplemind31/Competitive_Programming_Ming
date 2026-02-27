#include <bits/stdc++.h>
#define Aull(x)x.begin(),x.end()
#define LsOne(x)x&(-x)
using namespace std;
typedef unsigned long long ull;
const ull MAXN=300005;
ull n,m,target[MAXN],a,q,ans[MAXN];
vector<ull> ownbyperson[MAXN];
vector<ull> todos;
pair<pair<ull,ull>,ull> queries[MAXN];
struct BIT{
    ull fenwick[MAXN];
    void update(ull pos,ull val){
        while(pos<MAXN){
            fenwick[pos]+=val;
            pos+=LsOne(pos);
        }
    }
    ull sum(ull pos){
        ull suma=0;
        while(pos>0){
            suma+=fenwick[pos];
            pos-=LsOne(pos);
        }
        return suma;
    }
    void range(ull a,ull b,ull val){
        update(a,val);
        update(b+1,-val);
    }
    BIT(){}
};
BIT res;
void solve(ull l,ull r,vector<ull> candiate){
    if(l==r){
        for(auto u:candiate){
            ans[u]=l;
        }
        return;
    }
    ull mid=(l+r)>>1;
    for(ull i=l;i<=mid;i++){
        if(queries[i].first.first>queries[i].first.second){
            res.range(queries[i].first.first,m,queries[i].second);
            res.range(1,queries[i].first.second,queries[i].second);
        }else{
            res.range(queries[i].first.first,queries[i].first.second,queries[i].second);
        }
    }
    vector<ull> iz,de;
    for(auto u:candiate){
        ull suma=0;
        for(auto v:ownbyperson[u])suma+=res.sum(v);
        if(suma>=target[u]){
            iz.push_back(u);
        }else{
            target[u]-=suma;
            de.push_back(u);
        }
    }
    for(ull i=l;i<=mid;i++){
        if(queries[i].first.first>queries[i].first.second){
            res.range(queries[i].first.first,m,-queries[i].second);
            res.range(1,queries[i].first.second,-queries[i].second);
        }else{
            res.range(queries[i].first.first,queries[i].first.second,-queries[i].second);
        }
    }
    solve(l,mid,iz);
    solve(mid+1,r,de);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(ull i=1;i<=m;i++){
        cin >> a;
        ownbyperson[a].push_back(i);
    }
    for(ull i=1;i<=n;i++){
        cin >> target[i];
        todos.push_back(i);
    }
    cin >> q;
    for(ull i=1;i<=q;i++){
        cin >> queries[i].first.first >> queries[i].first.second >> queries[i].second;
    }
    vector<ull> lo(n+1,1),hi(n+1,q+1);
    while(true){
        bool changed=false;
        vector<vector<ull>> bucket(q+2);
        for(ull i=1;i<=n;i++){
            if(lo[i]<hi[i]){
                changed=true;
                ull mid=(lo[i]+hi[i])>>1;
                bucket[mid].push_back(i);
            }
        }
        if(!changed)break;
        memset(res.fenwick,0,sizeof(res.fenwick));
        for(ull i=1;i<=q;i++){
            // apply query i
            if(queries[i].first.first>queries[i].first.second){
                res.range(queries[i].first.first,m,queries[i].second);
                res.range(1,queries[i].first.second,queries[i].second);
            }else{
                res.range(queries[i].first.first,queries[i].first.second,queries[i].second);
            }
            // process countries that test at time i
            for(ull country:bucket[i]){
                ull suma=0;
                for(auto pos:ownbyperson[country])suma+=res.sum(pos);
                if(suma>=target[country])hi[country]=i;
                else lo[country]=i+1;
            }
        }
    }
    for(ull i=1;i<=n;i++)ans[i]=lo[i];
    //solve(1,q+1,todos);
    for(ull i=1;i<=n;i++){
        if(ans[i]==q+1)cout << "NIE\n";
        else cout << ans[i] << '\n';
    }
}