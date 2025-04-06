/*
    创建人：神数不神
    创建日期：2025-3-7
    无修正
*/
#pragma once
#include "lqt_global.h"
#include <memory>
#include <Lua/lua.hpp>
#include <QMap>
#include <QList>
#include "Ui/lwidget.h"
#include "Ui/llabel.h"
#include "Util/util.h"
using namespace ysp::tool;
using namespace ysp::lqt::ui;
namespace ysp::lqt {
    // 存储 Lua 回调引用
    struct LuaCallbackRef {
        lua_State* L;
        qint32 ref;
        LuaCallbackRef(lua_State* L, qint32 ref) : L(L), ref(ref) {}
        ~LuaCallbackRef() {
            if (L && ref != LUA_NOREF) {
                luaL_unref(L, LUA_REGISTRYINDEX, ref);
            }
        }
    };
    class LQT_EXPORT LuaApi {
    public:
        /*static QMap<qint32, QString> constValueMap;*/
        //记录lua中官方默认的全局key值
        static QList<QString> defaultEnvironmentKey;
        static void LibRegister(lua_State* L);
        static void LuaRegisterGlobal(lua_State* L);
        static void LuaRegisterUserData(lua_State* L);
    private:
        template<typename T>
        static std::function<void(T*, luabridge::LuaRef)> Callback(lua_State* L,const std::function<void(T*, const std::function<void(T*)>&)>& func) {
            return [L, func](T* widget, luabridge::LuaRef callback) {
                if (callback.isFunction()) {
                    // 创建一个引用到 Lua 函数
                    callback.push(L);
                    qint32 ref = luaL_ref(L, LUA_REGISTRYINDEX);
                    // 创建一个共享指针来管理引用的生命周期
                    auto callbackRef = std::make_shared<LuaCallbackRef>(L, ref);
                    func(widget, [L, callbackRef, widget](T*) {
                        // 获取 Lua 函数
                        lua_rawgeti(L, LUA_REGISTRYINDEX, callbackRef->ref);
                        // 将 widget 作为参数推入栈
                        luabridge::push(L, widget);
                        // 调用函数
                        if (lua_pcall(L, 1, 0, 0) != 0) {
                            Util::QtDebug("[LuaApi::Callback]Error lua callback:",
                                QString::fromStdString(lua_tostring(L, -1)));
                            lua_pop(L, 1);
                        }
                    });
                }
            };
        }
    };
}