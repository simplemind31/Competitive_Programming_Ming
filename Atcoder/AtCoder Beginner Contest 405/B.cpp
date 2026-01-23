#include <bits/stdc++.h>
using namespace std;
int n,k,con[100],cont,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
        if(con[--nums[i]]++==0)cont++;
    }
    while(cont==k){
        if(con[nums.back()]--==1)cont--;
        nums.pop_back();
        res++;
    }
    cout << res;
}