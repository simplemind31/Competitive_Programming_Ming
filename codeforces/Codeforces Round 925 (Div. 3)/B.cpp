#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define MOD 1000000007
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FIN "\n"
#define REP(i,a,b) for(int i=a;i<b;i++)
#define ALL(x) x.begin(),x.end()
#define LSOne(x) (x)&-(x)
typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<long long> vll;

int t,n;
int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);*/
    scanf("%d",&t);
    while(t--){
        bool xd=true;
        ll sum=0;
        scanf("%d",&n);
        vi agua(n);
        for(int i=0;i<n;i++){
            scanf("%d",&agua[i]);
            sum+=agua[i];
        }
        sum/=n;
        int res=0;
        for(int i=0;i<n;i++){
            if(agua[i]<sum){
                if(agua[i]+res<sum){
                    xd=false;
                    break;
                }else{
                    res-=sum-agua[i];
                }
            }else{
                res+=agua[i]-sum;
            }
        }
        if(xd){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}