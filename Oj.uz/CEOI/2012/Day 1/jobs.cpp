#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,d,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> d >> m;
    pair<int,int> nums[m];
    for(int i=0;i<m;i++){
        cin >> nums[i].first;
        nums[i].second=i;
    }
    sort(nums,nums+m);
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)>>1;
        int day=1,can=0,delay=0;
        for(int i=0;i<m;i++){
            if(nums[i].first>day){
                day=nums[i].first;
                can=0;
            }
            delay=max(delay,day-nums[i].first);
            can++;
            if(can==mid){
                day++;
                can=0;
            }
        }
        if(delay<=d)r=mid;
        else l=mid+1;
    }
    cout << l << '\n';
    for(int i=0;i<n;i++){
        cout << "0\n";
    }
}