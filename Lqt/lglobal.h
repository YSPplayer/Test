/*
    创建人：神数不神
    创建日期：2025-3-11
    无修正
*/
#pragma once
#include <Lua/lua.hpp>
#include <QString>
#include "Util/util.h"
using namespace ysp::tool;
namespace ysp::lqt {
    class LGlobal {
    public:
        static qint32 DebugMessage(lua_State* L) {
            qint32 numArgs = lua_gettop(L); // 获取参数数量
            QString context = "";
            // 遍历所有参数
            for (qint32 i = 1; i <= numArgs; i++) {
                qint32 argType = lua_type(L, i);
                // 根据参数类型处理
                switch (argType) {
                case LUA_TSTRING: {
                    context += lua_tostring(L, i);
                    break;
                }
                case LUA_TNUMBER: {
                    context += QString::number(lua_tonumber(L, i));
                    break;
                }
                case LUA_TBOOLEAN: {
                    context += lua_toboolean(L, i) ? "true" : "false";
                    break;
                }
                case LUA_TTABLE: {
                    context += QString("table:0x%1").arg(reinterpret_cast<quintptr>(lua_topointer(L, i)), 0, 16);
                    break;
                }
                case LUA_TNIL: {
                    context += "nil";
                    break;
                }
                case LUA_TFUNCTION: {
                    context += QString("function:0x%1").arg(reinterpret_cast<quintptr>(lua_topointer(L, i)), 0, 16);
                    break;
                }
                case LUA_TUSERDATA: {
                    context += QString("userdata:0x%1").arg(reinterpret_cast<quintptr>(lua_topointer(L, i)), 0, 16);
                    break;
                }
                case LUA_TTHREAD: {
                    context += QString("thread:0x%1").arg(reinterpret_cast<quintptr>(lua_topointer(L, i)), 0, 16);
                    break;
                }
                default: {
                    context += QString("unknown(%1)").arg(argType);
                    break;
                }
                }
            }
            Util::QtDebug("[LGlobal::DebugMessage]", QString("Lua Debug: ") + context);
            return 0; // 无返回值
        };

    };

}