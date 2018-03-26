#include <stdio.h>

int main()
{
	int *pArray(nullptr);
	int nInputSize(0);
	int nData(0);
	long int nSumData(0L);

	int nDivisor(0);
	int nRes(0);
	//
	freopen("input.txt", "r", stdin);

	scanf("%d", &nInputSize);
	pArray = new int[nInputSize] {};
	for (int i = 0; i < nInputSize; ++i)
	{
		for (int j = 0; j < nInputSize; ++j)
		{
			scanf("%d", &nData);
			pArray[i] += nData;
			nSumData += nData;
		}
	}

	if (nInputSize == 2)
	{
		for (int i = 0; i < nInputSize; ++i)
		{
			printf("%d ", pArray[i] / 2);
		}
		printf("\n");
		return 0;
	}

	nDivisor = 2 * nInputSize - 2;
	nSumData = nSumData / nDivisor;
	
	for (int i = 0; i < nInputSize; ++i)
	{
		nRes = pArray[i] - nSumData;
		nRes = nRes / (nInputSize - 2);
		printf("%d ", nRes);
	}
	printf("\n");

	delete[] pArray;
	pArray = nullptr;

	return 0;
}