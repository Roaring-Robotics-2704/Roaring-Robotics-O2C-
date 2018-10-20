################################################################################
# Modded Default Makefile
################################################################################


t := $(wildcard ../examples/*.cpp) $(wildcard ../practice/*.cpp)

all: $(t)
	$(foreach f,$(t),g++ $(f) -I../include/ -o $(subst .cpp,.exe,$(f));)
