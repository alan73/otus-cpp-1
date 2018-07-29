cmake_minimum_required(VERSION 3.0)

find_package(Qt5Core REQUIRED)
find_package(GTest REQUIRED)

add_executable(hello-world main.cpp)
add_executable(test-cli test-main.cpp)

set_target_properties(hello-world test-cli PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_FLAGS "-Wpedantic -Wall -Wextra"
)

set_target_properties(hello-world PROPERTIES
  INCLUDE_DIRECTORIES ${Qt5Core_INCLUDE_DIRS}
)

target_link_libraries(hello-world
  ${Qt5Core_LIBRARIES}
)

target_link_libraries(test-cli
  ${GTEST_LIBRARIES}
  pthread
)

set(CPACK_GENERATOR DEB)
set(CPACK_VERSION_MAJOR 1)
set(CPACK_VERSION_MINOR 0)
set(CPACK_VERSION_PATCH 0)
set(CPACK_PACKAGE_CONTACT s_savelov@mail.ru)

include(CPack)
