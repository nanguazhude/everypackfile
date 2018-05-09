#ifdef WIN32

#include <windows.h>
#include <QString>

bool move_file(const QString & argS,const QString & argT){
    const auto varS = argS.toLocal8Bit();
    const auto varT = argT.toLocal8Bit();
    return MoveFileA( varS.constData(),varT.constData() );
}

#endif
