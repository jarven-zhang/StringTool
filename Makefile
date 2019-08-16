#DIR_INC = ./include
DIR_SRC = ./src

SRC = $(wildcard ${DIR_SRC}/*.cpp)  

TARGET = server
LIB = -lpthread

CC = g++
#CFLAGS = -g -Wall -I${DIR_INC} 
CFLAGS = -g -Wall -std=c++11

    
${TARGET}:${SRC}
	$(CC) $(CFLAGS) $^ -o $@ ${LIB}

.PHONY:clean
clean:
	rm  $(TARGET)

