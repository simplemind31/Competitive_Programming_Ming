#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,q;
ll a,b;
vector<ll> iz,de,nums;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    nums.resize(n);
    de=iz=nums;
    for(int i=0;i<n;i++)cin >> nums[i];
    sort(ALL(nums));
    for(int i=1;i<n;i++)iz[i]=iz[i-1]+i*(nums[i]-nums[i-1]);
    for(int i=n-2;i>=0;i--)de[i]=de[i+1]+(n-1-i)*(nums[i+1]-nums[i]);
    cin >> q;
    while(q--){
        cin >> a >> b;
        if(a<=b){
            /*
            supongamos que la respuesta es pos
            necesitamos min(a*iz[pos]+b*de[pos])
            como a<=b enonces iz[pos]>=de[pos]
            enotonces si pos aumenta 1 a*(iz[pos]+(pos+1))+b(de[pos]-(n-pos))
            a*iz[pos]+a*pos+a+b*de[pos]-n*b+pos
            1 2 3 6 7
            9 4 2 1 1
            46,22,13,11,12
            1,5,
            */
        }
    }
}