#include <iostream>

class Sudoku{
	public:
		void giveQuestion();

		void readIn();

		bool checkRow();
		bool checkColumn();
		bool checkCell();
		bool checkSolvable();
		
		bool map_observeRow(int x);
		bool map_observeColumn(int x);
		bool map_observeCell(int x);
		
		bool MAP_observeRow(int x);
		bool MAP_observeColumn(int x);
		bool MAP_observeCell(int x);
		
		int record_map_result;
		int map_findSpace();
		void map_fillBlank();
		
		int record_MAP_result;
		int MAP_findSpace();
		void MAP_fillBlank();
	
		void solve();

		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a, int b);
		void sub_rotate();
		void rotate(int n);
		void flip(int n);
		void transform();

		void printOut();
	private:
		static const int SIZE = 81;
		int map[SIZE];
		int MAP[SIZE];
		int remap[SIZE];
		int REMAP[SIZE];
};
