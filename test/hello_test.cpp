#include "../include/Hex.h"
#include <gtest/gtest.h>

TEST(HexTest, defaultConstructor)
{
  Hex defaultData;
  size_t expectedSize = 1;
  unsigned char expectedData[] = {'0'};
  size_t realSize = defaultData.getSize();
  unsigned char *realData = defaultData.getData();

  ASSERT_TRUE(expectedSize == realSize);
  ASSERT_TRUE(expectedData[0] == realData[0]);
}

TEST(HexTest, defaultValueConstructor)
{
  size_t length = 3;
  unsigned char defaultValue = 'A';
  size_t expectedSize = 3;
  unsigned char expectedValue[] = {'A', 'A', 'A'};

  Hex testValue(length, defaultValue);
  size_t realSize = testValue.getSize();
  unsigned char *realValue = testValue.getData();

  ASSERT_TRUE(realSize == expectedSize);
  ASSERT_TRUE(realValue[0] == expectedValue[0]);
  ASSERT_TRUE(realValue[1] == expectedValue[1]);
  ASSERT_TRUE(realValue[2] == expectedValue[2]);
}

TEST(HexTest, initializerListConstructor)
{
  std::initializer_list<unsigned char> data = {'A', 'B', 'C'};
  size_t expectedSize = 3;
  unsigned char expectedValue[] = {'A', 'B', 'C'};

  Hex testValue(data);
  size_t realSize = testValue.getSize();
  unsigned char *realValue = testValue.getData();

  ASSERT_TRUE(realSize == expectedSize);
  ASSERT_TRUE(realValue[0] == expectedValue[0]);
  ASSERT_TRUE(realValue[1] == expectedValue[1]);
  ASSERT_TRUE(realValue[2] == expectedValue[2]);
}

TEST(HexTest, stringValueConstructor)
{
  size_t length = 3;
  std::string stringValue = "ABC";
  size_t expectedSize = 3;
  unsigned char expectedValue[] = {'A', 'B', 'C'};

  Hex testValue(stringValue);
  size_t realSize = testValue.getSize();
  unsigned char *realValue = testValue.getData();

  ASSERT_TRUE(realSize == expectedSize);
  ASSERT_TRUE(realValue[0] == expectedValue[0]);
  ASSERT_TRUE(realValue[1] == expectedValue[1]);
  ASSERT_TRUE(realValue[2] == expectedValue[2]);
}

TEST(HexTest, AddUpTest)
{
  std::string str = "AC5";
  std::string str2 = "456";
  size_t expectedSize = 3;
  unsigned char expectedData[] = {'F', '1', 'B'};

  Hex number1(str);
  Hex number2(str2);
  number2 += number1;
  size_t realSize = number2.getSize();
  unsigned char *realData = number2.getData();

  ASSERT_TRUE(expectedSize == realSize);
  ASSERT_TRUE(expectedData[0] == realData[0]);
  ASSERT_TRUE(expectedData[1] == realData[1]);
  ASSERT_TRUE(expectedData[2] == realData[2]);
}

TEST(HexTest, SubstractTest)
{
  std::string str = "456";
  std::string str2 = "AC5";
  size_t expectedSize = 3;
  unsigned char expectedData[] = {'6', '6', 'F'};

  Hex number1(str);
  Hex number2(str2);
  number2 -= number1;
  size_t realSize = number2.getSize();
  unsigned char *realData = number2.getData();

  ASSERT_TRUE(expectedSize == realSize);
  ASSERT_TRUE(expectedData[0] == realData[0]);
  ASSERT_TRUE(expectedData[1] == realData[1]);
  ASSERT_TRUE(expectedData[2] == realData[2]);
}

TEST(HexTest, NegativeSubtractionException)
{
  std::string str = "AC5";
  std::string str2 = "456";
  size_t expectedSize = 3;
  unsigned char expectedData[] = {'6', '6', 'F'};

  Hex number1(str);
  Hex number2(str2);

  bool result = number1 > number2;

  ASSERT_TRUE(result);
  ASSERT_THROW(number2 -= number1, NegativeSubtraction);
}

TEST(HexTest, CompareLessTest){
  std::string str = "AC5";
  std::string str2 = "456";
  Hex number1(str);
  Hex number2(str2);

  bool result = number1 > number2;

  ASSERT_TRUE(result);
}

TEST(HexTest, CompareGreatTest) {
  std::string str = "456";
  std::string str2 = "AC5";
  Hex number1(str);
  Hex number2(str2);

  bool result = number2 > number1;

  ASSERT_TRUE(result);
}

TEST(HexTest, CompareEqualTest) {
  std::string str = "ABCD";
  std::string str2 = "ABCD";

  Hex number1(str);
  Hex number2(str2);

  bool result = number1 == number2;

  ASSERT_TRUE(result);
}

TEST(HexTest, InvalidDigitException)
{
  std::string str = "G";

  ASSERT_THROW(Hex number1(str), invalidDigit);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}