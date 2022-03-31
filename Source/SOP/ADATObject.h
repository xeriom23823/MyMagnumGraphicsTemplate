#ifndef AIR_WEAVER_SOP_ADATOBJECT_H_
#define AIR_WEAVER_SOP_ADATOBJECT_H_

#include <list>

#include "AIKit.h"
#include "AudioInformation.h"
#include "ItemCheck.h"
#include "VoiceCommand.h"

enum class ADATObjectType
{
	kNone = -1,
	kSentence,
	kPicture,
	kRectangle,
	kButton,
	kText,
	kAudio,
	kAI,
	kHud,
	kHudVoice,
	kSetPoint,
	kCircle,
	kContionalStep,
	kSopCard,
	kCube,
	kModel,
	kAnchor,
	kInteraction,
	kTarget
};

struct ADATObject
{
	bool is_show;

	ADATObjectType type;
	string caption;
	string file_name;
	string sop_card_size;
	string shape;
	string mProjectionType;
	string content;

	vector<float> position;
	vector<float> rotation;
	vector<float> scale;

	ItemCheck item_check;
	AudioInformation audio_information;

	list<VoiceCommand *> voice_command_list;
	vector<AIKit *> ai_kits;

	ADATObject()
	{
		is_show = false;
		type = ADATObjectType::kNone;
		caption = "";
		file_name = "";
		sop_card_size = "";
		shape = "";
		mProjectionType = "";
		content = "";

		position = {0.0f, 0.0f, 0.0f};
		rotation = {0.0f, 0.0f, 0.0f};
		scale = {1.0f, 1.0f, 1.0f};
	}
};

#endif // AIR_WEAVER_SOP_ADATOBJECT_H_