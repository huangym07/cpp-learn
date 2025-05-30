#include <iostream>
#include <utility>
#include <cstddef>
#include <gtest/gtest.h>
#include "StrVecLib.h"

void StrVecTest() { std::cout << __func__ << std::endl; }

TEST(StrVecTest, DefaultConstructor) {
    StrVec str_vec;
    EXPECT_EQ(str_vec.size(), 0);
    EXPECT_EQ(str_vec.capacity(), 0);
    EXPECT_TRUE(str_vec.empty());
}

TEST(StrVecTest, PUSH_BACK) {
    StrVec vec;
    vec.push_back("StrVec");
    vec.push_back("push_back");
    vec.push_back("test");

    EXPECT_EQ(vec.size(), 3);
    EXPECT_FALSE(vec.empty());
    EXPECT_EQ(*(vec.begin() + 0), "StrVec");
    EXPECT_EQ(*(vec.begin() + 1), "push_back");
    EXPECT_EQ(*(vec.begin() + 2), "test");
}

TEST(StrVecTest, CopyConstruct) {
    StrVec vec;
    vec.push_back("one");
    vec.push_back("two");

    StrVec vec2(vec);

    EXPECT_EQ(vec.size(), vec2.size());
    for (std::size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(*(vec.begin() + i), *(vec2.begin() + i));
    }

    vec2.push_back("three");
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec2.size(), 3);
}

TEST(StrVecTest, MoveConstruct) {
    StrVec vec;
    vec.push_back("one");
    vec.push_back("two");

    auto old_capacity = vec.capacity();
    StrVec vec2(std::move(vec));

    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 0);
    
    EXPECT_EQ(vec2.size(), 2);
    EXPECT_EQ(vec2.capacity(), old_capacity);

    EXPECT_EQ(*(vec2.begin() + 0), "one");
    EXPECT_EQ(*(vec2.begin() + 1), "two");
}


TEST(StrVecTest, CopyAssignment) {
    StrVec vec;
    vec.push_back("one");
    vec.push_back("two");

    StrVec vec2;
    vec2 = vec;

    EXPECT_EQ(vec.size(), vec2.size());
    for (std::size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(*(vec.begin() + i), *(vec2.begin() + i));
    }

    vec2.push_back("three");
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec2.size(), 3);
}

TEST(StrVecTest, MoveAssignment) {
    StrVec vec;
    vec.push_back("one");
    vec.push_back("two");

    auto old_capacity = vec.capacity();
    StrVec vec2;
    vec2 = std::move(vec);

    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 0);
    
    EXPECT_EQ(vec2.size(), 2);
    EXPECT_EQ(vec2.capacity(), old_capacity);

    EXPECT_EQ(*(vec2.begin() + 0), "one");
    EXPECT_EQ(*(vec2.begin() + 1), "two");
}

int main(int argc, char **argv) {
    StrVecTest(); 

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}