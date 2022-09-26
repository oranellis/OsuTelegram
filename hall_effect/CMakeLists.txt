#  ____  _ ____  _           _____ ____   ____
# |  _ \(_)  _ \(_) ___ ___ | ____/ ___| / ___|
# | |_) | | |_) | |/ __/ _ \|  _| \___ \| |
# |  __/| |  __/| | (_| (_) | |___ ___) | |___
# |_|   |_|_|   |_|\___\___/|_____|____/ \____|
#
# ==== CMakeLists.txt ====
#
# Authors: Oran Ellis, Karl Hartmann
# Licence: GPLv3

cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_PATH $ENV{SDK_PATH}/pico-sdk)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(pico_sdk_import.cmake)

project(PiPicoESC)

pico_sdk_init()

add_executable(keypad
    src/main.cpp
)

target_include_directories(keypad PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(keypad pico_stdlib hardware_gpio pico_multicore pico_time hardware_adc)

pico_add_extra_outputs(keypad)
pico_enable_stdio_usb(keypad 1)
pico_enable_stdio_uart(keypad 0)

add_custom_target(flash ALL ${CMAKE_SOURCE_DIR}/pi_flash.sh
    DEPENDS keypad)
