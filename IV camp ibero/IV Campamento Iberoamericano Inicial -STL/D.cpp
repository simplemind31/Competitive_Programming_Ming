#include <bits/stdc++.h>
using namespace std;
int con[1000002],n,a,res;
int main(){
    cin >> n;
    while(n--){
        cin >> a;
        if(con[a+1]){
            con[a+1]--;
        }else{
            res++;
        }
        con[a]++;
    }
    cout << res;
}