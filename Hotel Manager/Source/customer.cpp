#include "customer.hpp"

Customer :: Customer (string sName, string sPhone, string sAddress, int iRoom){
    nameCustomer = sName;
    phonesNumberCustomer = sPhone;
    addressCustomer = sAddress;
    idRoom = iRoom;
}
string Customer :: getName(){
    return nameCustomer;
}
string Customer :: getPhone(){
    return phonesNumberCustomer;
}
string Customer :: getAddress(){
    return addressCustomer;
}
int Customer :: getIdRoom(){
    return idRoom;
}
void Customer :: setName(string sName){
    nameCustomer = sName;
}
void Customer :: setPhone(string sPhone){
    phonesNumberCustomer = sPhone;
}
void Customer :: setAddress(string sAddress){
    addressCustomer = sAddress;
}

void Customer :: addBookingHistory(BookingHistory bBookingDetails){
    databaseHistory.push_back(bBookingDetails);
}
void Customer :: displayBookingHistory(){
    cout<<"Date\t\tTime\t\tStatus"<<endl;
    for(auto item : databaseHistory){
        cout<<item.date.day<<"/"<<item.date.month<<"/"<<item.date.year;
        cout<<"\t"<<item.time.hour<<":"<<item.time.min<<":"<<item.time.sec;
        cout<<"\t"<<((item.status == IN) ? "Check in" : "Check out")<<endl;
    }
}

void CustomersManager :: addCustomer(){
    int l_iKey, l_iRoom;
    string l_sName, l_sPhone, l_sAddress;
    do{
        cout<<"Enter room number of customer: ";
        cin>>l_iRoom;
        if(databaseCustomer.size()){
            for(auto item : databaseCustomer){
                if(item.getIdRoom() == l_iRoom){
                    cout<<"Add failed! This room is occupied. Please chose other room\r\n";
                    return;
                }
            }
        }
        cout<<"Enter name of customer: ";
        cin>>l_sName;
        cout<<"Enter phone of customer: ";
        cin>>l_sPhone;
        cout<<"Enter address of customer: ";
        cin.ignore();
        getline(cin, l_sAddress);
        Customer customer(l_sName, l_sPhone, l_sAddress, l_iRoom);
        databaseCustomer.push_back(customer);
        cout<<"Add successfully"<<endl;
        do{
            cout<<"1. Add more customer\r\n"
                <<"0. Return\r\n"
                <<"Your chose: ";
            cin>>l_iKey;
        }while(l_iKey != 0 && l_iKey != 1);
    }while(l_iKey != 0);
}
void CustomersManager :: addHistory(){
    BookingHistory history;
    int l_istatus, l_iRoom;
    cout<<"Enter ID Room of Customer: ";
    cin>>l_iRoom;
    for(int i = 0; i < databaseCustomer.size(); i++){
        if(databaseCustomer[i].getIdRoom() == l_iRoom){
            cout<<"Enter Day: ";
            cin>>history.date.day;
            cout<<"Enter Month: ";
            cin>>history.date.month;
            cout<<"Enter Year: ";
            cin>>history.date.year;
            cout<<"Enter Hour: ";
            cin>>history.time.hour;
            cout<<"Enter Minute: ";
            cin>>history.time.min;
            cout<<"Enter Second: ";
            cin>>history.time.sec;
            cout<<"Tatus:   0. Check In   1. Check Out\r\n"<<"Your chose: ";
            cin>>l_istatus;
            history.status = (TypeStatus)l_istatus;
            databaseCustomer[i].addBookingHistory(history);
            cout<<"Add history successfully"<<endl;
            return;
        }
    }
    cout<<"Add failed! ID Room do not exist"<<endl;
}
void CustomersManager :: editCustomer(){
    int l_iKey, l_iRoom;
    if(!databaseCustomer.size()){
        cout <<"List customer is emty. Please add more customer"<<endl;
        return;
    }
    cout <<"--------------List of Customers----------------"<<endl;
    cout <<"Room\tName\tPhone   \tAddress"<<endl;
    for (auto customer : databaseCustomer) {
        cout<<customer.getIdRoom()
            <<"\t"<<customer.getName()
            <<"\t"<<customer.getPhone()
            <<"\t"<<customer.getAddress()<<endl;
    }
    cout <<"-----------------------------------------------"<< endl;
    do{
        cout<<"1. Edit Customer\r\n"
            <<"0. Return\r\n"
            <<"Your chose: ";
        cin>>l_iKey;
        if(l_iKey){
            cout<<"Enter ID Room of Customer: ";
            cin>>l_iRoom;
            for(int i = 0; i < databaseCustomer.size(); i++){
                if(databaseCustomer[i].getIdRoom() == l_iRoom){
                    string l_sName, l_sPhone, l_sAddress;
                    cout<<"Enter new name: ";
                    cin>>l_sName;
                    cout<<"Enter new phone number: ";
                    cin>>l_sPhone;
                    cout<<"Enter new address: ";
                    cin>>l_sAddress;
                    databaseCustomer[i].setName(l_sName);
                    databaseCustomer[i].setPhone(l_sPhone);
                    databaseCustomer[i].setAddress(l_sAddress);
                    cout<<"Edit customer successfully"<<endl;
                    return;
                }
            }
            cout<<"Failed! ID Room do not exist"<<endl;
        }
    }while(l_iKey != 0 && l_iKey != 1);
}
void CustomersManager :: deleteCustomer(){
    int l_iKey, l_iRoom;
    if(!databaseCustomer.size()){
        cout <<"List customer is emty. Please add more customer"<<endl;
        return;
    }
    cout <<"--------------List of Customers----------------"<<endl;
    cout <<"Room\tName\tPhone   \tAddress"<<endl;
    for (auto customer : databaseCustomer) {
        cout<<customer.getIdRoom()
            <<"\t"<<customer.getName()
            <<"\t"<<customer.getPhone()
            <<"\t"<<customer.getAddress()<<endl;
    }
    cout <<"-----------------------------------------------"<< endl;
    do{
        cout<<"1. Delete Customer\r\n"
            <<"0. Return\r\n"
            <<"Your chose: ";
        cin>>l_iKey;
        if(l_iKey){
            cout<<"Enter ID Room of Customer: ";
            cin>>l_iRoom;
            for(int i = 0; i < databaseCustomer.size(); i++){
                if(databaseCustomer[i].getIdRoom() == l_iRoom){
                    databaseCustomer.erase(databaseCustomer.begin()+i);
                    cout<<"Delete customer successfully"<<endl;
                    return;
                }
            }
            cout<<"Failed! ID Room do not exist"<<endl;
        }
    }while(l_iKey != 0 && l_iKey != 1);
}
void CustomersManager :: displayCustomer(){
    int l_iKey, l_iRoom;
    if(!databaseCustomer.size()){
        cout <<"List customer is emty. Please add more customer"<<endl;
        return;
    }
    cout <<"--------------List of Customers----------------"<<endl;
    cout <<"Room\tName\tPhone   \tAddress"<<endl;
    for (auto customer : databaseCustomer) {
        cout<<customer.getIdRoom()
            <<"\t"<<customer.getName()
            <<"\t"<<customer.getPhone()
            <<"\t"<<customer.getAddress()<<endl;
    }
    cout <<"-----------------------------------------------"<< endl;
    do{
        cout<<"1. Display History\r\n"
            <<"0. Return\r\n"
            <<"Your chose: ";
        cin>>l_iKey;
        if(l_iKey){
            cout<<"Enter ID Room of Customer: ";
            cin>>l_iRoom;
            for(int i = 0; i < databaseCustomer.size(); i++){
                if(databaseCustomer[i].getIdRoom() == l_iRoom){
                    databaseCustomer[i].displayBookingHistory();
                    return;
                }
            }
            cout<<"Failed! ID Room do not exist"<<endl;
        }
    }while(l_iKey != 0 && l_iKey != 1);
}
