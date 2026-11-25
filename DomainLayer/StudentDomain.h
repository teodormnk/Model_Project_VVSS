#pragma once
#include "StudentRepository.h"
// Domeniul are o singura referinta catre Repository
// Rolul domeniului: validarea criteriilor de business (validare = toate usecase-urile business-ului sunt acoperite, rezolvam doar ce ni se cere si nu altceva)
// Fiecare functie din domeniu apeleaza functia echivalenta din Repository in momentul in care validarea trece

class StudentDomain {
public:
    StudentDomain(IStudentRepository& m_repository);
public:
    void deleteStudent(int id);
    void addStudent(std::string firstName, std::string lastName, std::string email, std::string address, std::string phone, std::string matriculationNumber, int studyYear);
    void updateStudent(std::string firstName, std::string lastName, std::string email, std::string address, std::string phone, std::string matriculationNumber, int studyYear);
    std::optional<Student> getStudentByID(int id);
    std::optional<std::vector<Student>> getAllStudents();
private:
    IStudentRepository& m_repository;
};

