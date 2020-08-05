# CMake generated Testfile for 
# Source directory: D:/My_file/opencv_contrib/modules/tracking
# Build directory: D:/My_file/opencv4.1/opencv-bulild/modules/tracking
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(opencv_test_tracking "D:/My_file/opencv4.1/opencv-bulild/bin/Debug/opencv_test_trackingd.exe" "--gtest_output=xml:opencv_test_tracking.xml")
  set_tests_properties(opencv_test_tracking PROPERTIES  LABELS "Extra;opencv_tracking;Accuracy" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/accuracy" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1282;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1069;ocv_add_accuracy_tests;D:/My_file/opencv_contrib/modules/tracking/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/tracking/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(opencv_test_tracking "D:/My_file/opencv4.1/opencv-bulild/bin/Release/opencv_test_tracking.exe" "--gtest_output=xml:opencv_test_tracking.xml")
  set_tests_properties(opencv_test_tracking PROPERTIES  LABELS "Extra;opencv_tracking;Accuracy" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/accuracy" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1282;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1069;ocv_add_accuracy_tests;D:/My_file/opencv_contrib/modules/tracking/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/tracking/CMakeLists.txt;0;")
else()
  add_test(opencv_test_tracking NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(opencv_perf_tracking "D:/My_file/opencv4.1/opencv-bulild/bin/Debug/opencv_perf_trackingd.exe" "--gtest_output=xml:opencv_perf_tracking.xml")
  set_tests_properties(opencv_perf_tracking PROPERTIES  LABELS "Extra;opencv_tracking;Performance" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/performance" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1189;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1070;ocv_add_perf_tests;D:/My_file/opencv_contrib/modules/tracking/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/tracking/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(opencv_perf_tracking "D:/My_file/opencv4.1/opencv-bulild/bin/Release/opencv_perf_tracking.exe" "--gtest_output=xml:opencv_perf_tracking.xml")
  set_tests_properties(opencv_perf_tracking PROPERTIES  LABELS "Extra;opencv_tracking;Performance" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/performance" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1189;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1070;ocv_add_perf_tests;D:/My_file/opencv_contrib/modules/tracking/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/tracking/CMakeLists.txt;0;")
else()
  add_test(opencv_perf_tracking NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(opencv_sanity_tracking "D:/My_file/opencv4.1/opencv-bulild/bin/Debug/opencv_perf_trackingd.exe" "--gtest_output=xml:opencv_perf_tracking.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
  set_tests_properties(opencv_sanity_tracking PROPERTIES  LABELS "Extra;opencv_tracking;Sanity" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/sanity" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1190;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1070;ocv_add_perf_tests;D:/My_file/opencv_contrib/modules/tracking/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/tracking/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(opencv_sanity_tracking "D:/My_file/opencv4.1/opencv-bulild/bin/Release/opencv_perf_tracking.exe" "--gtest_output=xml:opencv_perf_tracking.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
  set_tests_properties(opencv_sanity_tracking PROPERTIES  LABELS "Extra;opencv_tracking;Sanity" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/sanity" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1190;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1070;ocv_add_perf_tests;D:/My_file/opencv_contrib/modules/tracking/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/tracking/CMakeLists.txt;0;")
else()
  add_test(opencv_sanity_tracking NOT_AVAILABLE)
endif()
