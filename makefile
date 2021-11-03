CC = gcc
AR = ar
OBJECTS_MAIN = main.o 
OBJECTS_LIB=basicClassification.o advancedClassificationLoop.o advancedClassificationRecursion.o

FLAGS= -Wall -g 

all: libNumClass.so libNumClass.a progmains progmaind



progmains: $(OBJECTS_MAIN) libNumClass.a
	$(CC) $(FLAGS) -o progmains $(OBJECTS_MAIN) libNumClass.a -lm 
progmaind: $(OBJECTS_MAIN) libNumClass.so
	$(CC) $(FLAGS) -o progmaind $(OBJECTS_MAIN) ./libNumClass.so -lm 

libNumClass.so: $(OBJECTS_LIB)
	$(CC) -shared -o libNumClass.so $(OBJECTS_LIB) -lm 
libNumClass.a: $(OBJECTS_LIB)
	$(AR) -rcs libNumClass.a $(OBJECTS_LIB) 

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c  -lm 

NumClass.o: basicClassification.c advancedClassificationLoop.c advancedClassificationRecursion.c NumClass.h 
	$(CC) $(FLAGS) -c basicClassification.c -c advancedClassificationLoop.c -c advancedClassificationRecursion.c -lm 


.PHONY: clean all 

clean: 
	rm -f *.o *.a *.so progmains progmaind 