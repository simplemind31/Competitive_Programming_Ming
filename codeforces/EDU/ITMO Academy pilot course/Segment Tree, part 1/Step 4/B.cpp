#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<pair<int,int>,pair<int,int>> matrix;
int r;
matrix operator*(matrix A,matrix B){
    return {{(A.F.F*B.F.F+A.F.S*B.S.F)%r,(A.F.F*B.F.S+A.F.S*B.S.S)%r},{(A.S.F*B.F.F+A.S.S*B.S.F)%r,(A.S.F*B.F.S+A.S.S*B.S.S)%r}};
}
struct segment{
    int tam;
    vector<matrix> st,a;
    void build(int node,int l,int r){
        if(l==r){
            st[node]=a[l];
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=st[hiji]*st[hijd];
        return;
    }
    void update(int node,int l,int r,int pos,matrix& val){
        if(l==r){
            st[node]=val;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node]=st[hiji]*st[hijd];
    }
    matrix query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return {{1,0},{0,1}};
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return query(hiji,l,mid,i,j)*query(hijd,mid+1,r,i,j);
    }
    segment(vector<matrix> x){
        a=x;
        tam=x.size();
        st.resize(4*tam+5);
        build(0,0,tam-1);
    }
};
void imprimir(matrix A){
    cout << A.F.F << ' ' << A.F.S << '\n' << A.S.F << ' ' << A.S.S << '\n';
}
int n,m,a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> r >> n >> m;
    vector<matrix> nums(n);
    for(int i=0;i<n;i++){
        cin >> a >> b >> c >> d;
        nums[i]={{a%r,b%r},{c%r,d%r}};
    }
    segment clav(nums);
    while(m--){
        cin >> a >> b;
        imprimir(clav.query(0,0,n-1,a-1,b-1));
        cout << '\n';
    }
}