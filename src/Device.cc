#include <Device.h>

std::mutex Device::publishMutex;

void Device::publishFnc() {
	while(true) {
	
	
		std::this_thread::sleep_for(std::chrono::seconds(this->Interval));
		std::lock_guard<std::mutex> lock(publishMutex);
		this->Data = generateData(this->dataMin, this->dataMax);
		//MqttPublish();
		std::cout << "Device Id:" << this->DeviceId << " - Sensor Type: " << this->SensorType << " - Data: " << this->Data << std::endl;
		//std::this_thread::sleep_for(3s);
	
	}
}

/*
Device::~Device() {

	if( publishThread != nullptr ) {
		delete publishThread;
	}
}
*/
void Device::startThread() {
    //publishThread = new std::thread(&Device::publishFnc, this);
    publishThread = std::thread(&Device::publishFnc, this);
}


int Device::generateData(int dataMin, int dataMax) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(dataMin, dataMax);
    return dist(gen);
}

/*
    int Device::generateData(int dataMin, int dataMax) {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(min, max);
        this->Data = distribution(generator);
        return this->Data;
    }

    int main() {
    Device dev(1, "Temperature", 0, 100, 1000);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 0;
}
*/
