#include <iostream>
#include <Device.h>
#include <chrono>

int main() 
{
	std::cout << "The simulator begun" << std::endl;
	Device dev1(1, "Temperature", 10, 30, 1);
	Device dev2(2, "Pressure", 10, 100, 2);
	
	while(true) {
		
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}


	return 0;
}

