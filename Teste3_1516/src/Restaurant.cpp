/*
 * Restaurant.cpp
 *
 *  Created on: 17/11/2015
 *      Author: hlc
 */

#include "Restaurant.h"

using namespace std;

Restaurant::Restaurant() { }

Restaurant::Restaurant(vector< stack<Dish*> >* cl, queue<Dish*>* di, list<Dish*>* dr) {
	if(cl != NULL) clean = *cl;
	if(di != NULL) dirty = *di;
	if(dr != NULL) drying = *dr;
}

void Restaurant::addTable(unsigned int n_places) {
	tables.push_back(Table(n_places));
}

void Restaurant::addTable(Table& t) {
	tables.push_back(t);
}

const Table& Restaurant::getTable(vector<Table>::size_type idx) const {
	return tables[idx];
}

/**
 * Gets the clean dishes stack for a given collection and type.
 * If there is none, adds and returns an empty stack.
 */
stack<Dish*>& Restaurant::getCleanDishStack(string collection, TypeOfDish type) {

	for(vector< stack<Dish*> >::iterator it = clean.begin(); it != clean.end(); ++it) {
		if((*it).empty() || ((*it).top()->getCollection() == collection && (*it).top()->getType() == type)) {
			return *it;
		}
	}

	stack<Dish*> st;
	clean.push_back(st);
	return clean.back();
}

const queue<Dish*>& Restaurant::getDirty() const {
	return dirty;
}

const list<Dish*>& Restaurant::getDrying() const {
	return drying;
}

/**
 * Adds a number of dishes of a collection/type to the respective clean stack.
 */

/////
//a)
void Restaurant::addDishes(unsigned int n, string collection, TypeOfDish type) {
	std::stack <Dish*> &dishes = getCleanDishStack(collection, type);
	for(int i = 0; i < n; i++)
	{
		dishes.push(new Dish(collection, type));
	}
}

/**
 * Washes a dish, getting if from the dirty queue and putting it in the wet list.
 * Returns the washed dish.
 */
/////
//b)
Dish* Restaurant::washDish() {
	Dish* d = dirty.front();
	dirty.pop();
	drying.push_back(d);

	return d;
}

/**
 * Clears a table, placing all dishes that are on it in the dirty queue.
 */
/////
//c)
void Restaurant::clearTable(vector<Table>::size_type idx) {
	vector<Dish*> dishes;
	if(idx < tables.size())
	{
		dishes = tables[idx].clear();
	}

	for(int i = 0; i < dishes.size(); i++)
	{
		dirty.push(dishes[i]);
	}
}

/**
 * Stores in the respective clean stack all drying dishes of a given collection and type.
 */

/////
//d)
void Restaurant::storeDryDishes(string collection, TypeOfDish type) {
	stack<Dish*> & dishes = getCleanDishStack(collection,type);
	list<Dish*>::iterator it;
	for(it = drying.begin(); it != drying.end(); it++)
	{
		if(((*it)->getCollection() == collection) && ((*it)->getType() == type))
		{
			dishes.push(*it);
			drying.erase(it);
			it--;

		}
	}

}

/**
 * Puts Plates of a given collection in a table.
 * Throws TableNotReadyException when the table is not empty.
 * Throws NotEnoughDishesException when there are not enough clean plates of the collection.
 */

////
//e)
void Restaurant::setupTable(vector<Table>::size_type idx, string collection) {
	vector<Dish*> dishesToPutOn;
	stack<Dish*> & dishes = getCleanDishStack(collection,Plate);

	if(idx >= tables.size() || idx < 0)
		return;

	if(!tables[idx].empty())
		throw TableNotReadyException();

	if (dishes.size() < tables[idx].size())
		throw NotEnoughDishesException();

	for (unsigned int i=0 ; i < tables[idx].size() ; i++){
		dishesToPutOn.push_back(dishes.top());
		dishes.pop();
	}
	tables[idx].putOn(dishesToPutOn);

}



/**
 * Picks the dry dishes and groups them.
 * Returns the grouped dishes.
 */

/////
//f)

bool sortDishes(Dish *d1, Dish *d2)
{
	if (d1->getCollection() == d2->getCollection())
		return d1->getType() < d2->getType();
	else return d1->getCollection() < d2->getCollection();
}
list<Dish*> Restaurant::pickupAndGroupDryDishes() {
	list<Dish*> dry_grouped = drying;
	drying.clear();
	dry_grouped.sort(sortDishes);

	return dry_grouped;
}

/**
 * Stores grouped dishes in the respective clean stacks.
 * Returns the number of stacks that have been updated.
 */
/////
//g)
int Restaurant::storeGroupedDishes(list<Dish*> grouped_dishes) {

	list<Dish*>::iterator it;
	string collection;
	TypeOfDish type;
	unsigned int dishStackCounter = 0;

	// Iterate through the grouped dishes
	for (it=grouped_dishes.begin() ; it!=grouped_dishes.end() ; it++){
		collection = (*it)->getCollection();
		type = (*it)->getType();
		dishStackCounter++;		// Increment the counter
		stack<Dish*> & dishesStack = getCleanDishStack(collection,type);	// Get the stack of the right type of dishes
		while ( ((*it)->getCollection()==collection) && ((*it)->getType()==type)){
			dishesStack.push(*it);
			it++;
			if (it == grouped_dishes.end()) break;
		}
		it--;	// Assert the iterator
	}

	return dishStackCounter;
}

