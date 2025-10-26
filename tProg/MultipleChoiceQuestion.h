#pragma once
#include "Question.h"
#include <algorithm>
#include <vector>

class MultipleChoiceQuestion : public Question {
public:
    MultipleChoiceQuestion(const std::string& text);
    bool checkAnswer(const std::vector<int>& selectedOptions) const override;
};