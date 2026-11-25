#include "Student.h"
#include "LoggerSingleton.h"
#include "Environment.h"
#include "Database.h"
#include "StudentDomain.h"
#include "StudentService.h"

// using namespace std;

int main()
{
	std::string postgres_conn = Environment::getInstance()->getValue("POSTGRES_CONN_STRING");

	Database postgres_database(postgres_conn);
	StudentRepository repo(postgres_database);
	StudentDomain domain(repo);
	StudentService service(domain);
	service.deleteStudent(5000);

	return 0;
}