
###############################################################################
## 程序名
PROC_NAME = detailsnews
## 输出文件名/var/www/cgi-bin/george/paco
OUTPUT_FILE = /var/www/cgi-bin/george/paco/$(PROC_NAME).fcgi
LIBRARY_PATH = ../../../../../library
PUB_PATH = ../../../../pub
## 编译器
COMPILER = g++
COMPILERC = gcc

## 编译选项
## for debug -DROOM_DEBUG_MCACHE
CPP_FLAG = -g -Wall -w -fPIC -c -D_LINUX -DDEBUG -D_DEBUG -D_REENTRANT -D_GNU_SOURCE -D__DEBUG_CORE__ -DFCGI_STD
## for release
#CPP_FLAG = -O3 -Wall -s -w -fPIC -c -D_LINUX -DNDEBUG -D_REENTRANT -D_GNU_SOURCE -DFCGI_STD

## 链接选项
## for debug
LINK_FLAGS = -g  -fPIC
## for release
## LINK_FLAGS = -s -O3 -shared -fPIC

## 头文件 -I /usr/local/libmemcached-1.0.7/include
INCLUDE_PATHS = -I$(LIBRARY_PATH)/public \
		-I$(LIBRARY_PATH)/base \
		-I$(LIBRARY_PATH) \
		-I../../../../ \
		-I/usr/local/lib \
	        -I$(LIBRARY_PATH)/third_party/breakpad/src  -I$(PUB_PATH)

## 库
LINK_LIBRARYS = -lrt -lpthread -lfcgi++ \

# 编译
COMPILE = $(COMPILER) $(CPP_FLAG) $(INCLUDE_PATHS) -o $@

# 链接
LINK = $(COMPILER) $(LINK_FLAGS) $? -o $(OUTPUT_FILE) $(LINK_LIBRARYS)

all: clean output delete-temp-file

output: $(PROC_NAME).o mig_log.o core_interface.o fcgimodule.o logic_comm.o
	$(LINK)

clean:
	-rm -f *.o
	-rm -f $(OUTPUT_FILE)

delete-temp-file:
	-rm -f *.o

### 编译
$(PROC_NAME).o:
	$(COMPILE) ./$(PROC_NAME).cc
	
fcgimodule.o:
	$(COMPILE) $(PUB_PATH)/fcgimodule/fcgimodule.cc

logic_comm.o:
	$(COMPILE) $(LIBRARY_PATH)/base/logic/logic_comm.cc
	
mig_log.o:
	$(COMPILE) $(LIBRARY_PATH)/public/log/mig_log.cc

core_interface.o:
	$(COMPILE) $(LIBRARY_PATH)/public/comm/core_interface.cc