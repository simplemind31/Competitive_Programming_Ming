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
    vector<pair<int,int>> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i].first;
        nums[i].second=i+1;
    }
    sort(ALL(nums));
    for(int i=0;i<3;i++){
        cout << nums[i].second << ' ';
    }
}