#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
char c;
int t,n,now,x,y,q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int nums[n+1],psum[n+1];
        nums[0]=psum[0]=now=0;
        for(int i=1;i<=n;i++){
            cin >> nums[i];
            psum[i]=psum[i-1]^nums[i];
        }
        for(int i=1;i<=n;i++){
            cin >> c;
            if(c=='1')now^=nums[i];
        }
        cin >> q;
        while(q--){
            cin >> c;
            if(c=='1'){
                cin >> x >> y;
                now^=psum[y]^psum[x-1];
            }else{
                cin >> c;
                if(c=='1')cout << now << ' ';
                else cout << (psum[n]^now) << ' ';
            }
        }
        cout << '\n';
    }
}