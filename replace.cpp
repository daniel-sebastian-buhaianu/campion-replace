#include <fstream>
#include <cstring>
#define NMAX 11
#define LGMAX_SIR 81
#define LGMAX_TXT 256
#define LGMAX_AUX 30001
using namespace std;
ifstream fin("replace.in");
ofstream fout("replace.out");
int main()
{
	int n, i;
	char f[NMAX][LGMAX_SIR], r[NMAX][LGMAX_SIR];
	char t[LGMAX_TXT], aux[LGMAX_AUX], *p, q[LGMAX_AUX];
	char c;
	fin >> n;
	fin.get(c);
	for (i = 0; i < n; i++)
	{
		fin.getline(f[i], LGMAX_SIR);
		if (strlen(f[i]) < 1)
		{
			strcpy(f[i], " ");
		}
		fin.getline(r[i], LGMAX_SIR);
		if (strlen(r[i]) < 1)
		{
			strcpy(r[i], " ");
		}
	}
	fin.getline(t, LGMAX_TXT);
	fin.close();
	strcpy(aux, t);
	for (i = 0; i < n; i++)
	{
		p = aux;
		do
		{
			p = strstr(p, f[i]);
			if (p)
			{
				*p = 0;
				strcpy(q, p+strlen(f[i]));
				strcat(aux, r[i]);
				p = aux+strlen(aux);
				strcat(aux, q);
			}
		} while (p);
	}
	strcpy(t, aux);
	fout << t;
	fout.close();
	return 0;
}
// scor 44
