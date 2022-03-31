#ifndef AIR_WEAVER_SOP_STYLEINFORMATION_H_
#define AIR_WEAVER_SOP_STYLEINFORMATION_H_

struct StyleInformation
{
	unsigned int border_color_index;
	unsigned int border_color;
	float border_width;
	unsigned int background_color_index;
	unsigned int background_color;
	unsigned int text_color_index;
	unsigned int text_color;
	unsigned int font_color_index;
	unsigned int font_color;
	unsigned int font_size;
	unsigned int shape;
    
	StyleInformation()
	{
		border_color_index = 147;
		border_color = 0;
		border_width = 0.0f;
		background_color_index = 147;
		background_color = 0;
		text_color_index = 147;
		text_color = 0;
		font_color_index = 147;
		font_color = 0;
		font_size = 12;
		shape = 0;
	}

	void clearObject()
	{
		border_color_index = 147;
		border_color = 0;
		border_width = 0.0f;
		background_color_index = 147;
		background_color = 0;
		text_color_index = 147;
		text_color = 0;
		font_color_index = 147;
		font_color = 0;
		font_size = 12;
		shape = 0;
	}
	StyleInformation &operator=(const StyleInformation &source)
	{
		if (this == &source)
		{
			return *this;
		}
		border_color_index = source.border_color_index;
		border_color = source.border_color;
		border_width = source.border_width;
		background_color_index = source.background_color_index;
		background_color = source.background_color;
		text_color_index = source.text_color_index;
		text_color = source.text_color;
		font_color_index = source.font_color_index;
		font_color = source.font_color;
		font_size = source.font_size;
		shape = source.shape;
		return *this;
	}
};

#endif // AIR_WEAVER_SOP_STYLEINFORMATION_H_