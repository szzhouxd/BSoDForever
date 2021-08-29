C = $(CROSSPREFIX)gcc

PROGRAM = build/bsod.exe
OBJECTS = build/obj/bsod.o
SOURCE = src/bsod.c

INCLUDEDIR = 
LIBDIR = 
LIBS = -lkernel32
CFLAGS = -DUNICODE -O2
LDFLAGS = -s -static -mwindows

$(PROGRAM) : $(OBJECTS)
	$(C) $(LDFLAGS) -o $(PROGRAM) $(OBJECTS) $(LIBDIR) $(LIBS)

$(OBJECTS) : $(SOURCE)
	$(C) -c $(SOURCE) -o $(OBJECTS) $(CFLAGS) $(INCLUDEDIR)

.PHONY : clean

clean :
	-DEL $(PROGRAM) $(OBJECTS)
