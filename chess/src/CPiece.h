/*
 * CPiece.h
 *
 *  Created on: 23 июня 2015 г.
 *      Author: kulpanov!
 */

#ifndef CPIECE_H_
#define CPIECE_H_
#include "CGame.h"

namespace chess {

//
class IStepRules {
public:
	virtual int isAllowedMoveTo(const CGameBoard::CSquare& _from, const CGameBoard::CSquare& _to) const  = 0;
//	CGameBoard::TSquares CPiece::allowedMoves() const {	}
public:
	virtual ~IStepRules(){	};
};

//
class CPiece {
public:
//	enum class ETypes{ pawn, rook, knight, bishop, queen, king};
//public:
//	int type() const ;
	int moveTo(const CGameBoard::CSquare& _to);

	int isAllowedMoveTo(const CGameBoard::CSquare& _to) const;
//	CGameBoard::TSquares CPiece::allowedMoves() const {	}
public:
	CPiece(IStepRules* _globalRules): pos(NULL), globalRules(_globalRules){	};
	virtual ~CPiece(){	};
protected:
	virtual int setPos(const CGameBoard::CSquare& _pos){
		pos = _pos;
		return 0;
	}
	virtual int checkByRules(const CGameBoard::CSquare& _to) const;
protected:
	CGameBoard::CSquare* pos = NULL;
	IStepRules* globalRules = NULL;//districtions by game
	int color = 0;
	//...
	//CPieceView* v;
};

//
//todo: en passant (взятие при проходке)?
class CPiece_pawn:public CPiece {
//private:
//	class CPawnRules{
//		int isAllowedMoveTo(const CPiece_pawn& )
//	};
protected:
	virtual int setPos(const CGameBoard::CSquare& _pos);

	virtual int checkByRules(const CGameBoard::CSquare& _to) const ;
public:
	CPiece_pawn(){	}

	virtual ~CPiece_pawn(){	}
private:
	bool isInitPos = true;
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
class CPiece_knight:public CPiece {
public:
	virtual int checkByRules(const CGameBoard::CSquare& _to) const;

	virtual ~CPiece_knight(){	}
};

///////////////////////////////////////////////////////////////////////////////////////////////
//
class CPiece_rook:public CPiece{
public:
	virtual int checkByRules(const CGameBoard::CSquare& _to) const;
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
class CPiece_bishop:public CPiece{
public:
	virtual int checkByRules(const CGameBoard::CSquare& _to) const;
};

class CPiece_queen:public CPiece{
	//i try to avoid multiple inheritance of code
	CPiece_bishop bishop;
	CPiece_rook rook;
public:
	virtual int checkByRules(const CGameBoard::CSquare& _to) const;
};

class CPiece_king:public CPiece_queen{
public:
	virtual int checkByRules(const CGameBoard::CSquare& _to) const;
};


} /* namespace chess */

#endif /* CPIECE_H_ */
