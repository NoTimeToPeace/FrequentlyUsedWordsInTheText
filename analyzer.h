#ifndef ANALYZER_H
#define ANALYZER_H

#include <QString>
#include <QMap>
#include <QDebug>

class Analyzer
{
private:
    QString m_text; // Analyzed text
    QMap<QString, int> m_key_words; // Rep Counting
    QVector<QPair<QString, int>> m_sorted_count_words; // Отсортированное количество слов

private:
    QVector<QPair<QString, int>> sortByValue(); // Сортировка Map по значению

public:
    Analyzer();
    Analyzer(QString text);
    Analyzer(const Analyzer& val) = delete;
    Analyzer(Analyzer&& val) = delete;
    Analyzer operator=(const Analyzer&) = delete;
    Analyzer operator=(Analyzer&&) = delete;
    ~Analyzer();

public:
    void removePunctuationMarks(); // Удаление всех пунктационных знаков и переходов на новую строку
    void wordsCount(); // Подсчёт повторяющихся слов
    const QVector<QPair<QString, int>> getWordsCount(); // Возврат отсортированных подсчитанных слов
};

#endif // ANALYZER_H
