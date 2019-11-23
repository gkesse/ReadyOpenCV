GREADYLIB = C:\Users\Admin\Downloads\Programs\ReadyLib\dev
GSRC = ../code/GOpenCV/src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)/GOpenCV.exe

GINCS = \
    -I$(GSRC)\manager \
    -I$(GREADYLIB)\opencv\c\2.4.13.6\include \

GLIBS = \
    -L$(GREADYLIB)\opencv\c\2.4.13.6\mingw64\lib \
    -lopencv_core2413 -lopencv_highgui2413 -lopencv_imgproc2413 \

GOBJS = \
    $(patsubst $(GSRC)/%.c, $(GBUILD)/%.o, $(wildcard $(GSRC)/*.c)) \
    $(patsubst $(GSRC)/manager/%.c, $(GBUILD)/%.o, $(wildcard $(GSRC)/manager/*.c)) \

GCFLAGS = \
    -std=c11 \
    -Wunused-function \
    -Wno-unused-function \
    
all: $(GOBJS)
	@if not exist "$(GBIN)" @mkdir $(GBIN)
	gcc -o $(GTARGET) $(GOBJS) $(GLIBS) 
$(GBUILD)/%.o: $(GSRC)/%.c
	@if not exist "$(GBUILD)" @mkdir $(GBUILD)
	gcc $(GCFLAGS) -c $< -o $@ $(GINCS)
$(GBUILD)/%.o: $(GSRC)/manager/%.c
	@if not exist "$(GBUILD)" @mkdir $(GBUILD)
	gcc $(GCFLAGS) -c $< -o $@ $(GINCS)
clean:
	del /q $(GBUILD)\*.o $(GBIN)\*.exe
