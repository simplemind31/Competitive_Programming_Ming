#include <bits/stdc++.h>
using namespace std;
int n,k,a,b,con,need;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("swap.in","r",stdin);
    freopen("swap.out","w",stdout);
    cin >> n >> k;
    int nums[n],res[n];
    for(int i=0;i<n;i++)nums[i]=res[i]=i;
    for(int i=0;i<2;i++){
        cin >> a >> b;
        reverse(nums+a-1,nums+b);   
    }
    for(int i=0;i<n;i++){
        a=i;con=1;
        while((a=nums[a])!=i)con++;
        need=k%con;
        while(need--)res[i]=nums[res[i]];
    }
    for(int i=0;i<n;i++)cout << res[i]+1 << '\n';
}