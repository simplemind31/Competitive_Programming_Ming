#include "boxes.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll dist(ll ini,ll fin,ll L){
    return min(abs(fin-ini),min(ini,fin)+L-max(ini,fin));
}
ll delivery(int N, int K, int L, int p[]){
    vector<ll> nums(p,p+N);
    sort(ALL(nums));
    reverse(ALL(nums));
    while(!nums.empty() && nums.back()==0)nums.pop_back();
    reverse(ALL(nums));
    if(nums.empty())return 0;
    N=nums.size();
    /*for(int i=0;i<N;i++){
        cout << nums[i] << ' ';
    }
    cout << endl;*/
    vector<ll> sum(K),p1(N),p2(N);
    for(int i=0;i<N;i++){
        p1[i]=sum[i%K];
        sum[i%K]+=2*nums[i];
    }
    reverse(ALL(p1));
    sum.assign(K,0);
    for(int i=0;i<N;i++){
        nums[i]=L-nums[i];
    }
    reverse(ALL(nums));
    for(int i=0;i<N;i++){
        p2[i]=sum[i%K];
        sum[i%K]+=2*nums[i];
    }
    ll res=1e18;
    for(int i=0;i<N-1;i++){
        res=min(res,p2[i]+nums[i]+p1[i+1]+L-nums[i+1]+dist(nums[i],0,L)+dist(nums[i+1],0,L));
    }
    /*for(int i=0;i<N;i++){
        cout << p1[i] << ' ';
    }
    cout << endl;
    for(int i=0;i<N;i++){
        cout << p2[i] << ' ';
    }
    cout << endl;
    cout << p1[0]+L-nums[0]+dist(L-nums[0],0,L) << ' ' << p2[N-1]+nums[N-1]+dist(nums[N-1],0,L) << '\n';*/
    return min(res,min(p1[0]+L-nums[0]+dist(L-nums[0],0,L),p2[N-1]+nums[N-1]+dist(nums[N-1],0,L)));
}