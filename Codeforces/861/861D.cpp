//In The Name of Allah
//Sun 26/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 7e4+5;

void Solution();

int n;
string data[M];
string ans[M];
map<int,int> trie;
map<int,int> mark;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i];
		fori(len,1,data[i].size()){
			ll hsh = 0;
			ll pr = 1;
			forar(j,len-1){
				hsh *= 11;
				hsh += data[i][j]-'0'+1;
				pr *= 11;
			}
			forar(pos,data[i].size()-len+1){
				hsh %= pr;
				hsh *= 11;
				hsh += data[i][pos+len-1]-'0'+1;
				if(mark[hsh] != i+1){
					mark[hsh] = i+1;
					trie[hsh]++;
				}
			}
		}
	}
	forar(i,n){
		string ans = data[i];
		fori(len,1,data[i].size()){
			ll hsh = 0;
			ll pr = 1;
			forar(j,len-1){
				hsh *= 11;
				hsh += data[i][j]-'0'+1;
				pr *= 11;
			}
			forar(pos,data[i].size()-len+1){
				hsh %= pr;
				hsh *= 11;
				hsh += data[i][pos+len-1]-'0'+1;
				if(trie[hsh] == 1 && len < ans.length()){
					ans = data[i].substr(pos,len);
					break;
				}
			}
		}
		cout << ans << endl;
	}
}
