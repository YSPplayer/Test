/*
    创建人：神数不神
    创建日期：2025-3-11
    无修正
*/
#pragma once
#include <functional>
#include <QWidget>
#include <QMouseEvent>
class CWidget :public QWidget {
public:
    CWidget(QWidget* parent = nullptr) : QWidget(parent) {
        //setMouseTracking(true);
        enterCallback = nullptr;
        leaveCallback = nullptr;
        clickedCallback = nullptr;
    }
    void setEnterCallback(const std::function<void()>& callback) {
        enterCallback = callback;
    }

    void setLeaveCallback(const std::function<void()>& callback) {
        leaveCallback = callback;
    }

    void setClickedCallback(const std::function<void()>& callback) {
        clickedCallback = callback;
    }
protected:
    void enterEvent(QEnterEvent* event) override {
        if (enterCallback) enterCallback();
    }

    void leaveEvent(QEvent* event) override {
        if (leaveCallback) leaveCallback();
    }

    void mousePressEvent(QMouseEvent* event) override {
        if (event->button() == Qt::LeftButton) {
            isPressed = true;
        }
    }

    void mouseReleaseEvent(QMouseEvent* event) override {
        if (event->button() == Qt::LeftButton && isPressed) {
            if (rect().contains(event->pos())) {
                if (clickedCallback) clickedCallback();
            }
            else {

            }
            isPressed = false;
        }
    }

    void mouseMoveEvent(QMouseEvent* event) override {
        
    }

private:
    bool isPressed = false;
    std::function<void()> enterCallback;
    std::function<void()> leaveCallback;
    std::function<void()> clickedCallback;
};