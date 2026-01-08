#include <bits/stdc++.h>
using namespace std;
int t,n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> con(n);
        for(int i=0;i<n;i++){
            cin >> a;
            con[--a]++;
        }
        vector<int> nums,nue;
        for(int i=0;i<n;i++){
            if(con[i])nums.push_back(con[i]);
        }
        n=nums.size();
        sort(nums.begin(),nums.end());
        nue.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1])nue.push_back(nums[i]);
        }
        swap(nums,nue);
        n=nums.size();
        /*for(int i=0;i<n;i++){
            cout << nums[i] << ' ';
        }*/
        //cout << endl;
        for(int i=nums[0]+1;i>=1;i--){
            bool lol=true;
            for(int j=0;j<n && lol;j++){
                if(nums[j]%i &&  nums[j]/i+nums[j]%i<i-1)lol=false;
            }
            if(lol){
                int res=0;
                for(int j=0;j<nue.size();j++){
                    res+=(nue[j]-1)/i+1;
                }
                //cout << i << ' ';
                cout << res << '\n';
                break;
            }
        }
        /*
        s=size;
        => nums[i]/s+nums[i]%s>=s-1
        10
        */
    }
}