#include <bits/stdc++.h>
#define imposible \
do{\
    cout << -1;\
    return 0;\
}while(0)
using namespace std;
int n,m,sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    if(m==1)imposible;
    pair<int,int> ord[m];
    for(int i=0;i<m;i++){
        cin >> ord[i].first;
        ord[i].first=min(ord[i].first,n/2);
        ord[i].second=i;
        sum+=ord[i].first;
    }
    if(sum<n)imposible;
    sort(ord,ord+m);
    reverse(ord,ord+m);
    // siempre es posible?
    vector<int> res(n,-1);
    //11 
    // 1 x 1 x 1 x 1 x 1 x x
    if((n&1) && ord[0].first>=(n+1)/2){
            int pos=1;
            for(int i=0;i<n-1;i+=2)res[i]=ord[0].second;
            res[n-1]=ord[pos].second;
            ord[pos].first--;
            if(ord[pos].first==0)pos++;
            for(int i=1;i<n-2;i+=2){
                if(pos>=m)imposible;
                res[i]=ord[pos].second;
                ord[pos].first--;
                if(ord[pos].first==0)pos++;
            }
            if(pos>=m)imposible;
            if(ord[pos].second==res[n-1])pos++;
            if(pos>=m)imposible;
            res[n-2]=ord[pos].second;
            for(int i=0;i<n;i++)cout << res[i]+1 << ' ';
    }
    int pos=0;
    for(int i=0;i<n;i+=2){
        if(pos>=m)imposible;
        res[i]=ord[pos].second;
        ord[pos].first--;
        if(ord[pos].first==0)pos++;
    }
    for(int i=1;i<n;i+=2){
        if(pos>=m)imposible;
        res[i]=ord[pos].second;
        ord[pos].first--;
        if(ord[pos].first==0)pos++;
    }
    for(int i=0;i<n;i++)cout << res[i]+1 << ' ';
}