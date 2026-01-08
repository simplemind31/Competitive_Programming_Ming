#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,K,l=0,r=1e18;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    cin >> N >> K;
    vector<int> nums(N);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    while(l<r){
        ll mid=(l+r+1)>>1,con=0;
        for(int i=0;i<N;i++){
            con+=nums[i]/mid;
        }
        if(con>=K){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout << l;
}