#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,q,t,x,y,rot;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    int nums[n];
    for(int i=0;i<n;i++){
        nums[i]=i+1;
    }
    while(q--){
        cin >> t;
        if(t==1){
            cin >> x >> y;
            x--;
            nums[(x+rot)%n]=y;
        }else if(t==2){
            cin >> x;
            x--;
            cout << nums[(x+rot)%n] << '\n';
        }else{
            cin >> x;
            rot=(rot+x)%n;
        }
    }
}