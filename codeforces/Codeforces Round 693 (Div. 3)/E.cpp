#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll t,n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        pair<pair<int,int>,int> nums[n];
        int res[n];
        for(int i=0;i<n;i++){
            cin >> nums[i].first.first >> nums[i].first.second;
            if(nums[i].first.first>nums[i].first.second)swap(nums[i].first.first,nums[i].first.second);
            nums[i].second=i;
        }
        sort(nums,nums+n);
        ll mini=-1,tempmini=0;
        res[nums[tempmini].second]=-2;
        for(int i=1;i<n;i++){
            if(nums[i].first.first==nums[i-1].first.first){
                if(nums[i].first.second<nums[tempmini].first.second)tempmini=i;
            }else{
                if(mini==-1)mini=tempmini;
                else if(nums[tempmini].first.second<nums[mini].first.second)mini=tempmini;
                tempmini=i;
            }
            res[nums[i].second]=-2;
            if(mini!=-1 && nums[mini].first.second<nums[i].first.second){
                res[nums[i].second]=nums[mini].second;
            }
        }
        for(int i=0;i<n;i++)cout << res[i]+1 << ' ';
        cout << '\n';
    }
}