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

string str[50];

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
	int n;
	cin >> n;
	forar(i,n)
		cin >> str[i];
	vector<int> dists;
	dists.pb(0);
	fori(i,1,n){
		int cnt = 0;
		while(str[i] != str[i-1]){
			cnt++;
			if(cnt > str[i].size()){
				cout << -1;
				return;
			}
			char temp = str[i][0];
			str[i] = str[i].substr(1);
			str[i] += temp;
		}
		dists.pb(cnt);
	}
	
	int base = 1;
	string temp = str[0];
	char t = temp[0];
	temp = temp.substr(1);
	temp += t;
	while(str[0] != temp){
		base++;
		t = temp[0];
		temp = temp.substr(1);
		temp += t;
	}
		
	int ans = n*str[0].length();
	forar(i,dists.size()){
		//Log(dists[i]);
		int d = 0;
		forar(j,dists.size()){
			d += (dists[j] - dists[i] + base) % base;
		}
		ans = (int)min(ans,d);
	}
	cout << ans;
}