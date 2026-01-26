#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(b>=min(a,c)){
            cout << min(a,c) << '\n';
        }else{
            a-=b;
            c-=b;
            int con=b;
            int temp=abs(a-c);
            if(temp>=min(a,c)){
                con+=min(a,c);
            }else{
                con+=temp;
                if(a>c){
                    a-=2*temp;
                    c-=temp;
                }else{
                    c-=a*temp;
                    a-=temp;
                }
                //cada 33 sumo 2;
                con+=((int)(a/3))*2;
                a%=3;
                if(a==2)con++;
            }
            cout << con << '\n';

        }
    }
}