/*
    创建人：神数不神
    创建日期：2025-3-11
    无修正
*/
#include "lwidget.h"
#include "Util/util.h"
using namespace ysp::tool;
namespace ysp::lqt::ui {
    LWidget::LWidget(LWidget* parent) {
        widget = new CWidget(parent ? parent->getWidget() : nullptr);
        qwidget = widget;
    }

    LWidget::LWidget() {
        widget = nullptr;
        qwidget = nullptr;
    }

    //LUA垃圾回收机制会自动调用类的析构函数，这里我们需要协调lua和qt两种不同的释放机制，避免冲突导致程序的崩溃
    LWidget::~LWidget() {
        if(widget && widget->parent() == nullptr) {
            Util::ReleasePointer(widget);
            qwidget = nullptr;
        } else {
            qwidget = nullptr;
            widget->setParent(nullptr);
            widget->deleteLater();
        }
      
    }

  /*  void LWidget::setEnterCallback(const std::function<void(LWidget*)>& callback) {
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
    }*/

    void LWidget::resize(qint32 width, qint32 height) {
        if (qwidget) qwidget->resize(width, height);
    }

    void LWidget::setFixedSize(qint32 width, qint32 height) {
        if (qwidget) qwidget->setFixedSize(width, height);
    }

    void LWidget::setEnabled(bool enable) {
        if (qwidget) qwidget->setEnabled(enable);
    }

    void LWidget::move(qint32 x, qint32 y) {
        if (qwidget) qwidget->move(x,y);
    }

    void LWidget::show() {
        if (qwidget) qwidget->show();
    }

    void LWidget::hide() {
        if (qwidget) qwidget->hide();
    }

    void LWidget::setGeometry(qint32 x, qint32 y, qint32 w, qint32 h) {
        if (qwidget) qwidget->setGeometry(x, y, w, h);
    }

    void LWidget::setStyleSheet(const std::string& styleSheet) {
        if (qwidget) qwidget->setStyleSheet(QString::fromStdString(styleSheet));
    }

    void LWidget::setWindowTitle(const std::string& text) {
        if (qwidget) qwidget->setWindowTitle(QString::fromStdString(text));
    }

    qint32 LWidget::width() {
        if (qwidget) return qwidget->width();
        return 0;
    }

    qint32 LWidget::height() {
        if (qwidget) return qwidget->height();
        return 0;
    }

    qint32 LWidget::x() {
        if (qwidget) return qwidget->x();
        return 0;
    }

    qint32 LWidget::y() {
        if (qwidget) return qwidget->y();
        return 0;
    }

}
