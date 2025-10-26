#include <iostream>
#include <vector>
#include <string>
#include "AnswerOption.h"
#include "Question.h"
#include "MultipleChoiceQuestion.h"
#include "Discipline.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // Создаем дисциплину
    Discipline discipline("Программирование на C++");

    // Создаем вопросы
    Question* q1 = new Question("Что такое класс в C++?");
    q1->addAnswerOption(AnswerOption("Функция", false));
    q1->addAnswerOption(AnswerOption("Тип данных", true));
    q1->addAnswerOption(AnswerOption("Переменная", false));

    MultipleChoiceQuestion* q2 = new MultipleChoiceQuestion("Какие из перечисленных типов являются встроенными в C++?");
    q2->addAnswerOption(AnswerOption("int", true));
    q2->addAnswerOption(AnswerOption("float", true));
    q2->addAnswerOption(AnswerOption("string", false));

    // Добавляем вопросы в дисциплину
    discipline.addQuestion(q1);
    discipline.addQuestion(q2);

    // Выводим дисциплину и вопросы
    discipline.display();

    // Проверка ответов
    vector<int> selectedOptions = { 1 };
    cout << "Ответ на первый вопрос " << (q1->checkAnswer(selectedOptions) ? "правильный" : "неправильный") << endl;

    selectedOptions = { 0, 1 };
    cout << "Ответ на второй вопрос " << (q2->checkAnswer(selectedOptions) ? "правильный" : "неправильный") << endl;

    return 0;
}