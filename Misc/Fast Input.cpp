#include <iostream>
using namespace std;
template<typename T = int>
inline T read() {
	T val = 0, sign = 1; char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') sign = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		val = val * 10 + ch - '0';
	return sign * val;
}
int main() {
	// your code goes here
	int n = read();
	int k = read();
	int ans = 0;
	while(n--){
		int a;
		a=read();
		//scanf("%d",&a);
		ans += a%k==0;
	}
	printf("%d",ans);
	return 0;
}