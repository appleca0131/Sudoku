#include <iostream>

class Sudoku{
	public:
		int ans[9][9];
		int ANS[9][9];

		int observe_row[9];
		int observe_column[9];
		int observe_cell[9];
		int conclude_observe[9];
		int statistics[9][9][9];
		
		int OBSERVE_ROW[9];
		int OBSERVE_COLUMN[9];
		int OBSERVE_CELL[9];
		int CONCLUDE_OBSERVE[9];
		int STATISTICS[9][9][9];

		void giveQuestion();

		void readIn();

		bool checkRow();
		bool checkColumn();
		bool checkCell();
		bool checkSolvable();
		
		void observeRow(int x, int y);
		void observeColumn(int x, int y);
		void observeCell(int x, int y);
		void fillBlank();
		void guess();
		void repeat();
		
		void OBSERVEROW(int x, int y);
		void OBSERVECOLUMN(int x, int y);
		void OBSERVECELL(int x, int y);
		void FILLBLANK();
		void GUESS();
		void REPEAT();
	
		void solve();

		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a, int b);
		void sub_rotate();
		void rotate(int n);
		void flip(int n);
		void transform();

		void printOut();
		void printAns();
	private:
		static const int SIZE = 81;
		int map[SIZE];
};