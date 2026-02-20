#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int q,n,a,b,x,y;
ll k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> q;
    while(q--){
        cin >> n;
        int nums[n];
        for(int i=0;i<n;i++){
            cin >> nums[i];
            nums[i]/=100;
        }
        sort(nums,nums+n);
        reverse(nums,nums+n);
        cin >> x >> a >> y >> b >> k;
        if(x<y){
            swap(a,b);
            swap(x,y);
        }
        int l=1,r=n+1;
        while(l<r){
            int mid=(l+r)>>1;
            // cada gcd(a,b) x+y;
            ll suma=0;
            int cangcd=mid/(1ll*a*b/gcd(a,b)),cana=mid/a-cangcd,canb=mid/b-cangcd;
            for(int i=0;i<cangcd;i++)suma+=1ll*(x+y)*nums[i];
            for(int i=cangcd;i<cangcd+cana;i++)suma+=1ll*x*nums[i];
            for(int i=cangcd+cana;i<cangcd+cana+canb;i++)suma+=1ll*y*nums[i];
            if(suma>=k)r=mid;
            else l=mid+1;
        }
        if(l==n+1)cout << "-1\n";
        else cout << l << '\n';
    }
}