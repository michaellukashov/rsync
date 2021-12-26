project(rsync)
cmake_minimum_required(VERSION 3.14)

# use vcpkg scripts
#

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

target_include_directories(rsync_lib PRIVATE
  lib
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

target_include_directories(rsync PRIVATE
  lib
  libw32
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
)

set_target_properties(rsync PROPERTIES
  OUTPUT_NAME rsync
  EXPORT_NAME exe
)

target_link_libraries(rsync
  rsync_lib
)
