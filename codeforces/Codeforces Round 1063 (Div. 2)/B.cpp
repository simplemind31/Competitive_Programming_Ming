#include <bits/stdc++.h>
using namespace std;
int t,n,pos1,posn;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
            if(nums[i]==n)posn=i;
            if(nums[i]==1)pos1=i;
        }
        cin >> st;
        if(st[0]-48+st.back()-48+st[pos1]-48+st[posn]-48){
            cout << -1 << '\n';
            continue;
        }
        cout << "5\n";
        cout << 1 << ' ' << pos1+1 << '\n';
        cout << 1 << ' ' << posn+1 << '\n';
        cout << pos1+1 << ' ' << n << '\n';
        cout << posn+1 << ' ' << n << '\n';
        cout << min(pos1,posn)+1 << ' ' << max(pos1,posn)+1 << '\n';
    }
}