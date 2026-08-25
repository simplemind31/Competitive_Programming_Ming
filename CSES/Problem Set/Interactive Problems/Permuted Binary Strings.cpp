#include <bits/stdc++.h>
using namespace std;
int n;
string ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> res(n);
    for(int i=0;(1<<i)<=n;i++){
        cout << "? ";
        for(int j=1;j<=n;j++){
            if(j&(1<<i))cout << 1;
            else cout << 0;
        }
        cout << '\n';
        cout.flush();
        cin >> ans;
        for(int j=0;j<n;j++){
            res[j]+=(ans[j]=='1')<<i;
        }
    }
    cout << "! ";
    for(int i=0;i<n;i++)cout << res[i] << ' ';
    cout.flush();
}