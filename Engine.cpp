#include "Engine.h"
using namespace std;

Engine::Engine() : Engine("No model", 0, 0, none) {}
Engine::Engine(string model, int year, int power_value, Engine_type type) {
    set_engine_model(model);
    set_produced_year(year);
    set_power(power_value);
    set_engine_type(type);
    cout << "\nObject of Engine class created\n";
}
Engine::~Engine() { cout << "\nDestructor for Engine class object runs\n"; }

void Engine::set_engine_model(string model) { engine_model = model; };
string Engine::get_engine_model() const { return engine_model; };

void Engine::set_produced_year(int year) { produced_year = year; };
int Engine::get_produced_year() const { return produced_year; };

void Engine::set_power(double power_value) { power = power_value; };
double Engine::get_power() const { return power; };

void Engine::set_engine_type(Engine_type type) { engine_type = type; };
Engine_type Engine::get_engine_type() const { return engine_type; };

ostream& operator<<(ostream& output, const Engine& e) {
    output << "\nengine model: " << e.get_engine_model()
        << "\nproduced year: " << e.get_produced_year()
        << "\npower: " << e.get_power()
        << "\nengine type: " << e.get_engine_type() << endl;
    return output;
};

istream& operator>>(istream& input, Engine& e) {
    cout << "\nInput Engine Parameters:\n";
    string model_name;
    cout << "\nInput model name:    ";
    input >> model_name;
    e.set_engine_model(model_name);
    int year;
    cout << "\nInput engine year:   ";
    input >> year;
    e.set_produced_year(year);
    int power;
    cout << "\nInput rngine power:  ";
    input >> power;
    e.set_power(power);

    int type_t;
    cout << "\nInput engine model (0 - diesel, 1 - petrol, 2 - gas, 3 - "
        "electric):  ";
    input >> type_t;
    switch (type_t) {
    case 0:
        e.set_engine_type(diesel);
        break;
    case 1:
        e.set_engine_type(petrol);
        break;
    case 2:
        e.set_engine_type(gas);
        break;
    case 3:
        e.set_engine_type(electric);
        break;
    default:
        e.set_engine_type(none);
    }
    return input;
};
