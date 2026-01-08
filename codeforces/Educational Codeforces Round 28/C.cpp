#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ri,rj,rk;
ll maxi;
int main(){
    cin >> n;
    vector<ll> nums(n),psum(n);
    for(int i=0;i<n;i++)cin >> nums[i];
    // sum(a,b)=sum(0,b)-sum(0,a);
    // sum(0,x)=psum[x-1];
    psum[0]=nums[0];
    for(int i=1;i<n;i++)psum[i]=psum[i-1]+nums[i];
    maxi=psum[n-1];
    ri=rj=rk=n;
    if(-maxi>maxi){
        maxi=-maxi;
        ri=rj=rk=0;
    }
    // solo 1;
    int x=1;
    for(int i=0;i<n;i++){
        //(0,i),(i,n)
        if(i){
            if(psum[i-1]+(psum[n-1]-psum[i-1])>maxi){
                maxi=psum[i-1]+(psum[n-1]-psum[i-1]);
                ri=i;
                rj=ri;
                rk=n;
            }
            if(psum[i-1]-(psum[n-1]-psum[i-1])>maxi){
                maxi=psum[i-1]-(psum[n-1]-psum[i-1]);
                ri=i;
                rj=n;
                rk=rj;
            }
            if(-psum[i-1]+(psum[n-1]-psum[i-1])>maxi){
                maxi=-psum[i-1]+(psum[n-1]-psum[i-1]);
                ri=0;
                rj=i;
                rk=n;
            }
            if(-psum[i-1]-(psum[n-1]-psum[i-1])>maxi){
                maxi=-psum[i-1]-(psum[n-1]-psum[i-1]);
                ri=0;
                rj=i;
                rk=rj;
            }
        }
        for(int j=i+1;j<n;j++){
            //(0,i),(i,j),(j,n)
            if(i){
                if(psum[i-1]+(psum[j-1]-psum[i-1])-(psum[n-1]-psum[j-1])>maxi){
                    maxi=psum[i-1]+(psum[j-1]-psum[i-1])-(psum[n-1]-psum[j-1]);
                    ri=i;
                    rj=ri;
                    rk=j;
                }
                if(psum[i-1]-(psum[j-1]-psum[i-1])+(psum[n-1]-psum[j-1])>maxi){
                    maxi=psum[i-1]-(psum[j-1]-psum[i-1])+(psum[n-1]-psum[j-1]);
                    ri=i;
                    rj=j;
                    rk=n;
                }
                if(psum[i-1]-(psum[j-1]-psum[i-1])-(psum[n-1]-psum[j-1])>maxi){
                    maxi=psum[i-1]-(psum[j-1]-psum[i-1])+(psum[n-1]-psum[j-1]);
                    ri=i;
                    rj=j;
                    rk=rj;
                }
                if(-psum[i-1]+(psum[j-1]-psum[i-1])-(psum[n-1]-psum[j-1])>maxi){
                    maxi=-psum[i-1]+(psum[j-1]-psum[i-1])-(psum[n-1]-psum[j-1]);
                    ri=0;
                    rj=i;
                    rk=j;
                }
            }
            //+(0,x)-(x,i)+(i,j)-(j,n);
            //+(0,x)-(0,i)+(0,x)+(i,j)-(j,n);
            //2*(0,x)-(0,i)+(i,j)-(j,n);
            //encontrar max x;
            //2(0,x)-(0,i)+(0,j)-(0,i)-(0,n)+(0,j)
            //2(0,x)-2(0,i)+2(0,j)-(0,n);
            if(i){
                if(2*psum[x-1]-2*psum[i-1]+2*psum[j-1]-psum[n-1]>maxi){
                    maxi=2*psum[x-1]-2*psum[i-1]+2*psum[j-1]-psum[n-1];
                    ri=x;
                    rj=i;
                    rk=j;
                }
                if(psum[i-1]>psum[x-1])x=i;
            }
        }
    }
    cout << ri << ' ' << rj << ' ' << rk << '\n';
    //cout << maxi;
}
// 25