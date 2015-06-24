/*
 * CHistory.h
 *
 *  Created on: 23 июня 2015 г.
 *      Author: kulpanov!
 */

#ifndef CHISTORY_H_
#define CHISTORY_H_

namespace chess {

class CHistory {
public:
	struct CItem{
		//
		CItem(const std::string& _str);
	};
public:
	void load(std::string fname);
	void save(std::string fname);


	CHistory();
	virtual ~CHistory();
};

} /* namespace chess */

#endif /* CHISTORY_H_ */
