#include <bits/stdc++.h>
using namespace std;
int n,q,a,b;
string brak;
vector<pair<pair<int,int>,int>> res;
//cant, sobra( ,sobra )
void init(int node,int l,int r){
    if(l==r){
        if(brak[l]=='('){
            res[node]={{0,1},0};
        }else{
            res[node]={{0,0},1};
        }
        return;
    }
    int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
    init(hiji,l,mid);
    init(hijd,mid+1,r);
    res[node]={{0,0},0};
    res[node].first.first=res[hiji].first.first+res[hijd].first.first+2*min(res[hiji].first.second,res[hijd].second);
    res[node].first.second=res[hiji].first.second+res[hijd].first.second-min(res[hiji].first.second,res[hijd].second);
    res[node].second=res[hiji].second+res[hijd].second-min(res[hiji].first.second,res[hijd].second);
}
pair<pair<int,int>,int> query(int node,int l,int r,int i,int j){
    if(i<=l && r<=j)return res[node];
    if(r<i || j<l)return {{0,0},0};
    int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
    pair<pair<int,int>,int>  iz=query(hiji,l,mid,i,j),de=query(hijd,mid+1,r,i,j);
    pair<pair<int,int>,int>  ans;
    ans.first.first=iz.first.first+de.first.first+2*min(iz.first.second,de.second);
    ans.first.second=iz.first.second+de.first.second-min(iz.first.second,de.second);
    ans.second=iz.second+de.second-min(iz.first.second,de.second);
    return ans;
}
int main(){
    cin >> brak;
    n=brak.size();
    res.resize(4*n+5);
    init(0,0,n-1);
    cin >> q;
    while(q--){
        cin >> a >> b;
        cout << query(0,0,n-1,a-1,b-1).first.first << '\n';
    }
}