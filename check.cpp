#include "lib.h"

int checkCorr(char *buf)
{
	short i=0;
	while(buf[i]!='\0')
	{
		if (buf[i]<'A' || buf[i]>'Z')
		{
			if (buf[i]<'a' || buf[i]>'z')
			{
				if (buf[i]<'�' || buf[i]>'�')
				{	if (buf[i]!=32) //interval
						return 1;
				}
			}
		}
		i++;
	}
	return 0;
}
