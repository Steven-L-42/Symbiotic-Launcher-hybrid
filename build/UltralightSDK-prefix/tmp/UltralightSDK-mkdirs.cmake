# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/slippert/Desktop/ultralight-quick-start/build/SDK"
  "/Users/slippert/Desktop/ultralight-quick-start/build/UltralightSDK-prefix/src/UltralightSDK-build"
  "/Users/slippert/Desktop/ultralight-quick-start/build/UltralightSDK-prefix"
  "/Users/slippert/Desktop/ultralight-quick-start/build/UltralightSDK-prefix/tmp"
  "/Users/slippert/Desktop/ultralight-quick-start/build/UltralightSDK-prefix/src/UltralightSDK-stamp"
  "/Users/slippert/Desktop/ultralight-quick-start/build/UltralightSDK-prefix/src"
  "/Users/slippert/Desktop/ultralight-quick-start/build/UltralightSDK-prefix/src/UltralightSDK-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/slippert/Desktop/ultralight-quick-start/build/UltralightSDK-prefix/src/UltralightSDK-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/slippert/Desktop/ultralight-quick-start/build/UltralightSDK-prefix/src/UltralightSDK-stamp${cfgdir}") # cfgdir has leading slash
endif()