#include "mainwindow.hpp"
#include <QApplication>
#include <QtCore>
#include <memory>
#include <cmath>
#include <algorithm>

bool move_file(const QString & ,const QString & );
inline void every_pack_file( const QString & varDirName  ){

    QDirIterator varDI{ varDirName ,QDir::NoDotAndDotDot|QDir::Files };

    class Item{
    public:
        QFileInfo varDirInfo ;
        QString varFileName ;
    };

    std::vector< std::shared_ptr<Item> > varItems ;

    while( varDI.hasNext() ){

       varDI.next() ;
       std::shared_ptr<Item> varIP =  std::make_shared< Item >();
       Item & varItem = *varIP;
       varItems.push_back( varIP );
       varItem.varDirInfo = varDI.fileInfo();
       varItem.varFileName = varItem.varDirInfo.fileName() ;
    }

    std::sort( varItems.begin() , varItems.end(),
               [](const auto & l,const auto & r){
         const Item & varL = (*l);
         const Item & varR = (*r);
         if( &varL == &varR ){ return false ; }
         {
             const auto varLS = varL.varFileName.size();
             const auto varRS = varR.varFileName.size();
             if( varLS < varRS ){ return true ; }
             if( varLS > varRS ){ return false ; }
         }
         return varL.varFileName < varR.varFileName;
    });

    const QDir varDir{ varDirName  };
    const auto varNumberWidth = static_cast<int>(
                std::log10( varItems.size() )+ 1 );
    int varCNumber = 0;
    auto varCNumberToString = [varNumberWidth](int * arg){
        ++(*arg);
        return QString("%1").arg(*arg,varNumberWidth,10,QChar('0'));
    };
    for( auto & varII : varItems ){
        Item & varI = *varII ;

        const static QString varLog[] = {
            QString::fromUtf8( u8R"_1_(▲)_1_" ),
            QString::fromUtf8( u8R"_1_(★)_1_" ),
        };
        const QString varDirName = varCNumberToString(&varCNumber)
                +varLog[0]
                +varI.varDirInfo.baseName()
                +varLog[1] ;

        varDir.mkpath( varDirName );
        move_file( varI.varDirInfo.absoluteFilePath() ,
                   varDir.absoluteFilePath( varDirName )
                   +QChar('/')
                   +varI.varDirInfo.fileName() );
    }


}


int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    MainWindow window;
    window.connect( &window , &MainWindow::justRun , &every_pack_file );
    window.show();

    return app.exec();
}


