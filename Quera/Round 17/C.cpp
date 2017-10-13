// Wrong Code
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

void Solution();

int n,m,cnt,bc,state=1;
string s;

map<char,int> verts[1002];

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
	cin >> n >> m >> s;
	bc = 0;
	for(int i = 0;i < m;i++){
		int a,b;
		char c;
		cin >> a >> b >> c;
		verts[a][c] = b;
	}
	for(int i = 0;i < s.length();i++){
		if(verts[state][s[i]] != 0){
			cnt=0;
			while(cnt <= n){
				cnt++;
				state = verts[state][s[i]];
				if(verts[state][s[i]] == 0){
					break;
				}
			}
			if(cnt < n){
				bc += cnt;
			} else {
				cout << "-1" << endl;
				return;
			}
			
		}
	}
	cout << s.length() + bc;
	
}

