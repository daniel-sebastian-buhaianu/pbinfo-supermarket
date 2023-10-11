#include <fstream>

#define NMAX 100000
#define XMAX 1000000

using namespace std;

ifstream fin("supermarket.in");
ofstream fout("supermarket.out");

int nrcasa[XMAX+1];

int main()
{
	int n, inc1, inc2, sf1, sf2, i, nrc1, nrc2, instr, x, j;

	fin >> n;

	int casa1[n], casa2[n];

	inc1 = inc2 = 0;
	sf1 = sf2 = -1;

	for (i = 0; i < n; i++)
	{
		fin >> instr;

		nrc1 = sf1-inc1+1;
		nrc2 = sf2-inc2+1;

		switch (instr)
		{
			case 1:
				if (nrc1 == 0)
				{
					fout << -1;
				}
				else
				{
					x = casa1[inc1++];

					fout << x;

					nrcasa[x] = 0;

					if (inc1 > sf1)
					{
						inc1 = 0;
						sf1 = -1;
					}
				}

				fout << '\n';

				break;
			case 2:
				if (nrc2 == 0)
				{
					fout << -1;
				}
				else
				{
					x = casa2[inc2++];

					fout << x;

					nrcasa[x] = 0;

					if (inc2 > sf2)
					{
						inc2 = 0;
						sf2 = -1;
					}
				}

				fout << '\n';

				break;
			case 3:
				fin >> x;

				if (nrc1 <= nrc2)
				{
					casa1[++sf1] = x;

					nrcasa[x] = 1;
					
					fout << 1;
				}
				else
				{
					casa2[++sf2] = x;

					nrcasa[x] = 2;

					fout << 2;
				}

				fout << '\n';

				break;
			case 4:
				fin >> x;

				if (nrcasa[x] == 1)
				{
					for (j = inc1; j <= sf1; j++)
					{
						if (casa1[j] == x)
						{
							break;
						}
					}

					for (; j < sf1; j++)
					{
						casa1[j] = casa1[j+1];
					}

					sf1--;
				}
				else
				{
					for (j = inc2; j <= sf2; j++)
					{
						if (casa2[j] == x)
						{
							break;
						}
					}

					for (; j < sf2; j++)
					{
						casa2[j] = casa2[j+1];
					}

					sf2--;
				}

				nrcasa[x] = 0;

				break;
		}
	}

	fin.close();

	fout.close();

	return 0;
}
// scor 100
