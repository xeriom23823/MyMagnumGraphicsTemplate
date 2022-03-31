#ifndef AIR_WEAVER_SOP_PROCEDURE_H_
#define AIR_WEAVER_SOP_PROCEDURE_H_

#include <string>
#include <vector>

using namespace std;

struct Procedure
{
	string version;
	string name;
	int spend_time_hour;
	int spend_time_minute;
	string super_model_type;
	string super_sop_type;

    vector<float> marker_position;
    vector<float> marker_rotation;
    vector<float> marker_scale;

	int entry_step_key;
	int last_step_key;
	int total_steps;

    string language;

	Procedure()
	{
		clear();
	}

    void clear()
    {
        version = "1.2126.8";
		name = "Untitled";
		spend_time_hour = 0;
		spend_time_minute = 0;
		super_model_type = "Scratch mode";
		super_sop_type = "Assembling";

        marker_position = {0.0f, 0.0f, 0.0f};
        marker_rotation = {0.0f, 0.0f, 0.0f};
        marker_scale = {1.0f, 1.0f, 1.0f};

		entry_step_key = 0;
		last_step_key = 0;
		total_steps = 0;
        language = "cn";
    }
};

#endif  // AIR_WEAVER_SOP_PROCEDURE_H_