//
// Created by NOAH on 2020/4/23.
//

#ifndef PRACTICE_4_3_GLOBALWRAPPER_H
#define PRACTICE_4_3_GLOBALWRAPPER_H


#include <string>

using namespace std;

class globalWrapper {
public:
    static int tests_passed() { return _tests_passed; }

    static int tests_run() { return _tests_run; }

    static int version_number() { return _version_number; }

    static string version_stamp() { return _version_stamp; }

    static string program_name() { return _program_name; }

    static void tests_passed(int nval) { _tests_passed = nval; }

    static void tests_run(int nval) { _tests_run = nval; }

    static void version_number(int nval) { _version_number = nval; }

    static void version_stamp(int nval) { _version_stamp = nval; }

    static void program_name(int nval) { _program_name = nval; }


private:
    static string _program_name;
    static string _version_stamp;
    static int _version_number;
    static int _tests_run;
    static int _tests_passed;
};


#endif //PRACTICE_4_3_GLOBALWRAPPER_H
