#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct{
    int sec;
    int min;
    int hour;
}TypeTime;

typedef struct{
    int day;
    int month;
    int year;
}TypeDate;

typedef enum{
    IN,
    OUT
}TypeStatus;

typedef struct{
    TypeDate date;
    TypeTime time;
    TypeStatus status;
}BookingHistory;

class Customer{
    private:
        vector<BookingHistory> databaseHistory;
        string nameCustomer;
        string phonesNumberCustomer;
        string addressCustomer;
        int idRoom;
    public:
        Customer(string sName, string sPhone, string sAddress, int iRoom);
        string getName();
        string getPhone();
        string getAddress();
        int getIdRoom();
        
        void setName(string sName);
        void setPhone(string sPhone);
        void setAddress(string sAddress);
        
        void addBookingHistory(BookingHistory bBookingDetails);
        void displayBookingHistory();
};

class CustomersManager{
    private:
        vector<Customer> databaseCustomer;
    public:
        void addCustomer();
        void addHistory();
        void editCustomer();
        void deleteCustomer();
        void displayCustomer();
};
#endif