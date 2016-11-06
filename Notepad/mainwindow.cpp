#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filename = "";
    txtText = ui->txtText;
    txtText->setFont(QFont("Plain",op.getFontSize()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNeu_triggered()
{
    txtText->setEnabled(true);
    filename = "";
}

void MainWindow::on_actionSpeichern_triggered()
{
    if(filename == "")
        filename = QFileDialog::getSaveFileName(this,tr("Speichere in Textdatei"),"",tr("Textdateien (*)"));
    if(filename != "")
    {
        QString text = ui->txtText->toPlainText();
        writeText(text,filename);
    }
}


void MainWindow::writeText(QString text, QString name)
{
    QFile file(name);
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out << text << "\n";
}

QString MainWindow::readText(QString filename)
{
    QString text;
    QFile file(filename);
    if(file.exists())
    {
        file.open((QIODevice::ReadOnly));
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            text += line + "\n";
        }
        return text;
    }
    else
    {
        QMessageBox error;
        error.setText("Datei existiert nicht!");
        error.exec();
    }
    return NULL;
}

void MainWindow::on_actionSpeichern_unter_triggered()
{
    filename = QFileDialog::getSaveFileName(this,tr("Speichere in Textdatei"),"",tr("Textdateien (*)"));
    if(filename != "")
    {
        QString text = ui ->txtText->toPlainText();
        writeText(text, filename);
    }
}

void MainWindow::on_action_ffnen_triggered()
{
    filename = QFileDialog::getOpenFileName(this,tr("Öffne Textdatei"),"",tr("Textdateien (*)"));
    if(filename != "")
    {
        txtText->setText(readText(filename));
        txtText->setEnabled(true);
    }
}

void MainWindow::on_actionSchlie_em_triggered()
{
    if(txtText->toPlainText()!="")
    {
        QMessageBox box;
        box.setText("Vor dem Schließen speichern?");
        QAbstractButton *btnOK = box.addButton(tr("Ja"), QMessageBox::YesRole);
        box.addButton(tr("Nein"), QMessageBox::NoRole);
        box.exec();
        if(box.clickedButton()== btnOK)
        {
            if(filename == "")
                on_actionSpeichern_unter_triggered();
            else
                on_actionSpeichern_triggered();
        }
    }
    txtText->clear();
    txtText->setEnabled(false);
}


void MainWindow::on_actionBeenden_triggered()
{
    if(txtText->toPlainText()!="")
    {
        QMessageBox box;
        box.setText("Vor dem Beenden speichern?");
        QAbstractButton *btnOK = box.addButton(tr("Ja"), QMessageBox::YesRole);
        box.addButton(tr("Nein"), QMessageBox::NoRole);
        box.exec();
        if(box.clickedButton()==btnOK)
        {
            if(filename == "")
                on_actionSpeichern_unter_triggered();
            else
                on_actionSpeichern_triggered();
        }
    }
    exit(0);
}

void MainWindow::on_action_Optionen_triggered()
{
    op.open();
    if(!op.isAbort())
    {
        txtText->setFont(QFont(op.getFont(),op.getFontSize()));
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    on_actionBeenden_triggered();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if((key == Qt::Key_S)&&event->modifiers()==Qt::ControlModifier)
    {
        on_actionSpeichern_triggered();
    }
}


