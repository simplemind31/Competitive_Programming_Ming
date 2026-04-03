#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t,k;
vector<int> operator*(vector<int> a,vector<int> b){
    vector<int> res(n);
    for(int i=0;i<n;i++)res[i]=b[a[i]];
    return res;
}
vector<int> binaryexp(vector<int> b,int e){
    vector<int> p(n);
    for(int i=0;i<n;i++)p[i]=i;
    while(e){
        if(e&1)p=b*p;
        e>>=1;
        b=b*b;
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> p(n);
        for(int i=0;i<n/2;i++)p[i]=2*i;
        for(int i=0;i<n/2;i++)p[i+n/2]=2*i+1;
        p=binaryexp(p,k);
        for(int i=0;i<n;i++)cout << p[i]+1 << ' ';
        cout << '\n';
    }
}