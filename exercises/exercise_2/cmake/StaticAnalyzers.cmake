option(ENABLE_CPPCHECK "Enable static analysis with cppcheck" ON)
option(ENABLE_CLANG_TIDY "Enable static analysis with clang-tidy" ON)
if(ENABLE_CPPCHECK)
  find_program(CPPCHECK cppcheck)
  if(CPPCHECK)
    set(CMAKE_CXX_CPPCHECK
        ${CPPCHECK}
        --enable=all
        --suppress=missingInclude
        --inconclusive)
  else()
    message(SEND_ERROR "cppcheck requested but executable not found")
  endif()
endif()

if(ENABLE_CLANG_TIDY)
  find_program(CLANGTIDY clang-tidy)
  if(CLANGTIDY)
  message(STATUS "🟢 CMake_RUN_CLANG_TIDY is ON")
    set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY} "-checks=-*,modernize-*")
    #add_custom_target(clang-tidy
    #  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target ${project}
    #  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clang-tidy
    #  COMMENT "Running clang-tidy..."
    #)
  else()
    message(WARNING "🔴 CMake_RUN_CLANG_TIDY is ON but clang-tidy is not found!")
    message(SEND_ERROR "clang-tidy requested but executable not found")
    set(CMAKE_CXX_CLANG_TIDY "" CACHE STRING "" FORCE)
  endif()
endif()


  
