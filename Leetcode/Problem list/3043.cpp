#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2){
        int n=arr1.size(),m=arr2.size(),power[10];
        vector<int> con2;
        power[0]=1;
        for(int i=1;i<=9;i++)power[i]=power[i-1]*10;
        short l=0,r=9;
        while(l<r){
            short mid=(l+r+1)>>1;
            bool xd=false;
            for(int j=0;j<n;j++){
                int a=arr1[j];
                while(a>=power[mid])a/=10;
                if(a>=power[mid-1])con2.push_back(a);
            }
            sort(ALL(con2));
            for(int j=0;j<m && !xd;j++){
                int a=arr2[j];
                while(a>=power[mid])a/=10;
                if(a>=power[mid-1]){
                    if(binary_search(ALL(con2),a))xd=true;
                }
            }
            con2.clear();
            if(xd)l=mid;
            else r=mid-1;
        }
        return l;
    }
};