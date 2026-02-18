#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,mini=1e6,suma;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    for(int i=0;i<m;i++){
        suma+=nums[i];
    }
    mini=suma;
    for(int i=m;i<n;i++){
        suma+=nums[i]-nums[i-m];
        mini=min(mini,suma);
    }
    cout << mini;
}