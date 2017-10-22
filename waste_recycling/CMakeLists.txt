project(dustbin)

set(HEADER_FILES
        dustbin/BottleCapException.hpp
        dustbin/Dustbin.h
        dustbin/Dustbin9000.h
        dustbin/DustbinContentError.hpp
        garbage/BottleCap.hpp
        garbage/Garbage.hpp
        garbage/MetalGarbage.hpp
        garbage/PaperGarbage.hpp
        garbage/PlasticGarbage.hpp
        dustbin/DustbinIsFullException.hpp
        UserInterface.h)

set(SOURCE_FILES
        dustbin/Dustbin.cpp
        dustbin/Dustbin9000.cpp
        UserInterface.cpp)

add_library(waste_recycling STATIC ${SOURCE_FILES} ${HEADER_FILES})