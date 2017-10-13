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

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

void Solution();

int a[100*1000];

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
	int n,ans=0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	if(n==1){
		cout << "NO";
		return;
	}
	int g = a[0];
	for(int i = 1;i < n;i++){
		g = gcd (g,a[i]);
	}
	
	if(g > 1){
		cout << "YES" << endl;
		cout << 0;
		return;
	}
	vector<int> odds;
	int odd=0;
	for(int i = 0;i < n;i++){
		if(a[i]%2==1)
			odd++;
		else if(odd>0){
			odds.push_back(odd);
			odd=0;
		}
	}
	odds.push_back(odd);
	for(int i = 0;i < odds.size();i++){
		ans += odds[i]/2 + 2*(odds[i]%2);
		//cout << odds[i] <<endl;
	}
	cout << "YES" << endl;
	cout << ans;
}