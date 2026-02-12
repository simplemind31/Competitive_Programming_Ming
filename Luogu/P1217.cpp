#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a,b;
vector<int> pal;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b;
    // 8
    // 1,2
    for(int i=1;i<10;i+=2){
        bool xd=true;
        int val=i;
        for(int j=2;j*j<=val && xd;j++)if(val%j==0)xd=false;
        if(xd)pal.push_back(val);
        string st=to_string(i);
        string temp=st;
        reverse(ALL(temp));
        st+=temp;
        val=stoi(st);
        for(int j=2;j*j<=val && xd;j++)if(val%j==0)xd=false;
        if(xd)pal.push_back(val);
    }
    //3,4
    for(int i=1;i<10;i+=2){
        for(int k=0;k<10;k++){
            bool xd=true;
            string st=to_string(i);
            string temp=st;
            reverse(ALL(temp));
            st.push_back(k+'0');
            st+=temp;
            int val=stoi(st);
            for(int j=2;j*j<=val && xd;j++)if(val%j==0)xd=false;
            if(xd)pal.push_back(val);
            xd=true;
            st=to_string(i*10+k);
            temp=st;
            reverse(ALL(temp));
            st+=temp;
            val=stoi(st);
            for(int j=2;j*j<=val && xd;j++)if(val%j==0)xd=false;
            if(xd)pal.push_back(val);
        }
    }
    // 5,6
    for(int i=1;i<10;i+=2){
        for(int k=0;k<10;k++){
            for(int l=0;l<10;l++){
                bool xd=true;
                string st=to_string(i*10+k);
                string temp=st;
                reverse(ALL(temp));
                st.push_back(l+'0');
                st+=temp;
                int val=stoi(st);
                for(int j=2;j*j<=val && xd;j++)if(val%j==0)xd=false;
                if(xd)pal.push_back(val);
                xd=true;
                st=to_string(i*100+10*k+l);
                temp=st;
                reverse(ALL(temp));
                st+=temp;
                val=stoi(st);
                for(int j=2;j*j<=val && xd;j++)if(val%j==0)xd=false;
                if(xd)pal.push_back(val);
            }
        }
    }
    for(int i=1;i<10;i+=2){
        for(int k=0;k<10;k++){
            for(int l=0;l<10;l++){
                for(int p=0;p<10;p++){
                    bool xd=true;
                    string st=to_string(i*100+10*k+l);
                    string temp=st;
                    reverse(ALL(temp));
                    st.push_back(p+'0');
                    st+=temp;
                    int val=stoi(st);
                    for(int j=2;j*j<=val && xd;j++)if(val%j==0)xd=false;
                    if(xd)pal.push_back(val);
                    xd=true;
                    st=to_string(i*1000+100*k+10*l+p);
                    temp=st;
                    reverse(ALL(temp));
                    st+=temp;
                    val=stoi(st);
                    for(int j=2;j*j<=val && xd;j++)if(val%j==0)xd=false;
                    if(xd)pal.push_back(val);
                }
            }
        }
    }
    sort(pal.begin(),pal.end());
    for(int i=0;i<pal.size() && pal[i]<=b;i++){
        if(pal[i]>=a)cout << pal[i] << '\n';
    }
}