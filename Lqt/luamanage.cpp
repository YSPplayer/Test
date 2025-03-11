/*
    �����ˣ���������
    �������ڣ�2025-3-7
    ������
*/
#include "luamanage.h"
namespace ysp::lqt {
    /*
      ��QT����ȷ��״̬����QT���߳�����
      ��ͬ�߳�֮�䲻�ܹ���ͬһ�� lua_State*����
      luaջ����
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
    /// ��ʼ��lua�Ļ���
    /// </summary>
    void LuaManage::InitLuaEnvironment() {
        L = luaL_newstate();
        //LuaApi::LibRegister(L);//ע��lua����
        //QString script;
        //IUtil::LoadLuaScript("E:\\open3d\\3DToos\\x64\\Debug\\Plug\\plug.lua", script);
        //LuaApi::RunScript(L, script);

    }

    /// <summary>
    /// ����lua����
    /// </summary>
    void LuaManage::DestroyLuaEnvironment() {
        if (L) lua_close(L);
        L = nullptr;
    }
}