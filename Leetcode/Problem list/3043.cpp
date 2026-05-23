#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
class Solution {
public:
    bitset<10000000> exis;
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2){
        int n=arr1.size(),m=arr2.size(),power[9],m8;
        power[0]=1;
        for(int i=1;i<=8;i++)power[i]=power[i-1]*10;
        bool xd=false;
        // si hay 2 1e8 entonces res=9
        // todos los demás son de tamaño <=8
        vector<int> a8,b8;
        for(int i=0;i<n;i++){
            if(arr1[i]==power[8]){
                xd=true;
                arr1[i]/=100;
            } else if(arr1[i]>=power[7]){
                //100000000
                // tiene tamaño 8
                a8.push_back(arr1[i]);
                arr1[i]/=10;
            }
        }
        for(int i=0;i<m;i++){
            if(arr2[i]==power[8]){
                if(xd)return 9;
                arr2[i]/=100;
            }else if(arr2[i]>=power[7]){
                //100000000
                // tiene tamaño 8
                b8.push_back(arr2[i]);
                arr2[i]/=10;
            }
        }
        m8=b8.size();
        sort(ALL(a8));
        for(int i=0;i<m8;i++)if(binary_search(ALL(a8),b8[i]))return 8;
        short l=0,r=7;
        while(l<r){
            short mid=(l+r+1)>>1;
            bool xd=false;
                for(int j=0;j<n;j++){
                    int x=arr1[j];
                    while(x>=power[mid])x/=10;
                    if(x>=power[mid-1])exis[x]=true;
                }
                for(int j=0;j<m && !xd;j++){
                    int x=arr2[j];
                    while(x>=power[mid])x/=10;
                    if(x>=power[mid-1])if(exis[x])xd=true;
                }
            if(xd)l=mid;
            else r=mid-1;
        }
        return l;
    }
};