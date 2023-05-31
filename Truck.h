#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle_file.h"

class Truck : public Vehicle {

    friend ostream& operator<<(ostream&, const Truck&);
    friend istream& operator>>(istream&, Truck&);

public:
    Truck();
    Truck(Engine, string, string, int, double, int, int,
        float); // last int parameter is for capacity
    ~Truck();

    void set_capacity(float);
    float get_capacity() const;
    float get_currentLoad() const;
    void set_currentLoad(float);
    virtual void draw() override;
    virtual void start() override;//-----------------------
    virtual void stop() override;
    virtual void accelerate(double) override;

protected:
    float capacity;
private:
    float currentLoad;//-----------------
};

#endif TRUCK_H
