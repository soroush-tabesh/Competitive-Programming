#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define first frs
#define second scnd
#define pb push_back
#define pf push_front

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

void Solution();

int main()
{
	//Init;
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
	int x,y,r,dx,dy;
	cin >> x >> y >> r >> dx >> dy;
	if(x <= dx && dx <= x+r && y-r <= dy && dy <= y)
		cout << "Mahdi" << endl;
	else
		cout << "Parsa" << endl;
}


