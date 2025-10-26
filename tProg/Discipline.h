#pragma once
#include "Question.h"
#include <vector>
#include <string>

class Discipline {
private:
    std::string name;
    std::vector<Question*> questions;

public:
    Discipline(const std::string& name);
    ~Discipline();

    void addQuestion(Question* question);
    void display() const;

    std::string getName() const { return name; }
    const std::vector<Question*>& getQuestions() const { return questions; }
    bool isEmpty() const { return questions.empty(); }
    size_t getQuestionsCount() const { return questions.size(); }
};