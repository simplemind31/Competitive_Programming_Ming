#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
int k;
double num=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> k;
    for(int i=1;1;i++){
        num+=1.0/i;
        if(num>k){
            cout << i;
            return 0;
        }
    }
}