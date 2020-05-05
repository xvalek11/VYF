
# C source code
CSRC	= io_png.c transform.c
# C++ source code
CXXSRC	= main.cpp color2grey.cpp rgb2lab.cpp optimalizer.cpp

# all source code
SRC	= $(CSRC) $(CXXSRC)

# C objects
COBJ	= $(CSRC:.c=.o)
# C++ objects
CXXOBJ	= $(CXXSRC:.cpp=.o)
# all objects
OBJ	= $(COBJ) $(CXXOBJ)
# binary target
BIN	= main

default	: $(BIN)

# C optimization flags
COPT	= -O3 -funroll-loops -fomit-frame-pointer  -fno-tree-pre -falign-loops -ffast-math -ftree-vectorize

# C++ optimization flags
CXXOPT	= $(COPT)

# C compilation flags
CFLAGS	= $(COPT) \
	-Wno-write-strings -ansi
# C++ compilation flags
CXXFLAGS	= $(CXXOPT) \
	-Wno-write-strings -Wno-deprecated -ansi -fopenmp
# link flags
LDFLAGS	= -fopenmp -lpng -fPIE -lnlopt -lm


# partial compilation of C source code
%.o: %.c %.h
	$(CC) -c -static -g -o $@  $< $(CFLAGS) -I/opt/local/include/ -I/usr/local/include/   
# partial compilation of C++ source code
%.o: %.cpp %.h
	$(CXX) -c -static -g -o $@  $< $(CXXFLAGS) -I/opt/local/include/ -I/usr/local/include/ 

# link all the object code
$(BIN) : % : %.o  io_png.o transform.o main.o color2grey.o rgb2lab.o optimalizer.o
	$(CXX) -L/opt/local/lib/ -L/usr/local/lib/  -fopenmp -lpng -lnlopt  -fPIE -o $@  $^ $(LDFLAGS)



# housekeeping
.PHONY	: clean distclean
clean	:
	$(RM) $(OBJ) main
distclean	: clean
	$(RM) $(BIN)

