set(GPIO_out GPIOStreamOut.cpp)
add_library(GPIO_out ${GPIO_out})

target_link_libraries(GPIO_out PRIVATE JetsonGPIO)