#ifndef DEVICE_H_
#define DEVICE_H_

#include <iostream>
#include <string>
#include <thread>
#include <functional>
#include <chrono>
#include <random>
#include <mutex>

class Device {
public:
    Device(int DeviceId, std::string SensorType, int dataMin, int dataMax, int Interval) : DeviceId(DeviceId), SensorType(SensorType), dataMin(dataMin), dataMax(dataMax), Interval(Interval) {
        startThread();
	//publishThread=nullptr;
    }
    //~Device();
    void publishFnc();
    void setInterval();
    std::string getInteravl();
    void setDeviceId();
    int getDeviceId();
    void setSensorType();
    std::string getSensorType();
    void setData();
    int getData();
private:
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
private:
    void startThread();
    int generateData(int dataMin, int dataMax);
};

#endif



