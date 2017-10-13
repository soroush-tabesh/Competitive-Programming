#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define frs first
#define scn second
#define pb push_back
#define pf push_front

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

void Solution();
ll powm(ll base,int p);
int main()
{
	Init;
	#ifndef ONLINE_JUDGE
    //WFile;
	#endif
	Solution();
    return 0;
}

ll powm(ll base,int p){
	if(p==1)
		return base;
	if(p==0)
		return 1;
	ll temp = powm(base,p/2);
	temp *= temp;
	if(p % 2 == 1)
		temp *= base;
	temp %= mod;
	return temp;
}

void Solution(){
	string s;
	int n;
	cin >> s;
	n = s.length();
	vector<string> subs;
	// on divs
	for(int i = 1;i <= n/2;i++){
		if(n%i != 0)
			continue;
		bool isp = false;
		for(int k = 0;k < subs.size();k++){
			if(i % subs[k].size() == 0){
				isp = true;
				break;
			}
		}
		if(isp)
			continue;
		
		bool is = true;
		for(int j = i;j < n;j++){
			if(s[j] != s[j%i]){
				is = false;
				break;
			}
		}
		if(is){
			subs.pb(s.substr(0,i));
		}
	}
	ll ans = 0;
	for(int i = 1;i < n;i++){
		ans = (ans +1)*26;//powm(26,i);
		ans %= mod;
	}
	for(int i = 0;i < subs.size();i++){
		ans -= n/subs[i].length() - 1;
		ans += mod;
		ans %= mod;
	}
	cout << ans;


}
