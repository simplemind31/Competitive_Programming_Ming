#include <bits/stdc++.h>
using namespace std;
int n,m,k,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("swap.in","r",stdin);
    freopen("swap.out","w",stdout);
    cin >> n >> m >> k;
    int nums[n],res[n],pad[n][31];
    for(int i=0;i<n;i++)nums[i]=res[i]=i;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        reverse(nums+a-1,nums+b);
    }
    for(int i=0;i<n;i++)pad[i][0]=nums[i];
    for(int i=1;i<31;i++)for(int j=0;j<n;j++)pad[j][i]=pad[pad[j][i-1]][i-1];
    for(int i=0;i<n;i++)for(int j=30;j>=0;j--)if(k&(1<<j))res[i]=pad[res[i]][j];
    for(int i=0;i<n;i++)cout << res[i]+1 << '\n';
}