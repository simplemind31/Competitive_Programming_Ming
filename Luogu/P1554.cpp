#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,con[10];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b;
    for(int i=a;i<=b;i++){
        int t=i;
        while(t){
            con[t%10]++;
            t/=10;
        }
    }
    for(int i=0;i<10;i++)cout << con[i] << ' ';
}