/*
ID: soroosh4
LANG: C++11
TASK: fracdec
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("fracdec.in","r",stdin),freopen("fracdec.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
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
const int M = 100*1000+5;

void Solution();
ll nom,den,i;
string ans;
int rems[1000*1000+5];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

int apptoans(int k){
	int v = 0;
	string s = "";
	while(k > 0){
		s += "0123456789"[k%10];
		k/=10;
		v++;
	}
	if(s == ""){
		s = "0";
		v++;
	}
	reverse(s.begin(),s.end());
	ans += s;
	return v;
}

void Solution(){
	cin >> nom >> den;
	i += apptoans(nom / den);
	nom %= den;
	rems[nom] = i+1;
	if(nom != 0){
		ans += ".";
		i++;
		bool is = false;
		while(i < 100000 && !is){
			nom *= 10;
			int rem = nom % den;
			int frc = nom / den;
			apptoans(frc);
			if(rem == 0){
				is = true;
			}else if(rems[rem]){
				ans += ")";
				ans.insert(rems[rem],"(");
				is = true;
			}else{
				rems[rem] = i+1;
			}
			nom = rem;
			i++;
		}
	}else{
		ans+=".0";
	}
	forar(i,ans.length()){
		if(i && i%76 == 0)
			cout << endl;
		cout << ans[i];
	}
	cout << endl;
}
