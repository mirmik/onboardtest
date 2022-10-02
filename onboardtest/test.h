#ifndef ONBOARDTEST_TEST_H_
#define ONBOARDTEST_TEST_H_

#include <onboardtest/testenv.h>

#define TEST_CASE(name)                                                        \
    void test##__LINE__();                                                     \
    static onboardtest::OnBoardTest test##__LINE__##__test(test##__LINE__,     \
                                                           name);              \
    void test##__LINE__()

#endif