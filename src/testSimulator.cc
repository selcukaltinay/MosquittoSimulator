#include <iostream>
#include <Device.h>
#include <chrono>

int main() 
{
	std::cout << "The simulator begun" << std::endl;
	Device dev1(1, "Temperature", 10, 30, 1);
	Device dev2(2, "Pressure", 10, 100, 1);
	Device dev3(3, "EKG", 80, 100, 1);
	Device dev4(4, "Saturation", 94, 100, 1);
	Device dev5(5, "CO2", 20, 30, 1);
	Device dev6(5, "O2", 40, 70, 1);
	Device dev7(5, "Noise", 80, 110, 1);

	
	while(true) {
		
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}


	return 0;
}

