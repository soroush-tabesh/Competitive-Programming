//In The Name of Allah
//Fri 14/7/96
#include <bits/stdc++.h>
using namespace std;
const int MN = 5e3+100 , inf=1e9+100 , mod=1e9+7 ;

#define int long long
#define pb push_back
#define F first
#define S second

int bp(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int nesf=bp(a,b/2);
    nesf=(nesf*nesf)%mod;
    if(b&1){
        nesf=(nesf*a)%mod;
    }
    return nesf;
}

int dp[MN][MN] , ans , ali[MN] , n , k , t2[MN] ;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;

    for(int i=0;i<MN;i++){
        dp[i][i]=1;
    }
    for(int j=0;j<=k;j++){
        for(int i=1;i<MN-10;i++){
            if((i%2)!=(j%2) || j<=i)continue;
            if(i==1){
                dp[i][j]=dp[i+1][j-1];
            }else{
                dp[i][j]=(dp[i+1][j-1]+dp[i-1][j-1])%mod;
            }
        }
    }

    t2[0]=1;
    for(int i=1;i<MN;i++){
        t2[i]=(t2[i-1]*2)%mod;
    }

    //cout<<dp[1][3]<<"////"<<endl;
    for(int i=0;i<MN;i++){
        for(int j=0;j<=k;j++){
            ali[i]=(ali[i]+ dp[i][j]*t2[k-j]%mod )%mod;
        }
    }
    //cout<<ali[1]<<endl;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        ans=(ans+ali[abs(a)])%mod;
    }

    cout<<ans<<endl;
}
