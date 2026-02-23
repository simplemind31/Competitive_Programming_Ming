#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,k,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> m >> k;
        vector<int> nums;
        int suma=0;
        //5=101=100+001
        for(int i=0;i<5 && suma<=m;i++){
            if(k&(1<<i)){
                suma+=(1<<(1<<i))-1;
                nums.push_back((1<<(1<<i))-1);
            }
        }
        //10,1111
        //1^4=101=5
        if(suma>m){
            cout << "-1\n";
            continue;
        }
        if((m-suma)%2==1){
            if(suma+nums[0]<=m){
                suma+=nums[0];
                nums[0]*=2;
            }else if(suma+3<=m){
                nums.push_back(1);
                nums.push_back(2);
                suma+=3;
            }else{
                cout << "-1\n";
                continue;
            }
        }
        int can=(m-suma)/2;
        nums.push_back(can);
        nums.push_back(can);
        cout << nums.size() << '\n';
        for(auto u:nums)cout << u << ' ';
        cout << '\n';
    }
}