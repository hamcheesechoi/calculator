#include <vector>
#include <string>

using std::vector;
using std::string;

class Wheel {
private:
	const int REVEALED = 1;
	const int UNREVELAED = 0;
	const static int ROW_COUNT = 4;
	const static int COL_COUNT = 15;
	const int CORRECT_ANSWER_BONUS = 100;
	const int LETS_FIRST_BONUS = 1000;
	const int LETS_SECOND_BONUS = 2000;

	template <typename Action>
	void for_each_hidden_matched_cell(
		const vector<string>& strs,
		int map[ROW_COUNT][COL_COUNT],
		char userAnswer,
		Action action
	) {
		for (int row = 0; row < strs.size(); row++) {
			for (int col = 0; col < strs[row].size(); col++) {
				if (is_answer_reveled_or_answer_not_match(map, row, col, strs, userAnswer)) continue;
				action(row, col);
			}
		}
	}

	int add_bonus_if_second_chance_satisfied(std::vector<std::string>& strs, bool  isPossibleSecondChance[ROW_COUNT], int  map[ROW_COUNT][COL_COUNT], char userAnswer)
	{
		int sum = 0;
		for (int y = 0; y < strs.size(); y++) {
			if (!isPossibleSecondChance[y]) {
				continue;
			}
			for (int x = 0; x < strs[y].size(); x++) {
				if(is_answer_reveled_or_answer_not_match(map, y, x, strs, userAnswer)) continue;
				//획득 성공시 2000달러를 얻는다.
				sum += LETS_SECOND_BONUS;
				break;
			}
			isPossibleSecondChance[y] = false;
		}
		return sum;
	}

	bool is_answer_reveled_or_answer_not_match(int  map[4][15], int y, int x, const std::vector<std::string>& strs, char userAnswer)
	{
		if (map[y][x] == 1) { return true; };
		if (strs[y][x] != userAnswer) { return true; };
		return false;
	}

	int add_bonus_if_first_chance_satisfied(std::vector<std::string>& strs, int  map[4][15], char userAnswer, bool  usedFirstChance[4], bool  isPossibleSecondChance[4])
	{
		int sum = 0;
		for (int y = 0; y < strs.size(); y++) {
			if (is_answer_reveled_or_answer_not_match(map, y, 0, strs, userAnswer)) continue;
			if (usedFirstChance[y]) continue;
			sum += LETS_FIRST_BONUS;
			isPossibleSecondChance[y] = true;
		}
		return sum;
	}

	void update_first_chance_expired(std::vector<std::string>& strs, int  map[4][15], char userAnswer, bool  usedFirstChance[4])
	{
		for_each_hidden_matched_cell(strs, map, userAnswer, [&](int row, int col) {
			usedFirstChance[row] = true;
			});
	}

	int count_find_char(std::vector<std::string>& strs, int  map[4][15], char userAnswer)
	{
		int passCnt = 0;
		for_each_hidden_matched_cell(strs, map, userAnswer, [&](int row, int col) {
			passCnt++;
			});
		return passCnt;
	}
	
	void update_map(std::vector<std::string>& strs, int  map[4][15], char userAnswer)
	{
		for_each_hidden_matched_cell(strs, map, userAnswer, [&](int row, int col) {
			map[row][col] = 1;
			});
	}

public:
	int getPrice(vector<string>& strs, string& userdata) {
		int map[ROW_COUNT][COL_COUNT] = { 0 };

		int conCnt = 0;
		// 첫 찬스에 대한 가능여부 : false가 아직 기회 사용 X, true는 기회가 사용 됨
		bool usedFirstChance[ROW_COUNT] = { false, };

		int sum = 0;
		// second 찬스에 대한 가능여부 : true가능성이 존재, false 가능성 X
		bool isPossibleSecondChance[ROW_COUNT] = { false, };

		//하나씩 처리
		//26글자 for 돌면서 퀴즈 참석자가 하나씩 시도를 하는 것
		for (char userAnswer : userdata) {

			//1. 2000 달러 찬스를 얻었는지 검사
			sum += add_bonus_if_second_chance_satisfied(strs, isPossibleSecondChance, map, userAnswer);

			// first찬스 점수 계산
			sum += add_bonus_if_first_chance_satisfied(strs, map, userAnswer, usedFirstChance, isPossibleSecondChance);

			update_first_chance_expired(strs, map, userAnswer, usedFirstChance);

			int passCnt = count_find_char(strs, map, userAnswer);

			update_map(strs, map, userAnswer);

			if (passCnt == 0) {
				conCnt = 0;
				for (int i = 0; i < ROW_COUNT; i++) isPossibleSecondChance[i] = false;
				continue;
			}
			conCnt++;
			sum += (conCnt * CORRECT_ANSWER_BONUS) * passCnt;
		}

		return sum;
	}

};