/*
    创建人：神数不神
    创建日期：2025-4-7
    无修正
*/
#include "llabel.h"
namespace ysp::lqt::ui {
    LLabel::LLabel(LWidget* parent):LWidget(){
        label = new QLabel(parent ? parent->getWidget() : nullptr);
        qwidget = label;
    }
    LLabel::~LLabel() {
        label = nullptr;
        //内存在父类中释放

    }

    void LLabel::setText(const std::string& text) {
        if (label) label->setText(QString::fromStdString(text));
    }
}