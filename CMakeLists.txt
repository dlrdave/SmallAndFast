cmake_minimum_required(VERSION 2.8)
project(SmallAndFast)

# CTestConfig settings:
#
set(SAF_PROJECT_NAME "SmallAndFast"
  CACHE STRING "maps to corresponding CTestConfig.cmake variable")

set(SAF_NIGHTLY_START_TIME "01:00:00 UTC"
  CACHE STRING "maps to corresponding CTestConfig.cmake variable")

set(SAF_DROP_METHOD "http"
  CACHE STRING "maps to corresponding CTestConfig.cmake variable")

set(SAF_DROP_SITE "my.cdash.org"
  CACHE STRING "maps to corresponding CTestConfig.cmake variable")

set(submit_php_path "/CDash/submit.php")
if(SAF_DROP_SITE STREQUAL "my.cdash.org")
  set(submit_php_path "/submit.php")
endif()

set(SAF_DROP_LOCATION "${submit_php_path}?project=${SAF_PROJECT_NAME}"
  CACHE STRING "maps to corresponding CTestConfig.cmake variable")

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/CTestConfig.cmake.in"
  "${CMAKE_CURRENT_SOURCE_DIR}/CTestConfig.cmake"
  @ONLY
  )

include(CTest)

add_executable(echoargs echoargs.c)
set_property(SOURCE echoargs.c APPEND PROPERTY LABELS SourceLabel Everything)
set_property(TARGET echoargs APPEND PROPERTY LABELS TargetLabel Everything)

add_test(test0 echoargs)
set_property(TEST test0 APPEND PROPERTY LABELS TestLabel 0ArgTest Everything)

add_test(test1 echoargs 1)
set_property(TEST test1 APPEND PROPERTY LABELS TestLabel 1ArgTest Everything)

add_test(test2 echoargs 1 2)
set_property(TEST test2 APPEND PROPERTY LABELS TestLabel 2ArgTest Everything)

if(SAF_INTENTIONAL_COMPILE_ERROR)
  add_executable(ice intentional_compile_error.cxx)
endif()

if(SAF_INTENTIONAL_COMPILE_WARNING)
  add_executable(icw intentional_compile_warning.cxx)
endif()
