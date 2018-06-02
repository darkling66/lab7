#include "stdafx.h"
#include "matrix.h"

Matrix::Matrix(int row, int col)
{
	rows = row;
	cols = col;
	creatematrix();
	return;
};

Matrix::~Matrix()
{
	for (int i = 0; i<this->rows; i++)
		delete[] this->intdata[i];
	delete[] this->intdata;
};

bool Matrix::creatematrix()
{
	if (!(this->rows>0 && this->cols>0))
		return false;
	this->intdata = new int*[this->rows];
	for (int i = 0; i<this->rows; i++)
		this->intdata[i] = new int[this->cols];
	return true;
};

void Matrix::fill()
{
	srand(time(0));
	for (int j = 0; j<rows; j++)
	{
		for (int i = 0; i<cols; i++)
		{
			intdata[j][i] = rand() % 10;
		};
	}
	return;
};

void Matrix::display(int x, int y, int x1, int y1)
{
	if (x<0 || y< 0 || x1<0 || y1<0 || x >= cols || x1 >= cols || y >= rows || y1 >= rows) {
		cout << "Matrix:\n";
		for (int j = 0; j<rows; j++) {
			cout << "Row:" << j + 1 << ">";
			for (int i = 0; i<cols; i++) {
				cout << " " << intdata[j][i];
			}
			puts("");
		}
	}
	else {
		cout << "Matrix: " << "(" << x << "," << y << ") - (" << x1 << "," << y1 << ")" << endl;
		for (int j = y; j<y1; j++) {
			cout << "Row:" << j << ">";
			for (int i = x; i<x1; i++) {
				cout << " " << intdata[j][i];
			}
			puts("");
		}
	}
	return;
};

int tab_handler1(void* p) {
	return matrix_ful();
}

int tab_handler2(void* p) {
	return matrix_part();
}

int matrix_ful() {
	int row, col;
	cout << "Enter number of rows: ";
	cin >> row;
	cout << "Enter number of cols: ";
	cin >> col;
	Matrix Matrix1(row, col);
	Matrix1.fill();
	Matrix1.display(-1, -1, -1, -1);
	return 0;
}

int matrix_part() {
	int row, col, x, y, x1, y1;
	cout << "Enter number of rows: ";
	cin >> row;
	cout << "Enter number of cols: ";
	cin >> col;
	cout << "Enter rows from to: ";
	cin >> y >> y1;
	cout << "Enter cols from to: ";
	cin >> x >> x1;
	Matrix Matrix1(row, col);
	Matrix1.fill();
	Matrix1.display(x, y, x1, y1);
	return 0;
}
