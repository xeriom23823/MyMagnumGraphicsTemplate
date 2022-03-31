#ifndef AIR_WEAVER_SOP_LOGICNODE_H_
#define AIR_WEAVER_SOP_LOGICNODE_H_

#include <string>
#include <vector>

using namespace std;

enum class LogicNodeType
{
	kTag = 0,
	kAnd,
	kOr,
	kNot,
	kTrigger
};

struct LogicNode
{
	int id;
	LogicNodeType type;
	string name;
	int tag_id;
	int confidence_threshold;
	int frame_threshold;
	vector<int> position;
	vector<int> vecInput;

	LogicNode()
	{
		position = {0, 0};
		vecInput.clear();
	}
};

#endif // AIR_WEAVER_SOP_LOGICNODE_H_