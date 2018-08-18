SH := $(shell 'pwd')
PROJECT :=$(notdir $(SH))
SOURCES := $(wildcard $(SH)/*.cpp)
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))
DEPENDS := $(patsubst %.cpp, %.dep, $(SOURCES))

CFLAGS = -c    
LFLAGS = -ggdb
CC = g++ 
$(PROJECT):$(OBJ) $(OBJECTS)
	@echo compiling $^
	$(CC) $(LFLAGS) $(OBJECTS) -o $@
	rm -rf *.o *.dep

%.o : %.cpp 
	@echo compiling $^
	$(CC) $(CFLAGS) $< -o $@ 
%.dep : %.cpp 
	@echo generating $^
	$(CC) -MM $< -MT "$@ $(subst .dep, .o, $@)" -o $@
.PHONY: clean
clean:
	rm -rf *.o *.dep *~ $(PROJECT)
-include $(DEPENDS)
