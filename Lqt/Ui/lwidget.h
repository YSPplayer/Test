/*
    创建人：神数不神
    创建日期：2025-3-11
    无修正
*/
#pragma once
#include <LuaBridge/LuaBridge.h>
#include "cwidget.h"
namespace ysp::lqt::ui {
    class LWidget {
    protected:
        QWidget* qwidget;
    private:
        CWidget* widget;
    public:
        inline CWidget* getWidget() {
            return widget;
        }
        LWidget(LWidget* parent);
        LWidget();
        ~LWidget();
      /*  void setEnterCallback(const std::function<void(LWidget*)>& callback);
        void setLeaveCallback(const std::function<void(LWidget*)>& callback);
        void setClickedCallback(const std::function<void(LWidget*)>& callback);*/
        void resize(qint32 width, qint32 height);
        void setFixedSize(qint32 width, qint32 height);
        void setEnabled(bool enable);
        void move(qint32 x, qint32 y);
        void show();
        void hide();
        void setGeometry(qint32 x, qint32 y, qint32 w, qint32 h); 
        void setStyleSheet(const std::string& styleSheet);
        void setWindowTitle(const std::string& text);
        qint32 width();
        qint32 height();
        qint32 x();
        qint32 y();
    };
}