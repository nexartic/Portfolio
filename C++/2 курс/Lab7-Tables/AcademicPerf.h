#ifndef _ACADEMIC_PERFORMANCE_H_
#define _ACADEMIC_PERFORMANCE_H_

#include "DatValue.h"
#include <map>
#include <string>
#include <utility>
#include <iostream>

class AcademicPerformance : public TDatValue
{
public:
    AcademicPerformance() : TDatValue() {}
    AcademicPerformance(const AcademicPerformance &rhs) : marks(rhs.marks) {}
    AcademicPerformance(AcademicPerformance &&rhs) : marks(std::move(rhs.marks)) {}
    ~AcademicPerformance() = default;

    AcademicPerformance& operator=(const AcademicPerformance &rhs);
    AcademicPerformance& operator=(AcademicPerformance &&rhs);
    bool operator==(const AcademicPerformance &rhs) const;

    void addCourse(std::string name, int mark);
    double getAvgMark() const;
    int getMark(std::string CourseName) const;
    void printCourses(std::ostream& str = std::cout) const;
    void printMarks(std::string, std::ostream& str = std::cout) const;

    TDatValue *GetCopy() override;
private:
    std::map<std::string, int> marks;
};

#endif
