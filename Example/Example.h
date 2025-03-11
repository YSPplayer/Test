#pragma once

#include <QtWidgets/QWidget>
#include "ui_Example.h"

class Example : public QWidget
{
    Q_OBJECT

public:
    Example(QWidget *parent = nullptr);
    ~Example();

private:
    Ui::ExampleClass ui;
};
