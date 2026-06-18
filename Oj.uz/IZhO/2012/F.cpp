#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,a,b,c,ante;
struct Node{
    int l,r,sum=0;
    bool lazy=false;
    Node *hiji=nullptr,*hijd=nullptr;
    Node (int x,int y){l=x,r=y;}
    void expand(){
        if(r-l+1<=1)return;
        int mid=(l+r)>>1;
        hiji=new Node(l,mid);
        hijd=new Node(mid+1,r);
    }
    void pushdown(){
        if(!lazy)return;
        if(hiji==nullptr)expand();
        if(hiji==nullptr)return;
        sum=r-l+1;
        hiji->lazy=hijd->lazy=1;
        hiji->sum=hiji->r-hiji->l+1;
        hijd->sum=hijd->r-hijd->l+1;
        lazy=0;
    }
    void paint(int iz,int de){
        if(r<iz || de<l)return;
        if(iz<=l && r<=de){
            lazy=1;
            sum=r-l+1;
            return;
        }
        pushdown();
        if(hiji==nullptr)expand();
        hiji->paint(iz,de);
        hijd->paint(iz,de);
        sum=hiji->sum+hijd->sum;
    }
    int getsum(int iz,int de){
        if(de<l || r<iz)return 0;
        if(iz<=l && r<=de)return sum;
        pushdown();
        if(hiji==nullptr)expand();
        return hiji->getsum(iz,de)+hijd->getsum(iz,de);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    Node clav(0,1000000000);
    while(n--){
        cin >> a >> b >> c;
        b+=ante-1;c+=ante-1;
        if(a==1)cout << (ante=clav.getsum(b,c)) << '\n';
        else clav.paint(b,c);
    }
}