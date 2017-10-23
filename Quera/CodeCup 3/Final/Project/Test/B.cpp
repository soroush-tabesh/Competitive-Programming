// IN THE be name khoda :)
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define endl '\n'

const int MN=3e3+10 , inf=1e9+100 ;

int dp[5][MN][5] , n , B , a[MN] ;


int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>B;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=0;i<MN;i++){
        dp[2][i][0]=dp[2][i][1]=inf;
        dp[1][i][0]=dp[1][i][1]=inf;
    }

    dp[1][1][1]=0;
    dp[1][0][0]=a[1];


    for(int i=2;i<=n;i++){
        for(int j=0;j<=B;j++){
            if(j==0){
                dp[2][j][0]=min(dp[1][j][0],dp[1][j][1]+a[i]);
            }else{
                dp[2][j][1]=min(dp[1][j-1][1],dp[1][j-1][0]+a[i]);
                dp[2][j][0]=min(dp[1][j][0],dp[1][j][1]+a[i]);
            }
        }
        for(int j=0;j<=B;j++){
            dp[1][j][1]=dp[2][j][1];
            dp[1][j][0]=dp[2][j][0];
        }
    }
    int ans=inf;
    for(int i=0;i<=B;i++){
        if(n-i <= B){
            ans=min(ans,dp[2][i][1]);
            ans=min(ans,dp[2][i][0]);
        }
    }
    cout<<ans<<endl;
}
