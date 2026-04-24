#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int MAXN=200000;
int t,n,q,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        int nums[n],mini=1e9+7;
        set<int> clav;
        for(int i=0;i<n;i++){
            cin >> nums[i];
            if(nums[i]<mini){
                mini=nums[i];
                clav.insert(i);
            }
        }
        while(q--){
            cin >> a >> b;
            nums[--a]-=b;
            auto p=clav.upper_bound(a),prin=prev(p);
            while(p!=clav.end() && nums[*p]>=nums[a])clav.erase(prev(++p));
            if(nums[*prin]>nums[a])clav.insert(a);
            cout << clav.size() << ' ';
        }
        cout << '\n';
    }
}