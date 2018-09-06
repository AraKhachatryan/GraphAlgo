SH := $(shell 'pwd')
PROJECT :=$(notdir $(SH))
OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.hpp)

CC = g++
CFLAGS = -std=c++11 -g -Wall

.PHONY: default all clean

default: $(PROJECT)
all: default

%.o: %.cpp $(HEADERS)
	@echo compiling $< '--->'
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(PROJECT) $(OBJECTS)

$(PROJECT): $(OBJECTS)
	@echo linking $< '--->'
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@
	-rm -f *.o

clean:
	-rm -f *.o
	-rm -f *~
	-rm -f $(PROJECT)
