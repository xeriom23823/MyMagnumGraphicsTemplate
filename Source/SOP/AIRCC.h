#ifndef AIR_WEAVER_SOP_AIRCC_H_
#define AIR_WEAVER_SOP_AIRCC_H_

#include "AIModel.h"
#include "AISOP.h"

struct AirCC
{
    // User
    string username;
	string password;
    string language;

    // ADB
	int master_oid;
    string type;
	string new_file;
	string path_file;
	string description;
    vector<string> linked_processes;

	vector<AIModel> ai_list;
	vector<AISop> ai_sops;

    string token;
	bool deployable;
	string deploy_status;

	AirCC()
	{
        clear();
	}

    void clear()
    {
        username = "";
		password = "";
		language = "cn";

		master_oid = 0;
        type = "";
		new_file = "0";
        path_file = "";
		description = "";
        linked_processes.clear();

		ai_list.clear();
		ai_sops.clear();

        token = "";
        deployable = false;
		deploy_status = "Steps are not completed.";
    }
};

#endif // AIR_WEAVER_SOP_AIRCC_H_