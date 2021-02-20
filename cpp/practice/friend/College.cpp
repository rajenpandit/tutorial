#include "College.h"
#include "Student.h"
const std::string& College::getStudentName()
{
    return m_student->getName();
}