#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int n;
bool task2=true;
ll maxi,suma;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll a[n],k[n],x[n];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> k[i];
    for(int i=0;i<n;i++)cin >> x[i];
    if(n<=5000){
        for(int i=0;i<n;i++){
            ll suma=0,con=k[i];
            for(int j=i;j<n;j++){
                suma+=a[j];
                if(con){
                    con--;
                    suma+=x[i];
                }
                maxi=max(maxi,suma);
            }
        }
        cout << maxi;
        return 0;
    }
    for(int i=0;i<n;i++){
        suma=max(suma+a[i],a[i]);
        maxi=max(maxi,suma);
    }
    cout << maxi;
    return 0;
}