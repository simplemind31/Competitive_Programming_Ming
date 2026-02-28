#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int j,cani,canj,n;
ll x,res,sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> x;
    int days[n];
    for(int i=0;i<n;i++)cin >> days[i];
    while(days[j]<=x){
        sum+=1ll*(1+days[j])*days[j]/2;
        x-=days[j];
        if(++j==n)j=0;
    }
    // usar lo que hay para j
    // queda x-candia dias;
    sum+=1ll*(canj+1+canj+x)*x/2;
    canj+=x;
    res=max(res,sum);
    //cout << res << '\n';
    for(int i=0;i<n;i++){
        // del dia i al dia j
        //tengo que quitar i para que entre j
        // hasta que llene dia j
        // necesito days[j]-canj dias para completar
        // tengo day[i]-cani para quitar;
        int canposi=min(days[j]-canj,days[i]-cani);
        sum+=1ll*(canj+1+canj+canposi)*canposi/2;
        sum-=1ll*(cani+1+cani+canposi)*canposi/2;
        if((cani+=canposi)<days[i])i--;
        else cani=0;
        if((canj+=canposi)==days[j]){
            canj=0;
            if(++j==n)j=0;
        }
        res=max(res,sum);
    }
    cout << res;
}