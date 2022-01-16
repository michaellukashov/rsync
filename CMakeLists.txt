project(rsync LANGUAGES C)
cmake_minimum_required(VERSION 3.15)
list(APPEND CMAKE_C_SOURCE_FILE_EXTENSIONS .cc)

# use vcpkg scripts
#

include(cmake/ucm.cmake)
include(cmake/CheckTypeExists.cmake)
include(CheckTypeSize)
include(CheckIncludeFile)
include(CheckSymbolExists)
include(CheckStructHasMember)

#check_type_exists(size_t "" HAVE_SIZE_T)
#check_type_exists(uint32_t "" HAVE_UINT32_T)
#check_type_exists(id_t "" HAVE_ID_T)
#check_type_exists(mode_t "sys/utypes.h" HAVE_MODE_T)
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
set(HAVE_MODE_T 1)
set(HAVE_SIZE_T 1)
set(HAVE_UINT32_T 1)
set(HAVE_ID_T 1)
set(HAVE_STRPBRK 1)
set(HAVE_MEMMOVE 1)
set(HAVE_STRCHR 1)
set(HAVE_GETCWD 1)
set(HAVE_WAITPID 1)
set(HAVE_CHMOD 1)
set(HAVE_FTRUNCATE 1)
set(HAVE_SOCKETPAIR 1)

set(RSYNC_PATH "\"rsync\"")
set(RSYNC_RSH "\"ssh\"")
set(NOBODY_GROUP "\"nobody\"")
set(NOBODY_USER "\"nobody\"")
set(RSYNCD_SYSCONF "\"/etc/rsyncd.conf\"")

#add_definitions(-DWIN32_UNISTD_MAP)
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
  lib/wildmatch.c
  lib/compat.c
  lib/snprintf.c
  lib/mdfour.c
  lib/md5.c
  lib/permstring.c
  lib/pool_alloc.c
  lib/sysacls.c
  lib/sysxattrs.c
#  lib/getpass.c
#  lib/getaddrinfo.c
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
  popt/findme.c
  popt/popt.c
  popt/poptconfig.c
  popt/popthelp.c
  popt/poptparse.c
)

target_include_directories(popt_lib BEFORE PRIVATE
  lib
#  libw32/msvc
  libw32
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
)

set(IS_LITTLE_ENDIAN 1)
set(STDC_HEADERS 1)
set(HAVE_EIGHTBIT 1)
set(HAVE_BCMP 1)
set(HAVE_BZERO 1)
set(HAVE_SYSERRLIST 1)
set(HAVE_SYS_SOCKET_H 1)
set(HAVE_STRLCPY 1)

configure_file(libw32/w32config.hin w32config.h)

add_library(libw32_lib OBJECT
  libw32/w32_getlocale.c
  libw32/w32_realpath.c
  libw32/w32_write.c
  libw32/w32_util.c
  libw32/w32_user.c
  libw32/w32_unlink.c
  libw32/w32_uname.c
  libw32/w32_truncate.c
  libw32/w32_time.c
  libw32/w32_sysdir.c
  libw32/w32_strtoull.c
  libw32/w32_strtoll.c
#  libw32/w32_strlcpy.c
#  libw32/w32_strlcat.c
  libw32/w32_string.c
  libw32/w32_strftime.c
  libw32/w32_statfs.c
  libw32/w32_sockpair.c
  libw32/w32_sockfd.c
  libw32/w32_socket2.c
  libw32/w32_socket.c
  libw32/w32_sockbase.c
#  libw32/w32_slang.c
  libw32/w32_signal.c
#  libw32/w32_shell.c
  libw32/w32_select.c
  libw32/w32_reparse.c
  libw32/w32_read.c
  libw32/w32_pwd.c
  libw32/w32_progname.c
#  libw32/w32_popen.c
  libw32/w32_poll.c
  libw32/w32_neterr.c
  libw32/w32_mmap.c
#  libw32/w32_mkstemp.c
#  libw32/w32_mknod.c
  libw32/w32_link.c
#  libw32/w32_langinfo.c
#  libw32/w32_lang.c
  libw32/w32_io.c
  libw32/w32_ino.c
#  libw32/w32_iconv_native.c
#  libw32/w32_iconv.c
  libw32/w32_grp.c
  libw32/w32_gistrerror.c
  libw32/w32_getsubopt.c
  libw32/w32_getopt.c
  libw32/w32_gethostname.c
  libw32/w32_getcwd.c
  libw32/w32_fsync.c
  libw32/w32_fcntl.c
  libw32/w32_errno.c
  libw32/w32_dirent.c
  libw32/w32_dir.c
#  libw32/w32_close.c
  libw32/w32_chown.c
  libw32/w32_child.c
#  libw32/w32_check.c
#  libw32/termemu_vio.c
  libw32/w32_trace.c
  libw32/bsd_bsearch.c
  libw32/bsd_qsort.c

  # from git-sdk-64\usr\src\MSYS2-packages\msys2-runtime\src\msys2-runtime\winsup\cygwin
  libw32/msys2-runtime/fork.cc
)
set_source_files_properties(libw32/msys2-runtime/fork.cc PROPERTIES LANGUAGE C)


target_include_directories(libw32_lib BEFORE PRIVATE
#  lib
#  libw32/msvc
  libw32
#  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
)

set(ZLIB_COMPAT ON)
set(ZLIB_FULL_VERSION 2.0.3)
set(ZLIB_ENABLE_TESTS OFF)
set(WITH_NEW_STRATEGIES ON)
set(ZLIB_COMPAT ON)
set(WITH_OPTIM ON)
add_subdirectory(zlib-ng)

add_executable(rsync
  byteorder.h
  config.h
  errcode.h
  proto.h
  rsync.h
  ifuncs.h
  itypes.h
  inums.h
  version.h
  case_N.h
  latest-year.h
  io.h

  flist.c
  rsync.c
  generator.c
  receiver.c
  cleanup.c
  sender.c
  exclude.c
  util.c
  util2.c
  main.c
  checksum.c
  match.c
  syscall.c
  log.c
  backup.c
  delete.c

  options.c
  io.c
  compat.c
  hlink.c
  token.c
  uidlist.c
  socket.c
  hashtable.c
  fileio.c
  batch.c
  clientname.c
  chmod.c
  acls.c
  xattrs.c

  progress.c
  pipe.c

  params.c
  loadparm.c
  clientserver.c
  access.c
  connection.c
  authenticate.c

  usage.c
#  t_stub.c
#  rounding.c
#  trimslash.c
#  getgroups.c
#  wildtest.c
#  t_unsafe.c
#  getfsdev.c
#  testrun.c
#  tls.c
)

add_custom_target(rsync_sources SOURCES
  config.h.cmake.in
  libw32/w32config.hin
)

target_include_directories(rsync BEFORE PRIVATE
  lib
#  libw32/msvc
  libw32
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
  popt
  zlib-ng
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
  libw32_lib
  zlibstatic
)

ucm_set_runtime(STATIC)
#ucm_print_flags()
ucm_add_linker_flags(EXE
  /NODEFAULTLIB:msvcrtd.lib
#  /NODEFAULTLIB:libucrtd.lib
)
