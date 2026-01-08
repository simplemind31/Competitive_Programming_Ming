#include <bits/stdc++.h>
using namespace std;
int t,n,maxi,lastmaxi;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        xd=true;
        cin >> n;
        vector<bool> used(n);
        vector<int> nums(n),pos(n);
        vector<pair<int,int>> res;
        for(int i=maxi=0;i<n;i++){
            cin >> nums[i];
            pos[--nums[i]]=i;
        }
        used[pos[lastmaxi=0]]=true;
        for(int j=pos[0]+1;j<n;j++){
            used[j]=true;
            res.push_back({0,nums[j]});
            lastmaxi=max(lastmaxi,nums[j]);
        }
        for(int i=1;i<n && xd;i++){
            if(!used[pos[i]]){
                used[pos[maxi=i]]=true;
                for(int j=pos[i]+1;!used[j];j++){
                    maxi=max(maxi,nums[j]);
                    used[j]=true;
                    res.push_back({i,nums[j]});
                }
                if(i<lastmaxi)res.push_back({i,lastmaxi});
                else xd=false;
                lastmaxi=max(lastmaxi,maxi);
            }
        }
        if(xd)cout << "YES\n";
        else cout << "NO\n";
    }
}
//5 3 6 1 4 2