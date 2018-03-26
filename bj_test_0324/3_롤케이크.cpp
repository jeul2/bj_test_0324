#include <stdio.h>

int main()
{
	int *pRollCake(nullptr);

	int nRollLength(0);
	int nPeopleNum(0);

	int nStartData(0);
	int nEndData(0);

	int nPredictMax(0);
	int nPredictRes(0);

	int nRealMax(0);
	int nRealTempSumData(0);
	int nRealRes(0);

	//
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &nRollLength, &nPeopleNum);

	pRollCake = new int[nRollLength + 1]{};

	for (int i = 1; i <= nPeopleNum; ++i)
	{
		scanf("%d %d", &nStartData, &nEndData);
		
		if (nEndData - nStartData + 1 > nPredictMax)
		{
			nPredictMax = nEndData - nStartData + 1;
			nPredictRes = i;
		}

		nRealTempSumData = 0;
		for (int j = nStartData; j <= nEndData; ++j)
		{
			if (pRollCake[j] == 0)
			{
				pRollCake[j] = i;
				nRealTempSumData += 1;
			}
		}
		
		if (nRealTempSumData > nRealMax)
		{
			nRealMax = nRealTempSumData;
			nRealRes = i;
		}

	}

	printf("%d\n%d\n", nPredictRes, nRealRes);

	delete[] pRollCake;
	pRollCake = nullptr;
	return 0;
}