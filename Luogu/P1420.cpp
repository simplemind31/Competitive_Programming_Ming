#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,last,now,con,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> last;
    maxi=con=1;
    while(n--){
        cin >> now;
        if(now==last+1)con++;
        else{
            maxi=max(maxi,con);
            con=1;
        }
        last=now;
    }
    maxi=max(maxi,con);
    cout << maxi;
}