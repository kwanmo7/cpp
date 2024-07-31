cmake_minimum_required(VERSION 3.28)
project(Calendar)

set(CMAKE_CXX_STANDARD 17)

set(wxWidgets_ROOT_DIR "C:/wxWidgets/")
set(wxWidgets_LIB_DIR "C:/wxWidgets/lib/vc_x64_lib")

find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(Calendar WIN32 src/main.cpp
        include/CalendarApp.h
        src/CalendarApp.cpp)

target_link_libraries(Calendar ${wxWidgets_LIBRARIES})