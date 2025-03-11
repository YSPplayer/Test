/*
    创建人：神数不神
    创建日期：2025-3-7
    无修正
*/
#include "luamanage.h"
namespace ysp::lqt {
    /*
      在QT中请确保状态机在QT主线程运行
      不同线程之间不能共享同一个 lua_State*对象
      lua栈规则
      3 |  | -1
      2 |  | -2
      1 |  | -3
  */
    LuaManage* LuaManage::Init() {
        static LuaManage* luaManage = new LuaManage;
        return luaManage;
    }

    LuaManage::LuaManage() {
        L = nullptr;
    }

    LuaManage::~LuaManage() {

    }

    /// <summary>
    /// 初始化lua的环境
    /// </summary>
    void LuaManage::InitLuaEnvironment() {
        L = luaL_newstate();
        //LuaApi::LibRegister(L);//注册lua函数
        //QString script;
        //IUtil::LoadLuaScript("E:\\open3d\\3DToos\\x64\\Debug\\Plug\\plug.lua", script);
        //LuaApi::RunScript(L, script);

    }

    /// <summary>
    /// 销毁lua环境
    /// </summary>
    void LuaManage::DestroyLuaEnvironment() {
        if (L) lua_close(L);
        L = nullptr;
    }
}