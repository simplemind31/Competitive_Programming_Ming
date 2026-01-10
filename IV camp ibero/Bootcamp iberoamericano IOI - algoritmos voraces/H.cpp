#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,nums[200000],pos[200000],l,r,con,i,mex;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(i=con=mex=0;i<n;i++){
            cin >> nums[i];
            pos[nums[i]]=i;
        }
        l=r=pos[0];
        while(l!=0 || r!=n-1){
            if(mex<n && l<=pos[mex] && pos[mex]<=r){
                mex++;
                continue;
            }
            if(2*mex<r-l+1){
                //extender
                if(r<pos[mex]){
                    r=pos[mex];
                }else{
                    l=pos[mex];
                }
                continue;
            }
            con++;
            if(r<pos[mex]){
                //extender progresivamente a la derecha
                //cuantos a la izquierda puedo extender?
                con+=min(2*mex-(r-l+1),l);
                r++;
            }else{
                con+=min(2*mex-(r-l+1),n-r-1);
                l--;
            }
        }
        cout << con+1 << '\n';
    }
}