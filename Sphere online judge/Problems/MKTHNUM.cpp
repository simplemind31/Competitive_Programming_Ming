#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m;
struct segment{
    int tam;
    vector<int> st;
    void update(int node,int l,int r,int pos){
        st[node]++;
        if(l==r)return;
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos);
        else update(hijd,mid+1,r,pos);
    }
    int query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return 0;
        if(i<=l && r<=j)return st[node];
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        return query(hiji,l,mid,i,j)+query(hijd,mid+1,r,i,j);
    }
    segment(int x){
        tam=x;
        st.resize(4*tam+5);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int nums[n];
    pair<int,int> ord[n];
    pair<pair<int,int>,int> query[m];
    int lo[m],hi[m];
    for(int i=0;i<m;i++){
        lo[i]=0;
        hi[i]=n;
    }
    set<int> dif;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        dif.insert(nums[i]);
    }
    vector<int> diffff(ALL(dif));
    for(int i=0;i<n;i++)ord[i]={nums[i]=lower_bound(ALL(diffff),nums[i])-diffff.begin(),i};
    sort(ord,ord+n);
    for(int i=0;i<m;i++){
        cin >> query[i].first.first >> query[i].first.second >> query[i].second;
        query[i].first.first--;
        query[i].first.second--;
    }
    int con=0;
    while(true){
        bool changed=false;
        vector<vector<int>> bucket(n);
        for(int i=0;i<m;i++){
            if(lo[i]<hi[i]){
                changed=true;
                bucket[(lo[i]+hi[i])>>1].push_back(i);
            }
        }
        if(!changed)break;
        segment clave(n);
        for(int i=0;i<n;i++){
            clave.update(0,0,n-1,ord[i].second);
            for(auto u:bucket[i]){
                if(clave.query(0,0,n-1,query[u].first.first,query[u].first.second)>=query[u].second)hi[u]=i;
                else lo[u]=i+1;
            }
        }
        /*for(int i=0;i<m;i++)cout << lo[i] << ' ';
        cout << endl;
        for(int i=0;i<m;i++)cout << hi[i] << ' ';
        cout << endl;
        if(con++==2)break;*/
    }
    for(int i=0;i<m;i++){
        cout << diffff[lo[i]] << '\n';
    }
}