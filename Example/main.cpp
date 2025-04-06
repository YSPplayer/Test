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
    s->RunLuaScript(QApplication::applicationDirPath()  + "/test.lua");
    return a.exec();
}
