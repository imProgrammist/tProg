#include "Question.h"
#include <iostream>

Question::Question(const std::string& text) : text(text) {}

void Question::addAnswerOption(const AnswerOption& option) {
    answerOptions.push_back(option);
}

void Question::display() const {
    std::cout << "Вопрос: " << text << std::endl;
    for (const auto& option : answerOptions) {
        option.display();
    }
}

bool Question::checkAnswer(const std::vector<int>& selectedOptions) const {
    return false;
}