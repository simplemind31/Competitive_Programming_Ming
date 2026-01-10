#include <bits/stdc++.h>
using namespace std;
bool xd=false;
int n,k,con,con2,psum[3000000],revclave[3000000],iz=-1,de=-1;
pair<int,int> nums[1000000],res[3000000],nue[3000000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
        res[con++]={nums[i].first,0};
        res[con++]={nums[i].second,0};
        res[con++]={nums[i].second,1};
    }
    sort(res,res+con);
    nue[con2++]=res[0];
    for(int i=1;i<con;i++)if(res[i]!=res[i-1])nue[con2++]=res[i];
    for(int i=con=0;i<con2;i++)revclave[con++]=nue[i].first;
    for(int i=0;i<n;i++){
        psum[lower_bound(nue,nue+con2,make_pair(nums[i].first,0))-nue]++;
        psum[lower_bound(nue,nue+con2,make_pair(nums[i].second,1))-nue]--;
    }
    for(int i=1;i<con2;i++)psum[i]+=psum[i-1];
    for(int i=con=0;i<con2;i++){
        if(psum[i]>=k){
            if(!xd)iz=i;
            de=i;
            xd=true;
        }else if(xd){
            res[con++]={iz,de};
            iz=de=-1;
            xd=!xd;
        }
    }
    if(iz!=-1)res[con++]={iz,de};
    cout << con << '\n';
    for(int i=0;i<con;i++)cout << revclave[res[i].first] << ' ' << revclave[res[i].second] << '\n';
}