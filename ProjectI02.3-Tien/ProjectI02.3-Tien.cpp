#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

bool Input(int[], int&, string);
void SelectionSort(int[], int);
bool Output(int[], int, string);

int main()
{
	static int a[1000000];
	int n;
	cout << "Project I02.3" << endl;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "intdata";
		if (i < 10)
			filename += '0';
		filename += to_string(i);
		string filenameinp = filename;
		filenameinp += ".inp";
		if (Input(a, n, filenameinp) == true)
		{
			SelectionSort(a, n);
			string filenameout = filename;
			filenameout += ".outp";
			Output(a, n, filenameout);
			cout << "\nImport	" << filenameinp << "	successfully!";
			cout << "\nExport	" << filenameout << "	successfully!" << endl;
		}
		else
			cout << "\nCan't open the file " << filename << endl;
	}
	cout << endl;
	return 1206;
}

bool Input(int a[], int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return false;
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
	return true;
}

void SelectionSort(int a[], int n)
{
	for (int i = n - 1; i >= 1; i--)
	{
		int lc = i;
		for (int j = i - 1; j >= 0; j--)
			if (a[j] < a[lc])
				lc = j;
		swap(a[i], a[lc]);
	}
}

bool Output(int a[], int n, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return false;
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; i++)
		fo << setw(5) << a[i];
	return true;
}