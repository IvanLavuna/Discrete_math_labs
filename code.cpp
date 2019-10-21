
#include<iostream>
#include<math.h>
#include <string> 
#include<algorithm>

using namespace std;

bool is_reflecsive(bool matrix[100][100], int size) //перевіряє на рефлексивність
{
	for (int i = 0;i < size;i++) {
		if (matrix[i][i] == false) {
			return false;
		}
	}
	return true;

}

bool is_symmetric(bool matrix[100][100], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int  j = 0; j < size; j++)
		{
			if (matrix[i][j] != matrix[j][i])
			{
				return false;
			}
		}
	}

	return true;
}

bool is_transitiv(bool matrix[100][100], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0;j < size;j++)
		{
			if (matrix[i][j] == 1) 
			{
				for (int q = 0;q < size;q++)
				{
					if (matrix[j][q] == 1)
					{
						if (matrix[i][q] != 1) {
							return false;
						}
					}
				}
			}
		}
	}

	return true;

}

void get_relation_mtrx(int matrix[2][100], bool relation_mtrx[100][100],int size)
{

	for (int i = 0;i < size;i++) 
	{
		for (int j = 0; j < size; j++)
		{
			if (2 * matrix[0][j] + 1 < matrix[1][i]) 
			{
				relation_mtrx[i][j] = true;
			}
			else {
				relation_mtrx[i][j] = false;
			}

		}
	}


}

void cin_matrix(int arr[2][100], int size) 
{
	cout << "Write your first set : ";
	
	for (int i = 0;i < size;i++) 
	{
		cin >> arr[0][i];
	}
	cout << "Write your second set : ";
	
	for (int i = 0;i < size;i++)
	{
		cin >> arr[1][i];
	}

	cout << endl;
}

void see_relation_matrix(bool matrix[100][100],int size) 
{
	for (int i = 0;i < size;i++) 
	{
		for (int j = 0;j < size;j++) 
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	int matrix[2][100];
	
	int size;
	
	cout << "write size of matrix: ";

	cin >> size;

	cin_matrix(matrix, size); // cin 2 sets in matrix

	bool relation_mtrx[100][100]; // my matrix of zeros and ones

	get_relation_mtrx(matrix, relation_mtrx, size);

	see_relation_matrix(relation_mtrx, size);

	// test matrixes for checking
	bool test1[100][100] = { {1,0,1,0,1},  
							 {1,1,0,1,0},
							 {1,0,1,0,1},
							 {1,1,1,0,0},
							 {0,0,0,1,0} };

	bool test2[100][100] = { {1,1,0,0,0},
							 {1,1,0,0,0},
							 {0,0,0,0,0},
							 {0,0,0,0,0},
							 {0,0,0,0,0} };

	bool test3[100][100] = { {1,1,1,1,0},
							 {1,0,1,1,0},
							 {1,1,1,1,0},
							 {1,1,1,0,1},
							 {0,0,0,1,0} };

	
}


