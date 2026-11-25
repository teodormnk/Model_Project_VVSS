#include "pch.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Environment.h"
#include "Database.h"
#include "StudentRepository.h"
#include "Student.h"
#include "StudentDomain.h"
#include "StudentService.h"

// Teste de integrare
// Avem o conexiune activa la un serviciu extern
// ex: baza de date, API, Auth Service, etc.

// In cadrul testului:
// 1. Ne declaram serviciul extern
// 2. Luam numarul de entitati din baza de date
// 3. Apelam functia din repository layer
// 4. Luam nr de entitati din baza de date si comparam

TEST(IntegrationTests, CheckDatabaseConnection) {
    auto conn = Environment::getInstance()->getValue("POSTGRES_CONN_STRING");
    Database database(conn);
    ASSERT_TRUE(database.getIsConnected());
    bool actual = database.getIsConnected();
    bool expected = true;
    EXPECT_EQ(expected, actual);
}

TEST(IntegrationTests, GetStudentById) {
    auto conn = Environment::getInstance()->getValue("POSTGRES_CONN_STRING");
    Database database(conn);
    ASSERT_TRUE(database.getIsConnected());
    StudentRepository repo(database);
    auto students = repo.getAllStudents();
    ASSERT_TRUE(students.has_value());
    ASSERT_FALSE(students->empty());

    const auto expected = students->at(0);
    auto actual = repo.getStudentByID(expected.getID());
    ASSERT_TRUE(actual.has_value());
    EXPECT_EQ(actual->getID(), expected.getID());
    EXPECT_EQ(actual->getFirstName(), expected.getFirstName());
}

TEST(IntegrationTests, GetAllStudents) {
    auto conn = Environment::getInstance()->getValue("POSTGRES_CONN_STRING");
    Database database(conn);
    ASSERT_TRUE(database.getIsConnected());
    StudentRepository repo(database);
    auto actual = repo.getAllStudents();
    ASSERT_TRUE(actual.has_value());
    ASSERT_FALSE(actual->empty());
}

// acesta este un test care se poate executa o singura data
TEST(IntegrationTests, DeleteStudent)
{
    auto conn = Environment::getInstance()->getValue("POSTGRES_CONN_STRING");
    Database database(conn);
    ASSERT_TRUE(database.getIsConnected());
    StudentRepository repo(database);

    auto studentiInitiali = repo.getAllStudents();
    ASSERT_TRUE(studentiInitiali.has_value());
    ASSERT_FALSE(studentiInitiali->empty());
    repo.deleteStudent(studentiInitiali->at(0).getID());
    auto studentiDupaStergere = repo.getAllStudents();
    ASSERT_TRUE(studentiDupaStergere.has_value());
    EXPECT_EQ(studentiDupaStergere->size(), studentiInitiali->size() - 1);
}

TEST(IntegrationTests, AddStudent)
{
    auto conn = Environment::getInstance()->getValue("POSTGRES_CONN_STRING");
    Database database(conn);
    ASSERT_TRUE(database.getIsConnected());
    StudentRepository repo(database);

    auto studentiInitiali = repo.getAllStudents();
    ASSERT_TRUE(studentiInitiali.has_value());
    Student student(
        "Test",
        "Student",
        "test.student@example.com",
        "Test address",
        "0712345678",
        "TEST001",
        3
    );
    repo.addStudent(student);
    auto studentiDupaAdaugare = repo.getAllStudents();
    ASSERT_TRUE(studentiDupaAdaugare.has_value());
    EXPECT_EQ(studentiDupaAdaugare->size(), studentiInitiali->size() + 1);
}

TEST(IntegrationTests, UpdateStudent)
{
    auto conn = Environment::getInstance()->getValue("POSTGRES_CONN_STRING");
    Database database(conn);
    ASSERT_TRUE(database.getIsConnected());
    StudentRepository repo(database);

    auto studenti = repo.getAllStudents();
    ASSERT_TRUE(studenti.has_value());
    ASSERT_FALSE(studenti->empty());

    Student studetDeActualizat(
        "Updated",
        "Student",
        "updated.student@example.com",
        "Updated address",
        "0712345679",
        "UPDATED001",
        3,
        studenti->at(0).getID()
    );
    repo.updateStudent(studetDeActualizat);
    auto studentActualizat = repo.getStudentByID(studenti->at(0).getID());
    ASSERT_TRUE(studentActualizat.has_value());
    EXPECT_EQ(studentActualizat->getFirstName(), "Updated");
}

TEST(DomainIntegrationTests, DeleteStudent) {
    auto conn = Environment::getInstance()->getValue("POSTGRES_CONN_STRING");
    Database database(conn);
    StudentRepository repo(database);
    StudentDomain domain(repo);

    auto studentiInitiali = repo.getAllStudents();
    domain.deleteStudent(studentiInitiali->at(0).getID());
    auto studentiDupaStergere = repo.getAllStudents();
    EXPECT_EQ(studentiDupaStergere->size(), studentiInitiali->size() - 1);
}

TEST(ServiceIntegrationTests, DeleteStudent) {
    auto conn = Environment::getInstance()->getValue("POSTGRES_CONN_STRING");
    Database database(conn);
    StudentRepository repo(database);
    StudentDomain domain(repo);
    StudentService service(domain);

    auto studentiInitiali = repo.getAllStudents();
    service.deleteStudent(studentiInitiali->at(0).getID());
    auto studentiDupaStergere = repo.getAllStudents();
    EXPECT_EQ(studentiDupaStergere->size(), studentiInitiali->size() - 1);
}