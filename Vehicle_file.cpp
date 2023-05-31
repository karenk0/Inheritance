#include "Vehicle_file.h"

Vehicle::Vehicle() : Vehicle(Engine(), "No producer", "No model", 0, 0, 0, 0) {};
Vehicle::Vehicle(Engine engine_p, string producer_p, string model_p,
    int price_p, double weight_p, int max_speed_p,
    int produced_year_p) {
    set_engine(engine_p);
    set_producer(producer_p);
    set_model(model_p);
    set_price(price_p);
    set_weight(weight_p);
    set_max_speed(max_speed_p);
    set_produced_year(produced_year_p);
    cout << "Object of Vehicle type created\n";
}

Vehicle::~Vehicle() { cout << "Destructor for Vehicle class object runs\n"; }

void Vehicle::set_engine(Engine engine_p) {
    engine.set_engine_model(engine_p.get_engine_model());
    engine.set_engine_type(engine_p.get_engine_type());
    engine.set_power(engine_p.get_power());
    engine.set_produced_year(engine_p.get_produced_year());
};
Engine Vehicle::get_engine() const { return engine; };

void Vehicle::set_producer(string producer_p) { producer = producer_p; };
string Vehicle::get_producer() const { return producer; };

void Vehicle::set_model(string model_p) { model = model_p; };
string Vehicle::get_model() const { return model; };

void Vehicle::set_price(int price_p) { price = price_p; };
int Vehicle::get_price() const { return price; };

void Vehicle::set_weight(double weight_p) { weight = weight_p; };
double Vehicle::get_weight() const { return weight; };

void Vehicle::set_max_speed(int max_speed_p) { max_speed = max_speed_p; };
int Vehicle::get_max_speed() const { return max_speed; };

void Vehicle::set_produced_year(int produced_year_p) {
    produced_year = produced_year_p;
};
int Vehicle::get_produced_year() const { return produced_year; };

void Vehicle::start() { //---------------------------------
    cout << "Vehicle starts moveing!";
}
void Vehicle::stop() {
    cout << "Vehicle stops moveing!";
}
void Vehicle::accelerate(double tillVellocity) {
    velocity += tillVellocity;
    cout << "Speed is changed to " << tillVellocity << " km/h\n";
}
void Vehicle::run(double tillVellocity) {
    start();
    stop();
    accelerate(tillVellocity);
}

ostream& operator<<(ostream& output, const Vehicle& v) {
    output << "\nengine model: " << v.get_engine()
        << "\nproducer: " << v.get_producer() << "\nmodel: " << v.get_model()
        << "\nprice: " << v.get_price() << "\nweight: " << v.get_weight()
        << "\nmax_speed: " << v.get_max_speed()
        << "\nproduced year: " << v.get_produced_year();
    return output;
};

void Vehicle::draw() { 
    cout << *this;
}

istream& operator>>(istream& input, Vehicle& v) {
    Engine engine;
    cout << "\nInput engine:  ";
    input >> engine;
    v.set_engine(engine);
    string producer;
    cout << "\nInput roducer:    ";
    input >> producer;
    v.set_producer(producer);
    string model;
    cout << "\nInput model:   ";
    input >> model;
    v.set_model(model);
    int price;
    cout << "\nInput price:   ";
    input >> price;
    v.set_price(price);
    double weight;
    cout << "\nInput weight:  ";
    input >> weight;
    v.set_weight(weight);
    int max_speed;
    cout << "\nInput maximum speed:   ";
    input >> max_speed;
    v.set_max_speed(max_speed);
    int year;
    cout << "\nInput produced year:  ";
    input >> year;
    v.set_produced_year(year);
    return input;
}