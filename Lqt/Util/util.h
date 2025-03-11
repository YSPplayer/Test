/*
    创建人：神数不神
    创建日期：2025-3-11
    无修正
*/
#pragma once
#include <QWidget>
namespace ysp::tool {
    class Util {
    public:
      /*  static QString rootPath;
        static QWidget* rootWidget;*/
        template<typename T>
        static void ReleasePointer(T*& point, bool isArray = false) {
            if (point == nullptr) return;
            isArray ? delete[] point : delete point;
            point = nullptr;
        }

        template<typename T>
        static void ReleasePointer(void*& point, bool isArray = false) {
            if (point == nullptr) return;
            T* rpoint = static_cast<T*>(point);
            isArray ? delete[] rpoint : delete rpoint;
            point = nullptr;
        }
        static void ReleasePointer(void**& point, quint32 size);
        /// <summary>
        /// 打印输出
        /// </summary>
        /// <param name="first"></param>
        /// <param name="...rest"></param>
        template<typename T, typename... Args>
        static void QtDebug(const T& first, const Args&... rest) {
            qDebug() << "";
            qDebug() << "----------";
            PrintCenter(first, rest...);
            qDebug() << "----------";
            qDebug() << "";
        }

        /// <summary>
        /// 封包
        /// </summary>
        /// <typeparam name="...Args"></typeparam>
        /// <param name="...args"></param>
        /// <returns></returns>
        template<typename... Args>
        static void** Packing(Args&&... args) {
            qint32 size = sizeof...(args);
            //这里初始化了argsArray的内存
            void** argsArray = new void* [size];
            qint32 index = 0;
            Pack(argsArray, index, std::forward<Args>(args)...);
            return argsArray;
        }

    private:
        static void PrintCenter() {
        }
        template<typename T, typename... Args>
        static void PrintCenter(const T& first, const Args&... rest) {
            qDebug() << first;
            PrintCenter(rest...);
        }

        static void Pack(void** arr, qint32& index) {
        }
        
        template<typename T, typename... Args>
        static void Pack(void** arr, qint32& index, T&& first, Args&&... rest) {
            arr[index++] = static_cast<void*>(first);//存储指针本身
            Pack(arr, index, std::forward<Args>(rest)...);
        }
    };
}