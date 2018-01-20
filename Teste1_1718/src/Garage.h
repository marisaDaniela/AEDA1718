/*
 * Garage.h
 *
 *  Created on: 24/10/2017
 *      Author: hlc
 */

#ifndef SRC_GARAGE_H_
#define SRC_GARAGE_H_

#include <vector>

template <class Vehicle>
class Garage {
	std::vector<Vehicle *> vehicles;
	const unsigned int capacity;
public:
	Garage(int size);
	~Garage();
	std::vector<Vehicle *> getVehicles() const;
	void setVehicles(std::vector<Vehicle *> vehicles);
	int getCapacity() const;
	bool addVehicle(Vehicle *vehicle);
	Vehicle* removeVehicle(std::string brand, std::string model);
	float avgPrice(std::string brand) const;
	void sortVehicles();
};

class NoSuchVehicleException {
public:
	NoSuchVehicleException() { }
};

template <class Vehicle>
Garage<Vehicle>::Garage(int size) : capacity(size) {
}

template <class Vehicle>
Garage<Vehicle>::~Garage() {
	typename std::vector<Vehicle *>::const_iterator it;
	for (it=vehicles.begin(); it!=vehicles.end(); it++) {
		delete *it;
	}
}

template<class Vehicle>
std::vector<Vehicle *> Garage<Vehicle>::getVehicles() const {
	return vehicles;
}

template<class Vehicle>
void Garage<Vehicle>::setVehicles(std::vector<Vehicle*> vehicles) {
	this->vehicles = vehicles;
}

template<class Vehicle>
int Garage<Vehicle>::getCapacity() const {
	return capacity;
}

//////////RESOLUCAO //////////////

////
//d)
template<class Vehicle>
bool Garage<Vehicle>::addVehicle(Vehicle *vehicle)
{
	if(capacity > 0)
	{
		for(unsigned int i = 0; i < vehicles.size(); i++)
		{
			if(vehicles[i]->getBrand() == vehicle->getBrand())
			{
				return false;
			}
		}

		vehicles.push_back(vehicle);
		return true;
	}
	return false;
}

////
//e)
//template<class Vehicle>
//bool myfunction(Vehicle v1, Vehicle v2)
//{
//	if(v1->getBrand() == v2.getBrand())
//	{
//		return v1->getPrice() < v2->getPrice();
//	}
//	else
//		return v1->getBrand() > v2.getBrand();
//}
//
template<class Vehicle>
void Garage<Vehicle>::sortVehicles() {
	sort(vehicles.begin(), vehicles.end());
}


/////
//f)

template<class Vehicle>
Vehicle* Garage<Vehicle>::removeVehicle(std::string brand, std::string model)
{
	Vehicle* veiculo;
	bool encontrado = false;
	for(int i = 0; i < vehicles.size(); i++)
	{
		if(vehicles[i]->getBrand()==brand)
		{
			if(vehicles[i]->getModel() == model)
			{
				encontrado = true;
				veiculo = vehicles[i];
				vehicles.erase(vehicles.begin()+i);
				return veiculo;
			}
		}
	}

	if(!encontrado)
	{
		throw NoSuchVehicleException();
	}
}

/////
//g)

class NoSuchBrandException {
	std::string brand;
public:
	NoSuchBrandException(std::string brand) {
		this->brand = brand;
	}
	std::string getBrand() const{
		return brand;
	}
};

template<class Vehicle>
float Garage<Vehicle>::avgPrice(std::string brand) const
{
	std::vector<Vehicle *> vehiclesBrand;
	bool encontrado = false;

	for(int i = 0; i < vehicles.size(); i++)
	{
		if(vehicles[i]->getBrand() == brand)
		{
			vehiclesBrand.push_back(vehicles[i]);
			encontrado = true;
		}
	}

	if(!encontrado)
	{
		throw NoSuchBrandException(brand);
	}

	int soma = 0;
	for(int j = 0; j < vehiclesBrand.size(); j++)
	{
		soma += vehiclesBrand[j]->getPrice();
	}

	float avg = soma / vehiclesBrand.size();

	return avg;
}




#endif /* SRC_GARAGE_H_ */
