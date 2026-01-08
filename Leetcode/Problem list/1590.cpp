#include <bits/stdc++.h>
using namespace std;
int suma,n,temp,mini;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p){
        unordered_map<int,int> last;
        last[0]=-1;
        mini=n=nums.size();
        for(int i=suma=temp=0;i<n;i++)suma=(suma+nums[i])%p;
        for(int i=0;i<n;i++){
            last[temp=(temp+nums[i])%p]=i;
            if(last.count(((temp-suma)%p+p)%p))mini=min(mini,i-last[((temp-suma)%p+p)%p]);
        }
        return (mini==n)?-1:mini;
    }
};