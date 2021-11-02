CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LOOP=advancedClassificationLoop.o
OBJECTS_REC=advancedClassificationRecursion.o
OBJECTS_BASEIC=basicClassification.o
FLAGS= -Wall -g

libclassloops.a : $ (OBJECTS_LOOP) $ (OBJECTS_BASEIC)
	$(AR) -rcs libclassloops.a $ (OBJECTS_LOOP) $ (OBJECTS_BASEIC)
libclassrec.a : $ (OBJECTS_REC)
	$(AR) -rcs libclassrec.a $ (OBJECTS_REC) $ (OBJECTS_BASEIC)
libclassrec.so : $ (OBJECT_REC) $ (OBJECTS_BASEIC)
	$(CC) -shared -o libclassrec.so $(OBJECTS_REC) $ (OBJECTS_BASEIC)
libclassloops.so : $ (OBJECTS_LOOP) $ (OBJECTS_BASEIC)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LOOP) $ (OBJECTS_BASEIC)
mains : $(OBJECTS_MAIN) libclassrec.a 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a 
maindloop: $(OBJECTS_MAIN) libclassloops.so 
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) libclassloops.so 
maindrec: $(OBJECTS_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) libclassrec.so
all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains maindloop maindrec

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec