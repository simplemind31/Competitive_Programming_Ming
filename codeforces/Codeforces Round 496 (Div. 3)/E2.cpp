#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,pos,now,con[600000];
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
        if(nums[i]==m)pos=i;
    }
    con[300000+0]++;
    for(int i=pos+1;i<n;i++){
        if(nums[i]>m)now++;
        else if(nums[i]<m)now--;
        con[now+300000]++;
    }
    now=0;
    res+=con[300000+0]+con[300000+1];
    for(int i=pos-1;i>=0;i--){
        if(nums[i]>m)now--;
        else if(nums[i]<m)now++;
        res+=con[now+300000]+con[now+1+300000];
    }
    cout << res;
}