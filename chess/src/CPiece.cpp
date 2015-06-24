/*
 * CPiece.cpp
 *
 *  Created on: 23 июня 2015 г.
 *      Author: kulpanov!
 */

#include "CPiece.h"

namespace chess {

CPiece::CPiece() {
	// TODO Auto-generated constructor stub

}

CPiece::~CPiece() {
	// TODO Auto-generated destructor stub
}

int CPiece::isAllowedMoveTo(const CGameBoard::CSquare& _to) const {
	if(0 == globalRules.isAllowedMoveTo(this, _to)) return 0;

	int res = checkByRules(_to);

	if(res == 1 &_to.isBusyByOther( _piece.color() ) ){
		res = 2;//attack!
	}
	return res;
}

int CPiece::moveTo(const CGameBoard::CSquare& _to) {
	//check validity of moving ...
	int res = 0;
	if(isAllowedMoveTo(_to)){
		if(_to.isBusyByOther(color)){
			//notice about attack
		}
		_to.setPiece(this);
		res = setPos(_to);
	}
	return res;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
int CPiece_pawn::checkByRules(const CGameBoard::CSquare& _to) const {
	int res = 0;
	if(pos.isSameColumn(to) ){
		if(isInitPos && !_piece.pos.forward().isBusy() &&_piece.pos.forward().forward()==_to) res = 1;//first long step
		if(_piece.pos.forward()== _to ) res = 1;//simple step
	}

	if (_piece.pos.left().forward() == _to || _piece.pos.right().forward() == _to){
		res = 1;
	}
	return res;
}

//
int CPiece_pawn::setPos(const CGameBoard::CSquare& _to) {
	base::setPos(_to);
	if(pos.IsLastRow()){
		//need to promotion, event to view
		//...
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
int CPiece_knight::checkByRules(const CGameBoard::CSquare& _to) const{
	int res = 0;

	if(pos.forward().forward().left() == _to || pos.forward().forward().right() == _to)
		res = 1;
	if(pos.forward().left().left() == _to || pos.forward().right().right() == _to)
		res = 1;
	if(pos.backward().backward().left() == _to || pos.backward().backward().right() == _to)
		res = 1;
	if(pos.backward().left().left() == _to || pos.backward().left().right() == _to)
		res = 1;
	return res;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//
int CPiece_rook::checkByRules(const CGameBoard::CSquare& _to) const{
	int res = 0;
	if(pos->inSameColoumn(to) || pos->inSameRow(to)){
		auto path = CGameBoard::CSquare::CLinePath(pos, to);
		for(auto posInPath: path){
			if(posInPath.isBusy()) { res = -1; break;}
		}
		if(res==0)res = 1;
	}
	return res;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//
int CPiece_bishop::checkByRules(const CGameBoard::CSquare& _to) const{
	int res = 0;
	if(pos->inDiagonal(to)){
		auto path = CGameBoard::CSquare::CDiagonalPath(pos, to);
		for(auto posInPath: path){
			if(posInPath.isBusy()) { res = -1; break;}
		}
		if(res==0)res = 1;
	}
	return res;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//
int CPiece_queen::checkByRules(const CGameBoard::CSquare& _to) const{
	if(bishop.checkByRules() == 0)
		if(rook.checkByRules() == 0)
			return 0;
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//
int CPiece_king::checkByRules(const CGameBoard::CSquare& _to) const{
	if(! pos->IsNeighbor(to))
		return 0;
	return CPiece_queen::checkByRules(_to);
}


} /* namespace chess */
