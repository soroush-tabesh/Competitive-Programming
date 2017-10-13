#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define first frs
#define second scnd
#define pb push_back
#define pf push_front

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

void Solution();

int mins[1000*1000+2];
int input[1000*1000+2];

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
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> input[i];
	}
	mins[n] = input[n];
	for(int i = n-1;i >= 1;i--){
		mins[i] = ((input[i] < mins[i+1]) ? input[i] : mins[i+1]);
	}
	int lind=0,cmin = mins[1];
	ll ans=0,temp=0;
	for(ll i = 1;i <= n+1;i++){
		if(cmin != mins[i]){
			temp = (i - lind - 1);
			temp *= cmin;
			ans += temp;
			cmin = mins[i];
			lind = i - 1;
		}
	}
	cout << ans;
}


