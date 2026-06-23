#pragma once

#include <QWidget>

class QLineEdit;
class QPushButton;

class Calculator : public QWidget{
Q_OBJECT
public:
    explicit Calculator(QWidget *parent = nullptr);


private:
    void setupUI();
    void setupConnections();

    QLineEdit *display;
    QPushButton *add,*sub,*multi, *divide, *equal, *clear; 
    QPushButton *num0, *num1, *num2,*num3, *num4, *num5, *num6, *num7, *num8, *num9;
    
    double firstnumber = 0;
    double secoundnumber = 0;
    double result = 0;
    QString oparation;
};
