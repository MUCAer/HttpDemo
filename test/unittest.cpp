#include "google/protobuf/message.h"
#include "gtest/gtest.h"
#include "yaml-cpp/yaml.h"
#include "mysql.h"
#include "util/tc_mysql.h"
#include <string>
#include <iostream>
#include <memory>
#include <cstdint>
/**
 * @class UserServerTest
 * @desc 测试UserServer环境初始化类
 */
class UserServerTest : public testing::Environment {
public:
    /* init test environment. */
    virtual void SetUp() {};

    /* clear test environment. */
    virtual void TearDown() {}; 
};

/*
 * @class TestDictManager
 */
class TestDict : public testing::Test {
public:
    /* start test. */
    static void SetUpTestCace() {
        std::cout << "StartDictTesting." << std::endl;
    }
    
    /* end test. */
    static void TearDownTestCase() {
        std::cout << "TearDownDictTesting." << std::endl;
    }

};


TEST_F(TestDict, test_gtest)  {
    ASSERT_EQ(1, 1);
}


const std::string DB_CONF = "../conf/config.yaml";
int main(int argc, char* argv[]) {
    testing::AddGlobalTestEnvironment(new UserServerTest);
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
