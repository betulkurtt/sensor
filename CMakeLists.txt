cmake_minimum_required(VERSION 3.16)
project(CokluSensorVeriYonetimi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(sensor_yonetimi
    src/main.cpp
    src/Sensor.cpp
    src/SicaklikSensoru.cpp
    src/NemSensoru.cpp
    src/HareketSensoru.cpp
    src/SensorYonetici.cpp
)

target_compile_options(sensor_yonetimi PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
)
