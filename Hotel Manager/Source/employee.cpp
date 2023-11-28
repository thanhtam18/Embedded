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
    static int index = 100;
    idEmployee = index;
    index++;
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
int Employee :: getIdEmployee(){
    return idEmployee;
}
string Employee :: getNameEmployee(){
   // if(checkAuthenticateEmployee)
        return nameEmployee;
    // else
    //     cout<<"Password Error !"<<endl;
    // return "";
}
string Employee :: getPhoneEmployee(){
    return phonesNumberEmployee;
}
JobPosition Employee :: getPositonEmployee(){
    return positionEmployee;
}
Schedule Employee :: getScheduleEmployee(){
    return scheduleEmployee;
}
void EmployeeManager :: addEmployee(){
    int l_iKey, l_iJob, l_iSchedule, l_iDay, l_iMonth, l_iYear, l_iHour, l_iMin, l_iSec;
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
        cout<<"Enter Day/Month/Year: ";
        cin>>l_iDay>>l_iMonth>>l_iYear;
        cout<<"Enter Hour:Minute:Second: ";
        cin>>l_iHour>>l_iMin>>l_iSec;
        scheduleEmployee.date = {l_iDay,l_iMonth,l_iYear};
        scheduleEmployee.time = {l_iHour,l_iMin,l_iSec};
        Employee employee(l_sName, l_sPhone, jobEmployee, scheduleEmployee);
        databaseEmployees.push_back(employee);
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
    int l_iKey, l_iRoom;
    if(!databaseEmployees.size()){
        cout <<"List employees are emty. Please add more employee"<<endl;
        return;
    }
    cout <<"-------------------------List of Employees--------------------------"<<endl;
    cout <<"Id\tName\tPhone   \tPosition\tSchedule"<<endl;
    for (auto employee : databaseEmployees) {
        cout<<employee.getIdEmployee()
            <<"\t"<<employee.getNameEmployee()
            <<"\t"<<employee.getPhoneEmployee()<<"\t";
            switch (employee.getPositonEmployee()){
                case JANITOR:
                    cout<<"Janitor";
                    break;
                case RECEPTIONIST:
                    cout<<"Receptionist";
                    break;
                case LAUNDRY_STAFF:
                    cout<<"Laundry Staff";
                    break;
                case LAUGGAGE_STAFF:
                    cout<<"Lauggage Staff";
                    break;
                case GRADENER:
                    cout<<"Gradebner";
                    break;
            }
            Schedule scheduleEmployee = employee.getScheduleEmployee();
            cout<<"\t"<<scheduleEmployee.date.day<<"/"<<scheduleEmployee.date.month<<"/"<<scheduleEmployee.date.year;
            cout<<"     "<<scheduleEmployee.time.hour<<":"<<scheduleEmployee.time.min<<":"<<scheduleEmployee.time.sec;
    }
    cout <<"\r\n---------------------------------------------------------------"<<endl;
}