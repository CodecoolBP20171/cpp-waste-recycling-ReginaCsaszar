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
        )

set(SOURCE_FILES
        dustbin/Dustbin.cpp
        dustbin/Dustbin9000.cpp
        )

add_library(waste_recycling STATIC ${SOURCE_FILES} ${HEADER_FILES})