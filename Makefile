CXX = g++
all: output.out

output.out: main.o game.o map.o player.o room.o weapon.o hazard.o
	$(CXX) main.o game.o map.o player.o room.o weapon.o hazard.o -o output.out

main.o: main.cpp
	$(CXX) -c main.cpp -o main.o

game.o: game.cpp game.h
	$(CXX) -c game.cpp -o game.o

map.o: map.cpp map.h
	$(CXX) -c map.cpp -o map.o

player.o: player.cpp player.h
	$(CXX) -c player.cpp -o player.o

room.o: room.cpp room.h
	$(CXX) -c room.cpp -o room.o

weapon.o: weapon.cpp weapon.h
	$(CXX) -c weapon.cpp -o weapon.o

hazard.o: hazard.cpp hazard.h
	$(CXX) -c hazard.cpp -o hazard.o

clean:
	rm -f *.o output.out

run:
	./output.out