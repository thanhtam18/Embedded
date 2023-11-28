#include <iostream>
#include "room.hpp"
#include "customer.hpp"
#include "employee.hpp"

using namespace std;

void roomHandler(RoomsManager &rManager){
    int l_iKey, l_iRoomNumber;
    do{
        cout<<"----Rooms----\r\n"
            <<"1. Display Rooms Status\r\n"
            <<"2. Add Room\r\n"
            <<"3. Book Room\r\n"
            <<"4. Check In\r\n"
            <<"5. Check Out\r\n"
            <<"0. Return\r\n"
            <<"Your chose: ";
        cin>>l_iKey;
            switch (l_iKey){
                case 0:
                    break;
                case 1:
                    rManager.displayAvailableRooms();
                    break;
                case 2:
                    rManager.addRoom();
                    break;
                case 3:
                    cout<<"Enter room number: ";
                    cin>>l_iRoomNumber;
                    rManager.bookRoom(l_iRoomNumber);
                    break;
                case 4:
                    cout<<"Enter room number: ";
                    cin>>l_iRoomNumber;
                    rManager.checkIn(l_iRoomNumber);
                    break;
                case 5:
                    cout<<"Enter room number: ";
                    cin>>l_iRoomNumber;
                    rManager.checkOut(l_iRoomNumber);
                    break;
                default:
                    cout<<"Your choice is invalid. Please try again.\r\n";
                break;
        }
    }while(l_iKey != 0);
}

void customerHandler(CustomersManager &cManager){
    int l_iKey;
    do{
        cout<<"----Customers----\r\n"
            <<"1. Display Customers\r\n"
            <<"2. Add Customers\r\n"
            <<"3. Add History of Customer\r\n"
            <<"4. Edit Customers\r\n"
            <<"5. Delete Customers\r\n"
            <<"0. Return\r\n"
            <<"Your chose: ";
        cin>>l_iKey;
            switch (l_iKey){
                case 0:
                    break;
                case 1:
                    cManager.displayCustomer();
                    break;
                case 2:
                    cManager.addCustomer();
                    break;
                case 3:
                    cManager.addHistory();
                    break;
                case 4:
                    cManager.editCustomer();
                    break;
                case 5:
                    cManager.deleteCustomer();
                    break;
                default:
                    cout<<"Your choice is invalid. Please try again.\r\n";
                break;
        }
    }while(l_iKey != 0);
}

void employeeHandler(EmployeeManager& eManager){
    int l_iKey;
    do{
        cout<<"----Employee----\r\n"
            <<"1. Display Employee\r\n"
            <<"2. Add Employee\r\n"
            <<"3. Update Employee\r\n"
            <<"4. Remove Employee\r\n"
            <<"0. Return\r\n"
            <<"Your chose: ";
        cin>>l_iKey;
            switch (l_iKey){
                case 0:
                    break;
                case 1:
                    eManager.displayEmployee();
                    break;
                case 2:
                    eManager.addEmployee();
                    break;
                case 3:
                    eManager.updateEmployee();
                    break;
                case 4:
                    eManager.removeEmployee();
                    break;
                default:
                    cout<<"Your choice is invalid. Please try again.\r\n";
                break;
        }
    }while(l_iKey != 0);    
}

int main()
{
    int l_iKey;
    RoomsManager roomsManager;
    CustomersManager customerManager;
    EmployeeManager employeeManager;
    do{
        cout<<"----Managerment System----\r\n"
            <<"1. Rooms\r\n"
            <<"2. Customers\r\n"
            <<"3. Employees\r\n"
            <<"0. Exit\r\n"
            <<"Your chose: ";
        cin>>l_iKey;
        switch (l_iKey){
            case 0:
                break;
            case 1:
                roomHandler(roomsManager);
                break;
            case 2:
                customerHandler(customerManager);
                break;
            case 3:
                employeeHandler(employeeManager);
                break;
            default:
                cout<<"Your choice is invalid. Please try again.\r\n";
                break;
        }
    }while(l_iKey != 0); 
    return 0;
}
