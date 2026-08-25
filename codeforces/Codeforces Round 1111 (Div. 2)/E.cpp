#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int t=1,n,q,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)nums[i]=i;
        do{
            int res=0;
            vector<int> pos(n);
            for(int i=0;i<n;i++)pos[nums[i]]=i;
            for(int i=0;i<n;i++)res+=abs(i-pos[(nums[i]+1)%n]);
            cout << res << ' ';
        }while(next_permutation(ALL(nums)));
        cout << '\n';
    }
}