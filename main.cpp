#include "Car.h"
#include "Engine.h"
#include "Truck.h"
#include "Vehicle_file.h"
#include <iostream>
#include <array>
using namespace std;

int main() {

	/*
	Truck truck1;
	cout << "Input truck1 objects parameters:\n";
	cin >> truck1;
	cout << truck1;
	*/

	/*
	Engine truck_engine1("Four-stroke engine", 2020, 2, diesel);
	Truck truck1(truck_engine1, "Honda", "Pilot", 150000, 2, 250, 2021, 6);

	Engine engine1("Four-stroke engine", 2020, 2, diesel);
	//cout << engine1;
	Car car1(engine1, "Honda", "Accord", 20000, 2, 250, 2021, 4);
	//cout << car1;
	

	Engine engine2("Petrol engine", 2018, 2, diesel);
	Car car2(engine2, "Tesla", "Model Y", 40000, 1.6, 290, 2022, 4);

	Engine engine3("Rotary engine", 2000, 2,  diesel);
	Car car3(engine3, "Audi", "A5 Cabriolet", 70000, 1.9, 310, 2023, 2);

	Engine engine4("Flat engine", 1998, 2, diesel);
	Car car4(engine4, "Cadillac", "Escalade", 150000, 3.5, 280, 2023, 6);
	*/

	/*
	Car* temp;
	array<Car*, 4> cars{&car1, &car2, &car3, &car4};
	//ARRAY, TO PRINT CARS FROM MOST POWERFULL TO LEAST,WHICH HAS NO MORE THAN 5 SEATS
	int k;
	for (size_t i{ 0 }; i < cars.size() - 1; ++i) {
		temp = cars[i];
		k = i;
		for (size_t j{ 0 }; j < cars.size() - i - 1; ++j) {
			if (cars[i]->get_engine().get_power() > temp->get_engine().get_power()) {
				temp = cars[i];
				k = i;
			}
		}
		cars[k] = cars[i];
		cars[i] = temp;
	}


	for (size_t i{ 0 }; i < cars.size() - 1; ++i) {
		if (cars[i]->get_seats() <= 5) {
			cout << "Object " << (i + 1) << "-----------" << endl << *cars[i] << endl;
		}
	}
	*/

	/*
	array<Vehicle*, 5> vehicles{&truck1, &car1, &car2, &car3, &car4 };
	for (size_t j{ 0 }; j < vehicles.size(); ++j) {
		cout << "Object " << j;
		cout << "------------------" << endl;
		vehicles[j]->draw();
		cout << "------------------" << endl;
	}
	*/

	Engine truck_engine1("Four-stroke engine", 2020, 2, diesel);
	Truck *truck1 = new Truck(truck_engine1, "Honda", "Pilot", 150000, 2, 250, 2021, 6);
	truck1->set_currentLoad(15000);

	Engine engine1("Four-stroke engine", 2020, 2, diesel);
	Car *car1 = new Car(engine1, "Honda", "Accord", 20000, 2, 250, 2021, 4);
	

	Engine engine2("Petrol engine", 2018, 2, diesel);
	Car *car2 = new Car(engine2, "Tesla", "Model Y", 40000, 1.6, 290, 2022, 4);

	Engine engine3("Rotary engine", 2000, 2,  diesel);
	Car *car3 = new Car(engine3, "Audi", "A5 Cabriolet", 70000, 1.9, 310, 2023, 2);

	Engine engine4("Flat engine", 1998, 2, diesel);
	Car *car4 = new Car(engine4, "Cadillac", "Escalade", 150000, 3.5, 280, 2023, 6);
	array<Vehicle*, 5> vehicles{ truck1, car1, car2, car3, car4 };
	for (size_t j{ 0 }; j < vehicles.size(); ++j) {
		cout << "Object " << j;
		cout << "------------------" << endl;
		vehicles[j]->draw();
		vehicles[j]->run(50);
		cout << "------------------" << endl;
	}

	for (size_t j{ 0 }; j < vehicles.size(); ++j) {
		cout << "Object " << j;
		cout << "##############\n" << endl;
		const type_info& tip = typeid(vehicles[j]);
		cout << "Object of " << tip.name() << "  is deleted:\n";
		delete vehicles[j];
		cout << "##############\n" << endl;
	}

}