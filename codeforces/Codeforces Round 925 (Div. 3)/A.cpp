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

int t,a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a;
        char ca='a';
        if(a-52<=1){
            a--;
            cout << "a";
        }else{
            a-=52;
            ca=96+a;
            a=52;
            cout << ca;
        }
        if(a-26<=1){
            a--;
            cout << "a";
        }else{
            a-=26;
            ca=96+a;
            a=26;
            cout << ca;
        }
        ca=96+a;
        cout << ca << "\n";
    }
}