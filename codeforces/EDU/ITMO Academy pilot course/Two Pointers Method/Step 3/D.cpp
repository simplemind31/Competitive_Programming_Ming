#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n[4],pos[4],res=1e9,resp[4];
vector<int> nums[4];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<4;i++){
        cin >> n[i];
        nums[i].resize(n[i]);
        for(int j=0;j<n[i];j++){
            cin >> nums[i][j];
        }
        sort(ALL(nums[i]));
    }
    bool xd=true;
    while(xd){
        int mini=1e9,maxi=0;
        for(int i=0;i<4;i++){
            mini=min(mini,nums[i][pos[i]]);
            maxi=max(maxi,nums[i][pos[i]]);
        }
        if(res>maxi-mini){
            res=maxi-mini;
            for(int i=0;i<4;i++){
                resp[i]=pos[i];
            }
        }
        xd=false;
        for(int i=0;i<4;i++){
            if(nums[i][pos[i]]==mini && pos[i]+1<n[i]){
                pos[i]++;
                xd=true;
            }
        }
    }
    for(int i=0;i<4;i++)cout << nums[i][resp[i]] << ' ';
}