# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/pg2_p2_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/pg2_p2_autogen.dir/ParseCache.txt"
  "pg2_p2_autogen"
  )
endif()
