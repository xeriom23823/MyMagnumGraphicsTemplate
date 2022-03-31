#ifndef AIR_WEAVER_SOP_STEP_H_
#define AIR_WEAVER_SOP_STEP_H_

#include "Group.h"
#include "ADATObject.h"
#include "Procedure.h"
#include "StyleInformation.h"
#include "SUPER.h"
#include "AIRCC.h"

#define FREE_POINTER(lpptr) \
	{                       \
		if (lpptr != NULL)  \
		{                   \
			delete lpptr;   \
			lpptr = NULL;   \
		}                   \
	}
#define RANGE                \
	{                        \
		{}, Vector2 { 1.0f } \
	}
#define UV0 ImVec2(0.0f, 1.0f)
#define UV1 ImVec2(1.0f, 0.0f)
#define UNDO 0
#define REDO 1
#define preview_icons_number 3
#define step_icons_number 4
#define object3Doperate_icons_number 3
#define step_object_type_number 20
#define step_flag_number 20
#define general_icons_number 18

enum class StepIcons
{
	kIconPositioning = 0,
	kExclamationMar,
	kCompleted,
	kIconTime
};

enum class StepFlag
{
	kGroup = 0,
	kChild,
	kHasBeenEdited,
	kCompleted,
	kAAN,
	kActive,
	kPressed,
	kFirstStep,
	kLastStep,
	kHasContionalStep,
	kQcReport
};

class Step
{
public:
	Step();
	~Step();

	string step_s;
	string title;
	string name;
	unsigned int key;
	unsigned int depth;
	unsigned int children;
	bool step_flags[step_flag_number];
	bool step_object_flag[step_object_type_number];

	vector<float> camera_pos;
	list<ADATObject *> ar_object_list;
	list<ADATObject *> hud_object_list;

	SUPER super_format;

	void UpdateObjectExistFlag();

private:
	void ClearObjectList();
	void ClearHUDList();
};

#endif // AIR_WEAVER_SOP_STEP_H_