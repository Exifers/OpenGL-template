CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++17 -I src/ -I lib/
LDFLAGS := -lGL -lGLU -lglut -lGLEW -lX11

debug : CXXFLAGS += -g -Werror
all : CXXFLAGS += -Werror

src := $(shell find src/ lib/ -type f -name "*.cc")
obj := $(src:%.cc=%.o)
bin := main

all: $(obj)
	$(CXX) $(fls) $^ $(LDFLAGS) -o $(bin)

warn: $(obj)
	$(CXX) $(fls) $^ $(LDFLAGS) -o $(bin)

debug: $(obj)
	$(CXX) $(fls) $^ $(LDFLAGS) -o $(bin)

clean:
	$(RM) $(obj) $(bin)

.PHONY: all debug clean
