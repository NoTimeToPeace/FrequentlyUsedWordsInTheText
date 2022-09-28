#include "analyzer.h"
#include <algorithm>
#include <QtAlgorithms>

QVector<QPair<QString, int>> Analyzer::sortByValue()
{
    QVector<QPair<QString, int>> vec;

    for (auto it = m_key_words.cbegin(); it != m_key_words.cend(); ++it)
    {
      vec.push_back(qMakePair(it.key(), it.value()));
    }
    auto sortByVal=[](const QPair<QString, int> &a,
                   const QPair<QString, int> &b)
    {
        return (a.second > b.second);
    };
    std::sort(vec.begin(), vec.end(), sortByVal);

    return vec;
}

Analyzer::Analyzer()
{
    qDebug() << "Initial " << this;
}

Analyzer::Analyzer(QString text) : m_text(text.toLower())
{
    qDebug() << "Initial " << this;
}

Analyzer::~Analyzer()
{
    qDebug() << "Destroyed " << this;
}

void Analyzer::removePunctuationMarks()
{
    m_text.removeIf([](QChar x){return (!x.isLetter() && x != ' ') || x == '?';});
    m_text = m_text.simplified();
}

void Analyzer::wordsCount()
{
    QStringList splitWords = m_text.split(" ");
    for (QString& val:splitWords) {
        if (m_key_words.find(val) == m_key_words.end()) {
            m_key_words.insert(val, splitWords.count(val));
        }
    }
    m_sorted_count_words = sortByValue();
}

const QVector<QPair<QString, int>> Analyzer::getWordsCount()
{
    return m_sorted_count_words;
}
