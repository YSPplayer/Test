/*
    创建人：神数不神
    创建日期：2025-3-11
    无修正
*/
#include "lwidget.h"
namespace ysp::lqt::ui {
    LWidget::LWidget(LWidget* parent) {
        widget = new CWidget(parent ? parent->getWidget() : nullptr);
    }

    void LWidget::setEnterCallback(const std::function<void(LWidget*)>& callback) {
        if (widget) widget->setEnterCallback([callback, this]() {
            callback(this);
        });
    }

    void LWidget::setLeaveCallback(const std::function<void(LWidget*)>& callback) {
        if (widget) widget->setLeaveCallback([callback, this]() {
            callback(this);
        });
    }

    void LWidget::setClickedCallback(const std::function<void(LWidget*)>& callback) {
        if(widget) widget->setClickedCallback([callback, this]() {
            callback(this);
        });
    }

    void LWidget::resize(qint32 width, qint32 height) {
        if (widget) widget->resize(width, height);
    }

    void LWidget::move(qint32 x, qint32 y) {
        if (widget) widget->move(x,y);
    }

    void LWidget::show() {
        if (widget) widget->show();
    }

    void LWidget::hide() {
        if (widget) widget->hide();
    }

    void LWidget::setGeometry(qint32 x, qint32 y, qint32 w, qint32 h) {
        if (widget) widget->setGeometry(x, y, w, h);
    }

    void LWidget::setStyleSheet(const std::string& styleSheet) {
        if (widget) widget->setStyleSheet(QString::fromStdString(styleSheet));
    }

    qint32 LWidget::width() {
        if (widget) return widget->width();
        return 0;
    }

    qint32 LWidget::height() {
        if (widget) return widget->height();
        return 0;
    }

}
