#include "Discipline.h"
#include <iostream>

Discipline::Discipline(const std::string& name) : name(name) {}

Discipline::~Discipline() {
    for (auto& question : questions) {
        delete question;
    }
}

void Discipline::addQuestion(Question* question) {
    questions.push_back(question);
}

void Discipline::display() const {
    std::cout << "Дисциплина: " << name << std::endl;
    for (const auto& question : questions) {
        question->display();
    }
}