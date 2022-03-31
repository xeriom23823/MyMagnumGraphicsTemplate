#ifndef AIR_WEAVER_SOP_AIMODEL_H_
#define AIR_WEAVER_SOP_AIMODEL_H_

#include <vector>
#include "AITag.h"

struct AIModel
{
    int id;
    string name;
	string description;
	vector<AITag> ai_tags;

	AIModel()
	{
		clear();
	}

    void clear()
    {
        id = -1;
		name = "";
		description = "";
		ai_tags.clear();
    }
};

#endif  // AIR_WEAVER_SOP_AIMODEL_H_