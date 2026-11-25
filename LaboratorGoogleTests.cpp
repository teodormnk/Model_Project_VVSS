#include "pch.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Student.h"

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName2) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(TestCaseName, CheckStudent) {
    Student student("Maria", "Popescu", "maria.popescu@student.unitbv.ro", "Str. Lunga nr 5", "0771123456", "123A", 3, 89);
    EXPECT_TRUE(student.getFirstName() != "");
    EXPECT_TRUE(student.getEmail().find("@student.unitbv.ro") != std::string::npos);
}

TEST(TestCaseName, CheckStudent2) {
    Student student("Alexandru", "Davidescu", "alex.davidescu@student.unitbv.ro", "Str. Lunga nr 8", "0772123456", "456B", 2, 90);
    EXPECT_TRUE(student.getFirstName() != "");
    EXPECT_TRUE(student.getEmail().find("@student.unitbv.ro") != std::string::npos);
}

TEST(TestCaseName, MaxInVector) {
    std::vector<double> vector = { 1, 2, 3, 4, 5 };
    double expectedMax = 5;
    double actualMax = calculateMaxInVector(vector);
    EXPECT_EQ(expectedMax, actualMax);
}

TEST(TestCaseName, MaxInNegativeVector) {
    std::vector<double> vector = { -1, -2, -3, -4, -5 };
    double expectedMax = -1;
    double actualMax = calculateMaxInVector(vector);
    EXPECT_EQ(expectedMax, actualMax);
}

TEST(TestcaseName, MaxInEmptyVector) {
    std::vector<double> vector = {};
    double expected = 0.0;
    double actual;
    try{
        actual = calculateMaxInVector(vector);
    }
    catch(const std::invalid_argument& exception)
    {
        EXPECT_EQ(std::string(exception.what()), "Vector gol!"); // daca avem eroare, facem cast la std::string(exception.what()) si comparam cu mesajul asteptat
    }
}

TEST(TestCaseName, AvgInVector) {
    std::vector<double> vector = { 1, 2, 3, 4, 5 };
    double expected = 3;
    double actual = calculateAvgInVector(vector);
    EXPECT_EQ(expected, actual);
}

TEST(TestCaseName, AvgInNegativeVector) {
    std::vector<double> vector = { -1, -2, -3, -4, -5 };
    double expected = -3;
    double actual = calculateAvgInVector(vector);
    EXPECT_EQ(expected, actual);
}

TEST(TestCaseName, AvgInEmptyVector) {
    std::vector<double> vector = {};
    double expected = 0.0;
    double actual;
    try {
        actual = calculateAvgInVector(vector);
    } catch (const std::invalid_argument& exception) {
        EXPECT_EQ(std::string(exception.what()), "Vector gol!");
    }
}