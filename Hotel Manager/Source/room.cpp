#include "room.hpp"

Room :: Room(int iNumber){
    roomNumber = iNumber;
    isBooked = false;
    isCleaning = false;
}

int Room :: getRoomNumber(){
    return roomNumber;
}

bool Room :: isAvailable(){
    return !isCleaning && isBooked;
}

bool Room :: isClean(){
    return isCleaning;
}

void Room :: bookRoom(){
    isBooked = true;
}

void Room :: checkIn(){
    isBooked = true;
    isCleaning = false;
}

void Room :: checkOut(){
    isBooked = false;
    isCleaning = true;
}

void RoomsManager :: displayAvailableRooms(){
    if(!databaseRooms.size()){
        cout<<"Room has not been created yet. Please create more rooms\r\n";
        return;
    }
    cout<<"Room Number\tStatus  \tClean"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(auto item : databaseRooms){
        cout<<"Room "<<item.getRoomNumber()
            <<"\t"<<((item.isAvailable()) ? "Booked  " : "Available")
            <<"\t"<<((item.isClean()) ? "Cleaned" : "Not Clean")<<"\r\n";
    }
}

void RoomsManager :: addRoom(){
    int l_iKey;
    do{
        cout<<"Enter room number: ";
        cin>>l_iKey;
        if(databaseRooms.size()){
            for(auto item : databaseRooms){
                if(item.getRoomNumber() == l_iKey){
                    cout<<"Add failed! Room number already exists"<<endl;
                    return;
                }
            }
        }
        Room room(l_iKey);
        databaseRooms.push_back(room);
        cout<<"Room added successfully"<<endl;
        do{
        cout<<"1. Add more room\r\n"
            <<"0. Return\r\n"
            <<"Your chose: ";
        cin>>l_iKey;
        }while(l_iKey != 0 && l_iKey != 1);
    }while(l_iKey != 0);
}

void RoomsManager :: bookRoom(int iNumber){
    for(int i = 0; i < databaseRooms.size(); i++){
        if(databaseRooms[i].getRoomNumber() == iNumber){
            if(!databaseRooms[i].isAvailable()){
                databaseRooms[i].bookRoom();
                cout<<"Book room successfully"<<endl;
                return;
            }
            else{
                cout<<"Book failed! Book is booked"<<endl;
                return;
            }
        }
    }
    cout<<"Book failed! Room do not exist"<<endl;
}

void RoomsManager :: checkIn(int iNumber){
    for(int i = 0; i < databaseRooms.size(); i++){
        if(databaseRooms[i].getRoomNumber() == iNumber){
            if(databaseRooms[i].isAvailable()){
                databaseRooms[i].checkIn();
                cout<<"Check in successfully"<<endl;
                return;
            }
            else{
                cout<<"Check in failed! Room has not been booked yet"<<endl;
                return;
            }
        }   
    }
    cout<<"Check in failed! Room do not exist"<<endl;
}

void RoomsManager :: checkOut(int iNumber){
    for(int i = 0; i < databaseRooms.size(); i++){
        if(databaseRooms[i].getRoomNumber() == iNumber){
            if(databaseRooms[i].isAvailable()){
                databaseRooms[i].checkOut();
                cout<<"Check out successfully"<<endl;
                return;
            }
            else{
                cout<<"Check out failed! Room has not been booked yet"<<endl;
                return;
            }
        }
    }
    cout<<"Check out failed! Room do not exist"<<endl;
}