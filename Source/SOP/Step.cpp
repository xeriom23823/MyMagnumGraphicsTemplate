#include "Step.h"

Step::Step()
{
	title = "";
	name = "";
	key = 0;
	depth = 0;
	children = 0;
	camera_pos = vector<float>(6, 0.0f);

	memset(step_flags, false, sizeof(step_flags));
	memset(step_object_flag, false, sizeof(step_object_flag));
}

Step::~Step()
{
	ClearObjectList();
	ClearHUDList();
}

void Step::UpdateObjectExistFlag()
{
	memset(step_object_flag, false, sizeof(step_object_flag));
	list<ADATObject *>::iterator it = ar_object_list.begin();
	while (it != ar_object_list.end())
	{
		step_object_flag[(int)(*it)->type] = true;
		it++;
	}
	it = hud_object_list.begin();
	while (it != hud_object_list.end())
	{
		step_object_flag[(int)(*it)->type] = true;
		it++;
	}
}

void Step::ClearObjectList(){
	for(ADATObject* obj : ar_object_list){
		delete obj;
	}
	ar_object_list.clear();
}

void Step::ClearHUDList(){
	for(ADATObject* HUD : hud_object_list){
		delete HUD;
	}
	hud_object_list.clear();
}