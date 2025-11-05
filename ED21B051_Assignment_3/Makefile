
compiler = clang

SRC = main.c
BIN = viewer

INCLUDE = -I/opt/homebrew/include
LIBPATH = -L/opt/homebrew/lib

LIBS = -lglfw -framework OpenGL -framework GLUT

CFLAGS = -Wall $(INCLUDE) -Wno-deprecated-declarations -Wno-unused-variable -Wno-unused-function

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBPATH) $(LIBS) -o $(BIN)

clean:
	-rm -f $(BIN)
