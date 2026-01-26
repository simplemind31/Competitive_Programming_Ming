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
bool unlock[200002];
int n,x,con,tem;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> x;
    //xtiene que abrir x para ir a iz, abrir x+1 para ir a x+1;
    bool nums[n+2];
    nums[0]=0;
    nums[n+1]=0;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
    }
    for(int i=1;i<=n;i++){
        unlock[i]=(!nums[i])||unlock[i-1];
    }
    while(x>1){
        if(unlock[x-1]){
            if(nums[x])con++;
            nums[x]=0;
            x--;
        }else{
            break;
        }
    }
    //cout << x << ' ' << con << ' ';
    while(x<=n){
        if(!nums[x] && x!=0){
            con++;
            con+=tem;
            tem=0;
        }
        nums[x]=true;
        if(nums[x+1])tem+=2;
        x++;
    }
    cout << con;
}