#selbsterklärend
cmake_minimum_required(VERSION 3.5.2)
#projektname und programmiersprache festlegen
project(Dein_projekt_name LANGUAGES CXX)

# cmake module pfad für eventuelle zusätzlichen cmake scripts, also im ordner
# cmake/Additional_cmake.cmake
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${PROJECT_SOURCE_DIR}/cmake)


# für windoofs
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest /wd4141 /WX /arch:AVX2")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ox /arch:AVX2 /DNDEBUG")
else() # für linux
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall") 	# flags wos es ban compilieren olm angeben soll
																# -std=c++17 -Werror -woswoasdenni
    set(CMAKE_CXX_FLAGS_DEBUG "")								# lei flags wos ban debuggen brauchsch
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG ")				# lei flags wos ban release brauchsch, -O3 z.b. optimiert dein programm
endif()

# zusätzliche cmake scripte loden, manchmal muas cmake se mit find suchen, dazu werd a FindSCRIPTNAME.cmake im cmake_module_path benötigt
FIND_PACKAGE(OpenCV REQUIRED COMPONENTS core imgproc imgcodecs highgui)	

# ifs sein a meglich
IF(OpenCV_FOUND)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenCV_CXX_FLAGS}")
ENDIF()

# meistens wenn man a externes package loaded muas man sel a includiern
include_directories(${OpenCV_INCLUDE_DIRS})

# add subdirectory, in der directory brauchts donn a eigenes cmakelists.txt file und man konn dort sozusogn a eigenes projekt mochn
add_subdirectory(${PROJECT_SOURCE_DIR}/test/)

# in dr variable XXXX in ordner mit die sourcefiles speichern
aux_source_directory(. XXXX)
# kenn a mehrere ordner sein
aux_source_directory(src/ XXXX)

# effektiv a binary erstellen mit add_executable(binaryname src_files_wo_genau_1_main.cpp_sein_muas)
add_executable(OpenCV ${XXXX})

# olle libraries wos man fürs executable brauch linken
target_link_libraries(OpenCV ${OpenCV_LIBS})
