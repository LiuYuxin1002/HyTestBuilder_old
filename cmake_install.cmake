# Install script for directory: D:/研究生课题/开源软件/SOEM

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/研究生课题/开源软件/SOEM/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/研究生课题/开源软件/HydraulicTestPlatform/Debug/soem.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/研究生课题/开源软件/HydraulicTestPlatform/Release/soem.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/研究生课题/开源软件/HydraulicTestPlatform/MinSizeRel/soem.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/研究生课题/开源软件/HydraulicTestPlatform/RelWithDebInfo/soem.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/soem" TYPE FILE FILES
    "D:/研究生课题/开源软件/SOEM/soem/ethercat.h"
    "D:/研究生课题/开源软件/SOEM/soem/ethercatbase.h"
    "D:/研究生课题/开源软件/SOEM/soem/ethercatcoe.h"
    "D:/研究生课题/开源软件/SOEM/soem/ethercatconfig.h"
    "D:/研究生课题/开源软件/SOEM/soem/ethercatconfiglist.h"
    "D:/研究生课题/开源软件/SOEM/soem/ethercatdc.h"
    "D:/研究生课题/开源软件/SOEM/soem/ethercateoe.h"
    "D:/研究生课题/开源软件/SOEM/soem/ethercatfoe.h"
    "D:/研究生课题/开源软件/SOEM/soem/ethercatmain.h"
    "D:/研究生课题/开源软件/SOEM/soem/ethercatprint.h"
    "D:/研究生课题/开源软件/SOEM/soem/ethercatsoe.h"
    "D:/研究生课题/开源软件/SOEM/soem/ethercattype.h"
    "D:/研究生课题/开源软件/SOEM/osal/osal.h"
    "D:/研究生课题/开源软件/SOEM/osal/win32/inttypes.h"
    "D:/研究生课题/开源软件/SOEM/osal/win32/osal_defs.h"
    "D:/研究生课题/开源软件/SOEM/osal/win32/osal_win32.h"
    "D:/研究生课题/开源软件/SOEM/osal/win32/stdint.h"
    "D:/研究生课题/开源软件/SOEM/oshw/win32/nicdrv.h"
    "D:/研究生课题/开源软件/SOEM/oshw/win32/oshw.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/研究生课题/开源软件/HydraulicTestPlatform/test/linux/slaveinfo/cmake_install.cmake")
  include("D:/研究生课题/开源软件/HydraulicTestPlatform/test/linux/eepromtool/cmake_install.cmake")
  include("D:/研究生课题/开源软件/HydraulicTestPlatform/test/linux/simple_test/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "D:/研究生课题/开源软件/HydraulicTestPlatform/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
