#include <bits/stdc++.h>
using namespace std;
int n,last=-1,i1,i2;
bool xd;
string st;
int con[26],maxi[27];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    n=st.size();
    for(int i=0;i<n;i++)con[st[i]-'A']++;
    maxi[26]=0;
    for(int i=25;i>=0;i--)maxi[i]=max(maxi[i+1],con[i]);
    //false i1,true i2;
    if(maxi[0]>(n+1)/2){
        cout << -1;
        return 0;
    }
    st=string(n,' ');
    for(;i1<26 && con[i1]==0;i1++);
    for(i2=i1+1;i2<26 && con[i2]==0;i2++);
    for(int i=0;i<n;i++){
        //si uso esto para otro
        if(!xd){
            st[i]=i1+'A';
            con[i1]--;
            maxi[i1]=max(maxi[i2],con[i1]);
            if((n-i)/2<maxi[i1]){
                //no se puede
                con[i1]++;
                maxi[i1]=max(maxi[i2],con[i1]);
                //encontrar al maxi y ponerlo a partir de i;
                int mamama=i1;
                for(int j=0;j<26;j++){
                    if(con[mamama]<con[j]){
                        mamama=j;
                    }
                }
                for(int j=i;j<n;j+=2){
                    st[j]=mamama+'A';
                    con[mamama]--;
                }
                for(int j=i+1;j<n;j+=2){
                    while(!con[i1++]);
                    i1--;
                    st[j]=i1+'A';
                    con[i1]--;
                }
                break;
            }else{
                //si se puede
                xd=1-xd;
            }
            if(con[i1]==0){
                i1=i2;
                i2=i1+1;
                for(i2=i1+1;i2<26 && con[i2]==0;i2++);
                xd=1-xd;
            }
        }else{
            st[i]=i2+'A';
            con[i2]--;
            maxi[i2]=max(maxi[i2+1],con[i2]);
            if((n-i)/2<maxi[i2]){
                //no se puede
                con[i2]++;
                maxi[i2]=max(maxi[i2+1],con[i2]);
                int mamama=i2;
                for(int j=0;j<26;j++){
                    if(con[mamama]<con[j]){
                        mamama=j;
                    }
                }
                for(int j=i;j<n;j+=2){
                    st[j]=mamama+'A';
                    con[mamama]--;
                }
                for(int j=i+1;j<n;j+=2){
                    while(!con[i1++]);
                    i1--;
                    st[j]=i1+'A';
                    con[i1]--;
                }
                break;
            }else{
                //si se puede
                xd=1-xd;
            }
            if(con[i2]==0){
                for(i2=i1+1;i2<26 && con[i2]==0;i2++);
            }
        }
    }
    cout << st;
}