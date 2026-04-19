#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int j=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            while(j+1<m && nums2[j+1]>=nums1[i])j++;
            if(nums2[j]>=nums1[i])maxi=max(maxi,j-i);
        }
        return maxi;
    }
};