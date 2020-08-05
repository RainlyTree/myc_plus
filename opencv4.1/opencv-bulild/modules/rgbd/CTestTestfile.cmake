# CMake generated Testfile for 
# Source directory: D:/My_file/opencv_contrib/modules/rgbd
# Build directory: D:/My_file/opencv4.1/opencv-bulild/modules/rgbd
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(opencv_test_rgbd "D:/My_file/opencv4.1/opencv-bulild/bin/Debug/opencv_test_rgbdd.exe" "--gtest_output=xml:opencv_test_rgbd.xml")
  set_tests_properties(opencv_test_rgbd PROPERTIES  LABELS "Extra;opencv_rgbd;Accuracy" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/accuracy" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1282;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1069;ocv_add_accuracy_tests;D:/My_file/opencv_contrib/modules/rgbd/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/rgbd/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(opencv_test_rgbd "D:/My_file/opencv4.1/opencv-bulild/bin/Release/opencv_test_rgbd.exe" "--gtest_output=xml:opencv_test_rgbd.xml")
  set_tests_properties(opencv_test_rgbd PROPERTIES  LABELS "Extra;opencv_rgbd;Accuracy" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/accuracy" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1282;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1069;ocv_add_accuracy_tests;D:/My_file/opencv_contrib/modules/rgbd/CMakeLists.txt;2;ocv_define_module;D:/My_file/opencv_contrib/modules/rgbd/CMakeLists.txt;0;")
else()
  add_test(opencv_test_rgbd NOT_AVAILABLE)
endif()
