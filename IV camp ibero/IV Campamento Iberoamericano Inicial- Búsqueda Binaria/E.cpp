#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,L,mini=1e18,maxi,countmid,countmid1,countamb,res;
bool xd=true;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    cin >> N >> L;
    vector<pair<ll,ll>> nums(N);
    for(int i=0;i<N;i++){
        cin >> nums[i].first >> nums[i].second;
        mini=min(mini,nums[i].second);
        maxi=max(maxi,nums[i].first);
    }
    for(int i=0;i<N;i++){
        if(nums[i].first<=L/N && L/N+1<=nums[i].second){
            countamb++;
        }else if(nums[i].first<=L/N && L/N<=nums[i].second){
            countmid++;
        }else if(nums[i].first<=L/N+1 && L/N+1<=nums[i].second){
            countmid1++;
        }else{
            xd=false;
            break;
        }
    }
    if(xd){
        //necesito L%N countmid1
        if(countmid1<=L%N && L%N<=countmid1+countamb){
            if(L%N)cout << 1;
            else cout << 0;
            return 0;
        }
    }
    //suppose max limita
    // el resto o max o menor
    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r)>>1;
        ll miniposi=0,maxiposi=0;
        // entre max-mid y max
        xd=true;
        for(int i=0;i<N;i++){
            if(nums[i].second<maxi-mid || maxi<nums[i].first){
                xd=false;
                break;
            }
            miniposi+=max(maxi-mid,nums[i].first);
            maxiposi+=min(maxi,nums[i].second);
        }
        if(xd && miniposi<=L && L<=maxiposi){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    res=l;
    // min limita
    // el resto o min o mayor
    l=0,r=1e9;
    while(l<r){
        int mid=(l+r)>>1;
        ll miniposi=0,maxiposi=0;
        // entre min y min+mid
        xd=true;
        for(int i=0;i<N;i++){
            if(nums[i].second<mini|| mini+mid<nums[i].first){
                xd=false;
                break;
            }
            miniposi+=max(mini,nums[i].first);
            maxiposi+=min(mini+mid,nums[i].second);
        }
        if(xd && miniposi<=L && L<=maxiposi){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    res=min(res,(ll)l);
    cout << res;
}