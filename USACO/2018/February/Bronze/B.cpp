#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie();
    freopen("hoofball.in","r",stdin);
    freopen("hoofball.out","w",stdout);
    cin >> n;
    bool une[n+2];
    int nums[n+2];
    for(int i=1;i<=n;i++){
        une[i]=0;
        cin >> nums[i];
    }
    nums[0]=-1e9;
    nums[n+1]=1e9;
    sort(nums,nums+(n+2));
    for(int i=1;i<=n;i++){
        if(nums[i]-nums[i-1]<=nums[i+1]-nums[i])une[i-1]=true;
        else une[i]=true;
    }
    vector<pair<int,int>> comp;
    int last=1;
    for(int i=1;i<=n;i++){
        if(une[i])continue;
        comp.push_back({last,i});
        last=i+1;
    }
    for(auto u:comp){
        if(nums[u.first+1]-nums[u.first]<nums[u.first]-nums[u.first-1] && nums[u.second]-nums[u.second-1]<nums[u.second-1]-nums[u.second-2]){
            con+=1;
        }else if(nums[u.first+1]-nums[u.first]<=nums[u.first+2]-nums[u.first+1] && nums[u.second]-nums[u.second-1]<=nums[u.second+1]-nums[u.second]){
            con+=1;
        }else{
            con+=2;
        }
    }
    cout << con;
}