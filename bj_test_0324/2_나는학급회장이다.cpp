#include <stdio.h>

int main()
{
	int arData[4][4]{};

	int nTestCaseNum(0);
	int nData(0);

	int nMaxTotalScore(0);
	int nMaxCount(0);
	int nMaxPeople(0);

	//
	freopen("input.txt", "r", stdin);

	scanf("%d", &nTestCaseNum);
	for (int i = 0; i < nTestCaseNum; ++i)
	{
		for (int i = 1; i <= 3; ++i)
		{
			scanf("%d", &nData);
			arData[i][nData] += 1;
		}
	}
	//
	for (int i = 1; i < 4; ++i)
	{
		arData[i][0] = 1 * arData[i][1] + 2 * arData[i][2] + 3 * arData[i][3];
	}

	nMaxTotalScore = arData[1][0];
	arData[0][0] = 1;
	for (int i = 2; i <= 3; ++i)
	{
		if (nMaxTotalScore < arData[i][0])
		{
			nMaxTotalScore = arData[i][0];
			arData[0][0] = i;
		}
	}
	
	for (int i = 1; i <= 3; ++i)
	{
		if (nMaxTotalScore == arData[i][0])
		{
			++nMaxCount;
		}
	}

	if (nMaxCount == 1)
	{
		printf("%d %d\n", arData[0][0], nMaxTotalScore);
	}
	else
	{
		nMaxCount = 0;
		nMaxPeople = arData[1][3];
		for (int i = 2; i <= 3; ++i)
		{
			if (nMaxTotalScore == arData[i][0] & nMaxPeople < arData[i][3])
			{
				nMaxPeople = arData[i][3];
			}

		}

		for (int i = 1; i <= 3; ++i)
		{
			if (nMaxPeople == arData[i][3])
			{
				++nMaxCount;
				arData[0][0] = i;
			}

		}

		if (nMaxCount == 1)
		{
			printf("%d %d\n", arData[0][0], nMaxTotalScore);

		}
		else
		{
			nMaxCount = 0;
			nMaxPeople = arData[1][2];
			for (int i = 2; i <= 3; ++i)
			{
				if (nMaxTotalScore == arData[i][0] & nMaxPeople < arData[i][2])
				{
					nMaxPeople = arData[i][2];
				}

			}

			for (int i = 1; i <= 3; ++i)
			{
				if (nMaxPeople == arData[i][2])
				{
					++nMaxCount;
					arData[0][0] = i;
				}

			}

			if (nMaxCount == 1)
			{
				printf("%d %d\n", arData[0][0], nMaxTotalScore);

			}
			else
			{
				printf("%d %d\n", 0, nMaxTotalScore);
			}

		}

	}


	return 0;
}
