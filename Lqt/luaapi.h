/*
    创建人：神数不神
    创建日期：2025-3-7
    无修正
*/
#pragma once
#include "lqt_global.h"
#include <Lua/lua.hpp>
#include <QMap>
#include <QList>
namespace ysp::lqt {
    class LQT_EXPORT LuaApi {
    public:
        /*static QMap<qint32, QString> constValueMap;*/
        //记录lua中官方默认的全局key值
        static QList<QString> defaultEnvironmentKey;
    private:
      
    };
}