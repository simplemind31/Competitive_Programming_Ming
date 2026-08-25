#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int t=1,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n),b(n);
        int cona=0,conb=0,con01=0,con10=0,con00=0,con11=0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            cona+=a[i];
        }
        // los 0 en a no cambian nada
        for(int i=0;i<n;i++){
            cin >> b[i];
            conb+=b[i];
            if(b[i]==a[i]){
                if(a[i])con11++;
                else con00++;
                continue;
            }
            if(!a[i])con01++;
            else con10++;
        }
        if(con10+con01==0){
            cout << "0\n";
            continue;
        }
        if(con10==0){
            // arreglar todos los 01 y usar un 00 para intermedio un 11
            if(con00 && con11){
                cout << "2\n";
                continue;
            }else{
                cout << "-1\n";
                continue;
            }
            // entonces habra un nuevo 01 y todos los demas estan arreglados
        }
        if(con10&1)cout << "1\n";
        else cout << "2\n";
    }
}
/*
10001
10111

10110
10111
*/