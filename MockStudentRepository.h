#pragma once

#include "pch.h"
#include <gmock/gmock.h>
#include "IStudentRepository.h"

class MockStudentRepository : public IStudentRepository {
public:
    MOCK_METHOD(void, deleteStudent, (int id), (override));
    MOCK_METHOD(void, addStudent, (Student student), (override));
    MOCK_METHOD(void, updateStudent, (Student student), (override));
    MOCK_METHOD(std::optional<Student>, getStudentByID, (int id), (override));
    MOCK_METHOD(std::optional<std::vector<Student>>, getAllStudents, (), (override));
};