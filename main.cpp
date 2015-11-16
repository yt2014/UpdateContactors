#include <QCoreApplication>
#include <QDebug>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QList>
#include <QVariant>
#include <QDebug>
#include "CContatorsTable.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"begin update...\n";

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC","Dail");
    db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=dail.mdb");
    db.setPassword("yt_2015_sdh");

    QSqlDatabase db1 = QSqlDatabase::database("Dail",true);

     if(db1.isValid()&&db1.isOpen())
     {
         QString strQuery = "select * from contactors where pinyin is null or ShortPinyin is null";
                            //"select * from contactors where pinyin = '' or ShortPinyin = ''";

         QSqlQuery query(db1);

         query.exec(strQuery);

         QSqlRecord columns = query.record();

         int index_Name = columns.indexOf("name");
         int index_telenum = columns.indexOf("telenumber");

         QString name;
         QString telenum;
         ContactorInfo infoToAdd;

        CContactorsTable * m_ContactorTable = new CContactorsTable();

         while(query.next())
         {
             name = query.value(index_Name).toString();
             telenum = query.value(index_telenum).toString();
             infoToAdd.name = name;
             infoToAdd.telenum = telenum;
             m_ContactorTable->InsertPinyinForRecord(infoToAdd);
             qDebug()<<name<<" "<<telenum<<"\n";
         }
         qDebug()<<"all updated\n";
         delete m_ContactorTable;
         if(db1.isOpen())
         {
             db1.close();
         }
         //file.close();
         //return 0;
     }
     else
     {
         //QMessageBox::information(NULL,"NO","数据库文件丢失");
         //file.close();
         qDebug()<<"can't find database file\n";

     }


    return a.exec();
}
