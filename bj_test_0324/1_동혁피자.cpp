#include <stdio.h>

int main()
{
	int nData(0);
	int nRadius(0);
	int nWidth(0);
	int nHeight(0);

	int nSrcSquareValue(0);
	int nResSquareValue(0);
	int nCount(1);
	//
	freopen("input.txt", "r", stdin);
	scanf("%d", &nData);
	while (nData != 0)
	{
		nRadius = nData;
		scanf("%d %d", &nWidth, &nHeight);
		//
		nRadius *= 2;
		nSrcSquareValue = nRadius * nRadius;
		nResSquareValue = nWidth * nWidth + nHeight * nHeight;

		printf("Pizza %d ", nCount);
		++nCount;
		if (nSrcSquareValue >= nResSquareValue)
		{
			printf("fits on the table.\n");
		}
		else
		{
			printf("does not fit on the table.\n");
		}

		//
		scanf("%d", &nData);
	}
	
	return 0;
}