#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int N,L,M,a;
vector<int> F,S,nums,identidad(101);
vector<int> combi(vector<int> a,vector<int> b){
    vector<int> res(101);
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            res[(i+j)%M]=(res[(i+j)%M]+1ll*a[i]*b[j]%MOD)%MOD;
        }
    }
    return res;
}
vector<int> binary(vector<int> b,int e){
    if(e==1)return b;
    vector<int> temp=binary(b,e>>1);
    temp=combi(temp,temp);
    if(e&1)temp=combi(temp,identidad);
    return temp;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> L >> M;
    // resolver hasta L-2
    // para cada wigth guardamos la cantidad
    //identidad[0]=1;
    vector<int> con(101);
    F.resize(N);
    S=nums=F;
    for(int i=0;i<N;i++){
        cin >> F[i];
        F[i]%=M;
    }
    for(int i=0;i<N;i++){
        cin >> nums[i];
        con[nums[i]%=M]++;
        identidad[nums[i]]++;
    }
    for(int i=0;i<N;i++){
        cin >> S[i];
        S[i]%=M;
    }
    if(L==2){
        // para cada N
        vector<int> nuecon(101);
        for(int i=0;i<N;i++){
            nuecon[F[i]]++;
        }
        vector<int> nuenuecon(101);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                nuenuecon[(nums[i]+j+S[i])%M]=(nuenuecon[(nums[i]+j+S[i])%M]+nuecon[j])%MOD;
            }
        }
        cout << nuenuecon[0];
        return 0;
    }
    con=binary(con,L-2);
    /*for(int i=0;i<M;i++){
        cout << i << ':' << con[i] << '\n';
    }
    cout << endl << endl;*/
    int res=0;
    vector<int> nuecon(101);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            nuecon[(S[i]+j+nums[i])%M]=(nuecon[(S[i]+j+nums[i])%M]+con[j])%MOD;
        }
    }
    vector<int> nuenuecon(101);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            nuenuecon[(j+F[i])%M]=(nuenuecon[(j+F[i])%M]+nuecon[j])%MOD;
        }
    }
    cout << nuenuecon[0];
}