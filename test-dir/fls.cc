#include <cstdio>
#include <cstring>

#include "fls.h"
#include "gtest/gtest.h"

// The fixture for testing class
class FLSTest: public ::testing::Test {

	protected:
		FLSTest() {
			// You can do set-up work for each test here.
		}

		~FLSTest() override {
			// You can do clean-up work that doesn't throw exceptions here.
		}

		// If the constructor and destructor are not enough for setting up
		// and cleaning up each test, you can define the following methods:
		void SetUp() override {
			// Code here will be called immediately after the constructor (right
			// before each test).
		}

		void TearDown() override {
			// Code here will be called immediately after each test (right
			// before the destructor).
		}

	protected:
		// Objects declared here can be used by all tests in the test case
};	// class: FLSTest

TEST_F(FLSTest, fls_get_log_level) {
	EXPECT_EQ(FLS_LOG_LEVEL_INFO, fls_get_log_level());
}

TEST_F(FLSTest, fls_set_log_level) {
    fls_set_log_level(FLS_LOG_LEVEL_ERR);
	EXPECT_EQ(FLS_LOG_LEVEL_ERR, fls_get_log_level());

    fls_set_log_level(FLS_LOG_LEVEL_WARN);
	EXPECT_EQ(FLS_LOG_LEVEL_WARN, fls_get_log_level());

    fls_set_log_level(FLS_LOG_LEVEL_INFO);
	EXPECT_EQ(FLS_LOG_LEVEL_INFO, fls_get_log_level());

    fls_set_log_level(FLS_LOG_LEVEL_DEBUG);
	EXPECT_EQ(FLS_LOG_LEVEL_DEBUG, fls_get_log_level());

    fls_set_log_level(FLS_LOG_LEVEL_VERBOSE);
	EXPECT_EQ(FLS_LOG_LEVEL_VERBOSE, fls_get_log_level());
}

TEST_F(FLSTest, __fls_inner_log) {
    char output[BUFSIZ], compare[BUFSIZ];

    setbuf(stderr, output);
    __fls_inner_log("%s %d\n", "test", 1);
    setbuf(stderr, nullptr);

    sprintf(compare, "%s %d\n", "test", 1);
    EXPECT_STREQ(output, compare);
}

TEST_F(FLSTest, fls_set_log_destination) {
    const char *tmpname = "/tmp/fls_unit_test";
    char output[BUFSIZ];

    memset(output, '\0', BUFSIZ);
    fls_set_log_destination(tmpname);

    setbuf(stderr, output);
    __fls_inner_log("test");
    setbuf(stderr, nullptr);

    FILE *file = fopen(tmpname, "r");
    EXPECT_NE(file, nullptr);
    EXPECT_STREQ(output, "");
    if(file != nullptr) {
        fclose(file);
    }
}
