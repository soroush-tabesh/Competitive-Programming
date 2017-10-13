#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

void Solution();

int data[200*1000];
int dp[200*1000];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	int n = 0;
	cin >> n;
	forar(i,n)
		cin >> data[i];
	forar(i,n){
		if(data[i] == 0){
			int j = i-1;
			while(data[j] != 0 && j >= 0){
				if(dp[j] != 0)
					dp[j] = (int)min(i-j,dp[j]);
				else
					dp[j] = i-j;
				j--;
			}
			j = i+1;
			while(data[j] != 0 && j < n){
				if(dp[j] != 0)
					dp[j] = (int)min(j-i,dp[j]);
				else
					dp[j] = j-i;
				j++;
			}
		}
	}
	forar(i,n)
		cout << dp[i] << " ";
}