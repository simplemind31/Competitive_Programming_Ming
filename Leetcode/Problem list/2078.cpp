#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& colors){
        int n=colors.size(),maxi=0;
        for(int i=0;i<n-maxi;i++){
            for(int j=n-1;j>i;j--){
                if(colors[i]!=colors[j]){
                    maxi=max(maxi,j-i);
                }
            }
        }
        return maxi;
    }
};