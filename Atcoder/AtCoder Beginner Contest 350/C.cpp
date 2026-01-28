#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n],pos[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
        pos[--nums[i]]=i;
    }
    vector<pair<int,int>> res;
    for(int i=0;i<n;i++){
        if(nums[i]==i)continue;
        int need=pos[i];
        res.push_back({i,need});
        pos[nums[i]]=need;
        pos[i]=i;
        nums[need]=nums[i];
    }
    cout << res.size() << '\n';
    for(auto u:res){
        cout << u.first+1 << ' ' << u.second+1 << '\n';
    }
}