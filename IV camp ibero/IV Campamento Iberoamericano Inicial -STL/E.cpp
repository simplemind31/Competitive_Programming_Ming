#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,m,n,canti,a,R;
char c;
int main(){
    cin >> l >> n >> m;
    canti=n+1;
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin >> c >> a;
        if(c=='R')a=l;
        nums.push_back(a);
    }
    sort(nums.begin(),nums.end());
    while(m--){
        cin >> c >> a;
        if(c=='L')a=0;
        //cauntos estrictamente derecha?
        int de=(nums.size()-1)-(upper_bound(nums.begin(),nums.end(),a)-nums.begin())+1;
        canti+=de+1;
    }
    cout << canti;
}