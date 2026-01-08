#include <bits/stdc++.h>
using namespace std;
int t,n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        int mini=1e9;
        cin >> n >> m;
        vector<int> nums(n);
        vector<int> con(m+1);
        int canti0=m;
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        sort(nums.begin(),nums.end());
        int l=0,r=0;
        while(r<n){
            int i=sqrt(nums[r]);
            while(i>0){
                if(nums[r]%i==0){
                    if(i<=m){
                        if(con[i]==0)canti0--;
                        con[i]++;
                    }
                    if(nums[r]/i<=m){
                        if(con[nums[r]/i]==0)canti0--;
                        con[nums[r]/i]++;
                    }
                }
                i--;
            }
            while(canti0==0){
                mini=min(nums[r]-nums[l],mini);
                i=sqrt(nums[l]);
                while(i>0){
                    if(nums[l]%i==0){
                        if(i<=m){
                            con[i]--;
                            if(con[i]==0)canti0++;
                        }
                        if(nums[l]/i<=m){
                            con[nums[l]/i]--;
                            if(con[nums[l]/i]==0)canti0++;
                        }
                    }
                    i--;
                }
                l++;
            }
            r++;
        }
        if(mini==1e9){
            cout << "-1\n";
        }else{
            cout << mini << '\n';
        }
    }
}