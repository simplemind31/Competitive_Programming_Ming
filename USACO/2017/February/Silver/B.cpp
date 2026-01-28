#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,b,mini=1e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("maxcross.in","r",stdin);
    freopen("maxcross.out","w",stdout);
    cin >> n >> k >> b;
    int nums[b+2];
    nums[0]=0;
    nums[b+1]=n+1;
    for(int i=1;i<=b;i++)cin >> nums[i];
    sort(nums,nums+b+2);
    // 0,1,2,5,9,10,11
    // 0,0,2,3,0,0

    // 0,4,5,9,10,11
    // 3,0,3,0,0
    int dif[b+1];
    for(int i=1;i<b+2;i++){
        dif[i-1]=nums[i]-nums[i-1]-1;
    }
    /*for(int i=0;i<b+1;i++){
        cout << dif[i] << ' ';
    }*/
    int suma=-1,iz=0;
    for(int i=0;i<b+1;i++){
        suma+=dif[i]+1;
        while(suma>=k){
            mini=min(mini,i-iz);
            suma-=dif[iz]+1;
            iz++;
        }
    }
    cout << mini;
}