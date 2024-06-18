# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ilusha_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ilusha_autogen.dir\\ParseCache.txt"
  "ilusha_autogen"
  )
endif()
