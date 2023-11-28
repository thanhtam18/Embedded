/*
* File: room.cpp
* Author: Tam
* Date: 23/11/2023
* Description: 
*/
#ifndef _ROOM_H
#define _ROOM_H

#include <iostream>
#include <vector>

using namespace std;

class Room{
    private:
        int roomNumber;
        bool isBooked;
        bool isCleaning;
    public:
        Room(int iNumber);
        int getRoomNumber();
        bool isAvailable();
        bool isClean();
        void bookRoom();
        void checkIn();
        void checkOut();
};

class RoomsManager{
    private:
        vector<Room> databaseRooms;
    public:
        void addRoom();
        void displayAvailableRooms();
        void bookRoom(int iRoomNumber);
        void checkIn(int iRoomNumber);
        void checkOut(int iRoomNumber);
};

#endif