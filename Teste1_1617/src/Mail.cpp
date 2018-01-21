/*
 * Mail.cpp
 */

#include "Mail.h"

Mail::Mail(string send, string rec, string zcode):
			sender(send),receiver(rec), zipCode(zcode)
{ }

Mail::~Mail()
{ }

string Mail::getZipCode() const {
	return zipCode;
}

RegularMail::RegularMail(string send, string rec, string zcode, unsigned int w):
			Mail(send, rec, zcode), weight(w)
{ }

GreenMail::GreenMail(string send, string rec, string zcode, string t):
			Mail(send, rec, zcode), type(t)
{ }


/////
//c)
unsigned int RegularMail::getPrice () const
{
	unsigned int price = 0;
	if(weight <= 20)
		price = 50;
	else if(weight <= 100)
		price = 75;
	else if(weight <= 500)
		price = 140;
	else
		price = 325;

	return price;
}

unsigned int GreenMail::getPrice () const {
	unsigned int price = 0;
	if(type == "envelope")
		price = 80;
	else if(type == "bag")
		price = 200;
	else if(type == "box")
		price = 240;
	return price;
}







