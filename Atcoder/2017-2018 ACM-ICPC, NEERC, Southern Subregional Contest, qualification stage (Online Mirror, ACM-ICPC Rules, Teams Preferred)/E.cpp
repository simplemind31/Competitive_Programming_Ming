#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,l,r;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> st;
    string cop=st;
    r=3*n;
    while(l<r){
        int mid=(l+r)>>1;
        // cada uno usa mid tiempo
        st=cop;
        int last=-1;
        for(int i=0;i<n;i++){
            while(last+1<n && st[last+1]!='*')last++;
            if(st[i]=='P'){
                //cout << last << ' ';
                int pos=-1;
                for(int j=last+1;j<i && pos==-1;j++){
                    if(st[j]=='*')pos=j;
                }
                if(pos!=-1){
                    // tengo que ir de i a pos y luego volver
                    //cout << pos << '\n';
                    int cantiiz=i-pos;
                    if(cantiiz>mid){
                        break;
                    }
                    if(mid-2*cantiiz>=cantiiz){
                        // ir iz luego de
                        for(int j=i-1;j>=i-cantiiz && j>=0;j--){
                            if(st[j]=='*')st[j]='.';
                        }
                        int sobra=mid-2*cantiiz;
                        //cout << last << ' ' << sobra << '\n';
                        for(int j=i+1;j<=i+sobra && j<n;j++){
                            if(st[j]=='*')st[j]='.';
                            else if(st[j]=='P')break;
                        }
                    }else{
                        // ir de luego iz;
                        int sobra=(mid-cantiiz)/2;
                        // ir sobra a la derecha i luego j a la iz;
                        for(int j=i-1;j>=i-cantiiz && j>=0;j--){
                            if(st[j]=='*')st[j]='.';
                        }
                        for(int j=i+1;j<=i+sobra && j<n;j++){
                            if(st[j]=='*')st[j]='.';
                            else if(st[j]=='P')break;
                        }
                    }
                    // cantiiz+cantide+min(cantiiz,cantide)==mid;
                    //o ir a derecha y luego volver a pos;
                }else{
                    // voy a la derecha nomás
                    for(int j=i+1;j<=i+mid && j<n;j++){
                        if(st[j]=='*')st[j]='.';
                        else if(st[j]=='P')break;
                    }
                }
            }
        }
        //cout << mid << ' ' << st << '\n';
        bool xd=true;
        if(st.find('*')!=-1)l=mid+1;
        else r=mid;
    }
    cout << l;
}