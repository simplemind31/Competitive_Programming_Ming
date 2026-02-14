#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,m,a,b;
vector<vector<int>> graph;
vector<int> bipart,col1,col2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        bool xd=true;
        cin >> n >> m;
        graph.clear();
        graph.resize(n);
        bipart.clear();
        bipart.assign(n,2);
        col1.clear();
        col2.clear();
        while(m--){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        queue<int> bfs;
        bfs.push(0);
        bipart[0]=0;
        while(!bfs.empty() && xd){
            int top=bfs.front();
            bfs.pop();
            for(auto u:graph[top]){
                if(bipart[u]==2){
                    bipart[u]=1-bipart[top];
                    bfs.push(u);
                }else if(bipart[u]==bipart[top])xd=false;
            }
        }
        if(!xd){
            // solo 1 y 2
            cout << "Alice\n";
            cout.flush();
            for(int i=0;i<n;i++){
                cout << "1 2\n";
                cout.flush();
                cin >> a >> b;
            }
        }else{
            for(int i=0;i<n;i++){
                if(bipart[i])col1.push_back(i);
                else col2.push_back(i);
            }
            cout << "Bob\n";
            cout.flush();
            while(n--){
                cin >> a >> b;
                if(a==1 || b==1){
                    if(col1.empty()){
                        cout << col2.back()+1 << ' ' << a+b-1 << '\n';
                        cout.flush();
                        col2.pop_back();
                    }else{
                        cout << col1.back()+1 << ' ' << 1 << '\n';
                        cout.flush();
                        col1.pop_back();
                    }
                }else if(a==2 || b==2){
                    if(col2.empty()){
                        cout << col1.back()+1 << ' ' << a+b-2 << '\n';
                        cout.flush();
                        col1.pop_back();
                    }else{
                        cout << col2.back()+1 << ' ' << 2 << '\n';
                        cout.flush();
                        col2.pop_back();
                    }
                }
            }
        }
    }
    
}