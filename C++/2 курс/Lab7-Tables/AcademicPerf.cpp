#include "AcademicPerf.h"

AcademicPerformance& AcademicPerformance::operator=(const AcademicPerformance &rhs)
{
    if (this != &rhs)
        marks = rhs.marks;
    return *this;
}

AcademicPerformance& AcademicPerformance::operator=(AcademicPerformance &&rhs)
{
    if (this != &rhs)
        marks = std::move(rhs.marks);
    return *this;
}

bool AcademicPerformance::operator==(const AcademicPerformance &rhs) const
{
    return marks == rhs.marks;
}

void AcademicPerformance::addCourse(std::string name, int mark)
{
    marks.insert({ name, mark });
}

double AcademicPerformance::getAvgMark() const
{
    double avg = .0;
    for (auto& it: marks)
        avg += it.second;
    return (marks.size()) ? avg / marks.size() : .0;
}

int AcademicPerformance::getMark(std::string CourseName) const
{
    try { return marks.at(CourseName); }
    catch (...) { return 0; }
}

void AcademicPerformance::printCourses(std::ostream& str) const
{
    for (int i = 0; i < 20; ++i)
        str << " ";
    for (auto& it : marks)
        str << it.first << "  ";
    str << std::endl;
}

void AcademicPerformance::printMarks(std::string key, std::ostream& str) const
{
    for (int i = 0; i < 20 - key.size(); ++i)
        str << " ";
    for (auto& it : marks)
    {
        for (int i = 0; i < it.first.size() / 2; ++i)
            str << " ";
        str << it.second;
        for (int i = 0; i < it.first.size() / 2 + 1; ++i)
            str << " ";
    }
    str << std::endl;
}

TDatValue* AcademicPerformance::GetCopy()
{
    return static_cast<TDatValue*>(new AcademicPerformance(*this));
}
