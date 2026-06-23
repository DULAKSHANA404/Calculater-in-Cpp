#include "mainwindow.h"
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <string>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
    setupConnections();
}

void Calculator::setupUI(){
    resize(400,300);
    setWindowTitle("Calculator");

    display = new QLineEdit;
    display->setPlaceholderText("0");
    display->setReadOnly(true);
    display->setMinimumHeight(50);

    add = new QPushButton("+");
    sub = new QPushButton("-");
    multi = new QPushButton("x");
    divide = new QPushButton("/");
    clear = new QPushButton("C");
    equal = new QPushButton("=");

    num1 = new QPushButton("1");
    num2 = new QPushButton("2");
    num3 = new QPushButton("3");
    num4 = new QPushButton("4");
    num5 = new QPushButton("5");
    num6 = new QPushButton("6");
    num7 = new QPushButton("7");
    num8 = new QPushButton("8");
    num9 = new QPushButton("9");
    num0 = new QPushButton("0");

    setStyleSheet(

        "QWidget {"
        "background-color: #222;"
        "}"

        "QPushButton {"
        "color: white;"
        "font-size: 18px;"
        "border: none;"
        "border-radius: 10px;"
        "width: 70px;"
        "height: 50px;"
        "}"

        "QLineEdit {"
        "background-color: #333;"
        "color: white;"
        "font-size: 24px;"
        "}"
    );

    QPushButton *buttons_num[10] = {num0,num1,num2,num3,num4,num5,num6,num7,num8,num9};
    for (auto button :  buttons_num){
        button->setStyleSheet(
            "background-color: #444;"
            "color: white;"
        );
    }

    QPushButton *buttons_op[] = {add,sub,multi,equal,divide,clear};

    for (auto button : buttons_op){
        button->setStyleSheet(
            "background-color: orange;"
        );
    }

    auto *layout = new QGridLayout();

    layout->addWidget(display,0,0,1,4);

    layout->addWidget(num0,4,0);
    layout->addWidget(num1,3,0);
    layout->addWidget(num2,3,1);
    layout->addWidget(num3,3,2);
    layout->addWidget(num4,2,0);
    layout->addWidget(num5,2,1);
    layout->addWidget(num6,2,2);  
    layout->addWidget(num7,1,0);
    layout->addWidget(num8,1,1);
    layout->addWidget(num9,1,2);

    layout->addWidget(clear,4,1);
    layout->addWidget(equal,4,2);


    layout->addWidget(sub,3,3);
    layout->addWidget(divide,1,3);
    layout->addWidget(multi,2,3);
    layout->addWidget(add,4,3);


    setLayout(layout);
}

void Calculator::setupConnections(){

    connect(num0,&QPushButton::clicked,[=](){display->setText(display->text() + "0");});
    connect(num1,&QPushButton::clicked,[=](){display->setText(display->text() + "1");});
    connect(num2,&QPushButton::clicked,[=](){display->setText(display->text() + "2");});
    connect(num3,&QPushButton::clicked,[=](){display->setText(display->text() + "3");});
    connect(num4,&QPushButton::clicked,[=](){display->setText(display->text() + "4");});
    connect(num5,&QPushButton::clicked,[=](){display->setText(display->text() + "5");});
    connect(num6,&QPushButton::clicked,[=](){display->setText(display->text() + "6");});
    connect(num7,&QPushButton::clicked,[=](){display->setText(display->text() + "7");});
    connect(num8,&QPushButton::clicked,[=](){display->setText(display->text() + "8");});
    connect(num9,&QPushButton::clicked,[=](){display->setText(display->text() + "9");});

    connect(add,&QPushButton::clicked,[=](){
        oparation = "add";
        firstnumber = display->text().toDouble();
        display->clear();
    });

    connect(sub,&QPushButton::clicked,[=](){
        oparation="sub";
        firstnumber = display->text().toDouble();
        display->clear();
    });

    connect(divide,&QPushButton::clicked,[=](){
        oparation = "divide";
        firstnumber = display->text().toDouble();
        display->clear();
    });

    connect(multi,&QPushButton::clicked,[=](){
        oparation="multi";
        firstnumber = display->text().toDouble();
        display->clear();
    });

    connect(clear,&QPushButton::clicked,[=](){
        display->clear();
        firstnumber = 0;
        secoundnumber = 0;
        oparation.clear();
    });

    connect(equal,&QPushButton::clicked,[=](){
        secoundnumber = display->text().toDouble();
        if(oparation=="add") result = firstnumber+secoundnumber;
        if(oparation=="sub") result = firstnumber-secoundnumber;
        if(oparation=="divide") result = firstnumber/secoundnumber;
        if(oparation=="multi") result = firstnumber*secoundnumber;

        display->setText(QString::number(result));
    });
}