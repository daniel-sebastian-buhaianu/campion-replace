#include <fstream>
#include <cstring>
#define NMAX 11
#define LGMAX_SIR 81
#define LGMAX_TXT 256
#define LGMAX_TSF 30001
using namespace std;
ifstream fin("replace.in");
ofstream fout("replace.out");
int main()
{
	int n, i;
	char f[NMAX][LGMAX_SIR], r[NMAX][LGMAX_SIR], t[LGMAX_TXT], c, *p, q[LGMAX_TSF];
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
	for (i = 0; i < n; i++)
	{
		p = t;
		do
		{
			p = strstr(p, f[i]);
			if (p)
			{
				*p = 0;
				strcpy(q, p+strlen(f[i]));
				strcat(t, r[i]);
				p = t+strlen(t);
				strcat(t, q);
			}
		} while (p);
	}
	fout << t;
	fout.close();
	return 0;
}
// scor 22
