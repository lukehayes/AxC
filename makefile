CC      = gcc
CFLAGS  = -Iinclude
LDFLAGS = -lglfw -lX11 -ldl -lpthread -lm
BIN     = -o bin/app
ENTRY   = main.c
OBJ     = obj
#OBJS    = $(OBJ)/glad.o
				  #$(OBJ)/FileIO.o
					#$(OBJ)/Shader.o
					#$(OBJ)/MathUtil.o
				  #$(OBJ)/VertexBuffer.o
				  #$(OBJ)/Engine.o
OBJS    = $(patsubst %c, %o, $(wildcard src/*.c))

$(OBJ)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJS)
	$(CC) $(ENTRY) $^ $(BIN) $(CFLAGS) $(LDFLAGS)

debug: $(OBJS)
	$(CC) $(ENTRY) $^ $(BIN) $(CFLAGS) -g $(LDFLAGS)

release: $(OBJS)
	$(CC) $(ENTRY) $^ $(BIN) $(CFLAGS) -O3 $(LDFLAGS)

preprocess: $(OBJS)
	$(CC) $(ENTRY) -E $^ $(BIN) $(CFLAGS) $(LDFLAGS)

clean:
	rm -r bin/* obj/*.o src/*.o
