#include <bits/stdc++.h>
using namespace std;
int n,m,a;
vector<int> con[1500000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a;
        con[a].push_back(i);
    }
    for(int i=0;i<n;i++){
        int last=-1;
        for(int u:con[i]){
            if(u-m>last){
                cout << i;
                return 0;
            }
            last=u;
        }
        if(last+m-1<n-1){
            cout << i;
            return 0;
        }
    }
    cout << n;
    return 0;
}