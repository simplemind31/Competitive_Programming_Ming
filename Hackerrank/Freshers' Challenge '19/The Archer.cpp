#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,k,m,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> m;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
        nums[i]=(nums[i]-1)/m+1;
    }
    sort(ALL(nums));
    for(int i=0;i<n;i++){
        if(k<nums[i]){
            break;
        }
        k-=nums[i];
        con++;
    }
    cout << con;
}