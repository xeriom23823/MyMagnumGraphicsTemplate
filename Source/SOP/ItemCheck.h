#ifndef AIR_WEAVER_SOP_ITEMCHECK_H_
#define AIR_WEAVER_SOP_ITEMCHECK_H_

#include "MoveTo.h"

struct ItemCheck
{
	bool used;
	MoveTo pass;
	MoveTo fail;

	ItemCheck()
	{
		used = false;
	}
    
	ItemCheck &operator=(const ItemCheck &source)
	{
		if (this == &source)
		{
			return *this;
		}
		pass = source.pass;
		fail = source.fail;

		return *this;
	}
};

#endif // AIR_WEAVER_SOP_ITEMCHECK_H_