#ifndef VEHICLE_H
#define VEHICLE_H

#include "Engine.h"
#include <iostream>
using namespace std;

class Vehicle {
	friend ostream& operator<<(ostream&, const Vehicle&);
	friend istream& operator>>(istream&, Vehicle&);

public:
	Vehicle();
	Vehicle(Engine, string, string, int, double, int, int);
	~Vehicle();

	void set_engine(Engine);
	Engine get_engine() const;

	void set_producer(string);
	string get_producer() const;

	void set_model(string);
	string get_model() const;

	void set_price(int);
	int get_price() const;

	void set_weight(double);
	double get_weight() const;

	void set_max_speed(int);
	int get_max_speed() const;

	void set_produced_year(int);
	int get_produced_year() const;

	virtual void draw();

private:		//-----------------------
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void accelerate(double) = 0;
public:
	void run(double);

protected:
	Engine engine;
	string producer;
	string model;
	int price;
	double weight;
	int max_speed;
	int produced_year;
	int velocity;//-----------------------
	int maxVelocity;
	bool isRunning;
};
#endif VEHICLE_H