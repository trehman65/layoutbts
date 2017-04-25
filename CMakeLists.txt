cmake_minimum_required(VERSION 3.5)
project(layoutbts)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
link_directories(/usr/local/lib/ /usr/lib/)

include_directories(/usr/local/include matplotlib-cpp)

set(SOURCE_FILES VerticalProfiles.cpp VerticalProfiles.h matplotlib-cpp/matplotlibcpp.h OneNearest.cpp OneNearest.h Evaluation.cpp Evaluation.h)

add_executable(layoutEvaluation main-evaluation.cpp ${SOURCE_FILES})
add_executable(layoutVerticalProjection main-verticalprojection.cpp ${SOURCE_FILES})
add_executable(layoutKNearest main-knearest.cpp ${SOURCE_FILES})


target_link_libraries(layoutEvaluation python2.7 lept tesseract opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs pthread)
target_link_libraries(layoutVerticalProjection python2.7 lept tesseract opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs pthread)
target_link_libraries(layoutKNearest python2.7 lept tesseract opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs pthread)
