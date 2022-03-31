#ifndef AIR_WEAVER_SOP_SUPER_H_
#define AIR_WEAVER_SOP_SUPER_H_

#include <vector>
#include <string>
#include <list>

using namespace std;

enum class SentenceType
{
	kSentence = 0,
	kGroup = 1,
	kContionalSentence = 2,
	kOther = 3
};

struct SUPER
{
    string rtg_my_dad;              // 母句的索引值
	SentenceType sentence_type;     // 句子類型: "0":step "1":Group "2":contional step
	string abosolute_x;             // 句子層別: 1, 2, 3
	string sop_sentence;            // 句子內容
	string noun;                    // 名詞
	string verb;                    // 動詞
	string adv;                     // 副詞
	string adj;                     // 形容詞
	string tool;                    // 使用工具
	string spec;                    // 規格
	string linkage;                 // 連接物
	string base;                    // 基底
	string prep_base;               // 基底前的介係詞
	string prep_tool;               // 工具前的介係詞
	string prep_linkage;            // 連接物前的介係詞
	string prep_spec;               // 規格前的介係詞

    list<string> my_baby;           // 子句們
	list<string> vs_prep_linkage;   // 候選的 連接物前介係詞
	list<string> vs_prep_spec;      // 候選的 規格前介係詞
	list<string> vs_prep_tool;      // 候選的 工具前介係詞
	list<string> vs_prep_base;      // 候選的 基底前介係詞

	// 20210426 Add
	string type;
	string selected_text;
	string item_check_text;
	string is_directory;
	string expanded;

	// 20210521 Add
	string base_2;
	string cn_prep_1;
	string cn_prep_2;

	SUPER()
	{
		clear();
	}

	void clear()
	{
		rtg_my_dad = "";
		sentence_type = SentenceType::kSentence;
		abosolute_x = "";
		sop_sentence = "";
		noun = "";
		verb = "";
		adv = "";
		adj = "";
		tool = "";
		spec = "";
		linkage = "";
		base = "";
		prep_base = "";
		prep_tool = "";
		prep_linkage = "";
		prep_spec = "";
        my_baby.clear();
		vs_prep_base.clear();
		vs_prep_tool.clear();
		vs_prep_linkage.clear();
		vs_prep_spec.clear();

		type = "";
		selected_text = "";
		item_check_text = "";
		is_directory = "";
		expanded = "";
        
		base_2 = "";
		cn_prep_1 = "";
		cn_prep_2 = "";
	}
};

#endif // AIR_WEAVER_SOP_SUPER_H_