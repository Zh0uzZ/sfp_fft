CC = clang
CXX = clang++

FLAGS = -Ilib -O2 -Wall -g
CFLAGS = -std=c99 $(FLAGS)
CXXFLAGS = -std=c++11 $(FLAGS)

LIB_TARGET = lib/libsfp.a
LIB_OBJ = lib/op.o lib/pack.o lib/sfp.o lib/utils.o lib/fft_1d.o lib/fft_1dd.o lib/fft_1d_size4.o

TARGET = sfp
OBJ = main.o $(LIB_TARGET)

all: $(TARGET) $(TEST_TARGET)

# out: $(TARGET) > out.log

clean:
	-rm -f lib/*.o $(LIB_TARGET)
	-rm -f *.o $(TARGET)
	-rm -f *.log

$(LIB_TARGET): $(LIB_OBJ)
	ar rcs $@ $^

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) -c $^

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $^
