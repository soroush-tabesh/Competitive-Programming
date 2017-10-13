//In The Name of Allah
//Tue 11/7/96
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MN = 1e6+100 ;

int n , l , ja[MN] , r[MN] , g[MN] ;

int f(int i , int t){
    t%=(r[i]+g[i]);
    if(t<r[i]){
        return 0;
    }
    return 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>l;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        cin>>r[d]>>g[d];
        ja[d]=1;
    }
    int i=0 , t=0 ;
    while(i<l){
        if(ja[i]){
            if(f(i,t)){
                t++;
                i++;
            }else{
                t++;
            }
        }else{
            i++;
            t++;
        }
    }
    cout<<t<<endl;
}
