#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <string>

using namespace std;

class Options : public QDialog
{
    Q_OBJECT
public:
    Options();
    int getFontSize();
    bool isAbort();
    QString getFont();
    void open();
private slots:
    void aClick();
    void okClick();
private:
    /*Variables*/
    int fontSize;
    QString font;
    int abort;
    /*GUI Elemente*/
    QComboBox *sizeBox;
    QComboBox *fontBox;
    QPushButton *btnOK;
    QPushButton *btnAbort;
    /*Funktionen*/
    void fillBox();
    void setupUi();
    void setConnects();
};

#endif // OPTIONS_H
