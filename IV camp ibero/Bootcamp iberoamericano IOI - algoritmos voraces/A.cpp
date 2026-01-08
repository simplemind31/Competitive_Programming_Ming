#include <bits/stdc++.h>
using namespace std;
int n,con[1000000],res;
int main(){
    freopen("outofplace.in","r",stdin);
    freopen("outofplace.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n+2];
    nums[0]=-1;
    nums[n+1]=1e9;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        con[--nums[i]]++;
    }
    int pos=-1;
    for(int i=1;i<=n;i++){
        if((nums[i-1]<nums[i]&&nums[i]>nums[i+1])||(nums[i-1]>nums[i]&&nums[i]<nums[i+1])){
            pos=i;
            break;
        }
    }
    if(pos==-1){
        cout << 0;
        return 0;
    }
    if(nums[pos]<nums[pos-1]){
        for(int i=nums[pos-1];i>nums[pos];i--){
            if(con[i])res++;
        }
    }else{
        for(int i=nums[pos+1];i<nums[pos];i++){
            if(con[i])res++;
        }
    }
    cout << res;
}