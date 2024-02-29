cmake_minimum_required (VERSION 3.2)

project (jetson_gpio_stream)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_executable(${PROJECT_NAME} src/main.cpp)

# option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

install(TARGETS ${PROJECT_NAME})

# Включите подпроекты.
add_subdirectory(src)
link_directories(GPIO_in)

add_subdirectory(JetsonGPIO)

# include(FetchContent)
# FetchContent_Declare(
#   JetsonGPIO 
#   GIT_REPOSITORY https://github.com/pjueon/JetsonGPIO.git 
#   GIT_TAG master
# )
# FetchContent_MakeAvailable(JetsonGPIO)

# target_link_libraries(mytarget JetsonGPIO::JetsonGPIO)

target_link_libraries(${PROJECT_NAME} PRIVATE GPIO_in ReadDataFileBin WriteDataFileBin JetsonGPIO)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
# add_subdirectory(src/Exceptions)
# link_directories(Exceptions)

# add_subdirectory(src/App)
# link_directories(App)

# add_subdirectory(src/Kernel)
# link_directories(Kernel)

# add_subdirectory(src/View)
# link_directories(View)

# target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics eigen Exceptions App)
# target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)