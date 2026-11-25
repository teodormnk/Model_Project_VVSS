#include "StudentService.h"

StudentService::StudentService(StudentDomain& domain): m_domain(domain) {}

void StudentService::deleteStudent(int id) {
    // daca id-ul este invalid (nu exista) -> ne oprim
    // altfel -> apelam functia de delete din domeniu
    if (id < 0) {
        return;
    }
    m_domain.deleteStudent(id);
}

void StudentService::addStudent(std::string firstName, std::string lastName, std::string email, std::string address, std::string phone, std::string matriculationNumber, int studyYear) {
    if (firstName.size() == 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    if (lastName.size() == 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    if (email.size() == 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    if (address.size() == 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    if (phone.size() == 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    if (matriculationNumber.size() == 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    if (studyYear < 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    m_domain.addStudent(firstName, lastName, email, address, phone, matriculationNumber, studyYear);
}

void StudentService::updateStudent(std::string firstName, std::string lastName, std::string email, std::string address,std::string phone, std::string matriculationNumber, int studyYear) {
    if (firstName.size() == 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    if (lastName.size() == 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    if (email.size() == 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    if (address.size() == 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    if (phone.size() == 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    if (matriculationNumber.size() == 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    if (studyYear < 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid email", Logger::Level::Error);
        return;
    }
    m_domain.addStudent(firstName, lastName, email, address, phone, matriculationNumber, studyYear);
}

std::optional<Student> StudentService::getStudentByID(int id) {
    if (id < 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid id", Logger::Level::Error);
        return std::nullopt;
    }
    return m_domain.getStudentByID(id);
}

std::optional<std::vector<Student>> StudentService::getAllStudents() {
    return m_domain.getAllStudents();
}
