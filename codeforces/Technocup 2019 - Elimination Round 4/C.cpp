#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int x[3],y[3],medx,medy,tex[3],tey[3];
set<pair<int,int>> res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<3;i++){
        cin >> x[i] >> y[i];
        tex[i]=x[i];
        tey[i]=y[i];
    }
    sort(tex,tex+3);
    sort(tey,tey+3);
    medx=tex[1];
    medy=tey[1];
    res.insert({medx,medy});
    for(int i=0;i<3;i++){
        // encajar primero y luego x
        int tempx=medx,tempy=medy;
        while(tempy>y[i]){
            tempy--;
            res.insert({tempx,tempy});
        }
        while(tempy<y[i]){
            tempy++;
            res.insert({tempx,tempy});
        }
        while(tempx>x[i]){
            tempx--;
            res.insert({tempx,tempy});
        }
        while(tempx<x[i]){
            tempx++;
            res.insert({tempx,tempy});
        }
    }
    cout << res.size() << '\n';
    for(auto u:res){
        cout << u.first << ' ' << u.second << '\n';
    }
}


/*
*********
****A****
****.*C**
**B******
*********
*********



*********
****A****
*********
**B*.****
******C**
*********
*/