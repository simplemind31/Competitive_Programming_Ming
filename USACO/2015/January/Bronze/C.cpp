#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll t,n1,n2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("whatbase.in","r",stdin);
    freopen("whatbase.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n1 >> n2;
        for(ll y=10;y<=15000;y++){
            ll temp=n2,sum=0,po=1;
            for(int i=0;i<3;i++){
                sum+=(temp%10)*po;
                temp/=10;
                po*=y;
            }
            ll dig[3];
            temp=n1;
            for(int i=2;i>=0;i--){
                dig[i]=temp%10;
                temp/=10;
            }
            dig[2]-=sum;
            if(dig[1]*dig[1]-4*dig[0]*dig[2]<0)continue;
            ll x=(-dig[1]+sqrtl(dig[1]*dig[1]-4*dig[0]*dig[2]))/(2*dig[0]);
            dig[2]+=sum;
            if(x>=10 && dig[0]*x*x+dig[1]*x+dig[2]==sum){
                cout << x << ' ' << y << '\n';
                break;
            }
        }
    }
}