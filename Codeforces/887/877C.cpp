//In The Name of Allah
//Sat 13/8/96
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

const ll mod = 1e9+7,M = 1e5+5;

void Solution();

int data[25];
int gmap[3][8] = {{3,17,10,16,4,19,9,14},{21,4,8,12,23,2,6,10},{13,5,17,21,14,6,18,22}};
bool ans;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

inline void rot(int d){
	forar(i,8){
		swap(data[gmap[d][4*(i/4)]],data[gmap[d][i]]);
	}
}

inline void check(){
	bool is = true;
	forar(i,24){
		is &= (data[i+1] == data[(i/4)*4+1]);
	}
	ans |= is;
}

void Solution(){
	forar(i,24){
		cin >> data[i+1];
	}
	forar(d,3){
		forar(i,2){
			rot(d);
			check();
			rot(d);			
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
}
