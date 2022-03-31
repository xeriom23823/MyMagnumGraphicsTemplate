#ifndef AIR_WEAVER_SOP_AUDIOINFORMATION_H_
#define AIR_WEAVER_SOP_AUDIOINFORMATION_H_

struct AudioInformation
{
	int type;           // 0:Auto, 1:Upload file, 2:Record
	int language;		// 0:English, 1:Chinese, .......

	AudioInformation()
	{
		type = 0;
		language = 0;
	}
};

#endif // AIR_WEAVER_SOP_AUDIOINFORMATION_H_