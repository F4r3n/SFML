CXX = g++ 
CFLAGS = -W -Wall --std=c++11 -g -lsfml-graphics -lsfml-window -lsfml-system
SRC = src/
INCLUDE=-I include/
BIN= bin/

all: main

main: $(BIN)main.o $(BIN)player.o $(BIN)entity.o $(BIN)box.o $(BIN)level.o $(BIN)game.o $(BIN)engine.o $(BIN)screen.o
	$(CXX) -o  $@ $^ $(CFLAGS) $(INCLUDE)

$(BIN)%.o: $(SRC)%.cpp
	$(CXX) $(INCLUDE) -o $@ -c $< $(CFLAGS)

clean:
	-rm -f $(BIN)*.o
	-rm main
