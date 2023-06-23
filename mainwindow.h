#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_validateButton_clicked();
    void on_textLineEdit_returnPressed();
//    void on_textLineEdit_textChanged(const QString& text);

private:
    Ui::MainWindow *ui;
    bool isValidAccountNumber(const QString& text);
};
#endif // MAINWINDOW_H
