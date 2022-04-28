#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <ctime>
using namespace std;

class vehicle
{
private:
    int ID;         //id used for selection when making sale
    string model;   //vehicle model
    string color;   //vehicle color
    bool isNew;     //boolean value for new/used inventory
    int tier;       //upgradeable levels of vehicle (GT, GTS, RTS, Z21, etc..)
    time_t receiveDate;
    time_t onLotTime;
public:
    vehicle();
    vehicle(string model);
    vehicle(string model, string color);
    vehicle(string model, string color, bool isNew);
    vehicle(string model, string color, bool isNew, int tier);
    void setModel(string model);
    string getModel();
    void setColor(string color);
    string getColor();
    void setIsNew(bool isNew);
    bool getIsNew();
    void setTier(int tier);
    int getTier();
    void setReceiveDate(time_t recvd);
    time_t getReceiveDate();
    string toString();
    void setLotTime(time_t sold);
    //here we overload the equality and inequality operator
    bool operator == (const vehicle& v) const {return model == v.model && receiveDate == v.receiveDate; }
    bool operator != (const vehicle& v) const {return !operator==(v); }
};

#endif // VEHICLE_H
