#include <bits/stdc++.h>
using namespace std;
int t,n,m,con,nums[500000],ord[500000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=con=0;i<n;i++){
            cin >> nums[i];
            ord[i]=nums[i];
        }
        sort(ord,ord+n);
        for(int i=0;i<n && m>=ord[i];i++){
            m-=ord[i];
            con++;
        }
        if(con!=0 && con!=n && m+ord[con-1]>=nums[con])con++;
        cout << n+1-con << '\n';
    }
}