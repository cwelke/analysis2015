CC = g++
INCLUDE = -I../ -I./ 
CFLAGS = -Wall -g -fPIC $(shell root-config --cflags) $(INCLUDE) $(EXTRACFLAGS) -DTOOLSLIB
LINKER = g++

LINKERFLAGS = $(shell root-config --ldflags) $(shell root-config --libs) -lMinuit
ifeq ($(shell root-config --platform),macosx)
	LINKERFLAGS = -dynamiclib -undefined dynamic_lookup -Wl,-x -O -Xlinker -bind_at_load -flat_namespace $(shell root-config --libs) -lEG -lGenVector
endif

SOURCES = ScanChain.cc
OBJECTS = $(SOURCES:.cc=.o) LinkDef_out.o
LIB = libScanChain.so

CORESOURCES = $(wildcard ../CORE/*.cc)
COREOBJECTS = $(CORESOURCES:.cc=.o) 
CORELIB = libBabymakerCORE.so

TOOLSSOURCES = $(wildcard ../Tools/*.cc) $(wildcard ../Tools/MT2/*.cc)
TOOLSOBJECTS = $(TOOLSSOURCES:.cc=.o) 
TOOLSLIB = libBabymakerTools.so

#FWLIB = libMiniFWLite.so
FWLIB = ../Software/MiniFWLite/libMiniFWLite.so

LIBS = $(LIB) $(CORELIB) $(TOOLSLIB) $(FWLIB) 

.PHONY: all help compile clean cms2env

libs:	$(LIBS)

$(LIB):	$(OBJECTS) 
	echo "Linking $(LIB)"; \
	$(LINKER) $(LINKERFLAGS) -shared $(OBJECTS) -o $@

$(CORELIB):	$(COREOBJECTS) 
	echo "Linking $(CORELIB)"; \
	$(LINKER) $(LINKERFLAGS) -shared $(COREOBJECTS) -o $@

$(TOOLSLIB):	$(TOOLSOBJECTS) 
	echo "Linking $(TOOLSLIB)"; \
	$(LINKER) $(LINKERFLAGS) -shared $(TOOLSOBJECTS) -o $@

$(FWLIB):
	echo "making MiniFWLite"; \
        cd ../Software/MiniFWLite; \
        $(MAKE) -f Makefile; cd -; \
	cp $(FWLIB) .;

LinkDef_out.cxx: LinkDef.h ScanChain.h
	rootcint -f $@ -c $(INCLUDE) ScanChain.h $<

# General rule for making object files
%.d:	%.cc
	$(CC) -MM -MT $@ -MT ${@:.d=.o} $(CFLAGS) $< > $@; \
                     [ -s $@ ] || rm -f $@
%.d:	%.cxx
	$(CC) -MM -MT $@ -MT ${@:.d=.o} $(CFLAGS) $< > $@; \
                     [ -s $@ ] || rm -f $@

%.o: 	%.cc 
	$(CC) $(CFLAGS) $< -c -o $@

%.o: 	%.cxx
	$(CC) $(CFLAGS) $< -c -o $@

.PHONY: all
all:	$(LIBS)  

.PHONY: clean
clean:  
	rm -v -f \
        ../CORE/*.o \
        ../CORE/*.d \
        ../CORE/*.so \
        ../Tools/*.o \
		../Tools/*.d \
        ../Tools/*.so \
        ../Tools/MT2/*.o \
		../Tools/MT2/*.d \
        ../Tools/MT2/*.so \
        ../Software/MiniFWLite/*.o \
		../Software/MiniFWLite/*.d \
        $(CORELIB) $(TOOLSLIB) $(MT2CORELIB) $(LIB) $(FWLIB) \
        LinkDef_out.cxx  LinkDef_out.h \
        *.o *.d *.so; echo "Done"

test: 
	@echo $(INCLUDE)

-include $(LIBDIR)/LinkDef_out.d
