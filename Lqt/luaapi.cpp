/*
    创建人：神数不神
    创建日期：2025-3-7
    无修正
*/
#include "luaapi.h"
#include "lglobal.h"
namespace ysp::lqt {
 /*   QMap <qint32, QString> LuaApi::constValueMap = {
       {LUA_VALUE_QWIDEGT_SHOW,"SHOW"},{LUA_VALUE_QWIDEGT_HIDE,"HIDE"},{LUA_VALUE_QWIDEGT_SETGEOMETRY,"SET_GEOMETRY"},
       {LUA_VALUE_QWIDEGT_SETENABLED,"SET_ENABLED"},{LUA_VALUE_QWIDEGT_MOVE,"MOVE"}, {LUA_VALUE_QWIDEGT_RESIZE,"RESIZE"},
       {LUA_VALUE_QWIDEGT_SETSTYLESHEET,"SET_STYLE_SHEET"}
    };*/
    QList<QString> LuaApi::defaultEnvironmentKey = { "pairs","ipairs","require","io","print","_VERSION","collectgarbage","rawlen",
    "assert","tostring","load","rawequal","setmetatable","next","math","rawget","os","string","loadfile","_G","error","debug",
    "utf8","table","getmetatable","rawset","pcall","warn","type","xpcall","coroutine","dofile","select","package","tonumber" };
    /// <summary>
     /// 注册lua函数
     /// </summary>
    void LuaApi::LibRegister(lua_State* L) {
        luaL_openlibs(L);  //注册标准库
        LuaRegisterGlobal(L); //注册全局函数
        LuaRegisterUserData(L);//注册自定义类型
    }

    /// <summary>
    /// 全局函数
    /// </summary>
    /// <param name="L"></param>
    void LuaApi::LuaRegisterGlobal(lua_State* L) {
        lua_register(L, "DebugMessage", LGlobal::DebugMessage);
    }

    /// <summary>
    /// 注册用户函数
    /// </summary>
    /// <param name="L"></param>
    void LuaApi::LuaRegisterUserData(lua_State* L) {
        luabridge::getGlobalNamespace(L)
            .beginNamespace("ysp")
            .beginNamespace("lqt")
            .beginNamespace("ui")
            .beginClass<LWidget>("LWidget")
            .addConstructor<void(*)(LWidget*)>()
            .addFunction("resize", &LWidget::resize)
            .addFunction("move", &LWidget::move)
            .addFunction("show", &LWidget::show)
            .addFunction("hide", &LWidget::hide)
            .addFunction("setGeometry", &LWidget::setGeometry)
            .addFunction("setStyleSheet", &LWidget::setStyleSheet)
            .addFunction("width", &LWidget::width)
            .addFunction("height", &LWidget::height)
            .addFunction("setEnterCallback", Callback<LWidget>(L, [](LWidget* widget, const std::function<void(LWidget*)>& callback) {
                widget->setEnterCallback(callback);
            }))
            .addFunction("setLeaveCallback", Callback<LWidget>(L, [](LWidget* widget, const std::function<void(LWidget*)>& callback) {
            widget->setLeaveCallback(callback);
            }))
            .addFunction("setClickedCallback", Callback<LWidget>(L, [](LWidget* widget, const std::function<void(LWidget*)>& callback) {
            widget->setClickedCallback(callback);
            }))
            .endClass()
            .endNamespace()
            .endNamespace()
            .endNamespace();

    }
}