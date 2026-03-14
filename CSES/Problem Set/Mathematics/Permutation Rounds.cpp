#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,descomp[200001];
ll mcm=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    bool visited[n];
    int arr[n];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++){
        cin >> arr[i];arr[i]--;
    }
    for(int i=0;i<n;i++){
        if(visited[i])continue;
        int lon=1,now=arr[i];
        visited[i]=true;
        while(now!=i){
            visited[now=arr[now]]=true;
            lon++;
        }
        for(int j=2;j*j<=lon;j++){
            int con=0;
            while(lon%j==0){
                lon/=j;
                con++;
            }
            descomp[j]=max(descomp[j],con);
        }
        if(lon>1)descomp[lon]=max(descomp[lon],1);
    }
    for(int i=0;i<200000;i++){
        for(int j=0;j<descomp[i];j++){
            mcm=(mcm*i)%MOD;
        }
    }
    cout << mcm;
}