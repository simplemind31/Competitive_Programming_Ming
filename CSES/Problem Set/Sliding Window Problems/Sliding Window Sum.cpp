#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int nums[10000000],n,k,x,a,b,c;
ll suma,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> x >> a >> b >> c;
    nums[0]=x;
    for(int i=1;i<n;i++)nums[i]=((ll)a*nums[i-1]+b)%c;
    for(int i=0;i<k;i++)suma+=nums[i];
    res=suma;
    for(int i=k;i<n;i++)res^=suma+=nums[i]-nums[i-k];
    cout << res;
}