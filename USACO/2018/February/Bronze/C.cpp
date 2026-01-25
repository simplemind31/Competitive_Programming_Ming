#include <bits/stdc++.h>
using namespace std;
int n,con,last;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("taming.in","r",stdin);
    freopen("taming.out","w",stdout);
    cin >> n;
    int nums[n];
    cin >> nums[0];
    if(nums[0]>0){
        cout << -1;
        return 0;
    }
    nums[0]=0;
    last=0;
    con++;
    for(int i=1;i<n;i++){
        cin >> nums[i];
        if(nums[i]==-1)continue;
        else if(nums[i]==0){
            last=i;
            con++;
            continue;
        }
        if(i-nums[i]<last || nums[i-nums[i]]>0){
            cout << -1;
            return 0;
        }else if(nums[i-nums[i]]==-1){
            last=max(last,i-nums[i]);
            nums[i-nums[i]]=0;
            con++;
        }
        for(int j=last+1;j<i;j++){
            if(nums[j]==-1)nums[j]=j-last;
        }
    }
    cout << con << ' ' << con+count(nums,nums+n,-1);
}