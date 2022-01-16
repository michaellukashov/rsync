set(CMAKE_SYSTEM_NAME Windows)
set(TOOLCHAIN_PREFIX x86_64-pc-msys) #x86_64-w64-mingw32)
#set(CMAKE_SYSTEM_PROCESSOR x86_64)

#set(CMAKE_SYSROOT D:/Projects/git-sdk-64)
set(CMAKE_FIND_ROOT_PATH D:/Projects/git-sdk-64/usr/x86_64-pc-msys)

set(CMAKE_C_COMPILER D:/Projects/git-sdk-64/usr/bin/x86_64-pc-msys-gcc.exe)
set(CMAKE_CXX_COMPILER D:/Projects/git-sdk-64/usr/bin/x86_64-pc-msys-g++.exe)
set(CMAKE_AR D:/Projects/git-sdk-64/usr/bin/ar.exe )
set(CMAKE_MAKE_PROGRAM D:/Projects/git-sdk-64/usr/bin/make.exe)
set(CMAKE_RC_COMPILER D:/Projects/git-sdk-64/usr/bin/windres.exe)


# these variables tell CMake to avoid using any binary it finds in
# the sysroot, while picking headers and libraries exclusively from it
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
