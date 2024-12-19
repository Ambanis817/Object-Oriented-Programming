#Samuel Ambani 1001234567

SRC1 = Code5_1001694453.cpp
SRC2 = House.cpp
SRC3 = TrickOrTreater.cpp
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)
EXE = $(SRC1:.cpp=.e)

CFLAGS = -g -std=c++11 -pthread

all : $(EXE)
 
$(EXE): $(OBJ1) $(OBJ2) $(OBJ3)
	g++ $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) -o $(EXE) 

$(OBJ1) : $(SRC1)
	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1) 

$(OBJ2) : $(SRC2)
	g++ -c $(CFLAGS) $(SRC2) -o $(OBJ2)	

$(OBJ3) : $(SRC3)
	g++ -c $(CFLAGS) $(SRC3) -o $(OBJ3)





