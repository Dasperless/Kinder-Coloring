CC=g++
CFLAGS=-Wall
RESULTS=main.cpp nodeadcode
PROGRAM = main.cpp
all: $(RESULTS)

plain: $(PROGRAM)
	$(CC) $(CFLAGS) -o plain $(PROGRAM)

nodeadcode: $(PROGRAM)
	$(CC) $(CFLAGS) -Os -fdata-sections -ffunction-sections -o main $(PROGRAM) -Wl,-gc-sections
clean:
	del *exe