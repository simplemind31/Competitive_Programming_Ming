#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,cona,conb,maxi,j;
ll c,now;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> c >> st;
    for(int i=0;i<n;i++){
        cin >> st[i];
        if(st[i]=='b'){
            now+=cona;
            conb++;
        }else if(st[i]=='a')cona++;
        while(now>c){
            if(st[j]=='a'){
                now-=conb;
                cona--;
            }else if(st[j]=='b')conb--;
            j++;
        }
        maxi=max(maxi,i-j+1);
    }
    cout << maxi;
}