#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("berries.in","r",stdin);
    freopen("berries.out","w",stdout);
    cin >> n >> k;
    int nums[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    for(int i=1000;i>=1;i--){
        vector<int> nue;
        for(int j=0;j<n;j++){
            int con=nums[j]/i;
            while(con--)nue.push_back(i);
            nue.push_back(nums[j]%i);
        }
        sort(nue.rbegin(),nue.rend());
        while(nue.size()<k)nue.push_back(0);
        int psum[k+1];
        psum[0]=0;
        for(int j=1;j<=k;j++)psum[j]=psum[j-1]+nue[j-1];
        maxi=max(maxi,psum[k]-psum[k/2]);
    }
    cout << maxi;
}