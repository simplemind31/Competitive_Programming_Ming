#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,k;
string st;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> k >> st;
        vector<int> con(26);
        int now=0,suma=0,tot=0;
        for(auto u:st)con[u-'a']++;
        for(int i=0;i<26 && now<k;i++){
            if(con[i]&1){
                con[i]--;
                now++;
            }
        }
        //hay now con 1 y k-now con 0
        //por cada k pares suben a 1+2*(suma/k),s*(suma/k); si hay sobra al
        for(int i=0;i<26;i++){
            tot+=(con[i]&1);
            suma+=con[i]/2;
        }
        int can1=1+((int)(suma/k))*2;
        int can2=((int)(suma/k))*2;
        suma%=k;
        //sobra 2*suma+tot
        if(2*suma+tot>=k-now){
            cout << can1 << '\n';
        }else{
            cout << can2 << '\n';
        }
    }
}