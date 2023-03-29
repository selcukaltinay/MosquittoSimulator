cmake_minimum_required(VERSION 3.5)

project(testSimulator)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenSSL REQUIRED)
find_package(PahoMqttCpp REQUIRED)

set(SOURCES
    Device.cc
    testSimulator.cc
)

add_executable(testSimulator ${SOURCES})

target_include_directories(testSimulator
    PRIVATE ${MQTT_SIMULATOR_DIR}/inc
    PRIVATE ${MQTT_SIMULATOR_DIR}/inc/mqtt
    PRIVATE ${PahoMqttCpp_INCLUDE_DIRS}
)

target_link_libraries(testSimulator
    PRIVATE paho-mqtt3as
    PRIVATE paho-mqttpp3
)
