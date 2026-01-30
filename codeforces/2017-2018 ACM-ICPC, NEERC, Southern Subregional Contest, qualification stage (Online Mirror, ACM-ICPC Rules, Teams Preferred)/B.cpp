#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ne[200001];
set<pair<int,int>> ayu;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n+1];
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        if(ayu.empty())ayu.insert({nums[i],i});
        else{
            auto p=ayu.lower_bound({nums[i],i});
            if(p==ayu.begin())ayu.insert({nums[i],i});
            else{
                p--;
                ne[p->second]=i;
                ayu.erase(p);
                ayu.insert({nums[i],i});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(nums[i]<0)continue;
        int p=i;
        cout << nums[p] << ' ';
        while(ne[p]!=0){
            cout << nums[p=ne[p]] << ' ';
            nums[p]=-1;
        }
        cout << '\n';
    }
}