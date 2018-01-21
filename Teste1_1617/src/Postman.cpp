/*
 * Postman.cpp
 */
#include "Postman.h"


Postman::Postman(): id(0) {}

void Postman::setName(string nm){
	name = nm;
}

string Postman::getName() const{
	return name;
}

vector<Mail *> Postman::getMail() const {
	return myMail;
}

void Postman::addMail(Mail *m) {
	myMail.push_back(m);
}

void Postman::addMail(vector<Mail *> mails) {
	myMail.insert(myMail.end(),mails.begin(),mails.end());
}

unsigned int Postman::getID() const{
	return id;
}


////////
//e)
Postman::Postman(string name)
{
	this->name = name;
	this->id = ID++;
}

//////
//f)
bool Postman::operator<(Postman &p1)
{
	vector <string> zips1;
	vector <string> zips2;
	for(int i = 0; i < this->getMail().size(); i++)
	{
		zips1.push_back(this->getMail()[i]->getZipCode());
	}
	for(int i = 0; i <p1.getMail().size(); i++)
	{
		zips2.push_back(p1.getMail()[i]->getZipCode());
	}
	return  (numberDifferent(zips1) <  numberDifferent(zips2));

}



