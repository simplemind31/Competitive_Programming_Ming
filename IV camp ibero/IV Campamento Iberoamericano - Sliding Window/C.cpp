#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n;
int main()
{
    scanf("%d",&n);
    vi songs(n);
    for(int i=0;i<n;i++){
        scanf("%d",&songs[i]);
    }
    map<int,int> aux;
    int point=0,con=0,maxi=0;
    for(int i=0;i<n;i++){
        while(aux[songs[i]]>0){
            aux[songs[point]]--;
            point++;
            con--;
        }
        con++;
        aux[songs[i]]++;
        maxi=max(maxi,con);
    }
    printf("%d",maxi);
}