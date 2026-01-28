#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool xd;
int n,q,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);
    cin >> n >> q;
    int nums[n+1][3];
    nums[0][0]=nums[0][1]=nums[0][2];
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++)nums[i][j]=nums[i-1][j];
        cin >> a;
        nums[i][--a]++;
    }
    while(q--){
        cin >> a >> b;
        cout << nums[b][0]-nums[a-1][0] << ' ' << nums[b][1]-nums[a-1][1] << ' ' << nums[b][2]-nums[a-1][2] << '\n';
    }
}