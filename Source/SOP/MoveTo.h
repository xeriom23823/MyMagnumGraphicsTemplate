#ifndef AIR_WEAVER_SOP_MOVETO_H_
#define AIR_WEAVER_SOP_MOVETO_H_

#include <string>

struct MoveTo
{
	string text;
	string sub_text;
	string key;
	string specific_move_to;

	MoveTo()
	{
		text = "";
		key = "";
		sub_text = "";
		specific_move_to = "0";
	}

	void clearObject()
	{
		text = "";
		key = "";
		sub_text = "";
		specific_move_to = "0";
	}

	MoveTo &operator=(const MoveTo &source)
	{
		if (this == &source)
		{
			return *this;
		}
		text = source.text;
		sub_text = source.sub_text;
		key = source.key;
		specific_move_to = source.specific_move_to;
		return *this;
	}
};

#endif // AIR_WEAVER_SOP_MOVETO_H_