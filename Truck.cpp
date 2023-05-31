#include "Truck.h"
#include <iostream>
using namespace std;

Truck::Truck() : Vehicle(), capacity{ 0 } {
    cout << "Default constructor for truck type object runs:";
}
Truck::Truck(Engine engine_p, const string producer_p, const string model_p,
    int price_p, double weight_p, int max_speed_p, int produced_year_p,
    float capacity_p)
    : Vehicle(engine_p, producer_p, model_p, price_p, weight_p, max_speed_p,
        produced_year_p),
    capacity{ capacity_p } {
    cout << "Constructor for truck object runs:";
}
Truck::~Truck() { cout << "Destructor for truck object runs:"; };

void Truck::set_capacity(float capacity_p) { capacity = capacity_p; };
float Truck::get_capacity() const { return capacity; };

void Truck::start() { //---------------------------------
    if (get_currentLoad() <= 10000) {
        cout << "Truck starts moveing with " << currentLoad << " kg\n";
    }
    else {
        cout << "Too much Loaded, cant start moveing:\n";
    }
}
void Truck::stop() {
    if (get_currentLoad() <= 10000) {
        cout << "Truck stops moveing!\n";
    }
    else {
        cout << "Truck doesnt move\n";
    }
}
void Truck::accelerate(double tillVellocity) {
    if (get_currentLoad() <= 10000) {
        velocity += tillVellocity;
        cout << "Truck speed is changed to " << tillVellocity << " km/h\n";
    }
    else {
        cout << "Truck doesnt move, cant change speed:\n";
    }
}
float Truck::get_currentLoad() const {
    return currentLoad;
}
void Truck::set_currentLoad(float load) {
    currentLoad = load;
}

ostream& operator<<(ostream& output, const Truck& c) {
    cout << static_cast<const Vehicle&>(c) //we've used the base class cout
        << "\nseats count: " << c.get_capacity() << endl;
    return output;
};


void Truck::draw() {
    cout << *this;
}


istream& operator>>(istream& input, Truck& t) {

    Engine engine;
    cout << "Input engine:  ";
    input >> engine;
    t.set_engine(engine);

    string model;
    cout << "Input model:   ";
    input >> model;
    t.set_model(model);

    string producer;
    cout << "Input producer:    ";
    input >> producer;
    t.set_producer(producer);

    int price;
    cout << "Input price:   ";
    input >> price;
    t.set_price(price);

    double weight;
    cout << "Input weight:  ";
    input >> weight;
    t.set_weight(weight);

    int max_speed;
    cout << "Input maximum speed:   ";
    input >> max_speed;
    t.set_max_speed(max_speed);

    int year;
    cout << "Input produced year:  ";
    input >> year;
    t.set_produced_year(year);

    float capacity_;
    cout << "Input capacity:    ";
    input >> capacity_;
    t.set_capacity(capacity_);

    return input;
}