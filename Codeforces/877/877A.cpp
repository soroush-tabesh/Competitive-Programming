//In The Name of Allah
//Mon 1/8/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 3e5+5;

void Solution();

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	string s;
	cin >> s;
	int ans = 0;
	s+="00000000";
	string check[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	forar(i,s.length()){
		forar(j,5){
			if(s.compare(i,check[j].length(),check[j]) == 0){
				ans++;
			}
		}
	}
	if(ans == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}