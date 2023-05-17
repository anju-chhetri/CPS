# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/yunika/esp/esp-idf/components/bootloader/subproject"
  "/home/yunika/Desktop/CPS/ESP_Deprecated_ADC_Data/build/bootloader"
  "/home/yunika/Desktop/CPS/ESP_Deprecated_ADC_Data/build/bootloader-prefix"
  "/home/yunika/Desktop/CPS/ESP_Deprecated_ADC_Data/build/bootloader-prefix/tmp"
  "/home/yunika/Desktop/CPS/ESP_Deprecated_ADC_Data/build/bootloader-prefix/src/bootloader-stamp"
  "/home/yunika/Desktop/CPS/ESP_Deprecated_ADC_Data/build/bootloader-prefix/src"
  "/home/yunika/Desktop/CPS/ESP_Deprecated_ADC_Data/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/yunika/Desktop/CPS/ESP_Deprecated_ADC_Data/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/yunika/Desktop/CPS/ESP_Deprecated_ADC_Data/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
