// IN THE be name khoda :)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MN=2e3+100 , inf=1e9+100 , mod=1000*1000*1000+7 ;

int n , m , a[MN][MN] , khar1 , khar2 ;
int d1[MN][MN] ;

vector<pair<pair<int,int>,int>>adj[MN][MN];
set<pair<int,pair<int,int>> >S;


int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c; cin>>c;
            if(c=='x')a[i][j]=1;
            d1[i][j]=inf;
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i>0){
                if(a[i-1][j]==1){
                    adj[i][j].pb({{i-1,j},1});
                }else{
                    adj[i][j].pb({{i-1,j},0});
                }
            }
            if(j>0){
                if(a[i][j-1]==1){
                    adj[i][j].pb({{i,j-1},1});
                }else{
                    adj[i][j].pb({{i,j-1},0});
                }
            }
            if(i<n-1){
                if(a[i+1][j]==1){
                    adj[i][j].pb({{i+1,j},1});
                }else{
                    adj[i][j].pb({{i+1,j},0});
                }
            }
            if(j<m-1){
                if(a[i][j+1]==1){
                    adj[i][j].pb({{i,j+1},1});
                }else{
                    adj[i][j].pb({{i,j+1},0});
                }
            }
        }
    }
    for(int j=0;j<m;j++){
        if(a[0][j]==1)
            d1[0][j]=1;
        else
            d1[0][j]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            S.insert({d1[i][j],{i,j}});
        }
    }

    while(!S.empty()){
        auto p=*S.begin();

        auto p2=p.second;
        int q1=p2.first;
        int q2=p2.second;

        int dis=p.first;

        for(auto i:adj[q1][q2]){
            auto ali=i.first;
            int p1=ali.first;
            int p2=ali.second;
            if(d1[p1][p2]>(dis+i.second)){
                S.erase({d1[p1][p2],{p1,p2}});
                d1[p1][p2]=dis+i.second;
                S.insert({d1[p1][p2],{p1,p2}});
            }
        }
        S.erase({d1[q1][q2],{q1,q2}});
    }
    khar1=inf;
    for(int j=0;j<m;j++){
        khar1=min(khar1,d1[n-1][j]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            adj[i][j].clear();
            d1[i][j]=inf;
        }
    }
///////////////////////////////////////
   for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i>0){
                if(a[i-1][j]==0){
                    adj[i][j].pb({{i-1,j},1});
                }else{
                    adj[i][j].pb({{i-1,j},0});
                }
            }
            if(j>0){
                if(a[i][j-1]==0){
                    adj[i][j].pb({{i,j-1},1});
                }else{
                    adj[i][j].pb({{i,j-1},0});
                }
            }
            if(i<n-1){
                if(a[i+1][j]==0){
                    adj[i][j].pb({{i+1,j},1});
                }else{
                    adj[i][j].pb({{i+1,j},0});
                }
            }
            if(j<m-1){
                if(a[i][j+1]==0){
                    adj[i][j].pb({{i,j+1},1});
                }else{
                    adj[i][j].pb({{i,j+1},0});
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        if(a[i][0]==0)
            d1[i][0]=1;
        else
            d1[i][0]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            S.insert({d1[i][j],{i,j}});
        }
    }
    while(!S.empty()){
        auto p=*S.begin();

        auto p2=p.second;
        int q1=p2.first;
        int q2=p2.second;

        int dis=p.first;

        for(auto i:adj[q1][q2]){
            auto ali=i.first;
            int p1=ali.first;
            int p2=ali.second;
            if(d1[p1][p2]>(dis+i.second)){
                S.erase({d1[p1][p2],{p1,p2}});
                d1[p1][p2]=dis+i.second;
                S.insert({d1[p1][p2],{p1,p2}});
            }
        }
        S.erase({d1[q1][q2],{q1,q2}});
    }
    khar2=inf;
    for(int i=0;i<n;i++){
        khar2=min(khar2,d1[m-1][i]);
    }
    cout<<khar1+khar2<<endl;
}
