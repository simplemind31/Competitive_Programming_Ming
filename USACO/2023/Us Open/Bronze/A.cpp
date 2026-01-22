#include <bits/stdc++.h>
using namespace std;
bool xd=true;
int n,iz=-1,de=-1,mini,maxi,con;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie();
    cin >> n >> st;
    for(int i=0;i<n && xd;i++)if(st[i]!='F')xd=false;
    if(count(st.begin(),st.end(),'F')==n){
        cout << n << '\n';
        for(int i=0;i<n;i++)cout << i << '\n';
        return 0;
    }
    for(int i=0;i<n && iz==-1;i++)if(st[i]!='F')maxi+=(iz=i);
    for(int i=n-1;i>=0 && de==-1;i--)if(st[i]!='F')maxi+=(de=n-i-1);
    for(int i=iz+1;i<=n-de;i++){
        if(st[i]=='F')con++;
        else{
            mini+=(con+(st[i]==st[i-con-1]))%2;
            maxi+=con+(st[i]==st[i-con-1]);
            con=0;
        }
    }
    if(iz||de){
        cout << maxi-mini+1 << '\n';
        for(int i=mini;i<=maxi;i++)cout << i << '\n';
    }else{
        cout << (maxi-mini)/2+1 << '\n';
        for(int i=mini;i<=maxi;i+=2)cout << i << '\n';
    }
}