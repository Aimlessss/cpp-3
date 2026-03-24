#include<bits/stdc++.h>
using namespace std;

enum class vehicleType {
    Bike,
    Car, 
    Truck
};

class Vehicle {

    private : 
        string vehicleNumber;
        vehicleType type;
    public : 
        Vehicle(string number, vehicleType type){
            this->type = type;
            this->vehicleNumber = number;
        }

        string getNumber(){
            return vehicleNumber;
        }
        vehicleType getType(){
            return type;
        }
};


class parkingSpot {
    private : 
        int id;
        string vehicleNumber;
        vehicleType type;
        bool occupied;
    public : 
        parkingSpot(int id, vehicleType type){
            this->id = id;
            this->type = type;
            this->vehicleNumber = "";

        };

        int getId(){
            return id;
        }
        vehicleType getType(){
            return type;
        }

        void park(string number){
            occupied = true;
            vehicleNumber = number;
        };

        void freeSpot(){
            occupied = true;
            vehicleNumber = "";
        }
};


class parkingLots{
    private : 
        vector<parkingSpot>spots;
        map<vehicleType,queue<parkingSpot*>>freeSpots;
        map<string, parkingSpot*>vehicleMap;
        map<string, Ticket>ticketMap;
    public : 
        parkingLots(int bikes, int cars, int trucks){
            int id = 1;

            for(int i = 0; i < bikes; i++){
                spots.emplace_back(id++, vehicleType::Bike);
                freeSpots[vehicleType::Bike].push(&spots.back());
            }

            for(int i = 0; i < cars; i++){
                spots.emplace_back(id++, vehicleType::Car);
                freeSpots[vehicleType::Car].push(&spots.back());
            }

            for(int i = 0; i < trucks; i++){
                spots.emplace_back(id++, vehicleType::Truck);
                freeSpots[vehicleType::Truck].push(&spots.back());
            }
        }

    bool parkVehicle(Vehicle& v) {

        vehicleType type = v.getType();

        if (freeSpots[type].empty()) {
            cout << "No spot available\n";
            return false;
        }

        parkingSpot* spot = freeSpots[type].front();
        freeSpots[type].pop();

        spot->park(v.getNumber());
        //ticket
        Ticket ticket(to_string(spot->getId()), v.getNumber());
        ticketMap[v.getNumber()] = ticket;

        vehicleMap[v.getNumber()] = spot;

        cout << "Vehicle " << v.getNumber()
             << " parked at spot " << spot->getId() << endl;

        return true;
    }

    void unparkVehical(Vehicle& v){
        if(vehicleMap.find(v.getNumber()) == vehicleMap.end()){
            cout<<"cant find"<<endl;
        }

        parkingSpot* spot = vehicleMap[v.getNumber()];
        spot->freeSpot();
        freeSpots[spot->getType()].push(spot);
            
        ticketMap.erase(v.getNumber());
        vehicleMap.erase(v.getNumber());
        cout<<"left"<<endl;
    }
};


class Ticket {
    private : 
        string spotId;
        string vehicleNumber;
        time_t entryTime;
    public : 
        Ticket(string spotId, string vehicleNumber){
            this->spotId = spotId;
            this->vehicleNumber = vehicleNumber;
            this->entryTime = time(0);
        }   
        string getSpotId(){
            return spotId;
        }
        string getVehicleNumber(){
            return vehicleNumber;
        }
        time_t getEntryTime(){
            return entryTime;
        }

};

int main(){

    parkingLots pq(2, 3, 4);
    Vehicle bike1("b1", vehicleType::Bike);
    Vehicle bike2("b2", vehicleType::Bike);

    Vehicle car3("c1", vehicleType::Car);

    pq.parkVehicle(bike1);
    pq.parkVehicle(bike2);
    pq.parkVehicle(car3);
    pq.unparkVehical(bike1);

}