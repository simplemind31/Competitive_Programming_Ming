#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,k;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    vector<int> hotels(n),clients(m);
    for(int i=0;i<n;i++){
        scanf("%d",&hotels[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&clients[i]);
    }
    int j=0,i=0;
    sort(ALL(clients));
    sort(ALL(hotels));
    int con=0;
    while(i<n && j<m){
        if(hotels[i]>=clients[j]){
            if(hotels[i]-k<=clients[j]){
                con++;
                i++;
            }
            j++;            
        }else{
            if(hotels[i]+k>=clients[j]){
                con++;
                j++;
            }
            i++;
        }
    }
    printf("%d",con);
}