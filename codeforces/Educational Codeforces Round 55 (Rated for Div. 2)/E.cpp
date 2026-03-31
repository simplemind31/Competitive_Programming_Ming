#include <bits/stdc++.h>
using namespace std;
int n,c,a,con[500000],maxi,tot,mini[500000],nums[500000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> c;
    c--;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        if(--nums[i]==c)tot++;
    }
    for(int i=0;i<n;i++){
        // max psum[a][i]-psum[a][j]-(psum[c][i]-psum[c][j]);
        // max psum[a][i]-psum[c][i]-(psum[a][j]-psum[c][j]);
        mini[nums[i]]=min(mini[nums[i]],con[nums[i]]-con[c]);
        con[nums[i]]++;
        maxi=max(maxi,tot+con[nums[i]]-con[c]-mini[nums[i]]);
    }
    cout << maxi;
}