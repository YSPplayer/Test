#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LQT_LIB)
#  define LQT_EXPORT Q_DECL_EXPORT
# else
#  define LQT_EXPORT Q_DECL_IMPORT
# endif
#else
# define LQT_EXPORT
#endif
