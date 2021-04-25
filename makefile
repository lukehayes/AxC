CC      = gcc
CFLAGS  = -Iinclude
LDFLAGS = -lm
BIN     = -o bin/app
ENTRY   = main.c
OBJ     = obj
#OBJS    = $(OBJ)/Vec2.o $(OBJ)/Mat4.o

$(OBJ)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJS)
	$(CC) $(ENTRY) $^ $(BIN) $(CFLAGS) $(LDFLAGS)

clean:
	rm -r bin/* obj/*.o
