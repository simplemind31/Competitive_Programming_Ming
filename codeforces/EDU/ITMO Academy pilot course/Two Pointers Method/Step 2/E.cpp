#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> s;
    ll j=0,nums[n],can=0,tam=0;
    map<int,int> cont;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        while(cont[nums[i]]==0 && tam==s){
            if(--cont[nums[j++]]==0)tam--;
        }
        if(cont[nums[i]]++==0)tam++;
        can+=i-j+1;
    }
    cout << can;
}