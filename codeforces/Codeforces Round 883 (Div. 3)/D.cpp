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
int n,t,d,h;
long double area;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> d >> h;
        area=0;
        int nums[n];
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        area+=(long double)n*d*h/2;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]<h){
                area-=(long double)(nums[i]+h-nums[i+1])*(nums[i]+h-nums[i+1])*d/(2*h);
            }
        }
        cout << fixed << setprecision(12) << area << '\n';
    }
}