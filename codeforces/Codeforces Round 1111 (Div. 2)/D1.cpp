#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int t=1,n,q;
struct segment{
    int tam;
    vector<int> st,a;
    void build(int node,int l,int r){
        if(l==r){
            st[node]=a[l];
            return;
        }
        int mid=(l+r)>>1;
    }
    segment(vector<int> x){
        a=x;
        tam=x.size();
        st.resize(4*tam);
        build(0,0,n-1);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        // ans es siempre power of 2
        int need=1;
        while(need<n)need<<=1;
        vector<int> maxi(2*need),mini(2*need,MOD);
        vector<int> canmal(20);
        for(int i=need;i<need+n;i++){
            cin >> maxi[i];
            mini[i]=maxi[i];
        }
        for(int i=need-1;i>0;i--){
            mini[i]=min(mini[2*i],mini[2*i+1]);
            maxi[i]=max(maxi[2*i],maxi[2*i+1]);
        }
        int debe=__builtin_ctz(need);
        for(int i=1;i<2*need;i++){
            if(__builtin_popcount(i)==1)continue;
            // el minimo de este bloque es>= que le mayor del anterior?
            canmal[debe-(31-__builtin_clz(i))]+=(mini[i]<maxi[i-1]);
        }
        for(int i=0;i<20;i++){
            if(canmal[i]==0){
                cout << ((1<<i)>>1) << '\n';
                break;
            }
        }
    }
}
/*
x0
x 1 0->3
xx 3 1->2
xxxx 7 2->1
xxxxxxxx 15 3->0

8=1000 ctz=3
*/