#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
ll n,res=0;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<pair<int,int>> nums(n),nue;
    for(int i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
    }
    sort(ALL(nums),cmp);
    set<int> lis;
    for(int i=0;i<n;i++){
        auto p=lis.lower_bound(nums[i].second);
        if(p!=lis.end()){
            lis.erase(p);
        }
        lis.insert(nums[i].second);
    }
    cout << lis.size();
}