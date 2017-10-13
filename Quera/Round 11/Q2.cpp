#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int coord[2] = {0,0};
    std::cin >> coord[0] >> coord[1];
	std::cout << "1" << std::endl;
	if(coord[0] == 7 && coord[1] == 7){
	    std::cout << "2 2" << std::endl;
	}else{
	    std::cout << "7 7" << std::endl;
	}
	return 0;
}
