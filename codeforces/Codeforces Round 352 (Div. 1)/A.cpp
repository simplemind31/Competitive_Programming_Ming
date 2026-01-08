#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ax,ay,bx,by,n,tx,ty;
long double res=0,nue1=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> n;
    pair<ll,ll> basura[n];
    pair<long double,ll> A[n],B[n];
    for(int i=0;i<n;i++){
        cin >> basura[i].first >> basura[i].second;
        res+=2*(sqrt((long double)((tx-basura[i].first)*(tx-basura[i].first)+(ty-basura[i].second)*(ty-basura[i].second))));
    }
    for(int i=0;i<n;i++){
        A[i]={sqrt((long double)((ax-basura[i].first)*(ax-basura[i].first)+(ay-basura[i].second)*(ay-basura[i].second)))-sqrt((long double)((tx-basura[i].first)*(tx-basura[i].first)+(ty-basura[i].second)*(ty-basura[i].second))),i};
        B[i]={sqrt((long double)((bx-basura[i].first)*(bx-basura[i].first)+(by-basura[i].second)*(by-basura[i].second)))-sqrt((long double)((tx-basura[i].first)*(tx-basura[i].first)+(ty-basura[i].second)*(ty-basura[i].second))),i};
    }
    sort(A,A+n);
    sort(B,B+n);
    //solo uso A o solo uso B
    nue1=res+min(A[0].first,B[0].first);
    if(n>1){
        // uso los dos?
        if(A[0].second==B[0].second){
            res=res+min(A[0].first+B[1].first,A[1].first+B[0].first);
        }else{
            res=res+A[0].first+B[0].first;
        }
        nue1=min(nue1,res);
    }
    cout << fixed << setprecision(12) << nue1;
}
/*
T...
.*B.
.*.*
.A..
*/