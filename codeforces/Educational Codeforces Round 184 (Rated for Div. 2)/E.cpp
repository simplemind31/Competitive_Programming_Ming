#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
bool cmp(pair<ll,ll>&a,pair<ll,ll>&b){return a.first>b.first;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        // el juego-> elegir algunos puntos
        // puntaje = max(suma de los costos de los puntos no elegidos+el perimetro del minimo rectangulo que incluye a los puntos)
        /*
        entonces si ya tenemos el rectangulo, es siempre mejor quitar lo que esta adentro
        => solo elegir puntos que están en el borde del triángulo
        // S=sumatoria de todos costos
        // R=sumatoria de costos elegidos
        // P=perimetro del minimo rectangulo que encubre
        // res=max(S-R+P)
        // es siempre mejor elegir <=4 puntos
        */
        cin >> n;
        ll x[n],y[n],c[n],sum=0,maxi=0;
        for(int i=0;i<n;i++)cin >> x[i];
        for(int i=0;i<n;i++)cin >> y[i];
        pair<ll,ll> lowerleft[n],upperright[n],upperleft[n],lowerright[n],left[n],up[n],down[n],right[n];
        for(int i=0;i<n;i++){
            cin >> c[i];
            sum+=c[i];
            // si i es lowerleft
            lowerleft[i]={-c[i]-2*y[i]-2*x[i],i};
            upperright[i]={-c[i]+2*y[i]+2*x[i],i};
            upperleft[i]={-c[i]+2*y[i]-2*x[i],i};
            lowerright[i]={-c[i]-2*y[i]+2*x[i],i};
            left[i]={-c[i]-2*x[i],i};
            right[i]={-c[i]+2*x[i],i};
            up[i]={-c[i]+2*y[i],i};
            down[i]={-c[i]-2*y[i],i};
        }
        sort(x,x+n);
        sort(y,y+n);
        sort(c,c+n);
        sort(lowerleft,lowerleft+n,cmp);
        sort(upperright,upperright+n,cmp);
        sort(lowerright,lowerright+n,cmp);
        sort(upperleft,upperleft+n,cmp);
        sort(left,left+n,cmp);
        sort(right,right+n,cmp);
        sort(up,up+n,cmp);
        sort(down,down+n,cmp);
        // no elijo nada
        maxi=2*(x[n-1]-x[0]+y[n-1]-y[0]);
        // elijo un punto
        maxi=max(maxi,sum-c[0]);
        // elijo 2 puntos
        if(n>=2){
            //lowerleft,upperright
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    if(lowerleft[i].second==upperright[j].second)continue;
                    maxi=max(maxi,sum+lowerleft[i].first+upperright[j].first);
                }
            }
            //lowerright,upperleft
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    if(lowerright[i].second==upperleft[j].second)continue;
                    maxi=max(maxi,sum+lowerright[i].first+upperleft[j].first);
                }
            }
        }
        // elijo 3 puntos
        if(n>=3){
            //lowerleft,right,up
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(lowerleft[i].second==right[j].second)continue;
                    for(int k=0;k<3;k++){
                        if(lowerleft[i].second==up[k].second || right[j].second==up[k].second)continue;
                        maxi=max(maxi,sum+lowerleft[i].first+right[j].first+up[k].first);
                    }
                }
            }
            //uppperright,left,down
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(upperright[i].second==left[j].second)continue;
                    for(int k=0;k<3;k++){
                        if(upperright[i].second==down[k].second || left[j].second==down[k].second)continue;
                        maxi=max(maxi,sum+upperright[i].first+left[j].first+down[k].first);
                    }
                }
            }
            //lowerright,left,up
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(lowerright[i].second==left[j].second)continue;
                    for(int k=0;k<3;k++){
                        if(lowerright[i].second==up[k].second || left[j].second==up[k].second)continue;
                        maxi=max(maxi,sum+lowerright[i].first+left[j].first+up[k].first);
                    }
                }
            }
            //upperleft,right,down
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(upperleft[i].second==right[j].second)continue;
                    for(int k=0;k<3;k++){
                        if(upperleft[i].second==down[k].second || right[j].second==down[k].second)continue;
                        maxi=max(maxi,sum+upperleft[i].first+right[j].first+down[k].first);
                    }
                }
            }
        }
        // elijo 4 puntos
        if(n>=4){
            //left,up,right,down
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(left[i].second==up[j].second)continue;
                    for(int k=0;k<4;k++){
                        if(left[i].second==right[k].second || up[j].second==right[k].second)continue;
                        for(int l=0;l<4;l++){
                            if(left[i].second==down[l].second || up[j].second==down[l].second || right[k].second==down[l].second)continue;
                            maxi=max(maxi,sum+left[i].first+up[k].first+right[k].first+down[l].first);
                        }
                    }
                }
            }
        }
        cout << maxi << '\n';
    }
}