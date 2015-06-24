//============================================================================
// Name        : chess.cpp
// Author      : alexander Kulpanov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	auto game = chess::CGame(CPlayer(), CPlayer());

	game.run();

	return 0;
}
