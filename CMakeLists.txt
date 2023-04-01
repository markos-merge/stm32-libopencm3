cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
set(CMAKE_TOOLCHAIN_FILE cmake/toolchain-arm-none-eabi-gcc.cmake)
project(blink VERSION 0.1.0 LANGUAGES CXX C ASM)

include(cmake/stm32f103.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(blink src/blink.cpp)
target_link_libraries(blink stm32f103)
set_property(TARGET blink PROPERTY CXX_STANDARD 17)
stm32_add_linker_script(blink PRIVATE src/stm32f103c8t6.ld)
stm32_add_flash_targets(blink)

#add_executable(timer src/timer.cpp)
#target_link_libraries(timer stm32f103)
#set_property(TARGET timer PROPERTY CXX_STANDARD 17)
#stm32_add_linker_script(timer PRIVATE src/stm32f7.ld)
#stm32_add_flash_targets(timer)
