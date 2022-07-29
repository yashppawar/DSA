CC=clang
CFLAGS=-g -Wall 

Vector/%.o: Vector/%.c Vector/%.h
	$(CC) $(CFLAGS) -c $^

vector: bin/vector

bin/vector: $(patsubst Vector/%.c, Vector/%.o, $(wildcard Vector/*.c))
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm */**.o bin/*
