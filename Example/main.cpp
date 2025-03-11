#include "Example.h"
#include <QtWidgets/QApplication>
#include <luastate.h>
using namespace ysp::lqt;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 /*   Example w;
    w.show();*/
    LuaState* s = new LuaState;
    s->Start();
    s->RunLuaScript("D:\\YueShaoPu\\Test\\Example\\x64\\Debug\\test.lua");
    return a.exec();
}
