/*
 * CGame.h
 *
 *  Created on: 23 июня 2015 г.
 *      Author: kulpanov!
 */

#ifndef CGAME_H_
#define CGAME_H_

#include <set>

namespace chess {

enum class EType{
	_black, _white
};


class CGameBoard {
public:
	class CSquare {
		EType type;
	public:
		CSquare();
		virtual ~CSquare();
	};
	typedef std::set<CSquare> TSquares;

public:
	TSquares allowedMoves() const ;

	CGameBoard();
	virtual ~CGameBoard();
private:
	TSquares squares;
};

class CPlayer{
public:
protected:
	EType type;
public:
	EType getType() const {return type;}

	void turn();

	void loose();
public:
	CPlayer(EType _type): type(_type){

	}
	virtual ~CPlayer();
};

class CGame {
public:
	class CRules{
	public:
		bool IsCheck();
		bool IsCheckMate();
	};
public:
	void interrupt();
	void save(std::string& _fname);

	CGame(const CPlayer& _black, const CPlayer _white);
	virtual ~CGame();
public:
	static void run();
protected:
	std::pair<CPlayer&, CPlayer&> players;
	CGameBoard board;
	CRules globalRules;
};






} /* namespace chess */

#endif /* CGAME_H_ */
