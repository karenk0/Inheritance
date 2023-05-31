#ifndef CAR_H
#define CAR_H

#include "Engine.h"
#include "Vehicle_file.h"
using namespace std;

class Car : public Vehicle {

    friend ostream& operator<<(ostream&, const Car&);
    friend istream& operator>>(istream&, Car&);

public:
    Car();
    Car(Engine, string, string, int, double, int, int,
        int); // last int parameter is for seats
    ~Car();

    void set_seats(int);
    int get_seats() const;
    virtual void draw() override;//----------------------
    virtual void start() override;
    virtual void stop() override;
    virtual void accelerate(double) override;
protected:
    int seats;
};

#endif CAR_H
