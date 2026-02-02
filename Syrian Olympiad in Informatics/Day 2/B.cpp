#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,q,a,b;
string st,password;
int miniconv[26][26];
struct segment{
    vector<ll> arr,seg;
    void build(int node,int l,int r){
        if(l==r){
            seg[node]=arr[l];
            return;
        }
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        seg[node]=min(seg[hiji],seg[hijd]);
    }
    ll query(int node,int l,int r,int i,int j){
        if(r<i ||j<l)return 1e9;
        if(i<=l && r<=j)return seg[node];
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        return min(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segment(vector<ll> x){
        arr.resize(n);
        arr=x;
        seg.resize(4*n+5);
        build(0,0,n-1);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    cin >> st >> password;
    for(int i=0;i<26;i++){
        for(int j=i;j<26;j++){
            miniconv[i][j]=miniconv[j][i]=min(j-i,i+26-j);
        }
    }
    if(n>1000){
        vector<ll> need(n);
        for(int i=0;i<m;i++)need[i]=1e9;
        for(int i=m-1;i<n;i++){
            ll suma=0;
            for(int j=i-m+1;j<=i;j++){
                suma+=miniconv[st[j]-'a'][password[j-(i-m+1)]-'a'];
            }
            need[i]=suma;
        }
        segment clave(need);
        while(q--){
            cin >> a >> b;
            if(b-a+1<m){
                cout << "-1\n";
                continue;
            }
            ll resp=clave.query(0,0,n-1,a+m-1,b);
            cout << resp << '\n';
        }
        return 0;
    }
    ll dp[n][n][m+1];
    // si tengo entre i y j, con k de espacios sin usar
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<=m;k++)dp[i][j][k]=1e9;
        }
    }
    for(int i=0;i+m-1<n;i++){
        //i,i+m-1
        ll sum=0;
        for(int j=i;j<i+m-1 && j<n;j++){
            dp[i][j][(j-i+1)]=0;
        }
        for(int j=i;j<=i+m-1;j++){
            sum+=miniconv[st[j]-'a'][password[j-i]-'a'];
        }
        dp[i][i+m-1][0]=sum;
        for(int j=i+m;j<n;j++){
            // no uso j:
            for(int k=1;k<=m;k++)dp[i][j][k]=min(dp[i][j][k],dp[i][j-1][k-1]);
            // uso j:
            sum=0;
            for(int k=j-m+1;k<=j;k++){
                sum+=miniconv[st[k]-'a'][password[k-(j-m+1)]-'a'];
            }
            for(int k=0;k<=m;k++){
                dp[i][j][k]=min(dp[i][j][k],sum+dp[i][j-m][k]);
                //cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
            }
        }
    }
    while(q--){
        cin >> a >> b;
        if(b-a+1<m){
            cout << "-1\n";
            continue;
        }
        cout << dp[a][b][(b-a+1)%m] << '\n';
    }
}