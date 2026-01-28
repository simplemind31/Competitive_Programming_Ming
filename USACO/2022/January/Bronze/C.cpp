#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll nums[n],con=0,mini=1e18;;
        for(int i=0;i<n;i++)cin >> nums[i];
        for(int i=n-2;i>=1;i--){
            int temp=max(0LL,nums[i]-nums[i+1]);
            con+=2*temp;
            nums[i]-=temp;
            nums[i-1]-=temp;
        }
        bool xd=true;
        for(int i=0;i<n && xd;i++){
            mini=min(mini,nums[i]);
            if(nums[i]<0)xd=false;
            if(i+1<n && nums[i]>nums[i+1])xd=false;
        }
        //ascending order
        for(int i=0;i<n && xd;i++){
            if(nums[i]==mini)continue;
            if(nums[i]==nums[i+1]){
                con+=2*(nums[i]-mini);
                nums[i]=mini;
                nums[i+1]=mini;
                i++;
            }else{
                xd=false;
            }
        }
        if(xd)cout << con << '\n';
        else cout << "-1\n";
    }
}