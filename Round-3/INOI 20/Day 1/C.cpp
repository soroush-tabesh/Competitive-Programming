//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
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

const ll delta = 10861;

void Solution();

string s = "1";

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	int n = 1389;
	fori(i,2,n+1){
		string t;
		int x = i;
		while(x > 0){
			t += (x%2 == 1 ? '1' : '0');
			x/=2;
		}
		reverse(t.begin(),t.end());
		int toplace = t.length();
		fori(start,max(0,int(s.length()-t.length())),s.length()){
			// check for overlap
			bool is = true;
			forar(last,min(int(s.length()-start),int(t.length()))){
				if(s[start+last] != t[last]){
					is = false;
					break;
				}
			}
			if(is){
				toplace = t.length() - min(int(s.length()-start),int(t.length()));
				break;
			}
		}
		//cout << i << " " << t << endl;
		// append answer
		fori(k,t.length()-toplace,t.length()){
			s+=t[k];
		}
	}
	cout << ((s.length()*1389)%delta);
}