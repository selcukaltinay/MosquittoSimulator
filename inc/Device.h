#ifndef DEVICE_H_
#define DEVICE_H_

#include <iostream>
#include <string>
#include <thread>
#include <functional>
#include <chrono>
#include <random>
#include <mutex>
#include <mqtt/client.h>

class Device {
public:

    Device(int DeviceId, std::string SensorType, int dataMin, int dataMax, int Interval) : DeviceId(DeviceId), SensorType(SensorType), dataMin(dataMin), dataMax(dataMax), Interval(Interval) {
        mqttConfig("localhost:1883", "consumer");
        startThread();
    }

    ~Device();

    void publishFnc();
    void setInterval();
    std::string getInteravl();
    void setDeviceId();
    int getDeviceId();
    void setSensorType();
    std::string getSensorType();
    void setData();
    int getData();
    void mqttConfig(std::string ipport, std::string id);
    void mqttPublish(std::string data);

private:
    //static mqtt::client* cli;
    static mqtt::async_client* cli;
    std::thread publishThread;
    static std::mutex publishMutex;
    //std::thread* publishThread;
    int DeviceId;
    std::string SensorType;
    int Data;
    std::string Timestamp;
    int Interval;
    int dataMin;
    int dataMax;
    std::string topic;
private:
    void startThread();
    int generateData(int dataMin, int dataMax);
};

#endif



