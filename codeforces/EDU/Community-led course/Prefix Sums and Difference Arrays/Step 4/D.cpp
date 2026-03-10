#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll nums[n+5],psum[n+5];
        memset(psum,0,sizeof(psum));
        memset(nums,0,sizeof(nums));
        ll res=0;
        for(int i=1;i<=n;i++)cin >> nums[i];
        for(int i=1;i<=n;i++){
            psum[i]+=psum[i-1];

            res+=max(0ll,nums[i]-1-psum[i]);

            if(nums[i]-1-psum[i]<=0){
                // solo gastar can
                ll can=psum[i];
                // [i+2,i+nums[i]]
                psum[i+2]++;
                psum[min(i+nums[i]+1,n+2)]--;
                can-=(i+nums[i])-(i+2)+1;
                // usar el resto de can para el siguiente
                psum[i+1]+=can;
                psum[i+2]-=can;
                can=0;
                nums[i]=1;
            }else{
                // gastar can y nuevos pero ya gaste para res+=max...
                psum[i+2]++;
                psum[min(i+nums[i]+1,n+2)]--;
            }
        }
        cout << res << '\n';
    }
}
/*
7 8 9 3 +4
3 8 9 3 +1
2 8 9 2 +1
1 8 8 2 +6
1 2 8 2 +1
1 1 8 1 +7
1 1 1 1
*/