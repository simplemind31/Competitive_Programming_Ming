#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int nums[n];
        vector<int> res;
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        bool xd=false;
        while(!xd){
            vector<bool> exis(n+1);
            int mex=0;
            for(int i=0;i<n;i++){
                exis[nums[i]]=true;
            }
            while(exis[mex])mex++;
            if(mex==n){
                xd=true;
                // cualquiera 
                for(int i=0;i<n && xd;i++){
                    if(nums[i]!=i){
                        xd=false;
                        res.push_back(i);
                        nums[i]=mex;
                    }
                }
            }else{
                res.push_back(mex);
                nums[mex]=mex;
            }
        }
        cout << res.size() << '\n';
        for(auto u:res)cout << u+1 << ' ';
        cout << '\n';
    }
}