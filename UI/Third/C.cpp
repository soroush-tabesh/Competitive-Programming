//In The Name of Allah
//Thu 30/9/96
#include <vector>
#include <utility>
#include <string>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

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
/*
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;
*/
void Solution();

int main()
{
	//Init;
	Solution();
	return 0;
}

void Solution(){
	int a,b,c;
	cin >> a >> b >> c;
	cout << fixed << setprecision(0) << fixed;
	if(a==0){
		if(b==0){
			if(c==0){
				cout << 0; 
			}else{
				cout << "You're fired!"; 
			}
		}else{
			if(c==0){
				cout << 0 << endl;
			}else{
				cout << ((-1)*c/b);
			}
		}
	}else{
		if((b*b) > (4*a*c)){
			if(b==0){
				cout << 0;
			}else{
				cout << (((-1)*b)/(a));
			}
		}else if((b*b) == (4*a*c)){
			if(b==0){
				cout << 0 << endl;
			}else{
				cout << (((-1)*b)/(a*2));
			}
		}else{
			cout << "You're fired!";
		}
	}
	
}
