#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <iostream>
#include <vector>
#include <string>
#include "customer.hpp"

using namespace std;

typedef enum{
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LAUGGAGE_STAFF,
    GRADENER
}JobPosition;

typedef struct{
     TypeDate date;
     TypeTime time;
}Schedule;

class User{
    private:
        string userName;
        string userPassword;
    public:
        User(string sName ="", string sPassword ="");
        string getUserName();
        bool authenticate(string sInputPassword);
};

class Employee{
    private:
        int idEmployee;
        string nameEmployee;
        string phonesNumberEmployee;
        JobPosition positionEmployee;
        Schedule scheduleEmployee;
        bool checkAuthenticateEmployee;
        User user;
    public:
        Employee(string sName, string sPhone, JobPosition jPostion, Schedule sSchedule);
        void getAuthenticate(string sInputPassword);
        int getIdEmployee();
        string getNameEmployee();
        string getPhoneEmployee();
        JobPosition getPositonEmployee();
        Schedule getScheduleEmployee();
};     

class EmployeeManager{
    private:
        vector<Employee> databaseEmployees;
    public:
        void addEmployee();
        void removeEmployee();
        void updateEmployee();
        void displayEmployee();
};

#endif