#include "pch.h"
#include "MockStudentRepository.h"
#include "StudentService.h"
#include "StudentDomain.h"

TEST(MockingTests, GetStudentByID) {
    int id = 5;
    MockStudentRepository mock;
    Student student("Ion", "Popescu", "ion.popescu@unitbv.ro","", "", "", 3, id);
    EXPECT_CALL(mock, getStudentByID(id)).WillOnce(::testing::Return(student));

    Student actual = mock.getStudentByID(id).value();
    EXPECT_EQ(student.getFirstName(), actual.getFirstName());
}

TEST(MockingTests, GetStudentByIdFiveTimes) {
    int id = 5;
    Student student("Ion", "Popescu", "ion.popescu@unitbv.ro","", "", "", 3, id);
    MockStudentRepository mock;
    EXPECT_CALL(mock, getStudentByID(id)).Times(5).WillRepeatedly(testing::Return(student));

    mock.getStudentByID(id);
    mock.getStudentByID(id);
    mock.getStudentByID(id);
    mock.getStudentByID(id);
    mock.getStudentByID(id);
}

TEST(MockingTests, DeleteStudent) {
    MockStudentRepository mock;
    int id = 5;
    EXPECT_CALL(mock, deleteStudent(id)).WillOnce(testing::Return());

    mock.deleteStudent(id);
}


// Cum se face mocking cu obiecte ca parametrii
// Hint: lambda functions
TEST(MockingTests, AddStudent) {
    MockStudentRepository mock;
    Student student("Ion", "Popescu", "ion.popescu@unitbv.ro","", "", "", 3);
    EXPECT_CALL(mock, addStudent(testing::Truly(
        [](const Student& student) {
            return student.getFirstName() == "Ion" &&
                student.getLastName() == "Popescu" &&
                    student.getEmail() == "ion.popescu@unitbv.ro" &&
                        student.getAddress() == "" &&
                            student.getMatriculationNumber() == "" &&
                                student.getPhone() == "" &&
                                    student.getStudyYear() == 3;
        }
        )));

    mock.addStudent(student);
}

TEST(DomainTestMock, GetStudentById) {
    MockStudentRepository mock;
    int id = 5000;
    Student student("Ion", "Popescu", "ion.popescu@unitbv.ro","", "", "", 3, id);
    StudentDomain domain(mock);
    EXPECT_CALL(mock, getStudentByID(id)).WillOnce(testing::Return(student));
    domain.getStudentByID(id);
}

TEST(ServiceTestMock, GetStudentById) {
    MockStudentRepository mock;
    int id = 5000;
    Student student("Ion", "Popescu", "ion.popescu@unitbv.ro","", "", "", 3, id);
    StudentDomain domain(mock);
    StudentService service(domain);
    EXPECT_CALL(mock, getStudentByID(id)).WillOnce(testing::Return(student));
    service.getStudentByID(id);
}