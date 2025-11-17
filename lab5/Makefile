CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

OBJ = src/main.c src/dynarray.o 

TARGET = prueba_dyn

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

src/%.o: src/%.c include/dynarray.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm .f $(OBJ) $(TARGET)