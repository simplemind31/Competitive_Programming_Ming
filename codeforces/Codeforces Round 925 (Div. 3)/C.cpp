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

int t,n,x;
int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);*/
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int maxi=1;
        bool xd=true;
        vi nums(n);
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
        }
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                maxi++;
            }else{
                break;
            }
        }
        int con=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==nums[i+1]){
                con++;
            }else{
                break;
            }
        }
        if(nums[0]==nums[n-1]){
            maxi+=con;
        }
        maxi=max(maxi,con);
        if(n-maxi<=0){
            printf("0\n");
        }else{
            printf("%d\n",n-maxi);
        }
    }
}