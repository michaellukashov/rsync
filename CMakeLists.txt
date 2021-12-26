project(rsync)
cmake_minimum_required(VERSION 3.14)

# use vcpkg scripts
#

include(cmake/CheckTypeExists.cmake)
include(CheckTypeSize)
include(CheckIncludeFile)
include(CheckSymbolExists)

check_type_exists(size_t "" HAVE_SIZE_T)
check_type_exists(uint32_t "" HAVE_UINT32_T)
check_type_size("int32_t" SIZEOF_INT32_T)
check_type_size("uint32_t" SIZEOF_UINT32_T)
check_type_size("int" SIZEOF_INT)
check_type_size("int32_t" SIZEOF_INT32)
check_type_size("uint32_t" SIZEOF_UINT32_T)
check_type_size("long" SIZEOF_LONG_T)
check_type_size("char*" SIZEOF_CHARP)
#CHECK_FUNCTION_EXISTS_GLIBC(acl_set_file HAVE_ACL_SET_FILE)
#CHECK_SYMBOL_EXISTS(acl_get_link_np "${INCLUDES}" HAVE_ACL_GET_LINK_NP)
check_include_file("stdint.h" HAVE_STDINT_H)
check_symbol_exists("addrinfo" "" HAVE_STRUCT_ADDRINFO)

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
  libw32
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
)

target_compile_definitions(rsync_lib PRIVATE
  -D__INSIDE_CYGWIN_NET__
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
  libw32
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
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
)
