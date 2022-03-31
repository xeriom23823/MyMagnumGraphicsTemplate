#ifndef AIR_WEAVER_SOP_VOICECOMMAND_H_
#define AIR_WEAVER_SOP_VOICECOMMAND_H_

#include <vector>
#include "MoveTo.h"

using namespace std;

struct VoiceCommand
{
	string command_word;
	MoveTo move_to;

	VoiceCommand()
	{
		command_word = "Next step";
	}

	void clearObject()
	{
		command_word = "Next step";
		move_to.clearObject();
	}

	VoiceCommand &operator=(const VoiceCommand &source)
	{
		if (this == &source)
		{
			return *this;
		}
		command_word = source.command_word;
		move_to.text = source.move_to.text;
		move_to.sub_text = source.move_to.sub_text;
		move_to.key = source.move_to.key;
		move_to.specific_move_to = source.move_to.specific_move_to;
		return *this;
	}
};

#endif // AIR_WEAVER_SOP_VOICECOMMAND_H_