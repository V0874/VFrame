# Set the correct CMake version
cmake_minimum_required(VERSION 4.0.1)

# Define project
project(pwm_driver C)

# Set system/target info
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)

# Set build type to Debug
set(CMAKE_BUILD_TYPE Debug)

# Toolchain paths
set(AVR_GCC_PATH /mnt/hdd/toolchains/avr/bin)
set(AVR_INCLUDE_PATH /mnt/hdd/toolchains/avr/avr/include)
set(AVR_LIB_PATH /mnt/hdd/toolchains/avr/avr/lib)

# Cross compilers
set(CMAKE_C_COMPILER ${AVR_GCC_PATH}/avr-gcc)
set(CMAKE_CXX_COMPILER ${AVR_GCC_PATH}/avr-g++)

# Include and link paths
include_directories(${AVR_INCLUDE_PATH})
include_directories(${CMAKE_SOURCE_DIR}/gpio)
link_directories(${AVR_LIB_PATH})

# Compilation flags
set(CMAKE_C_FLAGS "-mmcu=atmega2560 -Os -fno-diagnostics-show-caret -g")

# Prevent dependency file generation
set(CMAKE_DEPFILE_FLAGS_C "")
set(CMAKE_DEPFILE_FLAGS_LINK "")

# Linker flags
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=atmega2560")

# Create executable
add_executable(pwm_driver main.c gpio/gpio.c)

# Prevent CMake 4.x from injecting the dependency file flag during linking
set_property(TARGET pwm_driver PROPERTY LINK_DEPENDS_NO_SHARED TRUE)
set_property(TARGET pwm_driver PROPERTY ADDITIONAL_LINK_FLAGS "-mmcu=atmega2560")

# Convert ELF to HEX after build
add_custom_command(TARGET pwm_driver POST_BUILD
    COMMAND ${AVR_GCC_PATH}/avr-objcopy -O ihex ${CMAKE_BINARY_DIR}/pwm_driver ${CMAKE_BINARY_DIR}/pwm_driver.hex
    COMMENT "Converting ELF to HEX"
)

#flash arduino
add_custom_command(TARGET pwm_driver POST_BUILD
    COMMAND avrdude -C /etc/avrdude.conf -v -p m2560 -c wiring -P /dev/ttyACM0 -b 115200 -D -U flash:w:${CMAKE_BINARY_DIR}/pwm_driver.hex:i
    COMMENT "Flashing the microcontroller with AVRDude"
)