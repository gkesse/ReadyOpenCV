GSRC = ../code/GProject/src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)/GProject.exe

GINCS = \
    -I$(GSRC)/manager \
    -IC:\Users\Admin\Downloads\OpenCV-MinGW-Build-OpenCV-4.1.0-x64\OpenCV-MinGW-Build-OpenCV-4.1.0-x64\include \

GLIBS = \
    -LC:\Users\Admin\Downloads\OpenCV-MinGW-Build-OpenCV-4.1.0-x64\OpenCV-MinGW-Build-OpenCV-4.1.0-x64\x64\mingw\lib \
    -lopencv_core410 -lopencv_highgui410 -lopencv_imgcodecs410 \
    -lopencv_videoio410 -lopencv_imgproc410

GOBJS = \
    $(patsubst $(GSRC)/%.cpp, $(GBUILD)/%.o, $(wildcard $(GSRC)/*.cpp)) \
    $(patsubst $(GSRC)/manager/%.cpp, $(GBUILD)/%.o, $(wildcard $(GSRC)/manager/*.cpp))

all: $(GOBJS)
	@if not exist "$(GBIN)" @mkdir $(GBIN)
	g++ -std=c++17 -o $(GTARGET) $(GOBJS) $(GLIBS) 
$(GBUILD)/%.o: $(GSRC)/%.cpp
	@if not exist "$(GBUILD)" @mkdir $(GBUILD)
	g++ -std=c++17 -Wall -c $< -o $@ $(GINCS)
$(GBUILD)/%.o: $(GSRC)/manager/%.cpp
	@if not exist "$(GBUILD)" @mkdir $(GBUILD)
	g++ -std=c++17 -Wall -c $< -o $@ $(GINCS)
clean:
	del /q $(GBUILD)\*.o $(GBIN)\*.exe
