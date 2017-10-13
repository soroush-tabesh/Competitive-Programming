//In The Name of Allah
//Sat 28/5/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
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

const ll mod = 1e9+7;

void Solution();

void process();

string infix;
string postfix;
int pos = -1;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void process(){
	pos++;
	char priorA,priorB;
	while(infix[pos] != ')'){
		switch(infix[pos]){
			case '*':
			case '/':
				if(priorA){
					postfix.append(1,priorA);
					priorA = 0;
				}
				priorA = infix[pos];
				break;
			case '+':
			case '-':
				if(priorA){
					postfix.append(1,priorA);
					priorA = 0;
				}
				if(priorB){
					postfix.append(1,priorB);
					priorB = 0;
				}
				priorB = infix[pos];
				break;
			case '(':
				process();
				break;
			default:
				postfix.append(1,infix[pos]);
				break;
		}
		pos++;
	}
	if(priorA){
		postfix.append(1,priorA);
		priorA = 0;
	}
	if(priorB){
		postfix.append(1,priorB);
		priorB = 0;
	}
}

void Solution(){
	cin >> infix;
	infix.append(1,')');
	process();
	cout << postfix << endl;
}

