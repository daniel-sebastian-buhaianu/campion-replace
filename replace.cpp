#include <fstream>
#include <cstring>
#define NMAX 11
#define LGMAX_SIR 81
#define LGMAX_TXT 30001
using namespace std;
ifstream fin("replace.in");
ofstream fout("replace.out");
struct regula
{
	char f[LGMAX_SIR], r[LGMAX_SIR];
};
void citesteDateIntrare(int &, regula [], char []);
void aplicaRegula(int, regula [], char []);
void afiseazaRezultat(char []);
int main()
{
	int n, i;
	regula R[NMAX];
	char t[LGMAX_TXT];
	citesteDateIntrare(n, R, t);
	for (i = 0; i < n; i++)
	{
		aplicaRegula(i, R, t);
	}
	afiseazaRezultat(t);
	return 0;
}
void citesteDateIntrare(int & n, regula R[NMAX], char t[LGMAX_TXT])
{
	fin >> n; fin.get();
	for (int i = 0; i < n; i++)
	{
		fin.getline(R[i].f, LGMAX_SIR);
		if (strlen(R[i].f) < 1)
		{
			strcpy(R[i].f, " ");
		}
		fin.getline(R[i].r, LGMAX_SIR);
	}
	fin.getline(t, LGMAX_TXT);
	fin.close();
}
void aplicaRegula(int i, regula R[NMAX], char t[LGMAX_TXT])
{
	int lgf = strlen(R[i].f);
	while (char *p = strstr(t, R[i].f))
	{
		char aux[LGMAX_TXT];
		strcpy(aux, p+lgf);
		*p = 0;
		strcat(t, R[i].r);
		strcat(t, aux);
	}
}
void afiseazaRezultat(char t[LGMAX_TXT])
{
	fout << t;
	fout.close();
}
// scor 100
