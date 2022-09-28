#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "analyzer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::Analyze_Clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Analyze_Clicked()
{
    qDebug() << "Analyze is clicked";
    ui->tableWidget->setRowCount(0);
    Analyzer analayze(ui->textEdit->toPlainText());
    analayze.removePunctuationMarks();
    analayze.wordsCount();
    const QVector<QPair<QString, int>> stat = analayze.getWordsCount();
    for (int i = 0; i < stat.size(); ++i) {
        // Добавляем строку в таблицу
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        // Добавляем в таблицу слово
        QTableWidgetItem *newItemWord = new QTableWidgetItem(stat[i].first);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, newItemWord);

        // Добавляем в таблицу количество повторений слова
        QTableWidgetItem *newItemCount = new QTableWidgetItem(QString::number(stat[i].second));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, newItemCount);

    }
}

