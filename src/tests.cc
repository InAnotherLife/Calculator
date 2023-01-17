#include <gtest/gtest.h>

#include "./Model/calculator.h"

constexpr double PREC = 1e-6;
constexpr char ERROR1[] = "Syntax error";
constexpr char ERROR2[] = "Math error";
constexpr char ERROR3[] = "The string is more than 250 symbols";
my::Calculator calculator;

TEST(Calculator, test_easy_num_1) {
  string str1("");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer("0.0000000");
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("10");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer("10.0000000");
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("-10");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer("-10.0000000");
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("2.222");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer("2.2220000");
  EXPECT_TRUE(str4_result == str4_answer);
}

TEST(Calculator, test_dot_error_2) {
  string str1("1.");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer = ERROR1;
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("1.");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer = ERROR1;
  EXPECT_TRUE(str2_result == str2_answer);

  string str3(".");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer = ERROR1;
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("(.)");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer = ERROR1;
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("..2+3.3");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer = ERROR1;
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("5.5.5+5");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer = ERROR1;
  EXPECT_TRUE(str6_result == str6_answer);

  string str7("2.2-3..3");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer = ERROR1;
  EXPECT_TRUE(str7_result == str7_answer);
}

TEST(Calculator, test_plus_minus_3) {
  string str1("((3+(22+99)+88-55))-50");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer("107.0000000");
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("(3+(22+99+88-55))");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer("157.0000000");
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("(3+(22+99+(88-55)))-21+22*2");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer("180.0000000");
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("3+(22+99+(88-55))");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer("157.0000000");
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("1.555999+2-3+4.000001");
  string str5_answer("4.5560000");
  string str5_result = calculator.CalculateResult(&str5);
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("2+-2");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer("0.0000000");
  EXPECT_TRUE(str6_result == str6_answer);
}

TEST(Calculator, test_mult_div_4) {
  string str1("2*5.6-3.1/8+1.1-0.9-3/2");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer("9.5125000");
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("2*5.6-3.1/8+0-0.9-3/2");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer("8.4125000");
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("0-1.5*2-5+3/4");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer("-7.2500000");
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("2*5.5-3.1-5-8-0.9");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer("-6.0000000");
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("2-5.6-3.1-8+0-0.9-3/2");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer("-17.1000000");
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("1.5+2*3*4");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer("25.5000000");
  EXPECT_TRUE(str6_result == str6_answer);

  string str7("-02*5");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer("-10.0000000");
  EXPECT_TRUE(str7_result == str7_answer);

  string str8(
      "5.5556563*26/3.565/251/15.5365*65.16/56.5466/4.646*43.488465/"
      "131.33-86.43654");
  string str8_result = calculator.CalculateResult(&str8);
  string str8_answer("-86.4356866");
  EXPECT_TRUE(str8_result == str8_answer);

  string str9("-5*8-(-5*9)");
  string str9_result = calculator.CalculateResult(&str9);
  string str9_answer("5.0000000");
  EXPECT_TRUE(str9_result == str9_answer);

  string str10("10*2/5");
  string str10_result = calculator.CalculateResult(&str10);
  string str10_answer("4.0000000");
  EXPECT_TRUE(str10_result == str10_answer);

  string str11("10/2*5");
  string str11_result = calculator.CalculateResult(&str11);
  string str11_answer("25.0000000");
  EXPECT_TRUE(str11_result == str11_answer);

  string str12("3*-10");
  string str12_result = calculator.CalculateResult(&str12);
  string str12_answer("-30.0000000");
  EXPECT_TRUE(str12_result == str12_answer);

  string str13("3*-3");
  string str13_result = calculator.CalculateResult(&str13);
  string str13_answer("-9.0000000");
  EXPECT_TRUE(str13_result == str13_answer);
}

TEST(Calculator, test_mult_div_error_5) {
  string str1("*59");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer = ERROR1;
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("59/");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer = ERROR1;
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("2/(1-1)");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer = ERROR2;
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("5*8+");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer = ERROR1;
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("5*");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer = ERROR1;
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("2/.(2-2)");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer = ERROR1;
  EXPECT_TRUE(str6_result == str6_answer);

  string str7("2/0");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer = ERROR2;
  EXPECT_TRUE(str7_result == str7_answer);

  string str8("*");
  string str8_result = calculator.CalculateResult(&str8);
  string str8_answer = ERROR1;
  EXPECT_TRUE(str8_result == str8_answer);

  string str9("*/-^.");
  string str9_result = calculator.CalculateResult(&str9);
  string str9_answer = ERROR1;
  EXPECT_TRUE(str9_result == str9_answer);

  string str10("2+-*2");
  string str10_result = calculator.CalculateResult(&str10);
  string str10_answer = ERROR1;
  EXPECT_TRUE(str10_result == str10_answer);

  string str11("2***2");
  string str11_result = calculator.CalculateResult(&str11);
  string str11_answer = ERROR1;
  EXPECT_TRUE(str11_result == str11_answer);

  string str12("2*.-2");
  string str12_result = calculator.CalculateResult(&str12);
  string str12_answer = ERROR1;
  EXPECT_TRUE(str12_result == str12_answer);

  string str13("(5*13*.)");
  string str13_result = calculator.CalculateResult(&str13);
  string str13_answer = ERROR1;
  EXPECT_TRUE(str13_result == str13_answer);
}

TEST(Calculator, test_bracket_6) {
  string str1("(1+1)(1+1)(1+1)");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer("8.0000000");
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("(1+1)(1+1)^2");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer("8.0000000");
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("2+1-6/(1+2)+5-9+5-5*9+46-44-100*0.5");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer("-91.0000000");
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("2+1-6/(1+2*3/5.7-6+5.8)");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer("-0.2386364");
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("2+1-6/(1+2*3)");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer("2.1428571");
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("(1+1)2");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer("4.0000000");
  EXPECT_TRUE(str6_result == str6_answer);

  string str7(
      "2^2-32*5.6*3.1/8+1.1-0.9-3/2*1.5+2*3*4*2+1+5^9.9+2-1+0-0-6/(1+2*3/"
      "5.7-6+5.8)-2+1-6/(1+2*3/5.7-6-5.8)");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer("8313845.3177814");
  EXPECT_TRUE(str7_result == str7_answer);

  string str8(
      "(5.55*88-565.555)(55/88/9.99*55)(44-66*5.555122-555/5.8562*6.00065)");
  string str8_answer("236634.8656269");
  string str8_result = calculator.CalculateResult(&str8);
  EXPECT_TRUE(str8_result == str8_answer);

  string str9(
      "2^(846.16561-825.6646-5.88712*9.55451/8.2242)+5.995622^0.555522-(55/88/"
      "9.99*55)-2256.541651*5.146584");
  string str9_result = calculator.CalculateResult(&str9);
  string str9_answer("1344.3234037");
  EXPECT_TRUE(str9_result == str9_answer);

  string str10(
      "0.569701^1-6/(1/2+3^5.7-6-5.8)-8*3/2*1.5+2*3*4*2+1+5^9.9+2-1^5(14.5551/"
      "5.6626)");
  string str10_result = calculator.CalculateResult(&str10);
  string str10_answer("8313897.4184808");
  EXPECT_TRUE(str10_result == str10_answer);

  string str11("(1+1)^3+(1+1)");
  string str11_result = calculator.CalculateResult(&str11);
  string str11_answer("10.0000000");
  EXPECT_TRUE(str11_result == str11_answer);

  string str12("2^2(1+1)");
  string str12_result = calculator.CalculateResult(&str12);
  string str12_answer("8.0000000");
  EXPECT_TRUE(str12_result == str12_answer);

  string str13("(((2+8)*2)+30)");
  string str13_result = calculator.CalculateResult(&str13);
  string str13_answer("50.0000000");
  EXPECT_TRUE(str13_result == str13_answer);

  string str14("(5*(2*(2+8)*2)+30)");
  string str14_result = calculator.CalculateResult(&str14);
  string str14_answer("230.0000000");
  EXPECT_TRUE(str14_result == str14_answer);

  string str15("(20-(2*(2+8)))");
  string str15_result = calculator.CalculateResult(&str15);
  string str15_answer("0.0000000");
  EXPECT_TRUE(str15_result == str15_answer);

  string str16("(+5)");
  string str16_result = calculator.CalculateResult(&str16);
  string str16_answer("5.0000000");
  EXPECT_TRUE(str16_result == str16_answer);
}

TEST(Calculator, test_bracket_error_7) {
  string str1("+5)-5(");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer = ERROR1;
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("-5(/)");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer = ERROR1;
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("-5(-)");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer = ERROR1;
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("-5(-5*)");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer = ERROR1;
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("-5(/5)");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer = ERROR1;
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("*(5+5)");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer = ERROR1;
  EXPECT_TRUE(str6_result == str6_answer);

  string str7(")(9");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer = ERROR1;
  EXPECT_TRUE(str7_result == str7_answer);

  string str8("()55");
  string str8_result = calculator.CalculateResult(&str8);
  string str8_answer = ERROR1;
  EXPECT_TRUE(str8_result == str8_answer);

  string str9("(55");
  string str9_result = calculator.CalculateResult(&str9);
  string str9_answer = ERROR1;
  EXPECT_TRUE(str9_result == str9_answer);

  string str10("55)");
  string str10_result = calculator.CalculateResult(&str10);
  string str10_answer = ERROR1;
  EXPECT_TRUE(str10_result == str10_answer);

  string str11(".5(x+x)");
  string str11_result = calculator.CalculateResult(&str11);
  string str11_answer = ERROR1;
  EXPECT_TRUE(str11_result == str11_answer);

  string str12("(1+1.)(1.+1)^2.");
  string str12_result = calculator.CalculateResult(&str12);
  string str12_answer = ERROR1;
  EXPECT_TRUE(str12_result == str12_answer);

  string str13("(.1+1)(1+1)^.2");
  string str13_result = calculator.CalculateResult(&str13);
  string str13_answer = ERROR1;
  EXPECT_TRUE(str13_result == str13_answer);

  string str14("*55.");
  string str14_result = calculator.CalculateResult(&str14);
  string str14_answer = ERROR1;
  EXPECT_TRUE(str14_result == str14_answer);
}

TEST(Calculator, test_degree_8) {
  string str1("2^(5.5-3.45)");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer("4.1410597");
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("(2^2)^3");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer("64.0000000");
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("2*5.5-3.1^5");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer("-275.2915100");
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("3-1/9^0-2");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer("0.0000000");
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("2^1-6/(1/2+3^5.7-6-5.8)^2-8");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer("-6.0000228");
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("2*5.5-3.1^5-8-2.2^5");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer("-334.8278300");
  EXPECT_TRUE(str6_result == str6_answer);

  string str7("2*5.5-3.1^5-8-2.2^4");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer("-306.7171100");
  EXPECT_TRUE(str7_result == str7_answer);

  string str8("5+5^-2.2+5");
  string str8_result = calculator.CalculateResult(&str8);
  string str8_answer("10.0289912");
  EXPECT_TRUE(str8_result == str8_answer);

  string str9("2^3^-2.2^2");
  string str9_result = calculator.CalculateResult(&str9);
  string str9_answer("1.0034064");
  EXPECT_TRUE(str9_result == str9_answer);

  string str10("-10^2");
  string str10_result = calculator.CalculateResult(&str10);
  string str10_answer("-100.0000000");
  EXPECT_TRUE(str10_result == str10_answer);

  string str11("(-10)^2");
  string str11_result = calculator.CalculateResult(&str11);
  string str11_answer("100.0000000");
  EXPECT_TRUE(str11_result == str11_answer);

  string str12("4+5^-2");
  string str12_result = calculator.CalculateResult(&str12);
  string str12_answer("4.0400000");
  EXPECT_TRUE(str12_result == str12_answer);

  string str13("-2^2");
  string str13_result = calculator.CalculateResult(&str13);
  string str13_answer("-4.0000000");
  EXPECT_TRUE(str13_result == str13_answer);

  string str14("-2^3");
  string str14_result = calculator.CalculateResult(&str14);
  string str14_answer("-8.0000000");
  EXPECT_TRUE(str14_result == str14_answer);

  string str15("(-2)^2");
  string str15_result = calculator.CalculateResult(&str15);
  string str15_answer("4.0000000");
  EXPECT_TRUE(str15_result == str15_answer);

  string str16("(-2)^3");
  string str16_result = calculator.CalculateResult(&str16);
  string str16_answer("-8.0000000");
  EXPECT_TRUE(str16_result == str16_answer);
}

TEST(Calculator, test_degree_error_9) {
  string str1("5^-");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer = ERROR1;
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("5^*2");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer = ERROR1;
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("5.^2");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer = ERROR1;
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("5(*5)");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer = ERROR1;
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("(-2)^3.1");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer = ERROR2;
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("3^");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer = ERROR1;
  EXPECT_TRUE(str6_result == str6_answer);

  string str7("^3");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer = ERROR1;
  EXPECT_TRUE(str7_result == str7_answer);

  string str8("3*^-3");
  string str8_result = calculator.CalculateResult(&str8);
  string str8_answer = ERROR1;
  EXPECT_TRUE(str8_result == str8_answer);

  string str9("3^^");
  string str9_result = calculator.CalculateResult(&str9);
  string str9_answer = ERROR1;
  EXPECT_TRUE(str9_result == str9_answer);

  string str10("^^3");
  string str10_result = calculator.CalculateResult(&str10);
  string str10_answer = ERROR1;
  EXPECT_TRUE(str10_result == str10_answer);
}

TEST(Calculator, test_mod_10) {
  string str1("5mod11");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer("5.0000000");
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("5mod(11)");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer("5.0000000");
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("230mod11");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer("10.0000000");
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("-5mod11");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer("-5.0000000");
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("9mod(5-10)");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer("4.0000000");
  EXPECT_TRUE(str5_result == str5_answer);
}

TEST(Calculator, test_mod_error_11) {
  string str1("mod10");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer = ERROR1;
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("10(mod)");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer = ERROR1;
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("(10)mod");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer = ERROR1;
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("2mod.11");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer = ERROR1;
  EXPECT_TRUE(str4_result == str4_answer);
}

TEST(Calculator, test_sin_asin_12) {
  string str1("sin0");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer("0.0000000");
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("asin0.5");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer("0.5235988");
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("sin(-8)");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer("-0.9893582");
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("sin(0)");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer("0.0000000");
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("sin916.5566");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer("-0.7092649");
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("sin8");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer("0.9893582");
  EXPECT_TRUE(str6_result == str6_answer);

  string str7("sin-8");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer("-0.9893582");
  EXPECT_TRUE(str7_result == str7_answer);

  string str8("-sin8");
  string str8_result = calculator.CalculateResult(&str8);
  string str8_answer("-0.9893582");
  EXPECT_TRUE(str8_result == str8_answer);
}

TEST(Calculator, test_sin_error_13) {
  string str1("sin0-");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer = ERROR1;
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("sin*0");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer = ERROR1;
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("sin.0");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer = ERROR1;
  EXPECT_TRUE(str3_result == str3_answer);
}

TEST(Calculator, test_cos_acos_14) {
  string str1("2^3-4-cos3.1415926");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer("5.0000000");
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("cos-10-10");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer("-10.8390715");
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("2*cos(3)");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer("-1.9799850");
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("2*cos3");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer("-1.9799850");
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("8/9+2^3^cos15");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer("2.2399070");
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("acos0.5");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer("1.0471976");
  EXPECT_TRUE(str6_result == str6_answer);

  string str7("(cos0+cos0)");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer("2.0000000");
  EXPECT_TRUE(str7_result == str7_answer);

  string str9("(2(cos0+cos0))");
  string str9_result = calculator.CalculateResult(&str9);
  string str9_answer("4.0000000");
  EXPECT_TRUE(str9_result == str9_answer);

  string str10("cos(-10)-10");
  string str10_result = calculator.CalculateResult(&str10);
  string str10_answer("-10.8390715");
  EXPECT_TRUE(str10_result == str10_answer);

  string str11("-cos0");
  string str11_result = calculator.CalculateResult(&str11);
  string str11_answer("-1.0000000");
  EXPECT_TRUE(str11_result == str11_answer);
}

TEST(Calculator, test_cos_sin_error_15) {
  string str1("cos.");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer = ERROR1;
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("cos");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer = ERROR1;
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("2cos(3)");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer = ERROR1;
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("sinxcosx");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer = ERROR1;
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("sin1cos1");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer = ERROR1;
  EXPECT_TRUE(str5_result == str5_answer);
}

TEST(Calculator, test_tan_atan_16) {
  string str1("tan(5)");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer("-3.3805150");
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("atan10");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer("1.4711277");
  EXPECT_TRUE(str2_result == str2_answer);
}

TEST(Calculator, test_sqrt_17) {
  string str1("sqrt2");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer("1.4142136");
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("sqrt-0");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer("0.0000000");
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("sqrt(2)*sqrt2");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer("2.0000000");
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("sqrt(2)^sqrt2");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer("1.6325269");
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("sqrt(-0)");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer("0.0000000");
  EXPECT_TRUE(str5_result == str5_answer);
}

TEST(Calculator, test_sqrt_error_18) {
  string str1("sqrt())");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer = ERROR1;
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("sqrt(3-5)");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer = ERROR2;
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("-sqrt(-1)");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer = ERROR2;
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("sqrt-2");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer = ERROR2;
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("sqrt(2)^sqrt-2");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer = ERROR2;
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("sqrt(-)");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer = ERROR1;
  EXPECT_TRUE(str6_result == str6_answer);

  string str7("sqrt-");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer = ERROR1;
  EXPECT_TRUE(str7_result == str7_answer);
}

TEST(Calculator, test_ln_log_19) {
  string str1("ln10");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer("2.3025851");
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("ln(10)");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer("2.3025851");
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("log10");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer("1.0000000");
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("log(10)");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer("1.0000000");
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("ln10*ln10-5");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer("0.3018981");
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("ln10*log10+5");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer("7.3025851");
  EXPECT_TRUE(str6_result == str6_answer);

  string str7("-ln10");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer("-2.3025851");
  EXPECT_TRUE(str7_result == str7_answer);

  string str8("-log(10)");
  string str8_result = calculator.CalculateResult(&str8);
  string str8_answer("-1.0000000");
  EXPECT_TRUE(str8_result == str8_answer);
}

TEST(Calculator, test_exp_20) {
  string str1("exp1");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer("2.7182818");
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("-exp(1)");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer("-2.7182818");
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("exp(1*)");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer = ERROR1;
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("exp");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer = ERROR1;
  EXPECT_TRUE(str4_result == str4_answer);

  string str5(".exp1");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer = ERROR1;
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("exp1.2");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer("3.3201169");
  EXPECT_TRUE(str6_result == str6_answer);

  string str7("8*7-5+exp18");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer("65660020.1373305");
  EXPECT_TRUE(str7_result == str7_answer);

  string str8("exp8.58*cos1.5+1855/461.65-0.665");
  string str8_result = calculator.CalculateResult(&str8);
  string str8_answer("379.9655218");
  EXPECT_TRUE(str8_result == str8_answer);
}

TEST(Calculator, test_scientific_notation_21) {
  string str1("123e+03");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer("123000.0000000");
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("123e-04");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer("0.0123000");
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("123e+03*2/3+18000");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer("100000.0000000");
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("123e-02+2*3");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer("7.2300000");
  EXPECT_TRUE(str4_result == str4_answer);

  string str5("0.123e+03^2");
  string str5_result = calculator.CalculateResult(&str5);
  string str5_answer("15129.0000000");
  EXPECT_TRUE(str5_result == str5_answer);

  string str6("2*5.6-3.1/8+0-0.9-3/2+1.23e+03");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer("1238.4125000");
  EXPECT_TRUE(str6_result == str6_answer);

  string str7("2*5.6-3.1/8+0-0.9-3/2*1.23e+03");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer("-1835.0875000");
  EXPECT_TRUE(str7_result == str7_answer);

  string str8("3/2+123e+2*3");
  string str8_result = calculator.CalculateResult(&str8);
  string str8_answer("36901.5000000");
  EXPECT_TRUE(str8_result == str8_answer);

  string str9("(123e-02+2)*3");
  string str9_result = calculator.CalculateResult(&str9);
  string str9_answer("9.6900000");
  EXPECT_TRUE(str9_result == str9_answer);

  string str10("(3/2+123e-02)*4");
  string str10_result = calculator.CalculateResult(&str10);
  string str10_answer("10.9200000");
  EXPECT_TRUE(str10_result == str10_answer);

  string str11("5*8+0.123e-0^2");
  string str11_result = calculator.CalculateResult(&str11);
  string str11_answer("40.0151290");
  EXPECT_TRUE(str11_result == str11_answer);

  string str12("(3/2+123e-0)*4");
  string str12_result = calculator.CalculateResult(&str12);
  string str12_answer("498.0000000");
  EXPECT_TRUE(str12_result == str12_answer);

  string str13("-123e-03");
  string str13_result = calculator.CalculateResult(&str13);
  string str13_answer("-0.1230000");
  EXPECT_TRUE(str13_result == str13_answer);

  string str14("-123e-00");
  string str14_result = calculator.CalculateResult(&str14);
  string str14_answer("-123.0000000");
  EXPECT_TRUE(str14_result == str14_answer);

  string str15("123e-00");
  string str15_result = calculator.CalculateResult(&str15);
  string str15_answer("123.0000000");
  EXPECT_TRUE(str15_result == str15_answer);

  string str16("123e+00");
  string str16_result = calculator.CalculateResult(&str16);
  string str16_answer("123.0000000");
  EXPECT_TRUE(str16_result == str16_answer);

  string str17("(123e-02)*4");
  string str17_result = calculator.CalculateResult(&str17);
  string str17_answer("4.9200000");
  EXPECT_TRUE(str17_result == str17_answer);

  string str18("(-123e-03)");
  string str18_result = calculator.CalculateResult(&str18);
  string str18_answer("-0.1230000");
  EXPECT_TRUE(str18_result == str18_answer);

  string str19("1e-1");
  string str19_result = calculator.CalculateResult(&str19);
  string str19_answer("0.1000000");
  EXPECT_TRUE(str19_result == str19_answer);

  string str20("3/2+123e-0");
  string str20_result = calculator.CalculateResult(&str20);
  string str20_answer("124.5000000");
  EXPECT_TRUE(str20_result == str20_answer);
}

TEST(Calculator, test_scientific_notation_error_22) {
  string str1("4*123e*03");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer = ERROR1;
  EXPECT_TRUE(str1_result == str1_answer);

  string str2("0.1+1.2.3e^03");
  string str2_result = calculator.CalculateResult(&str2);
  string str2_answer = ERROR1;
  EXPECT_TRUE(str2_result == str2_answer);

  string str3("-123e03");
  string str3_result = calculator.CalculateResult(&str3);
  string str3_answer = ERROR1;
  EXPECT_TRUE(str3_result == str3_answer);

  string str4("-123e");
  string str4_result = calculator.CalculateResult(&str4);
  string str4_answer = ERROR1;
  EXPECT_TRUE(str4_result == str4_answer);

  string str6("3/2+1.23e+");
  string str6_result = calculator.CalculateResult(&str6);
  string str6_answer = ERROR1;
  EXPECT_TRUE(str6_result == str6_answer);

  string str7("(1.23e)*2");
  string str7_result = calculator.CalculateResult(&str7);
  string str7_answer = ERROR1;
  EXPECT_TRUE(str7_result == str7_answer);

  string str8("e-02*5");
  string str8_result = calculator.CalculateResult(&str8);
  string str8_answer = ERROR1;
  EXPECT_TRUE(str8_result == str8_answer);

  string str9("(-123e-03)/");
  string str9_result = calculator.CalculateResult(&str9);
  string str9_answer = ERROR1;
  EXPECT_TRUE(str9_result == str9_answer);

  string str10("(123e-03/)");
  string str10_result = calculator.CalculateResult(&str10);
  string str10_answer = ERROR1;
  EXPECT_TRUE(str10_result == str10_answer);

  string str11("4*123e/3");
  string str11_result = calculator.CalculateResult(&str11);
  string str11_answer = ERROR1;
  EXPECT_TRUE(str11_result == str11_answer);

  string str12(")-123e+03(");
  string str12_result = calculator.CalculateResult(&str12);
  string str12_answer = ERROR1;
  EXPECT_TRUE(str12_result == str12_answer);

  string str13("e9");
  string str13_result = calculator.CalculateResult(&str13);
  string str13_answer = ERROR1;
  EXPECT_TRUE(str13_result == str13_answer);

  string str14("e/");
  string str14_result = calculator.CalculateResult(&str14);
  string str14_answer = ERROR1;
  EXPECT_TRUE(str14_result == str14_answer);

  string str15("e.");
  string str15_result = calculator.CalculateResult(&str15);
  string str15_answer = ERROR1;
  EXPECT_TRUE(str15_result == str15_answer);

  string str16("123(e-03)");
  string str16_result = calculator.CalculateResult(&str16);
  string str16_answer = ERROR1;
  EXPECT_TRUE(str16_result == str16_answer);

  string str17("ecos9");
  string str17_result = calculator.CalculateResult(&str17);
  string str17_answer = ERROR1;
  EXPECT_TRUE(str17_result == str17_answer);

  string str18("e(cos(9))");
  string str18_result = calculator.CalculateResult(&str18);
  string str18_answer = ERROR1;
  EXPECT_TRUE(str18_result == str18_answer);
}

TEST(Calculator, test_overflow_23) {
  string str1(
      "123456789012345678901234567890123456789012345678901234567890123456789012"
      "345678901234567890123456789012345678901234567890123456789012345678901234"
      "567890123456789012345678901234567890123456789012345678901234567890123456"
      "78901234567890123456789012345678901234+1");
  string str1_result = calculator.CalculateResult(&str1);
  string str1_answer = ERROR3;
  EXPECT_TRUE(str1_result == str1_answer);
}

int main(int argc, char **argv) {
  setlocale(LC_ALL, "en_US.UTF-8");
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
