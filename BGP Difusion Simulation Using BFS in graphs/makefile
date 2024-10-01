CPPFLAGS=-std=c++17 -Wall -Wextra
IPATH=-Iinc/
SRC=src/
OBJ=obj/

all: app

app: main.gch Network.gch AutonomousSystem.gch  
	g++ $(OBJ)main.gch $(OBJ)Network.gch $(OBJ)AutonomousSystem.gch -o app

main.gch: $(SRC)main.cpp
	$(CHAIN)-gcc $(CPPFLAGS) $(IPATH) -c $(SRC)main.cpp -o $(OBJ)main.gch

Network.gch: $(SRC)Network.cpp
        $(CHAIN)-gcc $(CPPFLAGS) $(IPATH) -c $(SRC)Network.cpp -o $(OBJ)Network.gch

AutonomousSystem.gch: $(SRC)AutonomousSystem.cpp
        $(CHAIN)-gcc $(CPPFLAGS) $(IPATH) -c $(SRC)AutonomousSystem.cpp -o $(OBJ)AutonomousSystem.gch

clean:
	rm -rf $(OBJ)*.gch

