#ifndef AIR_WEAVER_SOP_AITAG_H_
#define AIR_WEAVER_SOP_AITAG_H_

#include <string>

struct AITag
{
	int id;
	int order;
	string name;

	AITag()
	{
		clear();
	}

	void clear()
	{
		id = -1;
		order = -1;
		name = "";
	}
};

#endif // AIR_WEAVER_SOP_AITAG_H_