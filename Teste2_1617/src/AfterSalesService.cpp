/*
 * AfterSalesService.cpp
 *
 *  Created on: Nov 16, 2016
 *      Author: hlc
 */

#include <algorithm>
#include "AfterSalesService.h"

using namespace std;

int AfterSalesService::tableOrdinal = 0;

AfterSalesService::AfterSalesService(int toWrapQS) : toWrapQueueSize(toWrapQS) {
}

vector<Article*> AfterSalesService::getPresentsTable() const {
	return presentsTable;
}

queue<Article*> AfterSalesService::getToWrap() const {
	return toWrap;
}

queue<Article*> AfterSalesService::getToDeliver() const {
	return toDeliver;
}

/**
 *  Place presents on the presents table, assigning them a relative present number and a sequential number.
 *  Assumes all given presents are from the same client.
 */
void AfterSalesService::dropPresentsOnTable(vector<Article*> presents) {
	for(vector<Article*>::size_type i = 0; i<presents.size(); i++) {
		presents[i]->setPresentNumber(i+1);
		presents[i]->setArrivalNumber(++tableOrdinal);
		presentsTable.push_back(presents[i]);
	}
}

/**
 * Remove from the table all articles of a given client.
 */

/////
// c)
vector<Article*> AfterSalesService::pickPresentsFromTable(long client) {
	vector<Article*> clientPresents;

	for(int i = 0; i < presentsTable.size(); i++)
	{
		if(presentsTable[i]->getClient() == client)
		{
			clientPresents.push_back(presentsTable[i]);
			presentsTable.erase(presentsTable.begin() + i);
			i--;
		}
	}

	return clientPresents;
}

/**
 * Sort the first 10 articles in the presents table:
 *   (i) give priority to articles that are NOT to be delivered at home (client is waiting);
 *  (ii) if two articles have (relative) present numbers differing more than 2,
 *       the one with lower present number should have priority (clients should not wait too much);
 * (iii) else, maintain article order in the table.
 */

/////
//e)

//bool compareArticles(Article* a1, Article* a2){
//	/* Get the 'Deliver Home' to the end */
//	if (a1->getDeliverHome() && !a2->getDeliverHome())
//		return false;
//	else if(!a1->getDeliverHome() && a2->getDeliverHome())
//		return true;
//	/* -------------------------------- */
//	else if(!a1->getDeliverHome() && !a2->getDeliverHome()){	// Both are to deliver now
//		if (abs(a1->getPresentNumber() - a2->getPresentNumber()) > 2){	// They differ more than 2!
//			return (a1->getPresentNumber() < a2->getPresentNumber());
//		}
//	}
//
//	return false;
//}
//
void AfterSalesService::sortArticles() {
	//std::sort(presentsTable.begin(), presentsTable.end(), compareArticles);
}

/**
 * Move the first presents in the table to the queue of presents to wrap, taking into account the size of the queue.
 */
void AfterSalesService::enqueueArticles() {
	while((toWrap.size() < toWrapQueueSize) &&(!presentsTable.empty()))
	{
		toWrap.push(presentsTable[0]);
		presentsTable.erase(presentsTable.begin());
	}

}

/**
 * Process the first present to wrap. If it is an article to deliver home, the article is placed in the toDeliver queue.
 */
Article* AfterSalesService::wrapNext() {
	if(toWrap.empty())
		return NULL;

	Article * artigoRetirado = toWrap.front();
	toWrap.pop();

	if(artigoRetirado->getDeliverHome()){
		toDeliver.push(artigoRetirado);
		return NULL;
	}

	else
		return artigoRetirado;

}

