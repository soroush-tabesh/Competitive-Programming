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
	string a,b;
	cin >> a >> b;
	int ans = 0;
	bool in = false;
	ForI(i,0,n){
		if(a[i] == b[i])
			in = false;
		else if(!in){
			in = true;
			ans++;
		}
	}
	cout << ans;
	
}
