#include <bits/stdc++.h>
using namespace std;
int n,q,a,b;
string brak;
vector<int> res[4000000];
//cant, sobra( ,sobra )
void init(int node,int l,int r){
    if(l==r){
        if(brak[l]=='('){
            res[node]={0,1,0};
        }else{
            res[node]={0,0,1};
        }
        return;
    }
    int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
    init(hiji,l,mid);
    init(hijd,mid+1,r);
    res[node]={0,0,0};
    res[node][0]=res[hiji][0]+res[hijd][0]+2*min(res[hiji][1],res[hijd][2]);
    res[node][1]=res[hiji][1]+res[hijd][1]-min(res[hiji][1],res[hijd][2]);
    res[node][2]=res[hiji][2]+res[hijd][2]-min(res[hiji][1],res[hijd][2]);
}
vector<int> query(int node,int l,int r,int i,int j){
    if(i<=l && r<=j)return res[node];
    if(r<i || j<l)return {0,0,0};
    int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
    vector<int> iz=query(hiji,l,mid,i,j),de=query(hijd,mid+1,r,i,j);
    vector<int> ans(3);
    ans[0]=iz[0]+de[0]+2*min(iz[1],de[2]);
    ans[1]=iz[1]+de[1]-min(iz[1],de[2]);
    ans[2]=iz[2]+de[2]-min(iz[1],de[2]);
    return ans;
}
int main(){
    cin >> brak;
    n=brak.size();
    init(0,0,n-1);
    cin >> q;
    while(q--){
        cin >> a >> b;
        cout << query(0,0,n-1,a-1,b-1)[0] << '\n';
    }
}