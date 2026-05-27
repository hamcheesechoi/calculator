#pragma once
#include "game.h"
#include <map>

using std::map;

namespace Board {
	static constexpr int BOARD_SIZE = 12;

	inline const vector<string>& allCategories() {
		static const vector<string> categories = { "Pop", "Science", "Sports", "Rock" };
		return categories;
	}

	inline string categoryAt(int position) {
		const vector<string>& categories = allCategories();
		return categories[position % categories.size()];
	}

	inline int advance(int position, int roll) {
		int next = position + roll;
		if (next >= BOARD_SIZE) next -= BOARD_SIZE;
		return next;
	}
}

class QuestionDeck {
	static constexpr int QUESTION_COUNT = 50;

	map<string, list<string>> questions;

public:
	QuestionDeck(const vector<string>& categories) {
		for (const auto& category : categories) {
			for (int i = 0; i < QUESTION_COUNT; i++) {
				questions[category].push_back(category + " Question " + to_string(i));
			}
		}
	}

	void ask(const string& category) {
		list<string>& q = questions[category];
		cout << q.front() << endl;
		q.pop_front();
	}
};

struct Player {
	string name;
	int place = 0;
	int purse = 0;
	bool inPenaltyBox = false;
	bool isGettingOutOfPenaltyBox = false;
};

class GameRefactor : public IGame {
	static constexpr int WINNING_COIN_COUNT = 6;

	vector<Player> players;
	int currentPlayer;
	QuestionDeck deck;

	bool isParticipatingInQuestion() const {
		return !players[currentPlayer].inPenaltyBox || players[currentPlayer].isGettingOutOfPenaltyBox;
	}

	bool canEscapePenaltyBox(int roll) const {
		return roll % 2 != 0;
	}

	void advanceToNextPlayer() {
		currentPlayer++;
		if (currentPlayer == (int)players.size()) currentPlayer = 0;
	}

	void movePlayer(int roll) {
		Player& p = players[currentPlayer];
		p.place = Board::advance(p.place, roll);
		string category = Board::categoryAt(p.place);

		cout << p.name << "'s new location is " << p.place << endl;
		cout << "The category is " << category << endl;
		deck.ask(category);
	}

	void sendToPenaltyBox() {
		cout << "Question was incorrectly answered" << endl;
		cout << players[currentPlayer].name + " was sent to the penalty box" << endl;
		players[currentPlayer].inPenaltyBox = true;
	}

	bool didPlayerWin() const {
		return players[currentPlayer].purse != WINNING_COIN_COUNT;
	}

public:
	GameRefactor() : currentPlayer{ 0 }, deck(Board::allCategories()) {}

	bool isPlayable() const {
		return howManyPlayers() >= 2;
	}

	bool add(string playerName) {
		players.push_back(Player{ playerName });
		cout << playerName << " was added" << endl;
		cout << "They are player number " << players.size() << endl;
		return true;
	}

	int howManyPlayers() const {
		return (int)players.size();
	}

	void rolling(int roll) {
		Player& p = players[currentPlayer];
		cout << p.name << " is the current player" << endl;
		cout << "They have rolled a " << roll << endl;

		if (p.inPenaltyBox) {
			if (canEscapePenaltyBox(roll)) {
				p.isGettingOutOfPenaltyBox = true;
				cout << p.name << " is getting out of the penalty box" << endl;
				movePlayer(roll);
			}
			else {
				cout << p.name << " is not getting out of the penalty box" << endl;
				p.isGettingOutOfPenaltyBox = false;
			}
		}
		else {
			movePlayer(roll);
		}
	}

	bool wasCorrectlyAnswered() {
		if (isParticipatingInQuestion()) {
			Player& p = players[currentPlayer];
			p.inPenaltyBox = false;
			cout << "Answer was correct!!!!" << endl;

			p.purse++;
			cout << p.name << " now has " << p.purse << " Gold Coins." << endl;

			bool winner = didPlayerWin();
			advanceToNextPlayer();

			return winner;
		}

		advanceToNextPlayer();
		return true;
	}

	bool wrongAnswer() {
		if (isParticipatingInQuestion()) {
			sendToPenaltyBox();
		}

		advanceToNextPlayer();
		return true;
	}
};
