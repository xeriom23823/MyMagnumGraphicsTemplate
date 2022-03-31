#ifndef AIR_WEAVER_SOP_GROUP_H_
#define AIR_WEAVER_SOP_GROUP_H_

#include <string>

using namespace std;

struct Group
{
	string key;
	string name;
	string next_group_key;
	string previous_group_key;
	string entry_group_key;

	Group()
	{
		key = "";
		name = "";
		next_group_key = "";
		previous_group_key = "";
		entry_group_key = "";
	}
};

#endif // AIR_WEAVER_SOP_GROUP_H_