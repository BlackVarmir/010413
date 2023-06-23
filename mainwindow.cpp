#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegularExpressionValidator* validator = new QRegularExpressionValidator(QRegularExpression("UA[\\d-]+"), this);
    ui->textLineEdit->setValidator(validator);

    connect(ui->validateButton, &QPushButton::clicked, this, &MainWindow::on_validateButton_clicked);
    connect(ui->textLineEdit, &QLineEdit::returnPressed, this, &MainWindow::on_textLineEdit_returnPressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isValidAccountNumber(const QString& text)
{
    if(text.length() == 27)
        return true;

    return false;
}


void MainWindow::on_validateButton_clicked()
{
    QString text = ui->textLineEdit->text();
    text.remove("UA");

    if (isValidAccountNumber(text))
    {
        if (text.length() < 27 || text.length() > 27) {
            ui->resultLabel->setText("Недійсний рахунок");
        }
        else {
            ui->resultLabel->setText("Дійсний рахунок");
        }
    }
    else {
        ui->resultLabel->setText("Недійсний рахунок");
    }

    ui->textLineEdit->setFocus();
}


void MainWindow::on_textLineEdit_returnPressed() {
    on_validateButton_clicked();
}




