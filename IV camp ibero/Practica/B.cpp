#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k,nums[300000],estado[300000];
string str;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> str;
        string nue=str;
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        int l=0,r=1e9;
        while(l<r){
            str=nue;
            int mid=(l+r)>>1,con=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid){
                    estado[i]=0;
                }else{
                    estado[i]=1;
                }
            }
            if(estado[0]==0)str[0]='R';
            if(str[0]=='B')con++;
            for(int i=1;i<n;i++){
                if(estado[i]==0){
                    str[i]=str[i-1];
                }
                if(str[i]=='B' && str[i-1]=='R')con++;
            }
            if(con<=k){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        cout << l << '\n';
    }
}