#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int nums[10000000],n,k,x,a,b,c,res;
deque<int> maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> x >> a >> b >> c;
    nums[0]=x;
    for(int i=1;i<n;i++)nums[i]=((ll)a*nums[i-1]+b)%c;
    for(int i=0;i<k;i++){
        while(!maxi.empty() && nums[maxi.back()]>=nums[i])maxi.pop_back();
        maxi.push_back(i);
    }
    res=nums[maxi.front()];
    for(int i=k;i<n;i++){
        if(maxi.front()==i-k)maxi.pop_front();
        while(!maxi.empty() && nums[maxi.back()]>=nums[i])maxi.pop_back();
        maxi.push_back(i);
        res^=nums[maxi.front()];
    }
    cout << res;
}