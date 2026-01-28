#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,q,a,t,con;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        ll nums[n];
        for(int i=con=0;i<n;i++)cin >> nums[i];
        for(int i=1;i<n;i++)nums[i]+=nums[i-1];
        cin >> st;
        for(int i=1;i<n;i++){
            if(st[i-1]=='L' && st[i]=='R' && nums[i-1]!=1LL*i*(i+1)/2)con++;
        }
        while(q--){
            cin >> a;
            a--;
            if(st[a]=='L'){
                if(st[a+1]=='R' && nums[a]!=1LL*(a+1)*(a+2)/2)con--;
                if(st[a-1]=='L' && nums[a-1]!=1LL*a*(a+1)/2)con++;
                st[a]='R';
            }else{
                if(st[a-1]=='L' && nums[a-1]!=1LL*a*(a+1)/2)con--;
                if(st[a+1]=='R' && nums[a]!=1LL*(a+1)*(a+2)/2)con++;
                st[a]='L';
            }
            if(con)cout << "NO\n";
            else cout << "YES\n";
        }
    }
}