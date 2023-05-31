#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
#include <string>
using namespace std;

enum Engine_type { diesel, petrol, gas, electric, none };

class Engine {
	friend ostream& operator<<(ostream&, const Engine&);
	friend istream& operator>>(istream&, Engine&);

public:
	Engine();
	Engine(string, int, int, Engine_type);
	~Engine();

	void set_engine_model(string);
	string get_engine_model() const;

	void set_produced_year(int);
	int get_produced_year() const;

	void set_power(double);
	double get_power() const;

	void set_engine_type(Engine_type);
	Engine_type get_engine_type() const;

private:
	string engine_model;
	int produced_year;
	double power;
	Engine_type engine_type;
};

#endif ENGINE_H
