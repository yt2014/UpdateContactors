#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"aaaa test\n";

    QSqlDatabase db1 = QSqlDatabase::database("Dail",true);

     if(db1.isValid()&&db1.isOpen())
     {
         QString strQuery = "select * from verification where hdnumber like \'%" + strDiskInfo.trimmed() +"%\'";

         QSqlQuery query(db1);

         query.exec(strQuery);



         int countOfRecord = 0;
         while(query.next())
         {
             countOfRecord = countOfRecord+1;
         }
         if(countOfRecord>0)
         {
           // MainWindow w;
           // w.show();
           // file.close();

            return a.exec();
         }
         else
         {
             //QMessageBox::information(NULL,"NO","认证不通过");
             qDebug()<<"verificating not passed\n";
         }

         db1.close();
         //file.close();
         return 0;
     }
     else
     {
         //QMessageBox::information(NULL,"NO","数据库文件丢失");
         //file.close();
         return 0;
     }


    //return a.exec();
}
