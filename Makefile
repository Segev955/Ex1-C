CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LOOP=advancedClassificationLoop.o basicClassification.o
OBJECTS_REC=advancedClassificationRecursion.o basicClassification.o
FLAGS= -Wall -g

libclassloops.a : $(OBJECTS_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOP) 
libclassrec.a : $(OBJECTS_REC)
	$(AR) -rcs libclassrec.a $(OBJECTS_REC)
libclassrec.so : $(OBJECT_REC)
	$(CC) -shared -o libclassrec.so $(OBJECTS_REC) -lm 
libclassloops.so : $(OBJECTS_LOOP)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LOOP) -lm 
mains : $(OBJECTS_MAIN) libclassrec.a 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a -lm 
maindloop: $(OBJECTS_MAIN) libclassloops.so 
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) libclassloops.so -lm 
maindrec: $(OBJECTS_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) libclassrec.so -lm 
all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains maindloop maindrec

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec