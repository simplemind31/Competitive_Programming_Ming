#include <bits/stdc++.h>
using namespace std;
int t,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(c==0){
            cout << "-1\n";
            continue;
        }
        if(!a){
            if(c>1){
                cout << "-1\n";
            }else{
                cout << b+c-1 << '\n';
            }
            continue;
        }
        int canlibre=2,level=0;
        a--;
        while(a>=canlibre){
            a-=canlibre;
            canlibre*=2;
            level++;
        }
        int nextcanti=canlibre;
        if(a){
            level++;
            canlibre-=a;
            nextcanti+=a;
            if(c!=nextcanti){
                cout << "-1\n";
                continue;
            }
            if(b>=canlibre){
                b-=canlibre;
                if(b){
                    level+=(b-1)/nextcanti+1;
                }
                level++;
                cout << level << '\n';
            }else{
                level++;
                cout << level << '\n';
            }
        }else if(b){
            if(c!=canlibre){
                cout << "-1\n";
                continue;
            }
            level+=(b-1)/nextcanti+1;
            level++;
            cout << level << '\n';
        }else if(c==canlibre){
            level++;
            cout << level << '\n';
        }else{
            cout << "-1\n";
        }
    }
}