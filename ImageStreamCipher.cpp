#include "ImageStreamCipher.h"

//Function to print a 2-D array on the console
void printarray(int **& arr,int rows, int columns)
{
	for (int j = 0; j < rows; j++)
	{
		for (int k = 0; k < columns; k++)
		{
			cout << arr[j][k];
		}
		cout << endl;
	}
	cout << endl;
}

//It takes a pointer to a pointer to an integer and makes a 2-D array out of it
//The size of the array is given as the arguments
void genmatrix(int **&matrix, int rows, int columns)
{
	matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[columns];
	}
}

//It also takes a pointer to a pointer to an integer and makes a 2-D array
//It also assign value of 1 or 0 randomly to all the elements
void genrandom(int **&arr, int rows, int columns)
{
	arr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[columns];
	}

	for (int j = 0; j < rows; j++)
	{
		for (int k = 0; k < columns; k++)
		{
			arr[j][k] = (int)(rand() % 2);
		}
	}
}

int XOR(int a, int b )
{
	if (a == b)
		return 0;
	else
		return 1;
}

void streamcipher(int **&m, int**&k, int **&e, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			e[i][j] = XOR(m[i][j], k[i][j]);
		}
	}
}

void RGB_to_grayscale( CImg<unsigned char> &RGB1, CImg<unsigned char>&grayscale)
{
	cimg_forXY(RGB1, x, y)
	{

		// want to print out the RGB value of each pixel? Uncomment the following:
		/*
		* cout << image.width() << "x" << image.height() << endl;
		* cout << "(" << x << "," << y << ") ="
		*             << " R:" << (int)image(x,y,0,0)
		*             << " G:" << (int)image(x,y,0,1)
		*             << " B:" << (int)image(x,y,0,2) << endl;
		*/

		// Separation of channels
		int R = (int)RGB1(x, y, 0, 0);
		int G = (int)RGB1(x, y, 0, 1);
		int B = (int)RGB1(x, y, 0, 2);
		// Arithmetic addition of channels for grayscale
		int grayValue = (int)(0.33*R + 0.33*G + 0.33*B);
		// saving píxel values into RGB information
		grayscale(x, y, 0, 0) = grayValue;
	}
}

void Image_to_Matrix(CImg <unsigned char> & picture, int **&matrix)
{
	matrix = new int*[picture.height()];
	for (int i = 0; i < picture.height(); i++)
	{
		matrix[i] = new int[picture.width()];
	}

	for (int i = 0; i < picture.height(); i++)
	{
		for (int j = 0; j < picture.width(); j++)
		{
			if ((int)picture(j, i) != 0)
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = 0;
			}
		}
		cout << endl;
	}
}

void Matrix_to_Image(int **&matrix, CImg<unsigned char>&picture)
{
	for (int i = 0; i < picture.height(); i++)
	{
		for (int j = 0; j < picture.width(); j++)
		{
			if (matrix[i][j] == 0)
				picture(j, i, 0, 0) = matrix[i][j];
			else
				picture(j, i, 0, 0) = 255;
		}
		cout << endl;
	}
	
}

