/*
    创建人：神数不神
    创建日期：2025-3-7
    无修正
*/
#pragma once
#include "lqt_global.h"
#include <Lua/lua.hpp>
namespace ysp::lqt {
    class LQT_EXPORT LuaState {
    public:
        LuaState();
        void Start();
        ~LuaState();
        bool RunLuaScript(const QString& path);
    private:
        lua_State* L;//lua栈的状态机
    };
}
