#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Sudoku.h"

using namespace std;

int main(){
	Sudoku sudoku;
	sudoku.readIn();
	sudoku.transform();

	return 0;
}
