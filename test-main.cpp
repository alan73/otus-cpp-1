#include <gtest/gtest.h>

int foo()
{
  return 73;
}

TEST(TestFoo, TestFoo)
{
  int fooValue = foo();
  ASSERT_TRUE(fooValue == 74);
}

int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
