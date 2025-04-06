/*
    创建人：神数不神
    创建日期：2025-3-7
    无修正
*/
#include "luastate.h"
#include "luaapi.h"
#include "Util/util.h"
using namespace ysp::tool;
namespace ysp::lqt {
    /*
      在QT中请确保状态机在QT主线程运行
      不同线程之间不能共享同一个 lua_State*对象
      lua栈规则
      3 |  | -1
      2 |  | -2
      1 |  | -3
  */
    
    LuaState::LuaState() {
        L = nullptr;
    }


    /// <summary>
    /// 开始lua的状态机
    /// </summary>
    void LuaState::Start() {
        L = luaL_newstate();
        LuaApi::LibRegister(L);
    }

    LuaState::~LuaState() {
        if (L) {
            lua_close(L);
            L = nullptr;
        }  
    }

    /// <summary>
    /// 执行Lua脚本
    /// </summary>
    /// <param name="path"></param>
    /// <returns></returns>
    bool LuaState::RunLuaScript(const QString& path) {
        if (luaL_dofile(L, path.toUtf8().constData()) != 0) {
            Util::QtDebug("[LuaState::RunLuaScript]Error running Lua script:",QString::fromStdString(lua_tostring(L, -1)));
            return false;
        }
        return true;
    }

}