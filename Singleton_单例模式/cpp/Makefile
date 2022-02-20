BIN = main_static main_pthread
ALL: ${BIN}
CC=g++

main_static: main_static.cc
	${CC} main_static.cc -o main_static -lpthread

main_pthread: main_pthread.cc pthread_once.h
	${CC} main_pthread.cc pthread_once.h -o main_pthread -lpthread

clean:
	rm -rf ${BIN} *.o