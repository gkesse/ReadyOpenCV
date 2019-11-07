GREADYLIB = C:\Users\Admin\Downloads\Programs\ReadyLib\dev
GSRC = ../code/GOpenCV/src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)/GOpenCV.exe

GINCS = \
    -I$(GSRC)\manager \
    -I$(GREADYLIB)\glfw\c\3.3\include \

GLIBS = \
    -L$(GREADYLIB)\glfw\c\3.3\mingw64\lib \
    
GOBJS = \
    $(patsubst $(GSRC)/%.c, $(GBUILD)/%.o, $(wildcard $(GSRC)/*.c)) \
    $(patsubst $(GSRC)/manager/%.c, $(GBUILD)/%.o, $(wildcard $(GSRC)/manager/*.c))
    	
all: $(GOBJS)
	@if not exist "$(GBIN)" @mkdir $(GBIN)
	gcc -o $(GTARGET) $(GOBJS) $(GLIBS) 
$(GBUILD)/%.o: $(GSRC)/%.c
	@if not exist "$(GBUILD)" @mkdir $(GBUILD)
	gcc -Wall -std=c11 -c $< -o $@ $(GINCS)
$(GBUILD)/%.o: $(GSRC)/manager/%.c
	@if not exist "$(GBUILD)" @mkdir $(GBUILD)
	gcc -Wall -std=c11 -c $< -o $@ $(GINCS)
clean:
	del /q $(GBUILD)\*.o $(GBIN)\*.exe
