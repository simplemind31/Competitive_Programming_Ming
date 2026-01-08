#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long n;
int x;
int con=0;
int main()
{
    scanf("%ld",&n);
    vector<int> arr(n+1);
    x=n;
    n*=n+1;
    n/=2;
    if(n%2==1){
        printf("NO\n");
    }else{
        printf("YES\n");
        n/=2;
        if(n==3){
            printf("1\n");
            printf("3\n");
            printf("2\n");
            printf("1 2");
        }else if(n==5){
            printf("2\n");
            printf("2 3\n");
            printf("2\n");
            printf("1 4");
        }else{
            x/=2;
            if(x%2==0){
                x--;
            }
            int y=n/x;
            int z=n%x;
            arr[y]=1;
            con++;
            if(z!=0){
                con++;
            }
            arr[z]=1;
            for(int i=1;i<=(x-1)/2;i++){
                arr[y+i]=1;
                arr[y-i]=1;
                con+=2;
            }
            printf("%d\n",con);
            for(int i=1;i<arr.size();i++){
                if(arr[i]==1){
                    printf("%d ",i);
                }
            }
            printf("\n%d\n",arr.size()-con-1);
            for(int i=1;i<arr.size();i++){
                if(arr[i]==0){
                    printf("%d ",i);
                }
            }
        }
    }
}