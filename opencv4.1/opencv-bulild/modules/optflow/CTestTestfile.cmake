# CMake generated Testfile for 
# Source directory: D:/My_file/opencv_contrib/modules/optflow
# Build directory: D:/My_file/opencv4.1/opencv-bulild/modules/optflow
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(opencv_test_optflow "D:/My_file/opencv4.1/opencv-bulild/bin/Debug/opencv_test_optflowd.exe" "--gtest_output=xml:opencv_test_optflow.xml")
  set_tests_properties(opencv_test_optflow PROPERTIES  LABELS "Extra;opencv_optflow;Accuracy" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/accuracy" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1282;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1069;ocv_add_accuracy_tests;D:/My_file/opencv_contrib/modules/optflow/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/optflow/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(opencv_test_optflow "D:/My_file/opencv4.1/opencv-bulild/bin/Release/opencv_test_optflow.exe" "--gtest_output=xml:opencv_test_optflow.xml")
  set_tests_properties(opencv_test_optflow PROPERTIES  LABELS "Extra;opencv_optflow;Accuracy" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/accuracy" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1282;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1069;ocv_add_accuracy_tests;D:/My_file/opencv_contrib/modules/optflow/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/optflow/CMakeLists.txt;0;")
else()
  add_test(opencv_test_optflow NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(opencv_perf_optflow "D:/My_file/opencv4.1/opencv-bulild/bin/Debug/opencv_perf_optflowd.exe" "--gtest_output=xml:opencv_perf_optflow.xml")
  set_tests_properties(opencv_perf_optflow PROPERTIES  LABELS "Extra;opencv_optflow;Performance" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/performance" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1189;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1070;ocv_add_perf_tests;D:/My_file/opencv_contrib/modules/optflow/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/optflow/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(opencv_perf_optflow "D:/My_file/opencv4.1/opencv-bulild/bin/Release/opencv_perf_optflow.exe" "--gtest_output=xml:opencv_perf_optflow.xml")
  set_tests_properties(opencv_perf_optflow PROPERTIES  LABELS "Extra;opencv_optflow;Performance" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/performance" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1189;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1070;ocv_add_perf_tests;D:/My_file/opencv_contrib/modules/optflow/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/optflow/CMakeLists.txt;0;")
else()
  add_test(opencv_perf_optflow NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(opencv_sanity_optflow "D:/My_file/opencv4.1/opencv-bulild/bin/Debug/opencv_perf_optflowd.exe" "--gtest_output=xml:opencv_perf_optflow.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
  set_tests_properties(opencv_sanity_optflow PROPERTIES  LABELS "Extra;opencv_optflow;Sanity" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/sanity" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1190;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1070;ocv_add_perf_tests;D:/My_file/opencv_contrib/modules/optflow/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/optflow/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(opencv_sanity_optflow "D:/My_file/opencv4.1/opencv-bulild/bin/Release/opencv_perf_optflow.exe" "--gtest_output=xml:opencv_perf_optflow.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
  set_tests_properties(opencv_sanity_optflow PROPERTIES  LABELS "Extra;opencv_optflow;Sanity" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/sanity" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1190;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1070;ocv_add_perf_tests;D:/My_file/opencv_contrib/modules/optflow/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/optflow/CMakeLists.txt;0;")
else()
  add_test(opencv_sanity_optflow NOT_AVAILABLE)
endif()
