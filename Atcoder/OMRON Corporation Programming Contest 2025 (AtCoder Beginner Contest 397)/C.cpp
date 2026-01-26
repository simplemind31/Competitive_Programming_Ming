#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int n,maxi;
set<int> dif;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int psum[n],nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
        dif.insert(nums[i]);
        psum[i]=dif.size();
    }
    dif.clear();
    for(int i=n-1;i>0;i--){
        dif.insert(nums[i]);
        maxi=max(maxi,(int)dif.size()+psum[i-1]);
    }
    cout << maxi;
}