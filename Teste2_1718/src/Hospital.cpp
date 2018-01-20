/*
 * Hospital.cpp
 */

#include "Hospital.h"
//
#include <algorithm>


Hospital::Hospital(unsigned trayC):trayCapacity(trayC)
{ }

void Hospital::addDoctor(const Doctor &d1) {
	doctors.push_back(d1);
}

list<Doctor> Hospital::getDoctors() const {
	return doctors;
}

void Hospital::addTrays(stack<Patient> tray1) {
	letterTray.push_back(tray1);
}

list<stack<Patient> > Hospital::getTrays() const {
	return letterTray;
}


/////
//a)
unsigned Hospital::numPatients(string medicalSpecialty) const
{
	list<Doctor> aux = doctors;
	list<Doctor>::iterator it;
	unsigned int numPatients = 0;
	for(it = aux.begin(); it != aux.end(); it++)
	{
		if(medicalSpecialty == it->getMedicalSpecialty())
		{
			queue <Patient> patients = it->getPatients();

			while(!patients.empty())
			{
				numPatients++;
				patients.pop();
			}
		}
	}
	return numPatients;
}

/////
//b)

bool compDoctors(const Doctor &d1, const Doctor &d2)
{
	if(d1.getPatients().size() < d2.getPatients().size())
		return true;
	else if(d1.getPatients().size() == d2.getPatients().size())
	{
		if(d1.getMedicalSpecialty() < d2.getMedicalSpecialty())
		{
			return true;
		}
		else if(d1.getMedicalSpecialty() == d2.getMedicalSpecialty())
			if(d1.getCode() < d2.getCode())
				return true;
		return false;
	}
	return false;

}

void Hospital::sortDoctors() {
	doctors.sort(compDoctors);
}


/////
//d)
bool Hospital::addDoctor(unsigned codM1, string medicalSpecialty1) {
	list<Doctor>aux = doctors;
	unsigned numDoctorsSpeciality = 0;
	list<Doctor>::iterator it;

	for(it = aux.begin(); it != aux.end(); it++)
	{
		if(it->getMedicalSpecialty() == medicalSpecialty1)
		{
			numDoctorsSpeciality++;
		}
	}

	if(numDoctorsSpeciality < 3)
	{
		Doctor d1(codM1, medicalSpecialty1);
		doctors.push_back(d1);
		return true;
	}
	return false;

}

////
//e)

queue<Patient> Hospital::removeDoctor(unsigned codM1) {
	queue<Patient> p1;
	list<Doctor>::iterator it;
	bool encontrado = false;
	for(it = doctors.begin(); it != doctors.end(); it++){
		if(it->getCode()==codM1)
		{
			encontrado = true;
			p1 = it->getPatients();
			doctors.erase(it);
		}
	}
	if(!encontrado)
	{
		throw  DoctorInexistent();
	}
	return p1;

}

//////
//f)
bool Hospital::putInLessBusyDoctor(unsigned cod1, string medicalSpecialty1) {
	list<Doctor>::iterator it;
	list<Doctor>::iterator currDoctor;

	bool entrou = false;
	for(it = doctors.begin(); it != doctors.end(); it++)
	{
		if(it->getMedicalSpecialty() == medicalSpecialty1)
		{
			if(!entrou)
			{
				entrou = true;
				currDoctor = it;
			}
			else
			{
				if(currDoctor->getPatients().size() > it->getPatients().size())
				{
					currDoctor = it;
				}
			}
		}
	}
	if(entrou)
	{
		Patient p1(cod1,medicalSpecialty1);
		currDoctor->addPatient(p1);
	}
	return entrou;
}



void Hospital::processPatient(unsigned codM1) {
	list<Doctor>::iterator it;
	list<stack<Patient> >::iterator it2;

	bool encontrado = false;
	bool comPacientes = false;
	bool comCapacidade = false;

	stack<Patient> novaStack;

	Patient p1(0,"");

	for(it = doctors.begin(); it != doctors.end(); it++)
	{
		if(it->getCode() == codM1)
		{
			encontrado = true;
			if(!it->getPatients().empty())
			{
				comPacientes = true;
				p1 = it->removeNextPatient();
			}

		}
	}

	if(encontrado && comPacientes)
	{
		for(it2 = letterTray.begin(); it2 != letterTray.end(); it2++)
		{
			if(it2->size() < trayCapacity)
			{
				comCapacidade = true;
				it2->push(p1);
				return;
			}
		}
		if(!comCapacidade)  // criar nova stack
		{
			novaStack.push(p1);
			addTrays(novaStack);
		}
	}

}

/////
//g)
unsigned Hospital::removePatients(unsigned codP1) {
	list<stack<Patient> >::iterator it;
	unsigned int contador = 0;
	for(it = letterTray.begin(); it != letterTray.end(); it++)
	{
		if(!(it->empty()))
		{
			if(it->top().getCode() == codP1)
			{
				it->pop();
				contador++;
			}
		}
		if(it->empty())
		{
			it = letterTray.erase(it);
		}
	}
	return contador;
}





