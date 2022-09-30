add_test([=[HelloTest.BasicAssertions]=]  /home/matt/Documents/code/cpp/common/test/build/code_test [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HelloTest.BasicAssertions]=]  PROPERTIES WORKING_DIRECTORY /home/matt/Documents/code/cpp/common/test/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  code_test_TESTS HelloTest.BasicAssertions)
