#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct node
{
	int info;
	struct node* pNext;
};
typedef struct node NODE;
struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void Init(LIST&);
bool IsEmpty(LIST);
NODE* GetNode(int);
void AddTail(LIST&, NODE*);
bool Inp(LIST&, string, int);
void SelectionSort(LIST&);
int NodeCount(LIST);
void Outp(LIST);
bool Outp(LIST, string);

int main()
{
	cout << "Project I05" << endl;
	LIST l;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "intdata";
		if (i < 10)
			filename += '0';
		filename += to_string(i);
		string filenameinp = filename;
		filenameinp += ".inp";
		if (Inp(l, filenameinp, i) == true)
		{
			SelectionSort(l);
			string filenameout = filename;
			filenameout += ".outp";
			Outp(l, filenameout);
			cout << "\nImport	" << filenameinp << "	successfully!";
			cout << "\nExport	" << filenameout << "	successfully!" << endl;
		}
		else cout << "\nCan't open the file " << filename << "\n";
	}
	return 1206;
}

void Init(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
bool IsEmpty(LIST l)
{
	if (l.pHead == NULL)
		return true;
	return false;
}
NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
}
void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

bool Inp(LIST& l, string filename, int i)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return false;
	int n;
	int x{};
	fi >> n;
	Init(l);
	for (int i = 1; i <= n; i++)
	{
		fi >> x;
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
	return true;
}
void SelectionSort(LIST& l)
{
	int n = NodeCount(l);
	for (NODE* p = l.pHead; p->pNext != NULL; p = p->pNext)
	{
		NODE* lcNode = p;
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
		{
			if (q->info < lcNode->info)
				lcNode = q;
		}
		if (lcNode != p)
			swap(p->info, lcNode->info);
	}
}
int NodeCount(LIST l)
{
	int counter = 0;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		counter++;
		p = p->pNext;
	}
	return counter;
}
void Outp(LIST l)
{
	NODE* p = l.pHead;
	while (p != NULL)
	{
		cout << setw(5) << p->info;
		p = p->pNext;
	}
	cout << ".";
}
bool Outp(LIST l, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return false;
	fo << setw(5) << NodeCount(l) << endl;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		fo << setw(5) << p->info;
		p = p->pNext;
	}
	return true;
}