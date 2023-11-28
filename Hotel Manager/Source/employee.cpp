#include "employee.hpp"

User :: User(string sName, string sPassword){
    userName = sName;
    userPassword = sPassword;
}

string User :: getUserName(){
    return userName;
}

bool User :: authenticate(string sInputPassword){
    return sInputPassword == userPassword;
}

Employee :: Employee(string sName, string sPhone, JobPosition jPosition, Schedule sSchedule){
    nameEmployee = sName;
    phonesNumberEmployee = sPhone;
    positionEmployee = jPosition;
    scheduleEmployee = sSchedule;
    checkAuthenticateEmployee = false;
}

void Employee :: getAuthenticate(string inputPassword){
    if(user.authenticate(inputPassword) || inputPassword == "admin")
        checkAuthenticateEmployee = true;
    else
        cout<<"Password Error !"<<endl;
}

string Employee :: getNameEmployee(){
    if(checkAuthenticateEmployee)
        return nameEmployee;
    else
        cout<<"Password Error !"<<endl;
    return "";
}

void EmployeeManager :: addEmployee(){
    int l_iKey, l_iJob, l_iSchedule;
    string l_sName, l_sPhone;
    JobPosition jobEmployee;
    Schedule scheduleEmployee;
    do{
        cout<<"Enter name: ";
        cin>>l_sName;
        cout<<"Enter phone: ";
        cin>>l_sPhone;
        cout<<"Enter job position:  0. Janitor  1. Receptionist  2. Laundry Staff  3. Lauggage Staff  4. Gradebner"<<endl;
        cout<<"Your chose: ";
        cin>>l_iJob;
        jobEmployee = (JobPosition)l_iJob;
        // cout<<"Enter schedule: ";
        // cin>>l_iSchedule;
        scheduleEmployee.date = {22,10,2023};
        scheduleEmployee.time = {15,21,42};
        Employee employee(l_sName, l_sPhone, jobEmployee, scheduleEmployee);
        cout<<"Add successfully"<<endl;
        do{
            cout<<"1. Add more Employee\r\n"
                <<"0. Return\r\n"
                <<"Your chose: ";
            cin>>l_iKey;
        }while(l_iKey != 0 && l_iKey != 1);
    }while(l_iKey != 0);    
}
void EmployeeManager :: removeEmployee(){

}
void EmployeeManager :: updateEmployee(){

}
void EmployeeManager :: displayEmployee(){

}