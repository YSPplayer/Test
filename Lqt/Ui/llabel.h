/*
    创建人：神数不神
    创建日期：2025-4-7
    无修正
*/
#pragma once
#include "lwidget.h"
#include <QLabel.h>
namespace ysp::lqt::ui {
    class LLabel: public LWidget {
    public:
        LLabel(LWidget* parent);
        ~LLabel();
        void setText(const std::string& text);
    private:
        QLabel* label;
    };
}
