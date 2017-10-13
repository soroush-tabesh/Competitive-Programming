//In The Name of Allah
//Tue 11/7/96
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MN = 1e6+100 ;

bool b1[MN] , b2[MN] , b3[MN] , hsh[MN] ;
int n , a1[MN] , a2[MN] , a3[MN] , ja[MN] , hazf ;
set<int>s;
map <int,int> m1 , m2 ;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int v; cin>>v;
        a1[i]=v;
        m1[v]++;
        b1[v]=1;
    }
    for(int i=0;i<n;i++){
        int v; cin>>v;
        a2[i]=v;
        m2[v]++;
        b2[v]=1;
    }
    for(int i=0;i<n;i++){
        int v; cin>>v;
        a3[i]=v;
        ja[v]=i;
    }
    for(int i=1;i<=n;i++){
        if(!b1[i]){
            s.insert(ja[i]);
            hsh[ja[i]]=1;
        }
        if(!b2[i]){
            s.insert(ja[i]);
            hsh[ja[i]]=1;
        }
    }

    while(hazf<n && s.size()){
        int ali=*s.begin();
        m1[a1[ali]]--;
        if(!m1[a1[ali]] && !hsh[a1[ali]]){
            s.insert(ja[a1[ali]]);
            hsh[a1[ali]]=1;
        }
        m2[a2[ali]]--;
        if(!m2[a2[ali]] && !hsh[a2[ali]]){
            s.insert(ja[a2[ali]]);
            hsh[a2[ali]]=1;
        }
        hazf++;
        s.erase(s.begin());
    }
    cout<<hazf<<endl;
}
