#include <bits/stdc++.h>
using namespace std;
int n,m,a;
unordered_map<int, vector<int>> con;
int main(){
    freopen("ca1.in","r",stdin);
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
            last=u+m-1;
        }
        if(last<n-1){
            cout << i;
            return 0;
        }
    }
    cout << n;
    return 0;
}
