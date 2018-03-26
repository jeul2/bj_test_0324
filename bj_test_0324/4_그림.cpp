#include <stdio.h>

enum
{
	E_MAXARRAY = 1000
};

struct S_POSITION
{
	int nRow;
	int nCol;
};

S_POSITION g_arQueue[E_MAXARRAY]{};
int g_nHead(0);
int g_nTail(-1);
int g_nSize(0);

void enqueue(int nRow, int nCol);
void dequeue(int *pRow, int *pCol);

bool checkArrayRange(int nRow, int nCol, int nMaxRow, int nMaxCol);
void printArray(int **ppSrc, int nMaxRow, int nMaxCol);

int main()
{
	int **ppData(nullptr);
	int nInputCol(0); int nInputRow(0);

	int nCountPicture(0);
	int nRow(0); int nCol(0);
	int nSizeTempPicture(0);
	int nMaxPictureSize(0);

	int nFlagRow[4] = { 1, -1, 0, 0 };
	int nFlagCol[4] = { 0, 0, 1, -1 };

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &nInputRow, &nInputCol);
	ppData = new int*[nInputRow] {};
	for (int i = 0; i < nInputRow; ++i)
	{
		ppData[i] = new int[nInputCol] {};
	}

	for (int i = 0; i < nInputRow; ++i)
	{
		for (int j = 0; j < nInputCol; ++j)
		{
			scanf("%d", &ppData[i][j]);
		}
	}

	for (int i = 0; i < nInputRow; ++i)
	{
		for (int j = 0; j < nInputCol; ++j)
		{
			if (ppData[i][j] == 1)
			{
				//BFS();
				nSizeTempPicture = 0;

				enqueue(i, j);
				ppData[i][j] = 2;
				++nSizeTempPicture;

				while (g_nSize != 0)
				{
					dequeue(&nRow, &nCol);

					for (int k = 0; k < 4; ++k)
					{
						if (checkArrayRange(nRow + nFlagRow[k], nCol + nFlagCol[k], nInputRow, nInputCol) == true)
						{
							if (ppData[nRow + nFlagRow[k]][nCol + nFlagCol[k]] == 1)
							{
								enqueue(nRow + nFlagRow[k], nCol + nFlagCol[k]);

								ppData[nRow + nFlagRow[k]][nCol + nFlagCol[k]] = 2;
								++nSizeTempPicture;
							}
						}
					}
					


				}
				
				//printArray(ppData, nInputRow, nInputCol);
				//printf("<%d>\n", nSizeTempPicture);

				if (nSizeTempPicture > nMaxPictureSize)
					nMaxPictureSize = nSizeTempPicture;

				//
				++nCountPicture;
			}
		}
	}

	printf("%d\n%d\n", nCountPicture, nMaxPictureSize);

	for (int i = 0; i < nInputRow; ++i)
	{
		delete[] ppData[i];
		ppData[i] = nullptr;
	}
	delete[] ppData;
	ppData = nullptr;

	return 0;
}

void enqueue(int nRow, int nCol)
{
	if (g_nSize > E_MAXARRAY)
	{
		printf("overflow\n");
		return;
	}
	if (g_nTail == E_MAXARRAY - 1)
	{
		g_nTail = -1;
	}
	++g_nTail;
	g_arQueue[g_nTail].nRow = nRow;
	g_arQueue[g_nTail].nCol = nCol;
	++g_nSize;
}

void dequeue(int * pRow, int * pCol)
{
	if (g_nSize <= 0)
	{
		printf("underflow\n");
		return;
	}
	if (g_nHead == E_MAXARRAY)
	{
		g_nHead = 0;
	}

	*pRow = g_arQueue[g_nHead].nRow;
	*pCol = g_arQueue[g_nHead].nCol;
	g_arQueue[g_nHead].nRow = 0;
	g_arQueue[g_nHead].nCol = 0;
	++g_nHead;
	--g_nSize;
}

bool checkArrayRange(int nRow, int nCol, int nMaxRow, int nMaxCol)
{
	if (nRow >= 0 && nRow < nMaxRow && nCol >= 0 && nCol < nMaxCol)
	{
		return true;
	}
	else
		return false;
}

void printArray(int ** ppSrc, int nMaxRow, int nMaxCol)
{
	for (int i = 0; i < nMaxRow; ++i)
	{
		for (int j = 0; j < nMaxCol; ++j)
		{
			printf("[%d]", ppSrc[i][j]);
		}
		printf("\n");
	}
	printf("--------\n");
}
