#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int iz[n+2][n+1],nums[n+2],de[n+2][n+1];
        nums[0]=nums[n+1]=res=0;
        for(int i=1;i<=n;i++)cin >> nums[i];
        for(int i=0;i<=n;i++)iz[0][i]=iz[n+1][i]=de[n+1][i]=de[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++)iz[i][j]=iz[i-1][j];
            iz[i][nums[i]]++;
        }
        for(int i=n;i>=1;i--){
            for(int j=0;j<=n;j++)de[i][j]=de[i+1][j];
            de[i][nums[i]]++;
        }
        for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)res+=1ll*iz[i-1][nums[j]]*de[j+1][nums[i]];
        cout << res << '\n';
    }
}