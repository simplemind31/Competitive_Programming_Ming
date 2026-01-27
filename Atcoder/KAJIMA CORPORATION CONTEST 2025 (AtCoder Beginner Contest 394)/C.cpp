#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int con=0;
string st,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=0,n=st.size();i<n;i++){
        if(st[i]=='W')con++;
        else if(st[i]=='A'){
            res.push_back('A');
            res.append(con,'C');
            con=0;
        }else{
            res.append(con,'W');
            res.push_back(st[i]);
            con=0;
        }
    }
    res.append(con,'W');
    cout << res;
}