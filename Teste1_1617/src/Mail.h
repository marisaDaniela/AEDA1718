/*
 * Mail.h
 */

#ifndef SRC_MAIL_H_
#define SRC_MAIL_H_

#include <string>
using namespace std;


class Mail {
	string sender;
	string receiver;
	string zipCode;
public:
	Mail(string send, string rec, string zcode);
	virtual ~Mail();
	string getZipCode() const;
	virtual unsigned int getPrice () const = 0;
};


class RegularMail: public Mail {
	unsigned int weight;
public:
	RegularMail(string send, string rec, string code, unsigned int w);
	unsigned int getPrice() const;
};


class GreenMail: public Mail {
	string type;  // "envelope", "bag", "box"
public:
	GreenMail(string send, string rec, string code, string t);
	unsigned int getPrice() const;
};

//////
///a)
template <class T>
unsigned int numberDifferent(const vector <T>&v1)
{
	vector <T> numerosDifferentes;

	for(int i = 0; i < v1.size(); i++)
	{
		bool encontradoNumeroIgual = false;
		if(numerosDifferentes.size() > 0 )
		{
			for(int j = 0; j < numerosDifferentes.size(); j++)
			{
				if(v1[i] == numerosDifferentes[j])
				{
					encontradoNumeroIgual = true;
					break;
				}
			}
		}

		if(!encontradoNumeroIgual)
		{
			numerosDifferentes.push_back(v1[i]);
		}
	}
	return numerosDifferentes.size();
}


#endif /* SRC_MAIL_H_ */
