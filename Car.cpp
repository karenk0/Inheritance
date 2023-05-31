#include "Car.h"
#include <iostream>
using namespace std;
using namespace std;

Car::Car() : Vehicle(), seats{ 0 } {
    cout << "\nDefault constructor for car type object runs:\n";
}
Car::Car(Engine engine_p, string producer_p, string model_p, int price_p,
    double weight_p, int max_speed_p, int produced_year_p, int seats_p)
    : Vehicle(engine_p, producer_p, model_p, price_p, weight_p, max_speed_p,
        produced_year_p),
    seats{ seats_p } {
    cout << "Constructor for Car type runs:\n";
}
Car::~Car() { cout << "Destructor for car type object runs:\n"; }

void Car::set_seats(int seats_count) { seats = seats_count; };
int Car::get_seats() const { return seats; };

ostream& operator<<(ostream& output, const Car& c) {  
    cout << static_cast<const Vehicle&>(c)
        << "\nseats count: " << c.get_seats() << endl;
    return output;
};

void Car::draw() {
    cout << *this;
}

void Car::start() { //---------------------------------
    cout << "Car starts moveing!";
}
void Car::stop() {
    cout << "Car stops moveing!";
}
void Car::accelerate(double tillVellocity) {
    velocity += tillVellocity;
    cout << "Car speed is changed to " << tillVellocity << " km/h\n";
}


istream& operator>>(istream& input, Car& c) {
    Engine engine;
    cout << "\nInput engine:  ";
    input >> engine;
    c.set_engine(engine);

    string producer;
    cout << "\nInput roducer:    ";
    input >> producer;
    c.set_producer(producer);

    string model;
    cout << "\nInput model:   ";
    input >> model;
    c.set_model(model);

    int price;
    cout << "\nInput price:   ";
    input >> price;
    c.set_price(price);

    double weight;
    cout << "\nInput weight:  ";
    input >> weight;
    c.set_weight(weight);

    int max_speed;
    cout << "\nInput maximum speed:   ";
    input >> max_speed;
    c.set_max_speed(max_speed);

    int year;
    cout << "\nInput produced year:  ";
    input >> year;
    c.set_produced_year(year);

    int seats_;
    cout << "\nInput capacity:    ";
    input >> seats_;
    c.set_seats(seats_);

    return input;
}
