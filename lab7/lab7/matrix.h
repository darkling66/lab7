#pragma once
typedef int(*handler_t)(void*);

int menu(const char* menu_items[]);
int tab_handler1(void* p);
int tab_handler2(void* p);
int matrix_ful();
int matrix_part();

class Matrix
{
private:
	int rows;
	int cols;
	int **intdata;
	bool creatematrix();
public:
	Matrix(int row = 1, int col = 1);
	~Matrix(void);
	void display(int x, int y, int x1, int y1);
	void fill();
};