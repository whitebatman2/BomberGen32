#ifndef BOMBER_HELPERS
#define BOMBER_HELPERS

#include <stdint.h>


namespace Bomber
{
	void multiAdd(char pass[20], int from, int to, int addition)
	{
		if (from < 0 || to > 20)
			return;

		for (int i = from; i <= to; i++)
		{
			pass[i] += addition;
			
			if (pass[i] < 0)
			{
				pass[i] = pass[i] % 16 + 16;
			}
			if (pass[i] > 15)
			{
				pass[i] = pass[i] % 16;
			}
		}
	}

	void singleAdd(char pass[20], int pos, int addition)
	{
		multiAdd(pass, pos, pos, addition);
	}
}


#endif//BOMBER_HELPERS
