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

int t,n,m,aux;
int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);*/
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        //vi arr(n);
        ll sum=0;
        vi ceros(n);
        for(int i=0;i<n;i++){
            scanf("%d",&aux);
            int can=0;
            bool xd=true;
            int digi=0;
            while(aux>0){
                int res=aux%10;
                aux/=10;
                if(res==0 && xd){
                    can++;
                }else{
                    xd=false;
                }
                digi++;
            }
            sum+=digi;
            ceros[i]=can;
        }
        //printf("%d ",sum);
        sort(ceros.rbegin(),ceros.rend());
        for(int i=0;i<n;i++){
            if(i%2==0){
                sum-=ceros[i];
            }
        }
        if(sum>m){
            printf("Sasha\n");
        }else{
            printf("Anna\n");
        }
    }
}