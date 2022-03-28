#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
using namespace std;

class vehicle
{
private:
    string model;   //vehicle model
    string color;   //vehicle color
    bool isNew;     //boolean value for new/used inventory
    int tier;       //upgradeable levels of vehicle (GT, GTS, RTS, Z21, etc..)

public:
    vehicle();
    vehicle(string model);
    vehicle(string model, string color);
    vehicle(string model, string color, bool isNew);
    vehicle(string model, string color, bool isNew, int tier);
    virtual ~vehicle();
    void setModel(string model);
    string getModel();
    void setColor(string color);
    string getColor();
    void setIsNew(bool isNew);
    bool getIsNew();
    void setTier(int tier);
    int getTier();
};

#endif // VEHICLE_H