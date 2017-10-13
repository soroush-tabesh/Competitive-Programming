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

const ll delta = 11743;

void SolutionA();
void SolutionB();

int main()
{
	Init;
	//WFile;
	//SolutionA();
	SolutionB();
	return 0;
}

void SolutionA(){
	ll x=13781378,p=1,q=3;
	ll ans = 0;
	while(x > 1){
		x-=p;
		ans = (ans*10+1)%delta;
		if(x > 1){
			ans = (ans*10+1)%delta;
		}
	}
	ans = (ans*10+1)%delta;
	cout << ans;
}

string curB;
string ansB = "z";
bool is = true;
ll xB=139151014546830LL,pB=5,qB=6;

void bruteB(ll num,bool role){
	if(num == 1){
		curB += (role ? '1' : '2');
		is = false;
		if(lexicographical_compare(curB.begin(),curB.end(),ansB.begin(),ansB.end())){
			ansB = curB;
		}
		return;
	}else if (num < 1){
		return;
	}
	if(role){ // div
		if(num % pB == 0){
			curB += '1';
			bruteB(num/pB,!role);
			curB.pop_back();			
		}
		if(num % qB == 0 && is){
			curB += '2';
			bruteB(num/qB,!role);
			curB.pop_back();
		}
	}else{ // sub
		curB += '1';
		bruteB(num-pB,!role);
		curB.pop_back();
		if(is){
			curB += '2';
			bruteB(num-qB,!role);
			curB.pop_back();	
		}
	}
}

void SolutionB(){
	bruteB(xB,true);
	curB = "";
	is = true;
	bruteB(xB,false);
	ll ansnum = 0;
	forar(i,ansB.length()){
		ansnum *= 10;
		ansnum += ansB[i]-'0';
		ansnum %= delta;
	}
	cout << ansnum;
}

