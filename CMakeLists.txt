cmake_minimum_required(VERSION 3.10)
project(Laborator)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/unixodbc" "/opt/homebrew")
endif()

include_directories(Utils EntityLayer IntegrationLayer/Logger)

add_executable(Laborator
    Source.cpp
    EntityLayer/User.cpp
    EntityLayer/User.h
    EntityLayer/Student.cpp
    EntityLayer/Student.h
    IntegrationLayer/Logger/Logger.cpp
    IntegrationLayer/Logger/Logger.h
    IntegrationLayer/Logger/LoggerSingleton.cpp
    IntegrationLayer/Logger/LoggerSingleton.h
    IntegrationLayer/Environment/Environment.cpp
    IntegrationLayer/Environment/Environment.h
    IntegrationLayer/Database/Database.cpp
    IntegrationLayer/Database/Database.h
    RepositoryLayer/StudentRepositoryLayer/StudentRepository.cpp
    RepositoryLayer/StudentRepositoryLayer/StudentRepository.h
    RepositoryLayer/StudentRepositoryLayer/IStudentRepository.h
    Utils/pch.h
        ServiceLayer/StudentService.cpp
        ServiceLayer/StudentService.h
        DomainLayer/StudentDomain.cpp
        DomainLayer/StudentDomain.h
)


target_include_directories(Laborator PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Utils
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityLayer
        ${CMAKE_CURRENT_SOURCE_DIR}/IntegrationLayer
        ${CMAKE_CURRENT_SOURCE_DIR}/IntegrationLayer/Database
        ${CMAKE_CURRENT_SOURCE_DIR}/IntegrationLayer/Environment
        ${CMAKE_CURRENT_SOURCE_DIR}/IntegrationLayer/Logger
        ${CMAKE_CURRENT_SOURCE_DIR}/RepositoryLayer/StudentRepositoryLayer
        ${CMAKE_CURRENT_SOURCE_DIR}/ServiceLayer
        ${CMAKE_CURRENT_SOURCE_DIR}/DomainLayer
        /opt/homebrew/include
)

target_link_directories(Laborator PRIVATE /opt/homebrew/lib)
target_link_libraries(Laborator PRIVATE odbc)

add_subdirectory(
        ${CMAKE_CURRENT_SOURCE_DIR}/../GoogleTests/googletest
        ${CMAKE_CURRENT_BINARY_DIR}/googletest
        EXCLUDE_FROM_ALL
)

enable_testing()

add_executable(LaboratorTests
        LaboratorGoogleTests.cpp
        IntegrationTests.cpp
        mocking_tests.cpp
        MockStudentRepository.h
        EntityLayer/User.cpp
        EntityLayer/Student.cpp
        IntegrationLayer/Database/Database.cpp
        IntegrationLayer/Environment/Environment.cpp
        IntegrationLayer/Logger/Logger.cpp
        IntegrationLayer/Logger/LoggerSingleton.cpp
        RepositoryLayer/StudentRepositoryLayer/StudentRepository.cpp
        DomainLayer/StudentDomain.cpp
        ServiceLayer/StudentService.cpp
)
target_include_directories(LaboratorTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Utils
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityLayer
        ${CMAKE_CURRENT_SOURCE_DIR}/IntegrationLayer/Database
        ${CMAKE_CURRENT_SOURCE_DIR}/IntegrationLayer/Environment
        ${CMAKE_CURRENT_SOURCE_DIR}/IntegrationLayer/Logger
        ${CMAKE_CURRENT_SOURCE_DIR}/RepositoryLayer/StudentRepositoryLayer
        ${CMAKE_CURRENT_SOURCE_DIR}/ServiceLayer
        ${CMAKE_CURRENT_SOURCE_DIR}/DomainLayer
        /opt/homebrew/include
)
target_link_libraries(LaboratorTests PRIVATE GTest::gtest_main GTest::gmock odbc)
target_link_directories(LaboratorTests PRIVATE /opt/homebrew/lib)

include(GoogleTest)
gtest_discover_tests(
        LaboratorTests
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)