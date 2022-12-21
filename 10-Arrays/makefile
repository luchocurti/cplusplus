# Macros
CPP = g++                  # Define CPP as g++
CFLAGS = -Wall             # Warnings (define CLAGS as flags to g++)
STD = c++14                # Standard of the input sources
OPTIMIZATION = -O0         # Optimization level (None)
OBJS = program.o           # Define Object code files
INCLUDE = -Ipath           # Define path as an INCLUDE directory
DEPS = program.h           # List ALL needed *.h headers files here
OUT_FILE = program.out     # Place here the name of the output file

# Target (file or label): Dependency List
# <Tab>Rules

%.o: %.cpp $(DEPS)         # for all *.o files: if its *.cpp or *.h file changed
	$(CPP) -std=$(STD) $(CFLAGS) $(OPTIMIZATION) -c $*.cpp -o $@
                           # compile corresponding .cpp file again, and give its
                           # the current target name

$(OUT_FILE): $(OBJS)       # target: dependency list of *.o files
	$(CPP) -std=$(STD) $(CFLAGS) $(OPTIMIZATION) $^ $(INCLUDE) -o $@

install: $(OUT_FILE)       # make will build program.out first
	echo Install $(OUT_FILE) in /usr/local/bin
	sudo mv $(OUT_FILE) /usr/local/bin/	

all: $(OUT_FILE) install   # build all listed targets: program.out, install

run: install               # depend on install
	echo Run executable image $(OUT_FILE)
	$(OUT_FILE) || /bin/true
                           # No make error 10 if main() return non-zero

clean:
	rm -f *.o 2> /dev/null
                           # Remove all *.o files
	sudo rm -f /usr/local/bin/$(OUT_FILE)
                           # Remove the program.out
