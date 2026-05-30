#include <bits/stdc++.h>
using namespace std;
int n,a,b;
string x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> x >> y;
        if(y=="soft")a++;
        else b++;
    }
    if(a<b)swap(a,b);
    for(int i=1;1;i++){
        if(i&1){
            if((i*i+1)/2>=a && (i*i-1)/2>=b){
                cout << i;
                return 0;
            }
        }else{
            if(i*i/2>=a && i*i/2>=b){
                cout << i;
                return 0;
            }
        }
    }
}