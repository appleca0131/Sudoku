#include <iostream>
#include <cstdio>
#include <cstdlib>
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

	for(int i=0;i<SIZE;++i)
		MAP[i] = map[i];
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

bool Sudoku::map_observeRow(int x){
	for(int i=0;i<9;i++)
		if(map[(x/9)*9+i]==map[x] && ((x/9)*9+i)!=x)
			return false;
	return true;
}

bool Sudoku::map_observeColumn(int x){
	for(int i=0;i<9;i++)
		if(map[(x%9)+i*9]==map[x] && ((x%9)+i*9)!=x)
			return false;
	return true;
}

bool Sudoku::map_observeCell(int x){
	if(x==0)
		if(map[x]==map[1] || map[x]==map[2] || map[x]==map[9] || map[x]==map[10] || map[x]==map[11] || map[x]==map[18] || map[x]==map[19] || map[x]==map[20])
			return false;
	if(x==1)
		if(map[x]==map[0] || map[x]==map[2] || map[x]==map[9] || map[x]==map[10] || map[x]==map[11] || map[x]==map[18] || map[x]==map[19] || map[x]==map[20])
			return false;
	if(x==2)
		if(map[x]==map[0] || map[x]==map[1] || map[x]==map[9] || map[x]==map[10] || map[x]==map[11] || map[x]==map[18] || map[x]==map[19] || map[x]==map[20])
			return false;
	if(x==3)
		if(map[x]==map[4] || map[x]==map[5] || map[x]==map[12] || map[x]==map[13] || map[x]==map[14] || map[x]==map[21] || map[x]==map[22] || map[x]==map[23])
			return false;
	if(x==4)
		if(map[x]==map[3] || map[x]==map[5] || map[x]==map[12] || map[x]==map[13] || map[x]==map[14] || map[x]==map[21] || map[x]==map[22] || map[x]==map[23])
			return false;
	if(x==5)
		if(map[x]==map[3] || map[x]==map[4] || map[x]==map[12] || map[x]==map[13] || map[x]==map[14] || map[x]==map[21] || map[x]==map[22] || map[x]==map[23])
			return false;
	if(x==6)
		if(map[x]==map[7] || map[x]==map[8] || map[x]==map[15] || map[x]==map[16] || map[x]==map[17] || map[x]==map[24] || map[x]==map[25] || map[x]==map[26])
			return false;
	if(x==7)
		if(map[x]==map[6] || map[x]==map[8] || map[x]==map[15] || map[x]==map[16] || map[x]==map[17] || map[x]==map[24] || map[x]==map[25] || map[x]==map[26])
			return false;
	if(x==8)
		if(map[x]==map[6] || map[x]==map[7] || map[x]==map[15] || map[x]==map[16] || map[x]==map[17] || map[x]==map[24] || map[x]==map[25] || map[x]==map[26])
			return false;
	//
	if(x==9)
		if(map[x]==map[0] || map[x]==map[1] || map[x]==map[2] || map[x]==map[10] || map[x]==map[11] || map[x]==map[18] || map[x]==map[19] || map[x]==map[20])
			return false;
	if(x==10)
		if(map[x]==map[0] || map[x]==map[1] || map[x]==map[2] || map[x]==map[9] || map[x]==map[11] || map[x]==map[18] || map[x]==map[19] || map[x]==map[20])
			return false;
	if(x==11)
		if(map[x]==map[0] || map[x]==map[1] || map[x]==map[2] || map[x]==map[9] || map[x]==map[10] || map[x]==map[18] || map[x]==map[19] || map[x]==map[20])
			return false;
	if(x==12)
		if(map[x]==map[3] || map[x]==map[4] || map[x]==map[5] || map[x]==map[13] || map[x]==map[14] || map[x]==map[21] || map[x]==map[22] || map[x]==map[23])
			return false;
	if(x==13)
		if(map[x]==map[3] || map[x]==map[4] || map[x]==map[5] || map[x]==map[12] || map[x]==map[14] || map[x]==map[21] || map[x]==map[22] || map[x]==map[23])
			return false;
	if(x==14)
		if(map[x]==map[3] || map[x]==map[4] || map[x]==map[5] || map[x]==map[12] || map[x]==map[13] || map[x]==map[21] || map[x]==map[22] || map[x]==map[23])
			return false;
	if(x==15)
		if(map[x]==map[6] || map[x]==map[7] || map[x]==map[8] || map[x]==map[16] || map[x]==map[17] || map[x]==map[24] || map[x]==map[25] || map[x]==map[26])
			return false;
	if(x==16)
		if(map[x]==map[6] || map[x]==map[7] || map[x]==map[8] || map[x]==map[15] || map[x]==map[17] || map[x]==map[24] || map[x]==map[25] || map[x]==map[26])
			return false;
	if(x==17)
		if(map[x]==map[6] || map[x]==map[7] || map[x]==map[8] || map[x]==map[15] || map[x]==map[16] || map[x]==map[24] || map[x]==map[25] || map[x]==map[26])
			return false;
	//
	if(x==18)
		if(map[x]==map[0] || map[x]==map[1] || map[x]==map[2] || map[x]==map[9] || map[x]==map[10] || map[x]==map[11] || map[x]==map[19] || map[x]==map[20])
			return false;
	if(x==19)
		if(map[x]==map[0] || map[x]==map[1] || map[x]==map[2] || map[x]==map[9] || map[x]==map[10] || map[x]==map[11] || map[x]==map[18] || map[x]==map[20])
			return false;
	if(x==20)
		if(map[x]==map[0] || map[x]==map[1] || map[x]==map[2] || map[x]==map[9] || map[x]==map[10] || map[x]==map[11] || map[x]==map[18] || map[x]==map[19])
			return false;
	if(x==21)
		if(map[x]==map[3] || map[x]==map[4] || map[x]==map[5] || map[x]==map[12] || map[x]==map[13] || map[x]==map[14] || map[x]==map[22] || map[x]==map[23])
			return false;
	if(x==22)
		if(map[x]==map[3] || map[x]==map[4] || map[x]==map[5] || map[x]==map[12] || map[x]==map[13] || map[x]==map[14] || map[x]==map[21] || map[x]==map[23])
			return false;
	if(x==23)
		if(map[x]==map[3] || map[x]==map[4] || map[x]==map[5] || map[x]==map[12] || map[x]==map[13] || map[x]==map[14] || map[x]==map[21] || map[x]==map[22])
			return false;
	if(x==24)
		if(map[x]==map[6] || map[x]==map[7] || map[x]==map[8] || map[x]==map[15] || map[x]==map[16] || map[x]==map[17] || map[x]==map[25] || map[x]==map[26])
			return false;
	if(x==25)
		if(map[x]==map[6] || map[x]==map[7] || map[x]==map[8] || map[x]==map[15] || map[x]==map[16] || map[x]==map[17] || map[x]==map[24] || map[x]==map[26])
			return false;
	if(x==26)
		if(map[x]==map[6] || map[x]==map[7] || map[x]==map[8] || map[x]==map[15] || map[x]==map[16] || map[x]==map[17] || map[x]==map[24] || map[x]==map[25])
			return false;
	//
	if(x==27)
		if(map[x]==map[28] || map[x]==map[29] || map[x]==map[36] || map[x]==map[37] || map[x]==map[38] || map[x]==map[45] || map[x]==map[46] || map[x]==map[47])
			return false;
	if(x==28)
		if(map[x]==map[27] || map[x]==map[29] || map[x]==map[36] || map[x]==map[37] || map[x]==map[38] || map[x]==map[45] || map[x]==map[46] || map[x]==map[47])
			return false;
	if(x==29)
		if(map[x]==map[27] || map[x]==map[28] || map[x]==map[36] || map[x]==map[37] || map[x]==map[38] || map[x]==map[45] || map[x]==map[46] || map[x]==map[47])
			return false;
	if(x==30)
		if(map[x]==map[31] || map[x]==map[32] || map[x]==map[39] || map[x]==map[40] || map[x]==map[41] || map[x]==map[48] || map[x]==map[49] || map[x]==map[50])
			return false;
	if(x==31)
		if(map[x]==map[30] || map[x]==map[32] || map[x]==map[39] || map[x]==map[40] || map[x]==map[41] || map[x]==map[48] || map[x]==map[49] || map[x]==map[50])
			return false;
	if(x==32)
		if(map[x]==map[30] || map[x]==map[31] || map[x]==map[39] || map[x]==map[40] || map[x]==map[41] || map[x]==map[48] || map[x]==map[49] || map[x]==map[50])
			return false;
	if(x==33)
		if(map[x]==map[34] || map[x]==map[35] || map[x]==map[42] || map[x]==map[43] || map[x]==map[44] || map[x]==map[51] || map[x]==map[52] || map[x]==map[53])
			return false;
	if(x==34)
		if(map[x]==map[33] || map[x]==map[35] || map[x]==map[42] || map[x]==map[43] || map[x]==map[44] || map[x]==map[51] || map[x]==map[52] || map[x]==map[53])
			return false;
	if(x==35)
		if(map[x]==map[33] || map[x]==map[34] || map[x]==map[42] || map[x]==map[43] || map[x]==map[44] || map[x]==map[51] || map[x]==map[52] || map[x]==map[53])
			return false;
	//
	if(x==36)
		if(map[x]==map[27] || map[x]==map[28] || map[x]==map[29] || map[x]==map[37] || map[x]==map[38] || map[x]==map[45] || map[x]==map[46] || map[x]==map[47])
			return false;
	if(x==37)
		if(map[x]==map[27] || map[x]==map[28] || map[x]==map[29] || map[x]==map[36] || map[x]==map[38] || map[x]==map[45] || map[x]==map[46] || map[x]==map[47])
			return false;
	if(x==38)
		if(map[x]==map[27] || map[x]==map[28] || map[x]==map[29] || map[x]==map[36] || map[x]==map[37] || map[x]==map[45] || map[x]==map[46] || map[x]==map[47])
			return false;
	if(x==39)
		if(map[x]==map[30] || map[x]==map[31] || map[x]==map[32] || map[x]==map[40] || map[x]==map[41] || map[x]==map[48] || map[x]==map[49] || map[x]==map[50])
			return false;
	if(x==40)
		if(map[x]==map[30] || map[x]==map[31] || map[x]==map[32] || map[x]==map[39] || map[x]==map[41] || map[x]==map[48] || map[x]==map[49] || map[x]==map[50])
			return false;
	if(x==41)
		if(map[x]==map[30] || map[x]==map[31] || map[x]==map[32] || map[x]==map[39] || map[x]==map[40] || map[x]==map[48] || map[x]==map[49] || map[x]==map[50])
			return false;
	if(x==42)
		if(map[x]==map[33] || map[x]==map[34] || map[x]==map[35] || map[x]==map[43] || map[x]==map[44] || map[x]==map[51] || map[x]==map[52] || map[x]==map[53])
			return false;
	if(x==43)
		if(map[x]==map[33] || map[x]==map[34] || map[x]==map[35] || map[x]==map[42] || map[x]==map[44] || map[x]==map[51] || map[x]==map[52] || map[x]==map[53])
			return false;
	if(x==44)
		if(map[x]==map[33] || map[x]==map[34] || map[x]==map[35] || map[x]==map[42] || map[x]==map[43] || map[x]==map[51] || map[x]==map[52] || map[x]==map[53])
			return false;
	//
	if(x==45)
		if(map[x]==map[27] || map[x]==map[28] || map[x]==map[29] || map[x]==map[36] || map[x]==map[37] || map[x]==map[38] || map[x]==map[46] || map[x]==map[47])
			return false;
	if(x==46)
		if(map[x]==map[27] || map[x]==map[28] || map[x]==map[29] || map[x]==map[36] || map[x]==map[37] || map[x]==map[38] || map[x]==map[45] || map[x]==map[47])
			return false;
	if(x==47)
		if(map[x]==map[27] || map[x]==map[28] || map[x]==map[29] || map[x]==map[36] || map[x]==map[37] || map[x]==map[38] || map[x]==map[45] || map[x]==map[46])
			return false;
	if(x==48)
		if(map[x]==map[30] || map[x]==map[31] || map[x]==map[32] || map[x]==map[39] || map[x]==map[40] || map[x]==map[41] || map[x]==map[49] || map[x]==map[50])
			return false;
	if(x==49)
		if(map[x]==map[30] || map[x]==map[31] || map[x]==map[32] || map[x]==map[39] || map[x]==map[40] || map[x]==map[41] || map[x]==map[48] || map[x]==map[50])
			return false;
	if(x==50)
		if(map[x]==map[30] || map[x]==map[31] || map[x]==map[32] || map[x]==map[39] || map[x]==map[40] || map[x]==map[41] || map[x]==map[48] || map[x]==map[49])
			return false;
	if(x==51)
		if(map[x]==map[33] || map[x]==map[34] || map[x]==map[35] || map[x]==map[42] || map[x]==map[43] || map[x]==map[44] || map[x]==map[52] || map[x]==map[53])
			return false;
	if(x==52)
		if(map[x]==map[33] || map[x]==map[34] || map[x]==map[35] || map[x]==map[42] || map[x]==map[43] || map[x]==map[44] || map[x]==map[51] || map[x]==map[53])
			return false;
	if(x==53)
		if(map[x]==map[33] || map[x]==map[34] || map[x]==map[35] || map[x]==map[42] || map[x]==map[43] || map[x]==map[44] || map[x]==map[51] || map[x]==map[52])
			return false;
	//
	if(x==54)
		if(map[x]==map[55] || map[x]==map[56] || map[x]==map[63] || map[x]==map[64] || map[x]==map[65] || map[x]==map[72] || map[x]==map[73] || map[x]==map[74])
			return false;
	if(x==55)
		if(map[x]==map[54] || map[x]==map[56] || map[x]==map[63] || map[x]==map[64] || map[x]==map[65] || map[x]==map[72] || map[x]==map[73] || map[x]==map[74])
			return false;
	if(x==56)
		if(map[x]==map[54] || map[x]==map[55] || map[x]==map[63] || map[x]==map[64] || map[x]==map[65] || map[x]==map[72] || map[x]==map[73] || map[x]==map[74])
			return false;
	if(x==57)
		if(map[x]==map[58] || map[x]==map[59] || map[x]==map[66] || map[x]==map[67] || map[x]==map[68] || map[x]==map[75] || map[x]==map[76] || map[x]==map[77])
			return false;
	if(x==58)
		if(map[x]==map[57] || map[x]==map[59] || map[x]==map[66] || map[x]==map[67] || map[x]==map[68] || map[x]==map[75] || map[x]==map[76] || map[x]==map[77])
			return false;
	if(x==59)
		if(map[x]==map[57] || map[x]==map[58] || map[x]==map[66] || map[x]==map[67] || map[x]==map[68] || map[x]==map[75] || map[x]==map[76] || map[x]==map[77])
			return false;
	if(x==60)
		if(map[x]==map[61] || map[x]==map[62] || map[x]==map[69] || map[x]==map[70] || map[x]==map[71] || map[x]==map[78] || map[x]==map[79] || map[x]==map[80])
			return false;
	if(x==61)
		if(map[x]==map[60] || map[x]==map[62] || map[x]==map[69] || map[x]==map[70] || map[x]==map[71] || map[x]==map[78] || map[x]==map[79] || map[x]==map[80])
			return false;
	if(x==62)
		if(map[x]==map[60] || map[x]==map[61] || map[x]==map[69] || map[x]==map[70] || map[x]==map[71] || map[x]==map[78] || map[x]==map[79] || map[x]==map[80])
			return false;
	//
	if(x==63)
		if(map[x]==map[54] || map[x]==map[55] || map[x]==map[56] || map[x]==map[64] || map[x]==map[65] || map[x]==map[72] || map[x]==map[73] || map[x]==map[74])
			return false;
	if(x==64)
		if(map[x]==map[54] || map[x]==map[55] || map[x]==map[56] || map[x]==map[63] || map[x]==map[65] || map[x]==map[72] || map[x]==map[73] || map[x]==map[74])
			return false;
	if(x==65)
		if(map[x]==map[54] || map[x]==map[55] || map[x]==map[56] || map[x]==map[63] || map[x]==map[64] || map[x]==map[72] || map[x]==map[73] || map[x]==map[74])
			return false;
	if(x==66)
		if(map[x]==map[57] || map[x]==map[58] || map[x]==map[59] || map[x]==map[67] || map[x]==map[68] || map[x]==map[75] || map[x]==map[76] || map[x]==map[77])
			return false;
	if(x==67)
		if(map[x]==map[57] || map[x]==map[58] || map[x]==map[59] || map[x]==map[66] || map[x]==map[68] || map[x]==map[75] || map[x]==map[76] || map[x]==map[77])
			return false;
	if(x==68)
		if(map[x]==map[57] || map[x]==map[58] || map[x]==map[59] || map[x]==map[66] || map[x]==map[67] || map[x]==map[75] || map[x]==map[76] || map[x]==map[77])
			return false;
	if(x==69)
		if(map[x]==map[60] || map[x]==map[61] || map[x]==map[62] || map[x]==map[70] || map[x]==map[71] || map[x]==map[78] || map[x]==map[79] || map[x]==map[80])
			return false;
	if(x==70)
		if(map[x]==map[60] || map[x]==map[61] || map[x]==map[62] || map[x]==map[69] || map[x]==map[71] || map[x]==map[78] || map[x]==map[79] || map[x]==map[80])
			return false;
	if(x==71)
		if(map[x]==map[60] || map[x]==map[61] || map[x]==map[62] || map[x]==map[69] || map[x]==map[70] || map[x]==map[78] || map[x]==map[79] || map[x]==map[80])
			return false;
	//
	if(x==72)
		if(map[x]==map[54] || map[x]==map[55] || map[x]==map[56] || map[x]==map[63] || map[x]==map[64] || map[x]==map[65] || map[x]==map[73] || map[x]==map[74])
			return false;
	if(x==73)
		if(map[x]==map[54] || map[x]==map[55] || map[x]==map[56] || map[x]==map[63] || map[x]==map[64] || map[x]==map[65] || map[x]==map[72] || map[x]==map[74])
			return false;
	if(x==74)
		if(map[x]==map[54] || map[x]==map[55] || map[x]==map[56] || map[x]==map[63] || map[x]==map[64] || map[x]==map[65] || map[x]==map[72] || map[x]==map[73])
			return false;
	if(x==75)
		if(map[x]==map[57] || map[x]==map[58] || map[x]==map[59] || map[x]==map[66] || map[x]==map[67] || map[x]==map[68] || map[x]==map[76] || map[x]==map[77])
			return false;
	if(x==76)
		if(map[x]==map[57] || map[x]==map[58] || map[x]==map[59] || map[x]==map[66] || map[x]==map[67] || map[x]==map[68] || map[x]==map[75] || map[x]==map[77])
			return false;
	if(x==77)
		if(map[x]==map[57] || map[x]==map[58] || map[x]==map[59] || map[x]==map[66] || map[x]==map[67] || map[x]==map[68] || map[x]==map[75] || map[x]==map[76])
			return false;
	if(x==78)
		if(map[x]==map[60] || map[x]==map[61] || map[x]==map[62] || map[x]==map[69] || map[x]==map[70] || map[x]==map[71] || map[x]==map[79] || map[x]==map[80])
			return false;
	if(x==79)
		if(map[x]==map[60] || map[x]==map[61] || map[x]==map[62] || map[x]==map[69] || map[x]==map[70] || map[x]==map[71] || map[x]==map[78] || map[x]==map[80])
			return false;
	if(x==80)
		if(map[x]==map[60] || map[x]==map[61] || map[x]==map[62] || map[x]==map[69] || map[x]==map[70] || map[x]==map[71] || map[x]==map[78] || map[x]==map[79])
			return false;
	return true;
}

bool Sudoku::MAP_observeRow(int x){
	for(int i=0;i<9;i++)
		if(MAP[(x/9)*9+i]==MAP[x] && ((x/9)*9+i)!=x)
			return false;
	return true;
}

bool Sudoku::MAP_observeColumn(int x){
	for(int i=0;i<9;i++)
		if(MAP[(x%9)+i*9]==MAP[x] && ((x%9)+i*9)!=x)
			return false;
	return true;
}

bool Sudoku::MAP_observeCell(int x){
	if(x==0)
		if(MAP[x]==MAP[1] || MAP[x]==MAP[2] || MAP[x]==MAP[9] || MAP[x]==MAP[10] || MAP[x]==MAP[11] || MAP[x]==MAP[18] || MAP[x]==MAP[19] || MAP[x]==MAP[20])
			return false;
	if(x==1)
		if(MAP[x]==MAP[0] || MAP[x]==MAP[2] || MAP[x]==MAP[9] || MAP[x]==MAP[10] || MAP[x]==MAP[11] || MAP[x]==MAP[18] || MAP[x]==MAP[19] || MAP[x]==MAP[20])
			return false;
	if(x==2)
		if(MAP[x]==MAP[0] || MAP[x]==MAP[1] || MAP[x]==MAP[9] || MAP[x]==MAP[10] || MAP[x]==MAP[11] || MAP[x]==MAP[18] || MAP[x]==MAP[19] || MAP[x]==MAP[20])
			return false;
	if(x==3)
		if(MAP[x]==MAP[4] || MAP[x]==MAP[5] || MAP[x]==MAP[12] || MAP[x]==MAP[13] || MAP[x]==MAP[14] || MAP[x]==MAP[21] || MAP[x]==MAP[22] || MAP[x]==MAP[23])
			return false;
	if(x==4)
		if(MAP[x]==MAP[3] || MAP[x]==MAP[5] || MAP[x]==MAP[12] || MAP[x]==MAP[13] || MAP[x]==MAP[14] || MAP[x]==MAP[21] || MAP[x]==MAP[22] || MAP[x]==MAP[23])
			return false;
	if(x==5)
		if(MAP[x]==MAP[3] || MAP[x]==MAP[4] || MAP[x]==MAP[12] || MAP[x]==MAP[13] || MAP[x]==MAP[14] || MAP[x]==MAP[21] || MAP[x]==MAP[22] || MAP[x]==MAP[23])
			return false;
	if(x==6)
		if(MAP[x]==MAP[7] || MAP[x]==MAP[8] || MAP[x]==MAP[15] || MAP[x]==MAP[16] || MAP[x]==MAP[17] || MAP[x]==MAP[24] || MAP[x]==MAP[25] || MAP[x]==MAP[26])
			return false;
	if(x==7)
		if(MAP[x]==MAP[6] || MAP[x]==MAP[8] || MAP[x]==MAP[15] || MAP[x]==MAP[16] || MAP[x]==MAP[17] || MAP[x]==MAP[24] || MAP[x]==MAP[25] || MAP[x]==MAP[26])
			return false;
	if(x==8)
		if(MAP[x]==MAP[6] || MAP[x]==MAP[7] || MAP[x]==MAP[15] || MAP[x]==MAP[16] || MAP[x]==MAP[17] || MAP[x]==MAP[24] || MAP[x]==MAP[25] || MAP[x]==MAP[26])
			return false;
	//
	if(x==9)
		if(MAP[x]==MAP[0] || MAP[x]==MAP[1] || MAP[x]==MAP[2] || MAP[x]==MAP[10] || MAP[x]==MAP[11] || MAP[x]==MAP[18] || MAP[x]==MAP[19] || MAP[x]==MAP[20])
			return false;
	if(x==10)
		if(MAP[x]==MAP[0] || MAP[x]==MAP[1] || MAP[x]==MAP[2] || MAP[x]==MAP[9] || MAP[x]==MAP[11] || MAP[x]==MAP[18] || MAP[x]==MAP[19] || MAP[x]==MAP[20])
			return false;
	if(x==11)
		if(MAP[x]==MAP[0] || MAP[x]==MAP[1] || MAP[x]==MAP[2] || MAP[x]==MAP[9] || MAP[x]==MAP[10] || MAP[x]==MAP[18] || MAP[x]==MAP[19] || MAP[x]==MAP[20])
			return false;
	if(x==12)
		if(MAP[x]==MAP[3] || MAP[x]==MAP[4] || MAP[x]==MAP[5] || MAP[x]==MAP[13] || MAP[x]==MAP[14] || MAP[x]==MAP[21] || MAP[x]==MAP[22] || MAP[x]==MAP[23])
			return false;
	if(x==13)
		if(MAP[x]==MAP[3] || MAP[x]==MAP[4] || MAP[x]==MAP[5] || MAP[x]==MAP[12] || MAP[x]==MAP[14] || MAP[x]==MAP[21] || MAP[x]==MAP[22] || MAP[x]==MAP[23])
			return false;
	if(x==14)
		if(MAP[x]==MAP[3] || MAP[x]==MAP[4] || MAP[x]==MAP[5] || MAP[x]==MAP[12] || MAP[x]==MAP[13] || MAP[x]==MAP[21] || MAP[x]==MAP[22] || MAP[x]==MAP[23])
			return false;
	if(x==15)
		if(MAP[x]==MAP[6] || MAP[x]==MAP[7] || MAP[x]==MAP[8] || MAP[x]==MAP[16] || MAP[x]==MAP[17] || MAP[x]==MAP[24] || MAP[x]==MAP[25] || MAP[x]==MAP[26])
			return false;
	if(x==16)
		if(MAP[x]==MAP[6] || MAP[x]==MAP[7] || MAP[x]==MAP[8] || MAP[x]==MAP[15] || MAP[x]==MAP[17] || MAP[x]==MAP[24] || MAP[x]==MAP[25] || MAP[x]==MAP[26])
			return false;
	if(x==17)
		if(MAP[x]==MAP[6] || MAP[x]==MAP[7] || MAP[x]==MAP[8] || MAP[x]==MAP[15] || MAP[x]==MAP[16] || MAP[x]==MAP[24] || MAP[x]==MAP[25] || MAP[x]==MAP[26])
			return false;
	//
	if(x==18)
		if(MAP[x]==MAP[0] || MAP[x]==MAP[1] || MAP[x]==MAP[2] || MAP[x]==MAP[9] || MAP[x]==MAP[10] || MAP[x]==MAP[11] || MAP[x]==MAP[19] || MAP[x]==MAP[20])
			return false;
	if(x==19)
		if(MAP[x]==MAP[0] || MAP[x]==MAP[1] || MAP[x]==MAP[2] || MAP[x]==MAP[9] || MAP[x]==MAP[10] || MAP[x]==MAP[11] || MAP[x]==MAP[18] || MAP[x]==MAP[20])
			return false;
	if(x==20)
		if(MAP[x]==MAP[0] || MAP[x]==MAP[1] || MAP[x]==MAP[2] || MAP[x]==MAP[9] || MAP[x]==MAP[10] || MAP[x]==MAP[11] || MAP[x]==MAP[18] || MAP[x]==MAP[19])
			return false;
	if(x==21)
		if(MAP[x]==MAP[3] || MAP[x]==MAP[4] || MAP[x]==MAP[5] || MAP[x]==MAP[12] || MAP[x]==MAP[13] || MAP[x]==MAP[14] || MAP[x]==MAP[22] || MAP[x]==MAP[23])
			return false;
	if(x==22)
		if(MAP[x]==MAP[3] || MAP[x]==MAP[4] || MAP[x]==MAP[5] || MAP[x]==MAP[12] || MAP[x]==MAP[13] || MAP[x]==MAP[14] || MAP[x]==MAP[21] || MAP[x]==MAP[23])
			return false;
	if(x==23)
		if(MAP[x]==MAP[3] || MAP[x]==MAP[4] || MAP[x]==MAP[5] || MAP[x]==MAP[12] || MAP[x]==MAP[13] || MAP[x]==MAP[14] || MAP[x]==MAP[21] || MAP[x]==MAP[22])
			return false;
	if(x==24)
		if(MAP[x]==MAP[6] || MAP[x]==MAP[7] || MAP[x]==MAP[8] || MAP[x]==MAP[15] || MAP[x]==MAP[16] || MAP[x]==MAP[17] || MAP[x]==MAP[25] || MAP[x]==MAP[26])
			return false;
	if(x==25)
		if(MAP[x]==MAP[6] || MAP[x]==MAP[7] || MAP[x]==MAP[8] || MAP[x]==MAP[15] || MAP[x]==MAP[16] || MAP[x]==MAP[17] || MAP[x]==MAP[24] || MAP[x]==MAP[26])
			return false;
	if(x==26)
		if(MAP[x]==MAP[6] || MAP[x]==MAP[7] || MAP[x]==MAP[8] || MAP[x]==MAP[15] || MAP[x]==MAP[16] || MAP[x]==MAP[17] || MAP[x]==MAP[24] || MAP[x]==MAP[25])
			return false;
	//
	if(x==27)
		if(MAP[x]==MAP[28] || MAP[x]==MAP[29] || MAP[x]==MAP[36] || MAP[x]==MAP[37] || MAP[x]==MAP[38] || MAP[x]==MAP[45] || MAP[x]==MAP[46] || MAP[x]==MAP[47])
			return false;
	if(x==28)
		if(MAP[x]==MAP[27] || MAP[x]==MAP[29] || MAP[x]==MAP[36] || MAP[x]==MAP[37] || MAP[x]==MAP[38] || MAP[x]==MAP[45] || MAP[x]==MAP[46] || MAP[x]==MAP[47])
			return false;
	if(x==29)
		if(MAP[x]==MAP[27] || MAP[x]==MAP[28] || MAP[x]==MAP[36] || MAP[x]==MAP[37] || MAP[x]==MAP[38] || MAP[x]==MAP[45] || MAP[x]==MAP[46] || MAP[x]==MAP[47])
			return false;
	if(x==30)
		if(MAP[x]==MAP[31] || MAP[x]==MAP[32] || MAP[x]==MAP[39] || MAP[x]==MAP[40] || MAP[x]==MAP[41] || MAP[x]==MAP[48] || MAP[x]==MAP[49] || MAP[x]==MAP[50])
			return false;
	if(x==31)
		if(MAP[x]==MAP[30] || MAP[x]==MAP[32] || MAP[x]==MAP[39] || MAP[x]==MAP[40] || MAP[x]==MAP[41] || MAP[x]==MAP[48] || MAP[x]==MAP[49] || MAP[x]==MAP[50])
			return false;
	if(x==32)
		if(MAP[x]==MAP[30] || MAP[x]==MAP[31] || MAP[x]==MAP[39] || MAP[x]==MAP[40] || MAP[x]==MAP[41] || MAP[x]==MAP[48] || MAP[x]==MAP[49] || MAP[x]==MAP[50])
			return false;
	if(x==33)
		if(MAP[x]==MAP[34] || MAP[x]==MAP[35] || MAP[x]==MAP[42] || MAP[x]==MAP[43] || MAP[x]==MAP[44] || MAP[x]==MAP[51] || MAP[x]==MAP[52] || MAP[x]==MAP[53])
			return false;
	if(x==34)
		if(MAP[x]==MAP[33] || MAP[x]==MAP[35] || MAP[x]==MAP[42] || MAP[x]==MAP[43] || MAP[x]==MAP[44] || MAP[x]==MAP[51] || MAP[x]==MAP[52] || MAP[x]==MAP[53])
			return false;
	if(x==35)
		if(MAP[x]==MAP[33] || MAP[x]==MAP[34] || MAP[x]==MAP[42] || MAP[x]==MAP[43] || MAP[x]==MAP[44] || MAP[x]==MAP[51] || MAP[x]==MAP[52] || MAP[x]==MAP[53])
			return false;
	//
	if(x==36)
		if(MAP[x]==MAP[27] || MAP[x]==MAP[28] || MAP[x]==MAP[29] || MAP[x]==MAP[37] || MAP[x]==MAP[38] || MAP[x]==MAP[45] || MAP[x]==MAP[46] || MAP[x]==MAP[47])
			return false;
	if(x==37)
		if(MAP[x]==MAP[27] || MAP[x]==MAP[28] || MAP[x]==MAP[29] || MAP[x]==MAP[36] || MAP[x]==MAP[38] || MAP[x]==MAP[45] || MAP[x]==MAP[46] || MAP[x]==MAP[47])
			return false;
	if(x==38)
		if(MAP[x]==MAP[27] || MAP[x]==MAP[28] || MAP[x]==MAP[29] || MAP[x]==MAP[36] || MAP[x]==MAP[37] || MAP[x]==MAP[45] || MAP[x]==MAP[46] || MAP[x]==MAP[47])
			return false;
	if(x==39)
		if(MAP[x]==MAP[30] || MAP[x]==MAP[31] || MAP[x]==MAP[32] || MAP[x]==MAP[40] || MAP[x]==MAP[41] || MAP[x]==MAP[48] || MAP[x]==MAP[49] || MAP[x]==MAP[50])
			return false;
	if(x==40)
		if(MAP[x]==MAP[30] || MAP[x]==MAP[31] || MAP[x]==MAP[32] || MAP[x]==MAP[39] || MAP[x]==MAP[41] || MAP[x]==MAP[48] || MAP[x]==MAP[49] || MAP[x]==MAP[50])
			return false;
	if(x==41)
		if(MAP[x]==MAP[30] || MAP[x]==MAP[31] || MAP[x]==MAP[32] || MAP[x]==MAP[39] || MAP[x]==MAP[40] || MAP[x]==MAP[48] || MAP[x]==MAP[49] || MAP[x]==MAP[50])
			return false;
	if(x==42)
		if(MAP[x]==MAP[33] || MAP[x]==MAP[34] || MAP[x]==MAP[35] || MAP[x]==MAP[43] || MAP[x]==MAP[44] || MAP[x]==MAP[51] || MAP[x]==MAP[52] || MAP[x]==MAP[53])
			return false;
	if(x==43)
		if(MAP[x]==MAP[33] || MAP[x]==MAP[34] || MAP[x]==MAP[35] || MAP[x]==MAP[42] || MAP[x]==MAP[44] || MAP[x]==MAP[51] || MAP[x]==MAP[52] || MAP[x]==MAP[53])
			return false;
	if(x==44)
		if(MAP[x]==MAP[33] || MAP[x]==MAP[34] || MAP[x]==MAP[35] || MAP[x]==MAP[42] || MAP[x]==MAP[43] || MAP[x]==MAP[51] || MAP[x]==MAP[52] || MAP[x]==MAP[53])
			return false;
	//
	if(x==45)
		if(MAP[x]==MAP[27] || MAP[x]==MAP[28] || MAP[x]==MAP[29] || MAP[x]==MAP[36] || MAP[x]==MAP[37] || MAP[x]==MAP[38] || MAP[x]==MAP[46] || MAP[x]==MAP[47])
			return false;
	if(x==46)
		if(MAP[x]==MAP[27] || MAP[x]==MAP[28] || MAP[x]==MAP[29] || MAP[x]==MAP[36] || MAP[x]==MAP[37] || MAP[x]==MAP[38] || MAP[x]==MAP[45] || MAP[x]==MAP[47])
			return false;
	if(x==47)
		if(MAP[x]==MAP[27] || MAP[x]==MAP[28] || MAP[x]==MAP[29] || MAP[x]==MAP[36] || MAP[x]==MAP[37] || MAP[x]==MAP[38] || MAP[x]==MAP[45] || MAP[x]==MAP[46])
			return false;
	if(x==48)
		if(MAP[x]==MAP[30] || MAP[x]==MAP[31] || MAP[x]==MAP[32] || MAP[x]==MAP[39] || MAP[x]==MAP[40] || MAP[x]==MAP[41] || MAP[x]==MAP[49] || MAP[x]==MAP[50])
			return false;
	if(x==49)
		if(MAP[x]==MAP[30] || MAP[x]==MAP[31] || MAP[x]==MAP[32] || MAP[x]==MAP[39] || MAP[x]==MAP[40] || MAP[x]==MAP[41] || MAP[x]==MAP[48] || MAP[x]==MAP[50])
			return false;
	if(x==50)
		if(MAP[x]==MAP[30] || MAP[x]==MAP[31] || MAP[x]==MAP[32] || MAP[x]==MAP[39] || MAP[x]==MAP[40] || MAP[x]==MAP[41] || MAP[x]==MAP[48] || MAP[x]==MAP[49])
			return false;
	if(x==51)
		if(MAP[x]==MAP[33] || MAP[x]==MAP[34] || MAP[x]==MAP[35] || MAP[x]==MAP[42] || MAP[x]==MAP[43] || MAP[x]==MAP[44] || MAP[x]==MAP[52] || MAP[x]==MAP[53])
			return false;
	if(x==52)
		if(MAP[x]==MAP[33] || MAP[x]==MAP[34] || MAP[x]==MAP[35] || MAP[x]==MAP[42] || MAP[x]==MAP[43] || MAP[x]==MAP[44] || MAP[x]==MAP[51] || MAP[x]==MAP[53])
			return false;
	if(x==53)
		if(MAP[x]==MAP[33] || MAP[x]==MAP[34] || MAP[x]==MAP[35] || MAP[x]==MAP[42] || MAP[x]==MAP[43] || MAP[x]==MAP[44] || MAP[x]==MAP[51] || MAP[x]==MAP[52])
			return false;
	//
	if(x==54)
		if(MAP[x]==MAP[55] || MAP[x]==MAP[56] || MAP[x]==MAP[63] || MAP[x]==MAP[64] || MAP[x]==MAP[65] || MAP[x]==MAP[72] || MAP[x]==MAP[73] || MAP[x]==MAP[74])
			return false;
	if(x==55)
		if(MAP[x]==MAP[54] || MAP[x]==MAP[56] || MAP[x]==MAP[63] || MAP[x]==MAP[64] || MAP[x]==MAP[65] || MAP[x]==MAP[72] || MAP[x]==MAP[73] || MAP[x]==MAP[74])
			return false;
	if(x==56)
		if(MAP[x]==MAP[54] || MAP[x]==MAP[55] || MAP[x]==MAP[63] || MAP[x]==MAP[64] || MAP[x]==MAP[65] || MAP[x]==MAP[72] || MAP[x]==MAP[73] || MAP[x]==MAP[74])
			return false;
	if(x==57)
		if(MAP[x]==MAP[58] || MAP[x]==MAP[59] || MAP[x]==MAP[66] || MAP[x]==MAP[67] || MAP[x]==MAP[68] || MAP[x]==MAP[75] || MAP[x]==MAP[76] || MAP[x]==MAP[77])
			return false;
	if(x==58)
		if(MAP[x]==MAP[57] || MAP[x]==MAP[59] || MAP[x]==MAP[66] || MAP[x]==MAP[67] || MAP[x]==MAP[68] || MAP[x]==MAP[75] || MAP[x]==MAP[76] || MAP[x]==MAP[77])
			return false;
	if(x==59)
		if(MAP[x]==MAP[57] || MAP[x]==MAP[58] || MAP[x]==MAP[66] || MAP[x]==MAP[67] || MAP[x]==MAP[68] || MAP[x]==MAP[75] || MAP[x]==MAP[76] || MAP[x]==MAP[77])
			return false;
	if(x==60)
		if(MAP[x]==MAP[61] || MAP[x]==MAP[62] || MAP[x]==MAP[69] || MAP[x]==MAP[70] || MAP[x]==MAP[71] || MAP[x]==MAP[78] || MAP[x]==MAP[79] || MAP[x]==MAP[80])
			return false;
	if(x==61)
		if(MAP[x]==MAP[60] || MAP[x]==MAP[62] || MAP[x]==MAP[69] || MAP[x]==MAP[70] || MAP[x]==MAP[71] || MAP[x]==MAP[78] || MAP[x]==MAP[79] || MAP[x]==MAP[80])
			return false;
	if(x==62)
		if(MAP[x]==MAP[60] || MAP[x]==MAP[61] || MAP[x]==MAP[69] || MAP[x]==MAP[70] || MAP[x]==MAP[71] || MAP[x]==MAP[78] || MAP[x]==MAP[79] || MAP[x]==MAP[80])
			return false;
	//
	if(x==63)
		if(MAP[x]==MAP[54] || MAP[x]==MAP[55] || MAP[x]==MAP[56] || MAP[x]==MAP[64] || MAP[x]==MAP[65] || MAP[x]==MAP[72] || MAP[x]==MAP[73] || MAP[x]==MAP[74])
			return false;
	if(x==64)
		if(MAP[x]==MAP[54] || MAP[x]==MAP[55] || MAP[x]==MAP[56] || MAP[x]==MAP[63] || MAP[x]==MAP[65] || MAP[x]==MAP[72] || MAP[x]==MAP[73] || MAP[x]==MAP[74])
			return false;
	if(x==65)
		if(MAP[x]==MAP[54] || MAP[x]==MAP[55] || MAP[x]==MAP[56] || MAP[x]==MAP[63] || MAP[x]==MAP[64] || MAP[x]==MAP[72] || MAP[x]==MAP[73] || MAP[x]==MAP[74])
			return false;
	if(x==66)
		if(MAP[x]==MAP[57] || MAP[x]==MAP[58] || MAP[x]==MAP[59] || MAP[x]==MAP[67] || MAP[x]==MAP[68] || MAP[x]==MAP[75] || MAP[x]==MAP[76] || MAP[x]==MAP[77])
			return false;
	if(x==67)
		if(MAP[x]==MAP[57] || MAP[x]==MAP[58] || MAP[x]==MAP[59] || MAP[x]==MAP[66] || MAP[x]==MAP[68] || MAP[x]==MAP[75] || MAP[x]==MAP[76] || MAP[x]==MAP[77])
			return false;
	if(x==68)
		if(MAP[x]==MAP[57] || MAP[x]==MAP[58] || MAP[x]==MAP[59] || MAP[x]==MAP[66] || MAP[x]==MAP[67] || MAP[x]==MAP[75] || MAP[x]==MAP[76] || MAP[x]==MAP[77])
			return false;
	if(x==69)
		if(MAP[x]==MAP[60] || MAP[x]==MAP[61] || MAP[x]==MAP[62] || MAP[x]==MAP[70] || MAP[x]==MAP[71] || MAP[x]==MAP[78] || MAP[x]==MAP[79] || MAP[x]==MAP[80])
			return false;
	if(x==70)
		if(MAP[x]==MAP[60] || MAP[x]==MAP[61] || MAP[x]==MAP[62] || MAP[x]==MAP[69] || MAP[x]==MAP[71] || MAP[x]==MAP[78] || MAP[x]==MAP[79] || MAP[x]==MAP[80])
			return false;
	if(x==71)
		if(MAP[x]==MAP[60] || MAP[x]==MAP[61] || MAP[x]==MAP[62] || MAP[x]==MAP[69] || MAP[x]==MAP[70] || MAP[x]==MAP[78] || MAP[x]==MAP[79] || MAP[x]==MAP[80])
			return false;
	//
	if(x==72)
		if(MAP[x]==MAP[54] || MAP[x]==MAP[55] || MAP[x]==MAP[56] || MAP[x]==MAP[63] || MAP[x]==MAP[64] || MAP[x]==MAP[65] || MAP[x]==MAP[73] || MAP[x]==MAP[74])
			return false;
	if(x==73)
		if(MAP[x]==MAP[54] || MAP[x]==MAP[55] || MAP[x]==MAP[56] || MAP[x]==MAP[63] || MAP[x]==MAP[64] || MAP[x]==MAP[65] || MAP[x]==MAP[72] || MAP[x]==MAP[74])
			return false;
	if(x==74)
		if(MAP[x]==MAP[54] || MAP[x]==MAP[55] || MAP[x]==MAP[56] || MAP[x]==MAP[63] || MAP[x]==MAP[64] || MAP[x]==MAP[65] || MAP[x]==MAP[72] || MAP[x]==MAP[73])
			return false;
	if(x==75)
		if(MAP[x]==MAP[57] || MAP[x]==MAP[58] || MAP[x]==MAP[59] || MAP[x]==MAP[66] || MAP[x]==MAP[67] || MAP[x]==MAP[68] || MAP[x]==MAP[76] || MAP[x]==MAP[77])
			return false;
	if(x==76)
		if(MAP[x]==MAP[57] || MAP[x]==MAP[58] || MAP[x]==MAP[59] || MAP[x]==MAP[66] || MAP[x]==MAP[67] || MAP[x]==MAP[68] || MAP[x]==MAP[75] || MAP[x]==MAP[77])
			return false;
	if(x==77)
		if(MAP[x]==MAP[57] || MAP[x]==MAP[58] || MAP[x]==MAP[59] || MAP[x]==MAP[66] || MAP[x]==MAP[67] || MAP[x]==MAP[68] || MAP[x]==MAP[75] || MAP[x]==MAP[76])
			return false;
	if(x==78)
		if(MAP[x]==MAP[60] || MAP[x]==MAP[61] || MAP[x]==MAP[62] || MAP[x]==MAP[69] || MAP[x]==MAP[70] || MAP[x]==MAP[71] || MAP[x]==MAP[79] || MAP[x]==MAP[80])
			return false;
	if(x==79)
		if(MAP[x]==MAP[60] || MAP[x]==MAP[61] || MAP[x]==MAP[62] || MAP[x]==MAP[69] || MAP[x]==MAP[70] || MAP[x]==MAP[71] || MAP[x]==MAP[78] || MAP[x]==MAP[80])
			return false;
	if(x==80)
		if(MAP[x]==MAP[60] || MAP[x]==MAP[61] || MAP[x]==MAP[62] || MAP[x]==MAP[69] || MAP[x]==MAP[70] || MAP[x]==MAP[71] || MAP[x]==MAP[78] || MAP[x]==MAP[79])
			return false;
	return true;
}

int Sudoku::map_findSpace(){
	for(int i=0;i<SIZE;i++){
		if(map[i]==0)
			return i;
	}
	return -1;
}

void Sudoku::map_fillBlank(){
	int x = map_findSpace();
	if(map_findSpace()==(-1)){
		for(int m=0;m<SIZE;m++)
			remap[m] = map[m];
		record_map_result = 1;
		return;
	}
	for(int k=1;k<=9;k++){
		map[x] = k;
		if(map_observeRow(x)==false || map_observeColumn(x)==false || map_observeCell(x)==false)
			continue;
		if(map_observeRow(x)==true && map_observeColumn(x)==true && map_observeCell(x)==true)
			map_fillBlank();
	}
	map[x] = 0;
}

int Sudoku::MAP_findSpace(){
	for(int i=0;i<SIZE;i++){
		if(MAP[i]==0)
			return i;
	}
	return -1;
}

void Sudoku::MAP_fillBlank(){
	int x = MAP_findSpace();
	if(MAP_findSpace()==(-1)){
		for(int M=0;M<SIZE;M++)
			REMAP[M] = MAP[M];
		record_MAP_result = 1;
		return;
	}
	for(int k=9;k>=1;k--){
		MAP[x] = k;
		if(MAP_observeRow(x)==false || MAP_observeColumn(x)==false || MAP_observeCell(x)==false)
			continue;
		if(MAP_observeRow(x)==true && MAP_observeColumn(x)==true && MAP_observeCell(x)==true)
			MAP_fillBlank();
	}
	MAP[x] = 0;
}

void Sudoku::solve(){	
	record_map_result = 10;
	record_MAP_result = 10;
	
	int result;
	int compare;
	
	if(checkSolvable()==false)
		result = 0;
	if(checkSolvable()==true){
		map_fillBlank();
		MAP_fillBlank();

		for(int i=0;i<SIZE;i++)
			if(remap[i]==REMAP[i])
				compare++;
		if(compare<81)
			result = 2;
		else
			result = 1;
		for(int m=0;m<SIZE;m++){
			if(remap[m]==0){
				result = 0;
				break;
			}
		}
	}
	
	if(result==0)
		cout << "0" << endl;
	if(result==1){
		cout << "1" << endl;
		printOut();
	}
	if(result==2)
		cout << "2" << endl;
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
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	
	for(int i=0;i<SIZE;++i)
		printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
}

void Sudoku::printOut(){
	for(int i=0;i<SIZE;++i)
		printf("%d%c",remap[i],(i+1)%9==0?'\n':' ');
}
