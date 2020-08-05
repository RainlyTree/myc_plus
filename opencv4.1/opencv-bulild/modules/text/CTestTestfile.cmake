# CMake generated Testfile for 
# Source directory: D:/My_file/opencv_contrib/modules/text
# Build directory: D:/My_file/opencv4.1/opencv-bulild/modules/text
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(opencv_test_text "D:/My_file/opencv4.1/opencv-bulild/bin/Debug/opencv_test_textd.exe" "--gtest_output=xml:opencv_test_text.xml")
  set_tests_properties(opencv_test_text PROPERTIES  LABELS "Extra;opencv_text;Accuracy" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/accuracy" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1282;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1069;ocv_add_accuracy_tests;D:/My_file/opencv_contrib/modules/text/CMakeLists.txt;7;ocv_define_module;D:/My_file/opencv_contrib/modules/text/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(opencv_test_text "D:/My_file/opencv4.1/opencv-bulild/bin/Release/opencv_test_text.exe" "--gtest_output=xml:opencv_test_text.xml")
  set_tests_properties(opencv_test_text PROPERTIES  LABELS "Extra;opencv_text;Accuracy" WORKING_DIRECTORY "D:/My_file/opencv4.1/opencv-bulild/test-reports/accuracy" _BACKTRACE_TRIPLES "D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVUtils.cmake;1547;add_test;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1282;ocv_add_test_from_target;D:/My_file/opencv4.1/opencv/sources/cmake/OpenCVModule.cmake;1069;ocv_add_accuracy_tests;D:/My_file/opencv_contrib/modules/text/CMakeLists.txt;7;ocv_define_module;D:/My_file/opencv_contrib/modules/text/CMakeLists.txt;0;")
else()
  add_test(opencv_test_text NOT_AVAILABLE)
endif()
