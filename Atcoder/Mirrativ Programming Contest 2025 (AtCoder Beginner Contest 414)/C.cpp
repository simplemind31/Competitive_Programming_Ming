#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,n,tem,tam,suma;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> n;
    tem=n;
    while(tem){
        tam++;
        tem/=10;
    }
    ll ta=powl(10,(tam+1)/2);
    for(int i=0;i<1000000;i++){
        ll num=i,tem=i,cop;
        while(tem){
            num*=10;
            num+=tem%10;
            tem/=10;
        }
        if(num>n)break;
        // convert num to a base
        cop=num;
        vector<int> abase;
        while(num){
            abase.push_back(num%a);
            num/=a;
        }
        vector<int> rev=abase;
        reverse(rev.begin(),rev.end());
        if(abase==rev){
            suma+=cop;
        }
    }
    for(int i=0;i<100000;i++){
        for(int j=0;j<10;j++){
            ll num=i,tem=i,cop;
            num*=10;
            num+=j;
            while(tem){
                num*=10;
                num+=tem%10;
                tem/=10;
            }
            if(num>n)break;
            // convert num to a base
            cop=num;
            vector<int> abase;
            while(num){
                abase.push_back(num%a);
                num/=a;
            }
            vector<int> rev=abase;
            reverse(rev.begin(),rev.end());
            if(abase==rev){
                suma+=cop;
            }
        }
    }
    cout << suma;
}