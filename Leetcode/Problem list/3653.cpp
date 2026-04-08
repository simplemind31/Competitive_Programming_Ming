#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int bigmod(int b,int e){
    int p=1;
    while(e){
        if(e&1)p=1ll*p*b%MOD;
        b=1ll*b*b%MOD;
        e>>=1;
    }
    return p;
}
int inversemod(int b){return bigmod(b,MOD-2);}
class Solution{
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries){
        int n=nums.size(),raiz=sqrt(n),q=queries.size();
        vector<vector<vector<int>>> nueque(raiz); 
        for(auto _:queries){
            int l=_[0],r=_[1],k=_[2],v=_[3];
            if(k>=raiz){
                for(int i=l;i<=r;i+=k)nums[i]=1ll*nums[i]*v%MOD;
                continue;
            }
            int temp=r-(r-l)%k+k;
            nueque[k].push_back({l,temp,v});
        }
        for(int k=1;k<raiz;k++){
            vector<int> psum(n,1);
            for(auto u:nueque[k]){
                psum[u[0]]=1ll*psum[u[0]]*u[2]%MOD;
                if(u[1]<n)psum[u[1]]=1ll*psum[u[1]]*inversemod(u[2])%MOD;
            }
            for(int i=k;i<n;i++){
                psum[i]=1ll*psum[i]*psum[i-k]%MOD;
            }
            for(int i=0;i<n;i++)nums[i]=1ll*nums[i]*psum[i]%MOD;
        }
        int x=0;
        for(int i=0;i<n;i++){
            x^=nums[i];
        }
        return x;
    }
};