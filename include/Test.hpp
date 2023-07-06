#ifndef TEST_HPP
#define TEST_HPP

#include <string>
#include <vector>
#include <iostream>
#include "../include/HealthTourism.hpp"

class Test
{
public:
    // Test();
    // ~Test();
    bool test_add_request();
    bool test_set_not_existed_supporter(HealthTourism* ht);
    bool test_set_existed_supporter(HealthTourism* ht);
    bool test_set_supporter();
    void run();
};

#endif