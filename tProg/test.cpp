#include <iostream>
#include <vector>
#include <string>
#include "AnswerOption.h"
#include "Question.h"
#include "MultipleChoiceQuestion.h"
#include "Discipline.h"

void testAnswerOption() {
    std::cout << "=== Тестирование AnswerOption ===" << std::endl;

    AnswerOption option1("Правильный ответ", true);
    AnswerOption option2("Неправильный ответ", false);

    if (option1.getText() == "Правильный ответ") {
        std::cout << "✓ ПРОЙДЕНО: getText() работает корректно" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: getText()" << std::endl;
    }

    if (option1.getIsCorrect() == true) {
        std::cout << "✓ ПРОЙДЕНО: getIsCorrect() возвращает true для правильного ответа" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: getIsCorrect()" << std::endl;
    }

    if (option2.getIsCorrect() == false) {
        std::cout << "✓ ПРОЙДЕНО: getIsCorrect() возвращает false для неправильного ответа" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: getIsCorrect()" << std::endl;
    }
}

void testQuestion() {
    std::cout << "\n=== Тестирование Question ===" << std::endl;

    Question question("Что такое ООП?");
    question.addAnswerOption(AnswerOption("Объектно-ориентированное программирование", true));
    question.addAnswerOption(AnswerOption("Объектно-открытое программирование", false));

    if (question.getAnswerOptionsCount() == 2) {
        std::cout << "✓ ПРОЙДЕНО: addAnswerOption() работает - добавлено 2 варианта" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: addAnswerOption() - ожидалось 2 варианта, получено " << question.getAnswerOptionsCount() << std::endl;
    }

    if (question.getAnswerOptionsCount() >= 1 && question.getAnswerOptionsCount() <= 10) {
        std::cout << "✓ ПРОЙДЕНО: количество ответов в допустимом диапазоне (1-10)" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: количество ответов вне допустимого диапазона" << std::endl;
    }

    if (question.getText() == "Что такое ООП?") {
        std::cout << "✓ ПРОЙДЕНО: текст вопроса сохраняется корректно" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: текст вопроса некорректен" << std::endl;
    }
}

void testMultipleChoiceQuestion() {
    std::cout << "\n=== Тестирование MultipleChoiceQuestion ===" << std::endl;

    MultipleChoiceQuestion question("Какие языки программирования являются ООП?");
    question.addAnswerOption(AnswerOption("C++", true));
    question.addAnswerOption(AnswerOption("Java", true));
    question.addAnswerOption(AnswerOption("Python", true));
    question.addAnswerOption(AnswerOption("HTML", false));

    std::vector<int> correctAnswer = { 0, 1, 2 };
    std::vector<int> wrongAnswer = { 0, 1, 2, 3 };
    std::vector<int> partialAnswer = { 0, 1 };

    if (question.checkAnswer(correctAnswer)) {
        std::cout << "✓ ПРОЙДЕНО: правильный ответ распознан" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: правильный ответ не распознан" << std::endl;
    }

    if (!question.checkAnswer(wrongAnswer)) {
        std::cout << "✓ ПРОЙДЕНО: неправильный ответ обнаружен" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: неправильный ответ не обнаружен" << std::endl;
    }

    if (!question.checkAnswer(partialAnswer)) {
        std::cout << "✓ ПРОЙДЕНО: частично правильный ответ помечен как неправильный" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: частично правильный ответ должен быть помечен как неправильный" << std::endl;
    }
}

void testDiscipline() {
    std::cout << "\n=== Тестирование Discipline ===" << std::endl;

    Discipline discipline("Программирование");

    if (discipline.getName() == "Программирование") {
        std::cout << "✓ ПРОЙДЕНО: название дисциплины сохраняется корректно" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: название дисциплины некорректно" << std::endl;
    }

    if (discipline.isEmpty()) {
        std::cout << "✓ ПРОЙДЕНО: новая дисциплина пуста" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: новая дисциплина должна быть пустой" << std::endl;
    }

    Question* q1 = new Question("Что такое класс?");
    Question* q2 = new MultipleChoiceQuestion("Какие принципы ООП?");

    discipline.addQuestion(q1);
    discipline.addQuestion(q2);

    if (discipline.getQuestionsCount() == 2) {
        std::cout << "✓ ПРОЙДЕНО: добавлено 2 вопроса в дисциплину" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: ожидалось 2 вопроса, получено " << discipline.getQuestionsCount() << std::endl;
    }

    if (discipline.getQuestionsCount() > 0 && discipline.getQuestionsCount() < 100) {
        std::cout << "✓ ПРОЙДЕНО: количество вопросов в разумном диапазоне" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: количество вопросов вне разумного диапазона" << std::endl;
    }
}

void testBoundaryValues() {
    std::cout << "\n=== Тестирование Граничных Значений ===" << std::endl;

    Discipline emptyDiscipline("Пустая дисциплина");
    if (emptyDiscipline.isEmpty()) {
        std::cout << "✓ ПРОЙДЕНО: пустая дисциплина корректно идентифицируется как пустая" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: пустая дисциплина должна быть пустой" << std::endl;
    }

    Question singleOptionQuestion("Вопрос с одним вариантом");
    singleOptionQuestion.addAnswerOption(AnswerOption("Единственный вариант", true));

    if (singleOptionQuestion.getAnswerOptionsCount() == 1) {
        std::cout << "✓ ПРОЙДЕНО: вопрос с одним вариантом ответа работает" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: вопрос должен иметь 1 вариант ответа" << std::endl;
    }
}

void testEdgeCases() {
    std::cout << "\n=== Тестирование Крайних Случаев ===" << std::endl;

    Question question("Простой вопрос");
    question.addAnswerOption(AnswerOption("Правильный", true));
    question.addAnswerOption(AnswerOption("Неправильный", false));

    std::vector<int> emptySelection;
    if (!question.checkAnswer(emptySelection)) {
        std::cout << "✓ ПРОЙДЕНО: пустой выбор обрабатывается корректно" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: пустой выбор должен возвращать false" << std::endl;
    }

    std::vector<int> invalidIndex = { 5 };
    if (!question.checkAnswer(invalidIndex)) {
        std::cout << "✓ ПРОЙДЕНО: недопустимый индекс обрабатывается корректно" << std::endl;
    }
    else {
        std::cout << "✗ ОШИБКА: недопустимый индекс должен возвращать false" << std::endl;
    }
}

int main() {
    // Настройка локали для вывода русских символов
    setlocale(LC_ALL, "RU");

    std::cout << "Запуск модульных тестов..." << std::endl;
    std::cout << "=============================" << std::endl;

    testAnswerOption();
    testQuestion();
    testMultipleChoiceQuestion();
    testDiscipline();
    testBoundaryValues();
    testEdgeCases();

    std::cout << "\n=============================" << std::endl;
    std::cout << "Все тесты завершены!" << std::endl;

    return 0;
}