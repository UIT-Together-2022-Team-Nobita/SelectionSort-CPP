#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

bool Input(int[][1000], int&, int&, string);
void SelectionSort(int[][1000], int, int);
bool Output(int[][1000], int, int, string);

int main()
{
	static int mat[1000][1000];
	int m, n;
	cout << "Project I04" << endl;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "intmatrixdata";
		if (i < 10)
			filename += '0';
		filename += to_string(i);
		string filenameinp = filename;
		filenameinp += ".inp";
		if (Input(mat, m, n, filenameinp) == true)
		{
			SelectionSort(mat, m, n);
			string filenameout = filename;
			filenameout += ".outp";
			Output(mat, m, n, filenameout);
			cout << "\nImport	" << filenameinp << "	successfully!";
			cout << "\nExport	" << filenameout << "	successfully!" << endl;
		}
		else
			cout << "\nCan't open the file " << filename << endl;
	}
	cout << endl;
	return 1206;
}

bool Input(int mat[][1000], int& m, int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return false;
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> mat[i][j];
	return true;
}
void SelectionSort(int mat[][1000], int m, int n)
{
	for (int i = 0; i <= m * n - 2; i++)
	{
		int lc = i;
		for (int j = i; j <= m * n - 1; j++)
			if (mat[j / n][j % n] < mat[lc / n][lc % n])
				lc = j;
		swap(mat[i / n][i % n], mat[lc / n][lc % n]);
	}		
}
bool Output(int mat[][1000], int m, int n, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return false;
	fo << setw(5) << m << setw(5) << n << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			fo << setw(5) << mat[i][j];
		fo << endl;
	}
	return true;
}