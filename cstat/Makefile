PLUGIN = cstat.so

PLUGINS_DIR = $(shell $(CC) -print-file-name=plugin)

CPPFLAGS   += -Wall -Wextra
CXXFLAGS   += -I$(PLUGINS_DIR)/include -fPIC -fno-rtti

$(PLUGIN): cstat.o
	$(CXX) -shared $^ -o $@

test: $(PLUGIN) test.c
	$(CC) -Wundef $(CPPFLAGS) -fplugin=./$(PLUGIN) test.c -o $@

.PHONY: clean
clean:
	$(RM) $(PLUGIN) test *.o
