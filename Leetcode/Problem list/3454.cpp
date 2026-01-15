#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
class Solution {
public:
    struct segment{
        vector<int> arr;
        vector<int> len,aclen,cov;
        //len=longitud del segmento/rango, aclen=actual len=cantidad de espacios cubiertos dentro del rango, cov=cantidad de cuadrados que cubren completamente al rango.
        int n=0;
        int query(){return aclen[0];};
        void update(int node,int l,int r,int i,int j,int val){
            if(r<i || j<l)return;
            int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
            if(i<=l && r<=j){
                cov[node]+=val;
            }else{
                update(hiji,l,mid,i,j,val);
                update(hijd,mid+1,r,i,j,val);
            }
            if(cov[node]>0){
                aclen[node]=len[node];
            }else{
                if(l==r)aclen[node]=0;
                else aclen[node]=aclen[hiji]+aclen[hijd];
            }
        }
        void build(int node,int l,int r){
            if(l==r){
                len[node]=arr[l+1]-arr[l];
                return;
            }
            int hiji=2*node+1,mid=(l+r)>>1,hijd=2*node+2;
            build(hiji,l,mid);
            build(hijd,mid+1,r);
            len[node]=len[hiji]+len[hijd];
        }
        segment(vector<int> x){
            arr=x;
            n=arr.size()-1;
            len.resize(4*n+5);
            cov=aclen=len;
            build(0,0,n-1);
        }
    };
    double separateSquares(vector<vector<int>>& squares){
        int n=squares.size();
        set<int> dif;
        for(int i=0;i<n;i++){
            swap(squares[i][0],squares[i][1]);
            squares.push_back(squares[i]);
            squares.back()[0]+=squares[i][2];
            squares.back()[2]*=-1;
            dif.insert(squares[i][1]);
            dif.insert(squares[i][1]+squares[i][2]);
        }
        sort(ALL(squares));
        n=squares.size();
        vector<int> nue;
        for(int i:dif)nue.push_back(i);
        vector<ll> psum(n,0);
        segment clave(nue);
        for(int i=0;i<n-1;i++){
            int posin=lower_bound(ALL(nue),squares[i][1])-nue.begin();
            int posfi=lower_bound(ALL(nue),squares[i][1]+abs(squares[i][2]))-nue.begin();
            int alt=squares[i+1][0]-squares[i][0];
            clave.update(0,0,nue.size()-2,posin,posfi-1,squares[i][2]>=0?1:-1);
            int wid=clave.query();
            psum[i+1]=psum[i]+1LL*wid*alt;
        }
        ll target=(psum.back()+1)/2;
        int ind=lower_bound(ALL(psum),target)-psum.begin();
        double ratio=(0.5*psum.back()-psum[ind-1])/(psum[ind]-psum[ind-1]);
        return squares[ind-1][0]+(squares[ind][0]-squares[ind-1][0])*ratio;
    }
};