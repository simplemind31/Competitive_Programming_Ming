#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        sort(ALL(hFences));
        sort(ALL(vFences));
        int a=hFences.size(),b=vFences.size(),maxi=-1,now;
        vector<int> nu1(a+1),nu2(b+1);
        nu1[0]=hFences[0]-1;
        for(int i=1;i<a;i++)nu1[i]=hFences[i]-hFences[i-1];
        nu1[a]=m-hFences.back();
        nu2[0]=vFences[0]-1;
        for(int i=1;i<b;i++)nu2[i]=vFences[i]-vFences[i-1];
        nu2[b]=n-vFences.back();
        m=a+1;
        n=b+1;
        unordered_map<int,bool> exist;
        for(int i=0;i<m;i++){
            now=0;
            for(int j=i;j<m;j++){
                now+=nu1[j];
                exist[now]=true;
            }
        }
        for(int i=0;i<n;i++){
            now=0;
            for(int j=i;j<n;j++){
                if((now+=nu2[j])<=maxi)continue;
                if(exist[now])maxi=max(maxi,now);
            }
        }
        if(maxi==-1)return -1;
        return 1LL*maxi*maxi%1000000007;
    }
};