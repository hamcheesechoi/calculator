#include <string>
using std::string;

class Tennis {
public:
    const string tennis_score(int& p1Score, int& p2Score) {

        bool is_same_score = p1Score == p2Score;
        bool is_end_condition = p1Score >= 4 || p2Score >= 4;

        if (is_same_score)
        {
            return make_same_score_string(p1Score);
        }
        if (is_end_condition)
        {
            return make_end_condition_string(p1Score, p2Score);
        }
        return make_normal_condition_string(p1Score, p2Score);

    }
private:

    const std::string make_normal_condition_string(int& p1Score, int& p2Score)
    {
        return convert_score_to_string(p1Score) + "-" + convert_score_to_string(p2Score);
    }
    const std::string convert_score_to_string(int& tempScore)
    {
        switch (tempScore)
        {
        case 0:
            return "Love";
        case 1:
            return "Fifteen";
        case 2:
            return "Thirty";
        case 3:
            return "Forty";
        }
    }
    const std::string make_end_condition_string(int& p1Score, int& p2Score)
    {
        string score;
        int score_diff = p1Score - p2Score;
        if (score_diff == 1) score = "Advantage player1";
        else if (score_diff == -1) score = "Advantage player2";
        else if (score_diff >= 2) score = "Win for player1";
        else score = "Win for player2";

        //if (p1Score == p2Score + 1);
        //else if (p1Score + 1 == p2Score);
        //else if (p1Score >= p2Score + 2);
        //return "";

        return score;
    }
    const std::string make_same_score_string(int& score)
    {
        if (score >= 3) return "Deuce";
        return convert_score_to_string(score)+"-All";
    }
};