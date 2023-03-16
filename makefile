COURSE = cs240
SEMESTER = spring2023
CP_NUMBER = 3
LASTNAME = Klein
GITUSERID = Sam-Klein1
EXE = ZLL

#REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
REPODIR = ../CP3

TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g

FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/test.o
	$(CC) $(FLAGS) $(OBJ)/test.o -o $@

$(OBJ)/test.o: test.cpp ZLL.h zany.h
	$(CC) $(FLAGS) -c test.cpp -o $@

tar: clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz