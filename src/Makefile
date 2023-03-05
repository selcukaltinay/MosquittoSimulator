CC=g++

OBJ= Device.o testSimulator.o

LIBS= -lpaho-mqttpp3 -lpaho-mqtt3as 

INCLUDE= -I${MQTT_SIMULATOR_DIR}/inc/ -I${MQTT_SIMULATOR_DIR}/inc/mqtt/

OUT= testSimulator

all: ${OUT}

testSimulator: ${OBJ}
	$(CC) $^ -o $@ $(INCLUDE) -L${LIBS} -lpaho-mqttpp3

Device.o: 
	$(CC) -c ${MQTT_SIMULATOR_DIR}/src/Device.cc $(INCLUDE) -L${LIBS} -lpaho-mqttpp3

testSimulator.o:
	$(CC) -c testSimulator.cc $(INCLUDE) -L${LIBS} -lpaho-mqttpp3

clean:
	-rm *.o 
	-rm $(OUT)
