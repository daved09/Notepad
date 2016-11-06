#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QLabel>
#include <QMessageBox>
#include "options.h"
#include <iostream>
#include <string>
#include <QCloseEvent>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QString filename;
    QTextEdit *txtText;
    Options op;
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent*);
    void keyPressEvent(QKeyEvent*);

private slots:
    void on_actionNeu_triggered();
    void on_actionSpeichern_triggered();
    void writeText(QString,QString);
    QString readText(QString);
    void on_actionSpeichern_unter_triggered();
    void on_action_ffnen_triggered();
    void on_actionSchlie_em_triggered();
    void on_actionBeenden_triggered();
    void on_action_Optionen_triggered();
};

#endif // MAINWINDOW_H
