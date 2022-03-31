#ifndef AIR_WEAVER_SOP_AIKIT_H_
#define AIR_WEAVER_SOP_AIKIT_H_

#include <string>
#include <vector>
#include "LogicNode.h"

using namespace std;

enum class AIKitType
{
	kNormal,
	kAnomaly
};

struct AIKit
{
	int trigger_id;
	string event_name;
	string event_description;
    int ai_sop_id;
	string ai_sop;
    int ai_model_id;
	string ai_model_name;
	bool normal_detected;

	LogicNode* result_trigger;
	vector<LogicNode *> ai_tags;
	vector<LogicNode *> ai_logics;

	AIKit()
	{
		trigger_id = -1;
		event_name = "";
		event_description = "";
        ai_sop_id = -1;
		ai_sop = "";
        ai_model_id = -1;
		ai_model_name = "";
		normal_detected = false;
	}
};

#endif // AIR_WEAVER_SOP_AIKIT_H_