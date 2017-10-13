#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
#define pf push_front
#define fr first
#define sc second

using namespace std;

typedef long long int ll;
typedef long double ld;

void solution();

int main(){
	Init;
	solution();
	return 0;
}

void solution(){
	string value;
	cin >> value;
	int carry = 1;
	for(int i = value.length()-1;i >= 0;i--){
		
		string sym(1, value[i]);
		const char *chr = sym.c_str();
		int number = (int)strtol(chr, NULL, 16);
		
		number += carry;
		if(number >= 16){
			carry = 1;
			number %=16;
		}else
			carry = 0;
		
		std::stringstream ss;
		ss << hex << number;
		value[i] = ss.str()[0];
	}
	
	if(carry == 1){
		cout << "1";
	}
	
	transform(value.begin(), value.end(),value.begin(), ::toupper);
	
	cout << value << endl;
	
}
