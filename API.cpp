#include "MinaCalc/MinaCalc.h"
#include <fstream>
#include <vector>
#include "smloader.h"

std::vector<NoteInfo> note_info;
extern "C" {
	#include "API.h"

	// internal utility function for C <-> C++ bridging
	extern "C++" Ssr skillset_vector_to_ssr(std::vector<float> &skillsets) {
		//assert(skillsets.size() == NUM_Skillset);
		return Ssr {
			skillsets[Skill_Overall],
			skillsets[Skill_Stream],
			skillsets[Skill_Jumpstream],
			skillsets[Skill_Handstream],
			skillsets[Skill_Stamina],
			skillsets[Skill_JackSpeed],
			skillsets[Skill_Chordjack],
			skillsets[Skill_Technical],
		};
	}

	int calc_version() {
		return GetCalcVersion();
	}

	CalcHandle *create_calc() {
		return reinterpret_cast<CalcHandle*>(new Calc);
	}

	void destroy_calc(CalcHandle *calc) {
		delete reinterpret_cast<Calc*>(calc);
	}

	Ssr calc_ssr(CalcHandle *calc, float music_rate, float score_goal) {
		auto skillsets = MinaSDCalc(
			note_info,
			music_rate,
			score_goal,
			reinterpret_cast<Calc*>(calc)
		);

		return skillset_vector_to_ssr(skillsets);
	}

	void calc_file(char* file_path, float rate, float score_goal){
		CalcHandle* calc = create_calc();
		std::ifstream file;
		file.open(file_path);
		SMNotes diffs = load_from_file(file);
		// printf("path=%s, rate=%f, goal:%f", file_path, rate, score_goal);

		for(ChartInfo diff : diffs){
			note_info = diff.notes;
			Ssr chart_msd = calc_ssr(calc, rate, score_goal);
			printf("%s|%f|%f|%f|%f|%f|%f|%f|%f", 
			diff.difficultyName.c_str(),
			chart_msd.overall, 
			chart_msd.stream, 
			chart_msd.jumpstream, 
			chart_msd.handstream, 
			chart_msd.stamina, 
			chart_msd.jackspeed, 
			chart_msd.chordjack, 
			chart_msd.technical);
		}
		destroy_calc(calc);
	}
}
