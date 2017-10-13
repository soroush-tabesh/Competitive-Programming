//In The Name of Allah
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

void Solution();

ll q;
string mstr;
bool isgood[200];

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
	string gs;
	cin >> gs;
	for(char c:gs)
		isgood[c]=1;
	cin >> mstr;
	cin >> q;
	while(q--){
		bool is = true;
		bool star = false;
		string query;
		cin >> query;
		ll r=0,l=query.length();
		
		// check from begin
		while(r<query.length()){
			if(mstr[r]=='*'){
				star = true;
				break;
			}
			if(r >= mstr.length()){
				is = false;
				break;
			}
			if(mstr[r] == '?'){
				if(!isgood[query[r]]){
					is = false;
					break;
				}
			}else{
				if(query[r] != mstr[r]){
					is = false;
					break;
				}
			}
			r++;
		}
		// check from end
		forar(ic,mstr.length()){
			l--;
			ll i = mstr.length() - ic - 1;
			if(mstr[i] == '*'){
				star = true;
				break;
			}
			if(mstr[i] == '?'){
				if(!isgood[query[l]]){
					is = false;
					break;
				}
			}else{
				if(query[l] != mstr[i]){
					is = false;
					break;
				}
			}
		}
		
		// check middle
		if(star){
			is = is && (query.length() >= mstr.length()-1);
		}else{
			is = is && (query.length() == mstr.length());
		}
		if(is && star){
			forar(i,query.length()-mstr.length()+1){
				if(isgood[query[r]]){
					is = false;
					break;
				}
				r++;
			}
		}
		
		if(is){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
		
	}
}



