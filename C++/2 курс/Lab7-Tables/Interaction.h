#ifndef _INTERACTION_H_
#define _INTERACTION_H_

#include "AcademicPerf.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>

template <typename Ty>
int get_student_course_mark(Ty& group, std::string key, std::string course)
{
    try
    {
        AcademicPerformance *tmp = 
            static_cast<AcademicPerformance*>(group.FindRecord(key));
        return tmp->getMark(course);
    }
    catch (...) { return 0; }
}

template <typename Ty>
double get_student_medium_mark(Ty& group, std::string key)
{
    try
    {
        AcademicPerformance *tmp =
            static_cast<AcademicPerformance*>(group.FindRecord(key));
        return tmp->getAvgMark();
    }
    catch (...) { return 0; }
}

template <typename Ty>
int get_excellent_students_num(Ty& group)
{
    int count = 0;
    for (group.Reset(); !group.IsTabEnded(); group.GoNext())
        if (static_cast<AcademicPerformance*>(group.GetValuePTR())->
            getAvgMark() == 5)
            count++;

    return count;
}

template <typename Ty>
double get_group_medium_mark(Ty& group, std::string course)
{
    double avg = .0;

    for (group.Reset(); !group.IsTabEnded(); group.GoNext())
        avg += static_cast<AcademicPerformance*>(group.GetValuePTR())
        ->getMark(course);

    return (group.GetDataCount()) ? avg / group.GetDataCount() : .0;
}

template <typename Ty>
double GetMediumGroupMark(Ty& group)
{
    double avg = .0;

    for (group.Reset(); !group.IsTabEnded(); group.GoNext())
        avg += static_cast<AcademicPerformance*>(group.GetValuePTR())->
        getAvgMark();

        return (group.GetDataCount()) ? avg / group.GetDataCount() : .0;
}

template <typename T>
int get_excellent_num_among_all_groups(T& group) 
{ return get_excellent_students_num(group); }

template <typename T, typename... Ty>
int get_excellent_num_among_all_groups(T& group, Ty&... args)
{
    return get_excellent_students_num(group) + 
        get_excellent_num_among_all_groups(args...);
}


template <typename Ty>
void read(Ty& group, const char* fname)
{
    std::ifstream in(fname);
    if (in.is_open())
    {
        std::string courses;
        std::getline(in, courses);
        std::stringstream course_ss(courses);
        std::string course_buf;
        std::vector<std::string> course_tokens;
        
        while (course_ss >> course_buf)
            course_tokens.push_back(course_buf);

        while (!in.eof())
        {
            std::string cur_stud;
            std::getline(in, cur_stud);
            std::stringstream stud_ss(cur_stud);
            std::string stud_buf;
            std::vector<std::string> stud_tokens;

            while (stud_ss >> stud_buf)
                stud_tokens.push_back(stud_buf);

            AcademicPerformance *data = new AcademicPerformance();
            for (int i = 0; i < course_tokens.size(); ++i)
                data->addCourse(course_tokens[i], std::atoi(stud_tokens[i + 2].c_str()));

            group.InsRecord(stud_tokens[0] + " " + stud_tokens[1], data);
        }
        in.close();
    }
    else
        std::cerr << "File not found" << std::endl;
}

template <typename Ty>
void print(Ty& group, std::ostream& str = std::cout)
{
    group.Reset();
    static_cast<AcademicPerformance*>(group.GetValuePTR())->printCourses(str);
    for (group.Reset(); !group.IsTabEnded(); group.GoNext())
    {
        str << group.GetKey();
        static_cast<AcademicPerformance*>(group.GetValuePTR())->
            printMarks(group.GetKey(), str);
    }
    str << std::endl;
}

template <typename Ty>
double sum(Ty x) { return x; }

template <typename T, typename... Ty>
double sum(T x, Ty... args) { return x + sum(args...); }

template <typename... Ty>
double get_avg_mark_among_all_groups(Ty&... args)
{
    double res = sum(GetMediumGroupMark(args)...);
    return sizeof...(args) ? res / sizeof...(args) : .0;
}

template <typename... Ty>
double get_course_avg_mark_among_all_groups(std::string course, Ty&... args)
{
    double res = sum(get_group_medium_mark(args, course)...);
    return sizeof...(args) ? res / sizeof...(args) : .0;
}

#endif