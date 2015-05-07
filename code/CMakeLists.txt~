cmake_minimum_required(VERSION 2.8)
file(GLOB sources *.h *.c *.cxx *.cpp *.hxx *.C)
file(GLOB main main.C)
list(REMOVE_DUPLICATES sources)
INCLUDE_DIRECTORIES( ~cdshaffer/allegro/include )
LINK_DIRECTORIES( ~cdshaffer/allegro/lib )
add_executable(main ${sources})

TARGET_LINK_LIBRARIES(main liballegro.so liballegro_dialog.so liballegro_main.so liballegro_image.so)

# I don't think this works
SET(GCC_DEBUG_COMPILE_FLAGS "-ggdb")
SET(GCC_DEBUG_LINK_FLAGS    "-ggdb")

add_definitions(${GCC_DEBUG_COMPILE_FLAGS})

#
# Add support for documentation generation via Doxygen
#
ADD_CUSTOM_TARGET(doc COMMAND doxygen Doxyfile)

#
#   BOOST unit test support
#

