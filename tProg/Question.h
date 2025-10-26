#pragma once
#include "AnswerOption.h"
#include <vector>
#include <string>

class Question {
protected:
    std::string text;
    std::vector<AnswerOption> answerOptions;

public:
    Question(const std::string& text);

    std::string getText() const { return text; }
    const std::vector<AnswerOption>& getAnswerOptions() const { return answerOptions; }
    size_t getAnswerOptionsCount() const { return answerOptions.size(); }

    void addAnswerOption(const AnswerOption& option);
    virtual void display() const;
    virtual bool checkAnswer(const std::vector<int>& selectedOptions) const;
};