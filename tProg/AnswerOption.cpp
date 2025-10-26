#include "AnswerOption.h"
#include <iostream>

AnswerOption::AnswerOption(const std::string& text, bool isCorrect)
    : text(text), isCorrect(isCorrect) {}

void AnswerOption::display() const {
    std::cout << "- " << text;
    if (isCorrect) std::cout << " (правильный)";
    std::cout << std::endl;
}