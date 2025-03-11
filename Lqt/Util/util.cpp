/*
    创建人：神数不神
    创建日期：2025-3-11
    无修正
*/
#include "util.h"
namespace  ysp::tool {
    void Util::ReleasePointer(void**& point, quint32 size) {
        if (point == nullptr) return;
        for (quint32 i = 0; i < size; ++i) ReleasePointer(point[i]);
        ReleasePointer(point, true);
    }
}