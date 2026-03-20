#include <bits/stdc++.h>
using namespace std;
int n,c,a,con[500000],maxi,tot;
pair<int,int> mini[500000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> c;
    c--;
    int nums[n+1];
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        nums[i]--;
        if(nums[i]==c)tot++;
    }
    for(int i=1;i<=n;i++){
        // max psum[a][i]-psum[a][j]-(psum[c][i]-psum[c][j]);
        // max psum[a][i]-psum[c][i]-(psum[a][j]-psum[c][j]);
        if(con[nums[i]])
        mini[nums[i]]=min(mini[nums[i]],con[nums[i]]-con[c]);
        con[a]++;
        maxi=max(maxi,con[a]-con[c]-mini[a]);

    }
}