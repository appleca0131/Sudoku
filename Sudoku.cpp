#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Sudoku.h"

using namespace std;

void Sudoku::giveQuestion(){
	int give_question_temp[SIZE] = {4,0,0,1,8,0,0,5,7,
									5,7,0,2,0,0,0,3,0,
									3,0,9,7,5,4,2,0,6,
									0,0,0,0,0,0,0,9,0,
									6,0,5,4,9,8,7,0,2,
									0,4,0,0,0,0,0,0,0,
									8,0,4,6,7,5,1,0,3,
									0,6,0,0,0,2,0,7,8,
									7,5,0,0,3,1,0,0,9};

	for(int i=0;i<SIZE;++i)
		map[i] = give_question_temp[i];

	cout << "My Sudoku:" << endl;
	printOut();
}

void Sudoku::readIn(){
	cout << "Please enter your Sudoku in one line:" << endl;

	for(int i=0;i<SIZE;++i)
		scanf("%1d",&map[i]);

	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
			ans[i][j] = map[j+i*9];

	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			ANS[i][j] = ans[i][j];

	cout << "The Sudoku you enter:" << endl;

	printOut();
}

bool Sudoku::checkRow(){
	int row_counter[9];

	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j)
			row_counter[j] = 0;
		for(int j=i*9;j<(i+1)*9;++j)
			for(int k=1;k<10;++k)
				if(map[j]==k)
					++row_counter[k-1];
		for(int j=0;j<9;++j)
			if(row_counter[j]!=0 && row_counter[j]!=1)
				return false;
	}

	return true;
}

bool Sudoku::checkColumn(){
	int column_counter[9];

	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j)
			column_counter[j] = 0;
		for(int j=i;j<73+i;j=j+9)
			for(int k=1;k<10;++k)
				if(map[j]==k)
					++column_counter[k-1];
		for(int j=0;j<9;++j)
			if(column_counter[j]!=0 && column_counter[j]!=1)
				return false;
	}

	return true;
}

bool Sudoku::checkCell(){
	int cell_counter[9];

	for(int I=0;I<=54;I=I+27){
		for(int i=I;i<=(I+6);i=i+3){
			for(int j=0;j<9;++j)
				cell_counter[j] = 0;
			for(int j=i;j<(i+3);++j)
				for(int k=1;k<10;++k)
					if(map[j]==k)
						++cell_counter[k-1];
			for(int j=(i+9);j<(i+12);++j)
				for(int k=1;k<10;++k)
					if(map[j]==k)
						++cell_counter[k-1];
			for(int j=(i+18);j<(i+21);++j)
				for(int k=1;k<10;++k)
					if(map[j]==k)
						++cell_counter[k-1];
			for(int j=0;j<9;++j)
				if(cell_counter[j]!=0 && cell_counter[j]!=1)
					return false;
		}
	}

	return true;
}

bool Sudoku::checkSolvable(){
	if(checkRow()==false || checkColumn()==false || checkCell()==false)
		return false;

	return true;
}

void Sudoku::observeRow(int x, int y){

	for(int i=0;i<9;i++)
		observe_row[i] = i+1;
	for(int i=y;i<9;i++)
		if(ans[x][i]!=0)
			observe_row[ans[x][i]-1] = 0;
	for(int i=y;i>=0;i--)
		if(ans[x][i]!=0)
			observe_row[ans[x][i]-1] = 0;
}

void Sudoku::OBSERVEROW(int x, int y){

	for(int i=0;i<9;i++)
		OBSERVE_ROW[i] = i+1;
	for(int i=y;i<9;i++)
		if(ANS[x][i]!=0)
			OBSERVE_ROW[ANS[x][i]-1] = 0;
	for(int i=y;i>=0;i--)
		if(ANS[x][i]!=0)
			OBSERVE_ROW[ANS[x][i]-1] = 0;
}

void Sudoku::observeColumn(int x, int y){
	for(int i=0;i<9;i++)
		observe_column[i] = i+1;
	for(int i=x;i<9;i++)
		if(ans[i][y]!=0)
			observe_column[ans[i][y]-1] = 0;
	for(int i=x;i>=0;i--)
		if(ans[i][y]!=0)
			observe_column[ans[i][y]-1] = 0;
}

void Sudoku::OBSERVECOLUMN(int x, int y){
	for(int i=0;i<9;i++)
		OBSERVE_COLUMN[i] = i+1;
	for(int i=x;i<9;i++)
		if(ANS[i][y]!=0)
			OBSERVE_COLUMN[ANS[i][y]-1] = 0;
	for(int i=x;i>=0;i--)
		if(ANS[i][y]!=0)
			OBSERVE_COLUMN[ANS[i][y]-1] = 0;
}

void Sudoku::observeCell(int x, int y){
	for(int i=0;i<9;i++)
		observe_cell[i] = i+1;
	if(x<=2 && y<=2)
		for(int i=0;i<=2;i++)
			for(int j=0;j<=2;j++)
				if(ans[i][j]!=0)
					observe_cell[ans[i][j]-1] = 0;
	if(x<=2 && (3<=y && y<=5))
		for(int i=0;i<=2;i++)
			for(int j=3;j<=5;j++)
				if(ans[i][j]!=0)
					observe_cell[ans[i][j]-1] = 0;
	if(x<=2 && (6<=y && y<=8))
		for(int i=0;i<=2;i++)
			for(int j=6;j<=8;j++)
				if(ans[i][j]!=0)
					observe_cell[ans[i][j]-1] = 0;
	if((3<=x && x<=5) && y<=2)
		for(int i=3;i<=5;i++)
			for(int j=0;j<=2;j++)
				if(ans[i][j]!=0)
					observe_cell[ans[i][j]-1] = 0;
	if((3<=x && x<=5) && (3<=y && y<=5))
		for(int i=3;i<=5;i++)
			for(int j=3;j<=5;j++)
				if(ans[i][j]!=0)
					observe_cell[ans[i][j]-1] = 0;
	if((3<=x && x<=5) && (6<=y && y<=8))
		for(int i=3;i<=5;i++)
			for(int j=6;j<=8;j++)
				if(ans[i][j]!=0)
					observe_cell[ans[i][j]-1] = 0;
	if((6<=x && x<=8) && y<=2)
		for(int i=6;i<=8;i++)
			for(int j=0;j<=2;j++)
				if(ans[i][j]!=0)
					observe_cell[ans[i][j]-1] = 0;
	if((6<=x && x<=8) && (3<=y && y<=5))
		for(int i=6;i<=8;i++)
			for(int j=3;j<=5;j++)
				if(ans[i][j]!=0)
					observe_cell[ans[i][j]-1] = 0;
	if((6<=x && x<=8) && (6<=y && y<=8))
		for(int i=6;i<=8;i++)
			for(int j=6;j<=8;j++)
				if(ans[i][j]!=0)
					observe_cell[ans[i][j]-1] = 0;
}

void Sudoku::OBSERVECELL(int x, int y){
	for(int i=0;i<9;i++)
		OBSERVE_CELL[i] = i+1;
	if(x<=2 && y<=2)
		for(int i=0;i<=2;i++)
			for(int j=0;j<=2;j++)
				if(ANS[i][j]!=0)
					OBSERVE_CELL[ANS[i][j]-1] = 0;
	if(x<=2 && (3<=y && y<=5))
		for(int i=0;i<=2;i++)
			for(int j=3;j<=5;j++)
				if(ANS[i][j]!=0)
					OBSERVE_CELL[ANS[i][j]-1] = 0;
	if(x<=2 && (6<=y && y<=8))
		for(int i=0;i<=2;i++)
			for(int j=6;j<=8;j++)
				if(ANS[i][j]!=0)
					OBSERVE_CELL[ANS[i][j]-1] = 0;
	if((3<=x && x<=5) && y<=2)
		for(int i=3;i<=5;i++)
			for(int j=0;j<=2;j++)
				if(ANS[i][j]!=0)
					OBSERVE_CELL[ANS[i][j]-1] = 0;
	if((3<=x && x<=5) && (3<=y && y<=5))
		for(int i=3;i<=5;i++)
			for(int j=3;j<=5;j++)
				if(ANS[i][j]!=0)
					OBSERVE_CELL[ANS[i][j]-1] = 0;
	if((3<=x && x<=5) && (6<=y && y<=8))
		for(int i=3;i<=5;i++)
			for(int j=6;j<=8;j++)
				if(ANS[i][j]!=0)
					OBSERVE_CELL[ANS[i][j]-1] = 0;
	if((6<=x && x<=8) && y<=2)
		for(int i=6;i<=8;i++)
			for(int j=0;j<=2;j++)
				if(ANS[i][j]!=0)
					OBSERVE_CELL[ANS[i][j]-1] = 0;
	if((6<=x && x<=8) && (3<=y && y<=5))
		for(int i=6;i<=8;i++)
			for(int j=3;j<=5;j++)
				if(ANS[i][j]!=0)
					OBSERVE_CELL[ANS[i][j]-1] = 0;
	if((6<=x && x<=8) && (6<=y && y<=8))
		for(int i=6;i<=8;i++)
			for(int j=6;j<=8;j++)
				if(ANS[i][j]!=0)
					OBSERVE_CELL[ANS[i][j]-1] = 0;
}

void Sudoku::fillBlank(){
	int possibility[9][9] = {0};

	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			for(int k=0;k<9;k++)
				statistics[i][j][k] = 0;

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			int l = 0;
			if(ans[i][j]==0){
				observeRow(i,j);
				observeColumn(i,j);
				observeCell(i,j);
				for(int k=0;k<9;k++)
					conclude_observe[k] = k+1;
				for(int k=0;k<9;k++)
					if(observe_row[k]==0 || observe_column[k]==0 || observe_cell[k]==0)
						conclude_observe[k] = 0;
				for(int k=0;k<9;k++){
					if(conclude_observe[k]!=0){
						possibility[i][j]++;
						statistics[i][j][l] = conclude_observe[k];
						l++;
					}
				}
			}
		}
	}

	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(possibility[i][j]==1)
				ans[i][j] = statistics[i][j][0];
}

void Sudoku::FILLBLANK(){
	int POSSIBILITY[9][9] = {0};

	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			for(int k=0;k<9;k++)
				STATISTICS[i][j][k] = 0;

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			int l = 0;
			if(ANS[i][j]==0){
				OBSERVEROW(i,j);
				OBSERVECOLUMN(i,j);
				OBSERVECELL(i,j);
				for(int k=0;k<9;k++)
					CONCLUDE_OBSERVE[k] = k+1;
				for(int k=0;k<9;k++)
					if(OBSERVE_ROW[k]==0 || OBSERVE_COLUMN[k]==0 || OBSERVE_CELL[k]==0)
						CONCLUDE_OBSERVE[k] = 0;
				for(int k=0;k<9;k++){
					if(CONCLUDE_OBSERVE[k]!=0){
						POSSIBILITY[i][j]++;
						STATISTICS[i][j][l] = CONCLUDE_OBSERVE[k];
						l++;
					}
				}
			}
		}
	}

	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(POSSIBILITY[i][j]==1)
				ANS[i][j] = STATISTICS[i][j][0];
}

void Sudoku::guess(){
	int flag1 = 0;
	int flag2 = 0;
	int possibility[9][9] = {0};

	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			for(int k=0;k<9;k++)
				statistics[i][j][k] = 0;

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			int l = 0;
			if(ans[i][j]==0){
				observeRow(i,j);
				observeColumn(i,j);
				observeCell(i,j);
				for(int k=0;k<9;k++)
					conclude_observe[k] = k+1;
				for(int k=0;k<9;k++)
					if(observe_row[k]==0 || observe_column[k]==0 || observe_cell[k]==0)
						conclude_observe[k] = 0;
				for(int k=0;k<9;k++){
					if(conclude_observe[k]!=0){
						possibility[i][j]++;
						statistics[i][j][l] = conclude_observe[k];
						l++;
					}
				}
			}
		}
	}

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(ans[i][j]==0 && possibility[i][j]>1){
				for(int k=8;k>=0;k--){
					if(statistics[i][j][k]!=0){
						ans[i][j] = statistics[i][j][k];
						flag1 = 1;
						flag2 = 1;
						break;
					}
				}
				if(flag2==1)
					break;
			}
		}
		if(flag1==1)
			break;
	}
}

void Sudoku::GUESS(){
	int flag1 = 0;
	int flag2 = 0;
	int POSSIBILITY[9][9] = {0};

	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			for(int k=0;k<9;k++)
				STATISTICS[i][j][k] = 0;

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			int l = 0;
			if(ANS[i][j]==0){
				OBSERVEROW(i,j);
				OBSERVECOLUMN(i,j);
				OBSERVECELL(i,j);
				for(int k=0;k<9;k++)
					CONCLUDE_OBSERVE[k] = k+1;
				for(int k=0;k<9;k++)
					if(OBSERVE_ROW[k]==0 || OBSERVE_COLUMN[k]==0 || OBSERVE_CELL[k]==0)
						CONCLUDE_OBSERVE[k] = 0;
				for(int k=0;k<9;k++){
					if(CONCLUDE_OBSERVE[k]!=0){
						POSSIBILITY[i][j]++;
						STATISTICS[i][j][l] = CONCLUDE_OBSERVE[k];
						l++;
					}
				}
			}
		}
	}

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(ANS[i][j]==0 && POSSIBILITY[i][j]>1){
				for(int k=0;k<=8;k++){
					if(STATISTICS[i][j][k]!=0){
						ANS[i][j] = STATISTICS[i][j][k];
						flag1 = 1;
						flag2 = 1;
						break;
					}
				}
				if(flag2==1)
					break;
			}
		}
		if(flag1==1)
			break;
	}
}

void Sudoku::repeat(){
	for(int K=0;K<5;K++){
		guess();
		for(int t=0;t<SIZE;t++)
			fillBlank();
	}
}

void Sudoku::REPEAT(){
	for(int K=0;K<5;K++){
		GUESS();
		for(int t=0;t<SIZE;t++)
			FILLBLANK();
	}
}

void Sudoku::solve(){
	int number = 1;

	if(checkSolvable()==false)
		number = 0;
	if(checkSolvable()==true){
		int exit = 0;
		int EXIT = 0;
		
		for(int t=0;t<SIZE;t++)
			fillBlank();
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
				if(ans[i][j]!=0)
					exit++;
		if(exit!=81){
			guess();
			for(int t=0;t<SIZE;t++)
				fillBlank();
			for(int i=0;i<9;i++)
				for(int j=0;j<9;j++)
					if(ans[i][j]!=0)
						EXIT++;
			if(EXIT!=81)
				number = 2;
		}
	}

	int zero = 0;
	for(int i=0;i<SIZE;i++)
		if(map[i]==0)
			zero++;
	if(zero>63)
		number = 2;

	if(number==0)
		cout << number << endl;
	if(number==1){
		cout << number << endl;
		printAns();
	}
	if(number==2)
		cout << number << endl;
}

void Sudoku::changeNum(int a, int b){
	for(int i=0;i<SIZE;++i){
		if(map[i]==a)
			map[i] = 10;
		if(map[i]==b)
			map[i] = a;
		if(map[i]==10)
			map[i] = b;
	}
}

void Sudoku::changeRow(int a, int b){
	int change_row_temp[27];

	for(int i=0;i<27;++i){
		if((a==0 && b==0) || (a==1 && b==1) || (a==2 && b==2)){
		}
		if((a==0 && b==1) || (a==1 && b==0)){
			change_row_temp[i] = map[i];
			map[i] = map[i+27];
			map[i+27] = change_row_temp[i];
		}
		if((a==0 && b==2) || (a==2 && b==0)){
			change_row_temp[i] = map[i];
			map[i] = map[i+54];
			map[i+54] = change_row_temp[i];
		}
		if((a==1 && b==2) || (a==2 && b==1)){
			change_row_temp[i] = map[i+27];
			map[i+27] = map[i+54];
			map[i+54] = change_row_temp[i];
		}
	}
}

void Sudoku::changeCol(int a, int b){
	int change_col_temp[27];

	if((a==0 && b==0) || (a==1 && b==1) || (a==2 && b==2)){
	}
	if((a==0 && b==1) || (a==1 && b==0)){
		for(int i=0;i<27;i=i+3){
			change_col_temp[i] = map[3*i];
			change_col_temp[i+1] = map[3*i+1];
			change_col_temp[i+2] = map[3*i+2];
			map[3*i] = map[3*i+3];
			map[3*i+1] = map[3*i+4];
			map[3*i+2] = map[3*i+5];
			map[3*i+3] = change_col_temp[i];
			map[3*i+4] = change_col_temp[i+1];
			map[3*i+5] = change_col_temp[i+2];
		}
	}
	if((a==0 && b==2) || (a==2 && b==0)){
		for(int i=0;i<27;i=i+3){
			change_col_temp[i] = map[3*i];
			change_col_temp[i+1] = map[3*i+1];
			change_col_temp[i+2] = map[3*i+2];
			map[3*i] = map[3*i+6];
			map[3*i+1] = map[3*i+7];
			map[3*i+2] = map[3*i+8];
			map[3*i+6] = change_col_temp[i];
			map[3*i+7] = change_col_temp[i+1];
			map[3*i+8] = change_col_temp[i+2];
		}
	}
	if((a==1 && b==2) || (a==2 && b==1)){
		for(int i=0;i<27;i=i+3){
			change_col_temp[i] = map[3*i+3];
			change_col_temp[i+1] = map[3*i+4];
			change_col_temp[i+2] = map[3*i+5];
			map[3*i+3] = map[3*i+6];
			map[3*i+4] = map[3*i+7];
			map[3*i+5] = map[3*i+8];
			map[3*i+6] = change_col_temp[i];
			map[3*i+7] = change_col_temp[i+1];
			map[3*i+8] = change_col_temp[i+2];
		}
	}
}

void Sudoku::sub_rotate(){
	int rotate_temp[SIZE];

	for(int i=0;i<9;++i){
		rotate_temp[i] = map[72-9*i];
		rotate_temp[i+9] = map[73-9*i];
		rotate_temp[i+18] = map[74-9*i];
		rotate_temp[i+27] = map[75-9*i];
		rotate_temp[i+36] = map[76-9*i];
		rotate_temp[i+45] = map[77-9*i];
		rotate_temp[i+54] = map[78-9*i];
		rotate_temp[i+63] = map[79-9*i];
		rotate_temp[i+72] = map[80-9*i];
	}
	for(int i=0;i<SIZE;++i)
		map[i] = rotate_temp[i];
}

void Sudoku::rotate(int n){
	if((n%4)==0){
	}
	if((n%4)==1){
		sub_rotate();
	}
	if((n%4)==2){
		sub_rotate();
		sub_rotate();
	}
	if((n%4)==3){
		sub_rotate();
		sub_rotate();
		sub_rotate();
	}
}

void Sudoku::flip(int n){
	int flip_temp[SIZE];

	if(n==0){
		for(int i=0;i<9;++i)
			flip_temp[i+72] = map[i];
		for(int i=9;i<18;++i)
			flip_temp[i+54] = map[i];
		for(int i=18;i<27;++i)
			flip_temp[i+36] = map[i];
		for(int i=27;i<36;++i)
			flip_temp[i+18] = map[i];
		for(int i=36;i<45;++i)
			flip_temp[i] = map[i];
		for(int i=45;i<54;++i)
			flip_temp[i-18] = map[i];
		for(int i=54;i<63;++i)
			flip_temp[i-36] = map[i];
		for(int i=63;i<72;++i)
			flip_temp[i-54] = map[i];
		for(int i=72;i<81;++i)
			flip_temp[i-72] = map[i];
		for(int i=0;i<SIZE;++i)
			map[i] = flip_temp[i];
	}
	if(n==1){
		for(int i=0;i<=72;i=i+9)
			flip_temp[i] = map[i+8];
		for(int i=1;i<=73;i=i+9)
			flip_temp[i] = map[i+6];
		for(int i=2;i<=74;i=i+9)
			flip_temp[i] = map[i+4];
		for(int i=3;i<=75;i=i+9)
			flip_temp[i] = map[i+2];
		for(int i=4;i<=76;i=i+9)
			flip_temp[i] = map[i];
		for(int i=5;i<=77;i=i+9)
			flip_temp[i] = map[i-2];
		for(int i=6;i<=78;i=i+9)
			flip_temp[i] = map[i-4];
		for(int i=7;i<=79;i=i+9)
			flip_temp[i] = map[i-6];
		for(int i=8;i<=80;i=i+9)
			flip_temp[i] = map[i-8];
		for(int i=0;i<SIZE;++i)
			map[i] = flip_temp[i];
	}
}

void Sudoku::transform(){
	int randnum;

	srand(time(NULL));
	randnum = rand()%5;

	cout << "The new Sudoku after ";

	if(randnum==0){
		changeNum(rand()%9+1,rand()%9+1);
		cout << "changing number:" << endl;
	}
	if(randnum==1){
		changeRow(rand()%3,rand()%3);
		cout << "changing row:" << endl;
	}
	if(randnum==2){
		changeCol(rand()%3,rand()%3);
		cout << "changing column:" << endl;
	}
	if(randnum==3){
		rotate(rand()%101);
		cout << "rotating:" << endl;
	}
	if(randnum==4){
		flip(rand()%2);
		cout << "flipping:" << endl;
	}

	printOut();
}

void Sudoku::printOut(){
	for(int i=0;i<SIZE;++i)
		printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
}

void Sudoku::printAns(){
	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
			printf("%d%c",ans[i][j],j==8?'\n':' ');
}