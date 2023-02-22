CC=g++

OBJ= Device.o testSimulator.o

LIBS=

INCLUDE= ${MQTT_SIMULATOR_DIR}/inc/

OUT= testSimulator

all: ${OUT}

testSimulator: ${OBJ}
	$(CC) $^ -o $@ -I $(INCLUDE)

Device.o: 
	$(CC) -c ${MQTT_SIMULATOR_DIR}/src/Device.cc -I $(INCLUDE)

testSimulator.o:
	$(CC) -c testSimulator.cc -I $(INCLUDE)

clean:
	-rm *.o 
	-rm $(OUT)
