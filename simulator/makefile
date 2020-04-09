#make -f makefile_perso all2

TARGET 		= main

CC 		= g++

CFLAGS 		= -W -Wall# -fopenmp -O3

LINKER 		= g++ -o

LFLAGS 		= -Wall# -I. -fopenmp -lm

SRCDIR      = .

OBJDIR 		= obj
BINDIR 		= bin

SOURCES 	:= $(wildcard $(SRCDIR)/*.cpp)
INCLUDES 	:= $(wildcard $(SRCDIR)/*.h)
OBJECTS 	:= $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm 		= rm -f

all: $(BINDIR)/$(TARGET)
#all: $(OBJECTS)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(OBJECTS) $(LFLAGS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all2:
	@$(CC) $(CFLAGS) -c src/main.cpp -o obj/main.o
	@$(CC) $(CFLAGS) -c src/cube.cpp -o obj/cube.o
	@$(LINKER) bin/main obj/main.o obj/cube.o $(LFLAGS)

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
