#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

void Solution();

ll data[100*1000+10];
ll dp[100*1000+10];
ll n,k;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

inline void Log(string s){
	cout << "Log: " << s << endl;
}

inline void Log(int s){
	cout << "Log: " << s << endl;
}

void Solution(){
	cin >> n >> k;
	cin >> data[0];
	dp[0] = data[0];
	ForI(i,1,n){
		cin >> data[i];
		if(data[i] < data[i-1]){
			dp[i] = dp[i-1] + k + data[i] - data[i-1];
		} else {
			dp[i] = dp[i-1] + data[i] - data[i-1];
		}
	}
	ForI(i,0,n){
		cout << dp[n-1] - dp[i] + data[i] << endl;
	}
}

