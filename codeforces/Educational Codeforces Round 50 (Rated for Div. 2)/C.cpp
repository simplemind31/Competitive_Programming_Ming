#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,b,combi[20][20],power[5][20];
ll solve(string x){
    vector<bool> usado(10);
    int cantiusado=0;
    ll res=0;
    for(int i=0,tam=x.size();i<tam && cantiusado<=3;i++){
        cout << i << ":\n";
        for(int j=0;j<x[i]-'0';j++){
            int canti=cantiusado+(j&&(!usado[j]));
            ll elegir0=0,elegir1=0,elegir2=0,elegir3=0;
            if(canti>=4)continue;
            // hay espacio suficiente para elegir x?
            if(canti<=3)elegir0=power[canti+1][tam-i-1];
            if(canti<=2 && tam-i-1>=1)elegir1=power[canti+2][tam-i-1]-elegir0;
            if(canti<=1 && tam-i-1>=2)elegir2=power[canti+3][tam-i-1]-elegir0-2*elegir1;
            if(canti<=0 && tam-i-1>=3)elegir3=power[canti+4][tam-i-1]-elegir0-3*elegir1-3*elegir2;
            res+=elegir0+combi[9-canti][1]*elegir1+combi[9-canti][2]*elegir2+combi[9-canti][3]*elegir3;
            cout << j << ' ' << elegir0 << ' ' << combi[9-canti][1]*elegir1 << ' ' << combi[9-canti][2]*elegir2 << ' ' << combi[9-canti][3]*elegir3 << '\n';
        }
        cantiusado+=((x[i]-'0')&&(!usado[x[i]-'0']));
        usado[x[i]-'0']=true;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<=4;i++)power[i][0]=1;
    for(int i=0;i<=4;i++){
        for(int j=1;j<20;j++){
            power[i][j]=power[i][j-1]*i;
        }
    }
    for(int i=0;i<20;i++){
        combi[i][i]=combi[i][0]=1;
        for(int j=1;j<i;j++){
            combi[i][j]=combi[i-1][j]+combi[i-1][j-1];
        }
    }
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << solve(to_string(b+1)) << '\n';// << ' ' << solve(to_string(a)) << '\n';
        //cout << solve(to_string(b+1))-solve(to_string(a)) << '\n';
    }
}
/*
1001 1
1025 1024
6461 6461
15852 15850
*/

/*#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

long long C[20][20];
long long pw[4];

long long cnk(int n, int k){
    if (k < 0 || k > n) return 0;
    return C[n][k];
}

long long get(int n, int lft){
    long long tot = 0;
    forn(i, lft + 1)
        tot += cnk(n, i) * pw[i];
    return tot;
}

long long calc(long long x){
    string s = to_string(x);
    
    long long res = 0;
    int cur = 3;
    int n = s.size();
    
    forn(i, n){
        if (s[i] == '0') continue;
        res += get(n - i - 1, cur);
        --cur;
        if (cur == -1) break;
        res += get(n - i - 1, cur) * (s[i] - '1');
    }
    
    return res;
}

int main() {
    forn(i, 20){
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    pw[0] = 1, pw[1] = 9, pw[2] = 81, pw[3] = 729;
    int T;
    scanf("%d", &T);
    forn(i, T){
        long long L, R;
        scanf("%lld%lld", &L, &R);
        cout << calc(R+1) << ' ' << calc(L) << '\n';
        //printf("%lld\n", calc(R + 1) - calc(L));
    }
    return 0;
}*/