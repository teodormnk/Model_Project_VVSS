#pragma once
#include <string>

#include "Student.h"
#include "StudentDomain.h"

// Serviciul are o singura referinta catre Domeniu
// Rolul serviciului: verificarea la nivelul atributelor care vin din exterior (frontend)
// Verificare = campurile sau atributele EXISTA
// Serviciul apeleaza functiile exhivalente din domeniu

class StudentService {
public:
    StudentService(StudentDomain& domain);
public:
    void deleteStudent(int id);
    void addStudent(std::string firstName, std::string lastName, std::string email, std::string address, std::string phone, std::string matriculationNumber, int studyYear);
    void updateStudent(std::string firstName, std::string lastName, std::string email, std::string address, std::string phone, std::string matriculationNumber, int studyYear);
    std::optional<Student> getStudentByID(int id);
    std::optional<std::vector<Student>> getAllStudents();

private:
    StudentDomain m_domain;
};