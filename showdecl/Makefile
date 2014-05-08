PLUGIN = showdecl.so
OBJS   = showdecl.o

PLUGINS_DIR = $(shell $(CC) -print-file-name=plugin)
CXXFLAGS   += -I$(PLUGINS_DIR)/include -fPIC -fno-rtti -W -Wall

$(PLUGIN): $(OBJS)
	$(CXX) -shared $^ -o $@

test: $(PLUGIN) test.c
	$(CXX) -fplugin=./$(PLUGIN) test.c -o $@

.PHONY: clean
clean:
	$(RM) $(OBJS) $(PLUGIN) test
