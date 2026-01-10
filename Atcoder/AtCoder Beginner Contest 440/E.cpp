#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
ll n,k,x;
vector<ll> nums;
// n<=50
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> x;
    nums.resize(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(REV(nums));
    vector<ll> cont(n);
    cont[0]=k;
    map<vector<ll>,bool> usado;
    vector<ll> res;// tam x
    set<pair<ll,vector<ll>>,greater<pair<ll,vector<ll>>>> dijbfs;
    dijbfs.insert({k*nums[0],cont});
    usado[cont]=true;
    while(res.size()<x){
        while(dijbfs.size()>x-res.size()){
            dijbfs.erase(--dijbfs.end());
        }
        pair<ll,vector<ll>> top=*dijbfs.begin();
        dijbfs.erase(dijbfs.begin());
        res.push_back(top.first);
        if(res.size()==x){
            break;
        }
        for(int i=0;i<n-1;i++){
            if(top.second[i]>0){
                top.second[i]--;
                top.first-=nums[i];
                top.second[i+1]++;
                top.first+=nums[i+1];
                if(!usado[top.second]){
                    usado[top.second]=true;
                    dijbfs.insert(top);
                }
                top.second[i+1]--;
                top.first-=nums[i+1];
                top.second[i]++;
                top.first+=nums[i];
            }
        }
    }
    for(int i=0;i<x;i++){
        cout << res[i] << '\n';
    }
}