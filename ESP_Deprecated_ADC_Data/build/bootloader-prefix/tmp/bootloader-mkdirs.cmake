# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/anju_chhetri/esp/esp-idf/components/bootloader/subproject"
  "/home/anju_chhetri/Desktop/CPS/test/build/bootloader"
  "/home/anju_chhetri/Desktop/CPS/test/build/bootloader-prefix"
  "/home/anju_chhetri/Desktop/CPS/test/build/bootloader-prefix/tmp"
  "/home/anju_chhetri/Desktop/CPS/test/build/bootloader-prefix/src/bootloader-stamp"
  "/home/anju_chhetri/Desktop/CPS/test/build/bootloader-prefix/src"
  "/home/anju_chhetri/Desktop/CPS/test/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/anju_chhetri/Desktop/CPS/test/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/anju_chhetri/Desktop/CPS/test/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
