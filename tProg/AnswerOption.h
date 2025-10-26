#pragma once
#include <string>

class AnswerOption {
private:
    std::string text;
    bool isCorrect;

public:
    AnswerOption(const std::string& text, bool isCorrect);

    std::string getText() const { return text; }
    bool getIsCorrect() const { return isCorrect; }

    void display() const;
};