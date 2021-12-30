project(rsync)
cmake_minimum_required(VERSION 3.14)

# use vcpkg scripts
#

include(cmake/CheckTypeExists.cmake)
include(CheckTypeSize)
include(CheckIncludeFile)
include(CheckSymbolExists)
include(CheckStructHasMember)

check_type_exists(size_t "" HAVE_SIZE_T)
check_type_exists(uint32_t "" HAVE_UINT32_T)
check_type_exists(id_t "" HAVE_ID_T)
#check_type_exists(mode_t "sys/utypes.h" HAVE_MODE_T)
set(HAVE_MODE_T 1)
check_type_exists(_off64_t "sys/_types.h" HAVE_OFF64_T)
check_type_size("int32_t" SIZEOF_INT32_T)
check_type_size("uint32_t" SIZEOF_UINT32_T)
check_type_size("int" SIZEOF_INT)
check_type_size("int32_t" SIZEOF_INT32)
check_type_size("uint32_t" SIZEOF_UINT32_T)
check_type_size("long" SIZEOF_LONG_T)
check_type_size("char*" SIZEOF_CHARP)
#check_type_size("_off64_t" SIZEOF_OFF64_T)
#check_type_size("_off_t" SIZEOF_OFF_T)
#check_function_exists_glibc(acl_set_file HAVE_ACL_SET_FILE)
#check_symbol_exists(acl_get_link_np "${INCLUDES}" HAVE_ACL_GET_LINK_NP)
check_include_file("stdint.h" HAVE_STDINT_H)
#check_symbol_exists("addrinfo" "" HAVE_STRUCT_ADDRINFO)

check_c_source_compiles(
  "#include <winsock2.h>\n#include <ws2def.h>\nint main(void) { struct addrinfo v; return sizeof(v); }"
  HAVE_STRUCT_ADDRINFO
)
check_c_source_compiles(
  "#include <winsock2.h>\n#include <ws2def.h>\nint main(void) { struct sockaddr_storage v; return sizeof(v); }"
  HAVE_STRUCT_SOCKADDR_STORAGE
)
check_c_source_compiles(
  "#include <sys/stat.h>\nint main(void) { struct _stat32 v; return sizeof(v); }"
  HAVE_STRUCT_STAT
)
check_c_source_compiles(
  "#include <sys/stat.h>\nint main(void) { struct _stat64 v; return sizeof(v); }"
  HAVE_STRUCT_STAT64
)
check_c_source_compiles(
  "#include <sys/stat.h>\nint main(void) { struct _stat64 v; return sizeof(v); }"
  HAVE_SYS_STAT_H
)
#check_c_source_compiles(
#  "#include <unistd.h>\nint main(void) { return 0; }"
#  HAVE_UNISTD_H
#)
set(SIZEOF_OFF_T 8)
set(SIZEOF_LONG 4)
set(SIZEOF_OFF64_T 8)
set(SIZEOF_INT64_T 8)

set(HAVE_UNISTD_H 1)
set(HAVE_STRERROR 1)
set(HAVE_GETTIMEOFDAY_TZ 1)
set(HAVE_DIRENT_H 1)
set(HAVE_LIBPOPT 1)
set(HAVE_UTIME 1)
set(HAVE_FCNTL_H 1)
set(HAVE_SYS_FCNTL_H 1)
set(HAVE_CONFIG_H 1)
set(HAVE_SYS_TYPES_H 1)
set(STDC_HEADERS 1)
set(HAVE_STDLIB_H 1)
set(HAVE_STRING_H 1)
set(HAVE_MEMORY_H 1)
set(HAVE_STDINT_H 1)
#set(HAVE_STRERROR 1)
#set(HAVE_FLOAT_H 1)

set(RSYNC_PATH "\"rsync\"")
set(RSYNC_RSH "\"ssh\"")
set(NOBODY_GROUP "\"nobody\"")
set(NOBODY_USER "\"nobody\"")
set(RSYNCD_SYSCONF "\"/etc/rsyncd.conf\"")

configure_file(config.h.cmake.in config.h)

add_library(rsync_lib OBJECT
  lib/sysacls.h
  lib/pool_alloc.h
  lib/md-defines.h
  lib/mdigest.h
  lib/sysxattrs.h
  lib/addrinfo.h
  lib/permstring.h
  lib/wildmatch.h
  lib/pool_alloc.c
  lib/compat.c
  lib/sysacls.c
  lib/md5.c
  lib/mdfour.c
  lib/snprintf.c
  lib/permstring.c
  lib/sysxattrs.c
  lib/getpass.c
  lib/getaddrinfo.c
  lib/wildmatch.c
  lib/inet_ntop.c
  lib/inet_pton.c
)

target_include_directories(rsync_lib BEFORE PRIVATE
  lib
#  libw32/msvc
  libw32
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
)

target_compile_definitions(rsync_lib PRIVATE
  -D__INSIDE_CYGWIN_NET__
)

add_library(popt_lib OBJECT
  popt/system.h
  popt/popt.h
  popt/poptint.h
  popt/findme.h
  popt/popt.c
  popt/popthelp.c
  popt/poptparse.c
  popt/poptconfig.c
  popt/findme.c
)

target_include_directories(popt_lib BEFORE PRIVATE
  lib
#  libw32/msvc
  libw32
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
)

add_executable(rsync
  version.h
  ifuncs.h
  rsync.h
  itypes.h
  byteorder.h
  case_N.h
  latest-year.h
  errcode.h
  inums.h
  io.h
  util2.c
  options.c
  exclude.c
  usage.c
  clientserver.c
  log.c
  syscall.c
  main.c
  util.c
  flist.c
  io.c
  compat.c
  generator.c
  rsync.c
  tls.c
  checksum.c
  uidlist.c
  cleanup.c
  xattrs.c
  access.c
  loadparm.c
  token.c
  clientname.c
  t_stub.c
  authenticate.c
  batch.c
  getgroups.c
  acls.c
  fileio.c
  hashtable.c
  hlink.c
  match.c
  params.c
  sender.c
  socket.c
  rounding.c
  delete.c
  getfsdev.c
  pipe.c
  progress.c
  receiver.c
  t_unsafe.c
  backup.c
  trimslash.c
  chmod.c
  connection.c
  wildtest.c
#  testrun.c
)

add_custom_target(rsync_sources SOURCES
  config.h.cmake.in
)

target_include_directories(rsync BEFORE PRIVATE
  lib
#  libw32/msvc
  libw32
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
  popt
)

target_compile_definitions(rsync PRIVATE
  -D__INSIDE_CYGWIN_NET__
)

set_target_properties(rsync PROPERTIES
  OUTPUT_NAME rsync
  EXPORT_NAME exe
)

target_link_libraries(rsync
  rsync_lib
  popt_lib
)
