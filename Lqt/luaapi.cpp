/*
    创建人：神数不神
    创建日期：2025-3-7
    无修正
*/
#include "luaapi.h"
namespace ysp::lqt {
 /*   QMap <qint32, QString> LuaApi::constValueMap = {
       {LUA_VALUE_QWIDEGT_SHOW,"SHOW"},{LUA_VALUE_QWIDEGT_HIDE,"HIDE"},{LUA_VALUE_QWIDEGT_SETGEOMETRY,"SET_GEOMETRY"},
       {LUA_VALUE_QWIDEGT_SETENABLED,"SET_ENABLED"},{LUA_VALUE_QWIDEGT_MOVE,"MOVE"}, {LUA_VALUE_QWIDEGT_RESIZE,"RESIZE"},
       {LUA_VALUE_QWIDEGT_SETSTYLESHEET,"SET_STYLE_SHEET"}
    };*/
    QList<QString> LuaApi::defaultEnvironmentKey = { "pairs","ipairs","require","io","print","_VERSION","collectgarbage","rawlen",
    "assert","tostring","load","rawequal","setmetatable","next","math","rawget","os","string","loadfile","_G","error","debug",
    "utf8","table","getmetatable","rawset","pcall","warn","type","xpcall","coroutine","dofile","select","package","tonumber" };
}