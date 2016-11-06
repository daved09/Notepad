#include "options.h"

Options::Options()
{
    setupUi();
    fillBox();
    setConnects();
    fontSize = 12;
    sizeBox->setCurrentIndex(11);
    font = "Plain";
    fontBox->setCurrentIndex(0);
}

void Options::fillBox()
{
    int size = 100;
    for(int i=1;i<=size;i++)
    {
        sizeBox->addItem(QString::number(i));
    }
    fontBox->addItem("Plain");
    fontBox->addItem("Times");
}

void Options::setupUi()
{
    //QWidget *w = new QWidget;
    //Initalize Layouts
    QVBoxLayout *vl = new QVBoxLayout;
    QHBoxLayout *hl = new QHBoxLayout;
    QHBoxLayout *hl2 = new QHBoxLayout;
    QHBoxLayout *hl3 = new QHBoxLayout;

    //Combobox
    sizeBox = new QComboBox;
    fontBox = new QComboBox;

    //Pushbutton
    btnAbort = new QPushButton;
    btnAbort->setText("Abbrechen");
    btnOK = new QPushButton;
    btnOK->setText("Ok");

    //Labels
    QLabel *lblSize = new QLabel;
    QLabel *lblFont = new QLabel;
    lblSize->setText("Schriftgröße");
    lblFont->setText("Schriftart");

    hl->addWidget(lblSize);
    hl->addWidget(sizeBox);
    hl2->addWidget(btnAbort);
    hl2->addWidget(btnOK);
    hl3->addWidget(lblFont);
    hl3->addWidget(fontBox);

    vl->addLayout(hl);
    vl->addLayout(hl3);
    vl->addLayout(hl2);
    this->setLayout(vl);
}

void Options::setConnects()
{
    connect(btnAbort, SIGNAL (clicked()),this,SLOT (aClick()));
    connect(btnOK, SIGNAL (clicked()), this, SLOT (okClick()));
}

void Options::aClick()
{
    abort = 1;
    this->close();
}

void Options::okClick()
{
    QString s = sizeBox->itemText(sizeBox->currentIndex());
    int size = s.toInt();
    fontSize = size;
    font = fontBox->currentText();
    close();
}

int Options::getFontSize()
{
    return fontSize;
}

QString Options::getFont()
{
    return font;
}

void Options::open()
{
    abort = 0;
    exec();
}
bool Options::isAbort()
{
    if(abort)
        return true;
    else return false;
}
