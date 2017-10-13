#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int rad[2] = {0,0};
	int rfr[2] = {0,0};
	std::cin >> rad[0];
	std::cin >> rad[1];
	std::cin >> rfr[0];
	std::cin >> rfr[1];
	if(rad[0]>rfr[0]){
	    std::cout << "Left" << std::endl;
	}else{
	    std::cout << "Right" << std::endl;
	}
	return 0;
}
