#include "MultipleChoiceQuestion.h"

MultipleChoiceQuestion::MultipleChoiceQuestion(const std::string& text)
    : Question(text) {}

bool MultipleChoiceQuestion::checkAnswer(const std::vector<int>& selectedOptions) const {
    for (size_t i = 0; i < answerOptions.size(); ++i) {
        bool isSelected = (std::find(selectedOptions.begin(), selectedOptions.end(), i) != selectedOptions.end());
        if (answerOptions[i].getIsCorrect() != isSelected) {
            return false;
        }
    }
    return true;
}