#include "StudentDomain.h"

//Exemplu criterii specifice de business:
// 1. Toate id-urile apartin intervalului [5000, 9000]
// 2. Toate adresele trebuie sa fie din Brasov
// 3. Toate email-urile contin "@student.unitbv.ro"
// 4. Anii de stuiu pot fi 1, 2, 3, 4, 5, 6
// etc (poate continua la infinit)

StudentDomain::StudentDomain(IStudentRepository& repository): m_repository(repository) {}

void StudentDomain::deleteStudent(int id) {
    if (id < 5000 || id > 9000) {
        LoggerSingleton::getLoggerInstance()->log("ID in afara range-ului", Logger::Level::Error);
        return;
    }
    m_repository.deleteStudent(id);
}

void StudentDomain::addStudent(std::string firstName, std::string lastName, std::string email, std::string address, std::string phone, std::string matriculationNumber, int studyYear) {
    if (address.find("Brasov") == std::string::npos) {
        LoggerSingleton::getLoggerInstance()->log("Adresa nu este din Brasov", Logger::Level::Error);
        return;
    }
    if (email.find("@student.unitbv.ro") == std::string::npos) {
        LoggerSingleton::getLoggerInstance()->log("Adresa este invalida", Logger::Level::Error);
        return;
    }
    if (studyYear < 1 || studyYear > 6) {
        LoggerSingleton::getLoggerInstance()->log("Anul de studiu este invalid", Logger::Level::Error);
        return;
    }
    // in acest moment, aici avem un obiect valid -> impachetam in entitatea lui
    Student student(firstName, lastName, email, address, phone, matriculationNumber, studyYear);
    m_repository.addStudent(student);
}

void StudentDomain::updateStudent(std::string firstName, std::string lastName, std::string email, std::string address, std::string phone, std::string matriculationNumber, int studyYear) {
    if (address.find("Brasov") == std::string::npos) {
        LoggerSingleton::getLoggerInstance()->log("Adresa nu este din Brasov", Logger::Level::Error);
        return;
    }
    if (email.find("@student.unitbv.ro") == std::string::npos) {
        LoggerSingleton::getLoggerInstance()->log("Adresa este invalida", Logger::Level::Error);
        return;
    }
    if (studyYear < 1 || studyYear > 6) {
        LoggerSingleton::getLoggerInstance()->log("Anul de studiu este invalid", Logger::Level::Error);
        return;
    }
    Student student(firstName, lastName, email, address, phone, matriculationNumber, studyYear);
    m_repository.updateStudent(student);
}

std::optional<Student> StudentDomain::getStudentByID(int id) {
    if (id < 5000 || id > 9000) {
        LoggerSingleton::getLoggerInstance()->log("ID-ul este in afara range-ului", Logger::Level::Error);
        return std::nullopt;
    }
    return m_repository.getStudentByID(id);
}

std::optional<std::vector<Student>> StudentDomain::getAllStudents() {
    return m_repository.getAllStudents();
}
