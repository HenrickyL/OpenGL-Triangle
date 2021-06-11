# g++ -o exemplo exemplo.cpp -lglut -lGLU -lm
#-lGL -lGLU -lglfw -lglut -lm
# Variables
MESA = /usr/bin/Mesa-5.0 
INCPATH = -I$(MESA)/include
LIBPATH = -L$(MESA)/lib
LIBS        = -lglut -lGLU -lGL -lglfw -lm -lGLEW  
CFLAGS  = $(INCPATH) -g
LFLAGS  = $(LIBPATH) $(LIBS)


main: window myScene
	g++  -o exe src/bin/*.o src/main.cpp $(LIBS)
	mv exe src/bin


window:
	g++   -c   window.o  src/models/window.cpp  $(LFLAGS) 
	mv window.o src/bin

myScene: 
	g++ -c myScene.o src/models/myScene.cpp $(LFLAGS)
	mv myScene.o src/bin


# clean:
#     rm -rf *.o *~ 
run: 
	clear
	./src/bin/exe