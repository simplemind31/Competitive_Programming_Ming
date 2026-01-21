#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool xd;
int n,a,con[2],res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a;
        con[a%2]++;
    }
    while(con[1]>=0){
        int a=con[0],b=con[1];
        if(b>a){
            if((b-a)%2==0){
                res=max(res,2*a);
            }else{
                a++;
                b-=2;
                if(b>a){
                    res=max(res,2*a);
                }else{
                    res=max(res,b+min(b+1,a));
                }
            }
        }else{
            res=max(res,b+min(b+1,a));
        }
        con[1]-=2;
        con[0]++;
    }
    cout << res;
}