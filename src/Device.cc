#include <Device.h>

//mqtt::client* Device::cli = nullptr;
mqtt::async_client* Device::cli = nullptr;

std::mutex Device::publishMutex;

void Device::publishFnc() {

    if (cli == nullptr)
        mqttConfig("localhost:1883", "consumer");
    
	while(true) {
        
		std::this_thread::sleep_for(std::chrono::seconds(this->Interval));
		std::lock_guard<std::mutex> lock(publishMutex);
        topic = this->SensorType;
		this->Data = generateData(this->dataMin, this->dataMax);
        std::cout << "Topic: " << topic << std::endl;
		std::cout << "Device Id:" << this->DeviceId << " - Sensor Type: " << this->SensorType << " - Data: " << this->Data << std::endl;
        try {
            auto msg = mqtt::make_message(topic, std::to_string(this->Data));
            cli->publish(msg);
        }
        catch (const mqtt::exception& exc) {
            std::cerr << "Error: " << exc.what() << " ["
                << exc.get_reason_code() << "]" << std::endl;
        }
		//std::this_thread::sleep_for(3s);
	
	}
}


Device::~Device() {
	/*if( publishThread != nullptr ) {
		delete publishThread;
	}*/

    cli->disconnect();
    if( cli != nullptr)
        delete cli;
}

void Device::startThread() {
    //publishThread = new std::thread(&Device::publishFnc, this);
    publishThread = std::thread(&Device::publishFnc, this);
}

void Device::mqttConfig(std::string ipport, std::string id) {
    cli = new mqtt::async_client(ipport, id);
    //cli = new mqtt::client(ipport, id);

    mqtt::connect_options connOpts;
    
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);
    cli->connect(connOpts);
    std::this_thread::sleep_for(std::chrono::seconds(2));

}

void Device::mqttPublish(std::string data) {
    try {
        std::cout << topic << std::endl;
        std::cout << data << std::endl;
        auto msg = mqtt::make_message(topic, data);
        cli->publish(msg);
        // Second way to publish -> client.publish(TOPIC, PAYLOAD, strlen(PAYLOAD), 0, false);
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << " ["
            << exc.get_reason_code() << "]" << std::endl;
    }
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
