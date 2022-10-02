#ifndef ONBOARDTEST_TEST_H_
#define ONBOARDTEST_TEST_H_

#include <nos/util/macro.h>
#include <onboardtest/testenv.h>

#define TEST_CASE(name)                                                        \
    void NOS_CONCAT2(test, __LINE__)();                                        \
    static onboardtest::OnBoardTest NOS_CONCAT2(test_test_, __LINE__)(         \
        NOS_CONCAT2(test, __LINE__), name);                                    \
    void NOS_CONCAT2(test, __LINE__)()

#endif