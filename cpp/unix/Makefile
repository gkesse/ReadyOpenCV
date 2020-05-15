GSRC = ../code/GProject/src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)/gp_opencv

GINCS = \
    -I$(GSRC)/include \
    -I/usr/include/opencv4 \
    
GLIBS = \
    -lopencv_gapi -lopencv_stitching -lopencv_alphamat -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_cvv -lopencv_dnn_objdetect -lopencv_dnn_superres -lopencv_dpm -lopencv_highgui -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hdf -lopencv_hfs -lopencv_img_hash -lopencv_intensity_transform -lopencv_line_descriptor -lopencv_quality -lopencv_rapid -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_dnn -lopencv_plot -lopencv_videostab -lopencv_videoio -lopencv_viz -lopencv_xfeatures2d -lopencv_shape -lopencv_ml -lopencv_ximgproc -lopencv_video -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core \
    -ltesseract -larchive -lcurl -lzbar -lfmt \
    
GOBJS = \
    $(patsubst $(GSRC)/%.cpp, $(GBUILD)/%.o, $(wildcard $(GSRC)/*.cpp)) \
    $(patsubst $(GSRC)/manager/%.cpp, $(GBUILD)/%.o, $(wildcard $(GSRC)/manager/*.cpp)) \

GCFLAGS = \
    -std=gnu++11 \
    
all: compile run

compile: $(GOBJS)
	@if ! [ -d $(GBIN) ] ; then mkdir -p $(GBIN) ; fi
	g++ -o $(GTARGET) $(GOBJS) $(GLIBS) 
$(GBUILD)/%.o: $(GSRC)/%.cpp
	@if ! [ -d $(GBUILD) ] ; then mkdir -p $(GBUILD) ; fi
	g++ $(GCFLAGS) -c $< -o $@ $(GINCS)
$(GBUILD)/%.o: $(GSRC)/manager/%.cpp
	@if ! [ -d $(GBUILD) ] ; then mkdir -p $(GBUILD) ; fi
	g++ $(GCFLAGS) -c $< -o $@ $(GINCS)
run:
	@$(GTARGET) $(args)
clean: 
	rm -f $(GBUILD)/* $(GBIN)/*
