#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,k,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int nums[n+1][n+1];
    memset(nums,0,sizeof(nums));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> nums[i][j];
            maxi=max(maxi,nums[i][j]);
        }
    }
    // 6->2
    // 7->3
    // enonctrar el (n*n-1)/2 menor
    int l=0,r=maxi;
    while(l<r){
        int mid=(l+r)>>1;
        int nue[n+1][n+1];
        memset(nue,0,sizeof(nue));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                nue[i][j]=(nums[i][j]<=mid);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                nue[i][j]+=nue[i-1][j]+nue[i][j-1]-nue[i-1][j-1];
            }
        }
        bool xd=false;
        for(int i=k;i<=n && !xd;i++){
            for(int j=k;j<=n && !xd;j++){
                if(nue[i][j]-nue[i-k][j]-nue[i][j-k]+nue[i-k][j-k]>=(k*k+1)/2)xd=true;
            }
        }
        if(xd)r=mid;
        else l=mid+1;
    }
    cout << l;
}