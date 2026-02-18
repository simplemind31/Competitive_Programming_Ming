#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,con,exis[20001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
        exis[nums[i]]++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(exis[nums[i]+nums[j]]){
                con++;
                exis[nums[i]+nums[j]]--;
            }
        }
    }
    cout << con;
}