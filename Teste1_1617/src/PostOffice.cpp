/*
 * PostOffice.cpp
 */

#include "PostOffice.h"
#include <string>

PostOffice::PostOffice(string firstZCode, string lastZCode):
								firstZipCode(firstZCode), lastZipCode(lastZCode)
{}
PostOffice::PostOffice() {}

void PostOffice::addMailToSend(Mail *m) {
	mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
	mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p){
	postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
	return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
	return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
	return postmen;
}


////////////////////////// RESOLUCAO
/////
//b)
vector<Mail *> PostOffice::removePostman(string name)
{
	vector<Mail *> mailPostman;
	bool existe = false;
	for(int i = 0; i < postmen.size(); i++)
	{
		if(postmen[i].getName() == name)
		{
			existe = true;
			mailPostman = postmen[i].getMail();
			postmen.erase(postmen.begin()+i);
			return mailPostman;
		}
	}
	if(!existe)
	{
		return mailPostman;
	}
}


///////
//d
vector<Mail *> PostOffice::endOfDay(unsigned int &balance)
{
	vector <Mail* > endOfDay;
	balance = 0;
	for(int i = 0; i < mailToSend.size(); i++)
	{
		balance += mailToSend[i]->getPrice();
		if((mailToSend[i]->getZipCode() >= firstZipCode) && (mailToSend[i]->getZipCode() <= lastZipCode))
		{
			addMailToDeliver(mailToSend[i]);
		}
		else
		{
			endOfDay.push_back(mailToSend[i]);
		}
	}
	mailToSend.clear();
	return endOfDay;

}


//////
//g)

Postman PostOffice::addMailToPostman(Mail *m, string name)
{
	bool existe;
	Postman p1("");
	for(int i = 0; i < postmen.size(); i++)
	{
		if(name == postmen[i].getName())
		{
			existe = true;
			postmen[i].addMail(m);
			p1 = postmen[i];
		}
	}

	if(!existe)
		throw  NoPostmanException(name);

	return p1;

}










