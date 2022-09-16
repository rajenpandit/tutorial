CXX=/usr/bin/g++
OBJDIR=obj
OBJS := $(patsubst %.cpp,$(OBJDIR)/%.o,$(wildcard *.cpp))
HEADERS:= $(wildcard *.h)

CPPFLAGS := $(CPPFLAGS) -std=c++11 -g
algoTest: $(OBJS) 
	$(CXX) $(LDFLAGS) $(OBJS) -o algoTest

$(OBJDIR)/%.o : %.cpp $(HEADERS)
	echo $@
	@mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm $(OBJS)