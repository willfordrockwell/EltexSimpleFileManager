CCFLAGS = -lncurses
CC = gcc
SOURCES = FileManager.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = $(SOURCES:.c=)

LIB_GRAPH_DIR = graph/
LIB_GRAPH = $(LIB_GRAPH_DIR:/=)
LIB_LOGIC_DIR = logic/
LIB_LOGIC= $(LIB_LOGIC_DIR:/=)

all: app

debug: CCFLAGS += -g
#debug: CCFLAGS += -DDEBUG
debug: clean
debug: app

app: libgraph liblogic $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE).elf $(CCFLAGS) -L./$(LIB_GRAPH) -l$(LIB_GRAPH) -L./$(LIB_LOGIC) -l$(LIB_LOGIC)

libgraph:
	make -C $(LIB_GRAPH_DIR)

liblogic:
	make -C $(LIB_LOGIC_DIR)

$(OBJECTS): $(SOURCES)
	$(CC) $(SOURCES) -c $(CCFLAGS)

all: app

.PHONY: clean
clean:
	rm -r *.elf *.o $(LIB_GRAPH_DIR)*.a $(LIB_GRAPH_DIR)*.o $(LIB_LOGIC_DIR)*.a $(LIB_LOGIC_DIR)*.o
