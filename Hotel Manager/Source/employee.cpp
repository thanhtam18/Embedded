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
void Employee :: setNameEmployee(string sName){
    nameEmployee = sName;
}
void Employee :: setPhoneEmployee(string sPhone){
    phonesNumberEmployee = sPhone;
}
void Employee :: setPositionEmployee(JobPosition position){
    positionEmployee = position;
}
void Employee :: setScheduleEmployee(Schedule schedule){
    scheduleEmployee = schedule;
}
void EmployeeManager :: displayEmployee(){
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

void EmployeeManager :: addEmployee(){
    int l_iKey, l_iJob, l_iDay, l_iMonth, l_iYear, l_iHour, l_iMin, l_iSec;
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
    if(!databaseEmployees.size()){
        cout <<"List employees are emty. Please add more employee"<<endl;
        return;
    }
    displayEmployee();
    int l_iId,l_iKey;
    do{
        cout<<"1. Remove Employee\r\n"
            <<"0. Return\r\n"
            <<"Your chose: ";
        cin>>l_iKey;
        if(l_iKey){
            cout<<"Enter ID of Employee: ";
            cin>>l_iId;
            for(int i = 0; i < databaseEmployees.size(); i++){
                if(databaseEmployees[i].getIdEmployee() == l_iId){
                    databaseEmployees.erase(databaseEmployees.begin()+i);
                    cout<<"Romve Employee successfully"<<endl;
                    return;
                }
            }
            cout<<"Failed! ID Employee do not exist"<<endl;
        }
    }while(l_iKey != 0 && l_iKey != 1);
}
void EmployeeManager :: updateEmployee(){
    if(!databaseEmployees.size()){
        cout <<"List employees are emty. Please add more employee"<<endl;
        return;
    }
    displayEmployee();
    int l_iId,l_iKey;
    do{
        cout<<"1. Edit Employee\r\n"
            <<"0. Return\r\n"
            <<"Your chose: ";
        cin>>l_iKey;
        if(l_iKey){
            cout<<"Enter ID of Employee: ";
            cin>>l_iId;
            for(int i = 0; i < databaseEmployees.size(); i++){
                if(databaseEmployees[i].getIdEmployee() == l_iId){
                    string l_sName, l_sPhone;
                    int l_iJob, l_iDay, l_iMonth, l_iYear, l_iHour, l_iMin, l_iSec;
                    JobPosition jobEmployee;
                    Schedule scheduleEmployee;
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
                    databaseEmployees[i].setNameEmployee(l_sName); 
                    databaseEmployees[i].setPhoneEmployee(l_sPhone);
                    databaseEmployees[i].setPositionEmployee(jobEmployee); 
                    databaseEmployees[i].setScheduleEmployee(scheduleEmployee); 
                    cout<<"Edit Employee successfully"<<endl;
                    return;
                }
            }
            cout<<"Failed! ID Employee do not exist"<<endl;
        }
    }while(l_iKey != 0 && l_iKey != 1);
}

