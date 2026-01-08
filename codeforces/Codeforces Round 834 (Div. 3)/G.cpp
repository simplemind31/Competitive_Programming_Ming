#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> res(n,-1);
        vector<bool> usado(n);
        bool xd=true;
        for(int i=1;i<n;i+=2){
            cin >> res[i];
            if(usado[--res[i]])xd=false;
            usado[res[i]]=true;
        }
        if(!xd){
            cout << "-1\n";
            continue;
        }
        set<int> dispon;
        for(int i=0;i<n;i++){
            if(!usado[i])dispon.insert(i);
        }
        for(int i=n-1;i>=0;i-=2){
            auto p=dispon.lower_bound(res[i]);
            if(p==dispon.begin()){
                xd=false;
                break;
            }
            p--;
            res[i-1]=*p;
            dispon.erase(p);
        }
        if(!dispon.empty() && !xd){
            cout << "-1\n";
        }else{
            for(int i=0;i<n;i++){
                cout << res[i]+1 << ' ';
            }
            cout << '\n';
        }
    }
}