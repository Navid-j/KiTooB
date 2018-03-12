#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSql"
#include "QtSql/QSqlDriver"
#include "QtSql/QSqlError"
#include "QSqlQuery"
#include "QString"
#include "QMessageBox"
#include "QPixmap"
#include "QGraphicsDropShadowEffect"


//database connection
bool databaseconnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
         db.setHostName("localhost");
         db.setDatabaseName("booknab");
         db.setUserName("root");
         db.setPassword("mysql@123");

         if (!db.open()) {
             QMessageBox::critical(0,QObject::tr("DATABASE ERROR "),
                                   db.lastError().text());
             return false;
         }
    return true;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(databaseconnection()){
        ui->statusBar->showMessage("Server Ready!");
    }else{
        ui->statusBar->showMessage("Server Not Ready! Please Check The Internet Connection");
    }


    ui->btnpreviews->setDisabled(true);
    ui->btnnext->setDisabled(true);

    ui->lblviewimage->hide();
    ui->lblviewauthor->hide();
    ui->lblviewbookformat->hide();
    ui->lblviewbooklang->hide();
    ui->lblviewbookname->hide();
    ui->lblviewbooksize->hide();
    ui->lblviewpagenumer->hide();
    ui->lblviewpublicdate->hide();
    ui->lblviewpublisher->hide();
    ui->lblviewISBN->hide();
    ui->lblviewprintnum->hide();
    ui->btndownload->hide();
    ui->btnviewcancel->hide();

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setColor(QColor::fromRgb(120, 120, 120));
    effect->setXOffset(0);
    effect->setYOffset(2);
    effect->setBlurRadius(4);
    QGraphicsDropShadowEffect *effect2 = new QGraphicsDropShadowEffect;
    effect2->setColor(QColor::fromRgb(120, 120, 120));
    effect2->setXOffset(0);
    effect2->setYOffset(2);
    effect2->setBlurRadius(4);
    QGraphicsDropShadowEffect *effect3 = new QGraphicsDropShadowEffect;
    effect3->setColor(QColor::fromRgb(120, 120, 120));
    effect3->setXOffset(0);
    effect3->setYOffset(2);
    effect3->setBlurRadius(4);
    QGraphicsDropShadowEffect *effect4 = new QGraphicsDropShadowEffect;
    effect4->setColor(QColor::fromRgb(120, 120, 120));
    effect4->setXOffset(0);
    effect4->setYOffset(2);
    effect4->setBlurRadius(4);
    QGraphicsDropShadowEffect *effect5 = new QGraphicsDropShadowEffect;
    effect5->setColor(QColor::fromRgb(120, 120, 120));
    effect5->setXOffset(0);
    effect5->setYOffset(2);
    effect5->setBlurRadius(4);
    QGraphicsDropShadowEffect *effect6 = new QGraphicsDropShadowEffect;
    effect6->setColor(QColor::fromRgb(120, 120, 120));
    effect6->setXOffset(0);
    effect6->setYOffset(2);
    effect6->setBlurRadius(4);

    ui->btnnext->setGraphicsEffect(effect);
    ui->btnpreviews->setGraphicsEffect(effect2);
    ui->viewbutton1->setGraphicsEffect(effect3);
    ui->viewbutton2->setGraphicsEffect(effect4);
    ui->viewbutton3->setGraphicsEffect(effect5);
    ui->viewbutton4->setGraphicsEffect(effect6);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    ui->frame_3->resize(571,91);
    ui->viewbutton1->show();
    ui->lblauthor1->show();
    ui->lblbname1->show();
    ui->lblbimage1->show();
    ui->frame_4->show();
    ui->frame_5->show();
    ui->frame_6->show();
    ui->btnnext->show();
    ui->btnpreviews->show();

    ui->lblviewimage->hide();
    ui->lblviewauthor->hide();
    ui->lblviewbookformat->hide();
    ui->lblviewbooklang->hide();
    ui->lblviewbookname->hide();
    ui->lblviewbooksize->hide();
    ui->lblviewpagenumer->hide();
    ui->lblviewpublicdate->hide();
    ui->lblviewpublisher->hide();
    ui->lblviewISBN->hide();
    ui->lblviewprintnum->hide();
    ui->btndownload->hide();
    ui->btnviewcancel->hide();


    int labelToUpdate= 1;

    QSqlQuery myquery;
    myquery.exec("SELECT * FROM Books LIMIT 4");

    while (myquery.next()) {

        if (labelToUpdate == 1) {
            ui->lblbname1->setText("نام کتاب: " + myquery.value(1).toString());     // BName
            ui->lblauthor1->setText("نویسنده: " + myquery.value(2).toString());     // Author
            ui->lblbimage1->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));                  //Book Image
            bookidviews1=myquery.value(0).toInt();
        }

        if (labelToUpdate == 2) {
            ui->lblbname2->setText("نام کتاب: " + myquery.value(1).toString());     // BName
            ui->lblauthor2->setText("نویسنده: " + myquery.value(2).toString());     // Author
            ui->lblbimage2->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));       //Book Image
            bookidviews2=myquery.value(0).toInt();
        }

        if (labelToUpdate == 3) {
            ui->lblbname3->setText("نام کتاب: " + myquery.value(1).toString());     // BName
            ui->lblauthor3->setText("نویسنده: " + myquery.value(2).toString());     // Author
            ui->lblbimage3->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));                  //Book Image
            bookidviews3=myquery.value(0).toInt();
        }

        if (labelToUpdate == 4) {
            ui->lblbname4->setText("نام کتاب: " + myquery.value(1).toString());     // BName
            ui->lblauthor4->setText("نویسنده: " + myquery.value(2).toString());     // Author
            ui->lblbimage4->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));                  //Book Image
            bookidviews4=myquery.value(0).toInt();
        }
   ++labelToUpdate;

    }
    offset=0;

    ui->btnnext->setDisabled(false);
}

void MainWindow::on_btnnext_clicked()
{
     int labelToUpdate = 1;

         offset += 4; //next page

     QSqlQuery myquery;
     myquery.exec("SELECT * FROM Books LIMIT " + QString::number(offset) + ", 4");


     while (myquery.next()) {

         if (labelToUpdate == 1) {
             ui->lblbname1->setText("نام کتاب: " + myquery.value(1).toString());     // BName
             ui->lblauthor1->setText("نویسنده: " + myquery.value(2).toString());     // Author
             ui->lblbimage1->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));                  //Book Image
             bookidviews1=myquery.value(0).toInt();
         }

         if (labelToUpdate == 2) {
             ui->lblbname2->setText("نام کتاب: " + myquery.value(1).toString());     // BName
             ui->lblauthor2->setText("نویسنده: " + myquery.value(2).toString());     // Author
             ui->lblbimage2->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));                  //Book Image
             bookidviews2=myquery.value(0).toInt();
         }

         if (labelToUpdate == 3) {
             ui->lblbname3->setText("نام کتاب: " + myquery.value(1).toString());     // BName
             ui->lblauthor3->setText("نویسنده: " + myquery.value(2).toString());     // Author
             ui->lblbimage3->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));                  //Book Image
             bookidviews3=myquery.value(0).toInt();
         }

         if (labelToUpdate == 4) {
             ui->lblbname4->setText("نام کتاب: " + myquery.value(1).toString());     // BName
             ui->lblauthor4->setText("نویسنده: " + myquery.value(2).toString());     // Author
             ui->lblbimage4->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));                  //Book Image
             bookidviews4=myquery.value(0).toInt();
         }

         ++labelToUpdate;
     }
     if (offset==0) {
         ui->btnpreviews->setDisabled(true);
     }else {
         ui->btnpreviews->setDisabled(false);
     }

}

void MainWindow::on_btnpreviews_clicked()
{

    int labelToUpdate = 1;

        offset -= 4; //previews page

    QSqlQuery myquery;
    myquery.exec("SELECT * FROM Books LIMIT " + QString::number(offset) + ", 4");


    while (myquery.next()) {

        if (labelToUpdate == 1) {
            ui->lblbname1->setText("نام کتاب: " + myquery.value(1).toString());     // BName
            ui->lblauthor1->setText("نویسنده: " + myquery.value(2).toString());     // Author
            ui->lblbimage1->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));                  //Book Image
            bookidviews1=myquery.value(0).toInt();
        }

        if (labelToUpdate == 2) {
            ui->lblbname2->setText("نام کتاب: " + myquery.value(1).toString());     // BName
            ui->lblauthor2->setText("نویسنده: " + myquery.value(2).toString());     // Author
            ui->lblbimage2->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));                  //Book Image
            bookidviews2=myquery.value(0).toInt();
        }

        if (labelToUpdate == 3) {
            ui->lblbname3->setText("نام کتاب: " + myquery.value(1).toString());     // BName
            ui->lblauthor3->setText("نویسنده: " + myquery.value(2).toString());     // Author
            ui->lblbimage3->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));                  //Book Image
            bookidviews3=myquery.value(0).toInt();
        }

        if (labelToUpdate == 4) {
            ui->lblbname4->setText("نام کتاب: " + myquery.value(1).toString());     // BName
            ui->lblauthor4->setText("نویسنده: " + myquery.value(2).toString());     // Author
            ui->lblbimage4->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));                  //Book Image
            bookidviews4=myquery.value(0).toInt();
        }

        ++labelToUpdate;
    }

    if (offset==0) {
        ui->btnpreviews->setDisabled(true);
    }else {
        ui->btnpreviews->setDisabled(false);
    }
}


void MainWindow::on_viewbutton1_clicked()
{
    ui->frame_4->hide();
    ui->frame_5->hide();
    ui->frame_6->hide();
    ui->btnnext->hide();
    ui->btnpreviews->hide();
    ui->frame_3->resize(571,421);
    ui->viewbutton1->hide();
    ui->lblauthor1->hide();
    ui->lblbname1->hide();
    ui->lblbimage1->hide();

    ui->lblviewimage->show();
    ui->lblviewbookname->show();
    ui->lblviewauthor->show();
    ui->lblviewpublisher->show();
    ui->lblviewbookformat->show();
    ui->lblviewbooklang->show();
    ui->lblviewbooksize->show();
    ui->lblviewpagenumer->show();
    ui->lblviewpublicdate->show();
    ui->lblviewISBN->show();
    ui->lblviewprintnum->show();
    ui->btndownload->show();
    ui->btnviewcancel->show();

    QSqlQuery myquery;
    myquery.exec("SELECT * FROM Books WHERE ID="+QString::number(bookidviews1));
    myquery.first();

    //VIEW BOOK DETAILS
    if(myquery.value(1).toString()==""){
            ui->lblviewbookname->hide();
    }else {
        ui->lblviewbookname->setText("کتاب "+ myquery.value(1).toString());
    }

    if(myquery.value(2).toString()==""){
            ui->lblviewauthor->hide();
    }else {
        ui->lblviewauthor->setText("نویسنده: "+ myquery.value(2).toString());
    }

    if(myquery.value(10).toString()==""){
        ui->lblviewpublisher->hide();
    }else {
        ui->lblviewpublisher->setText("انتشارات: "+ myquery.value(10).toString());
    }

    if(myquery.value(3).toString()==""){
        ui->lblviewpagenumer->hide();
    }else {
        ui->lblviewpagenumer->setText("تعداد صفحات: "+ myquery.value(3).toString());
    }

    if(myquery.value(4).toString()==""){
        ui->lblviewbooklang->hide();
    }else {
        ui->lblviewbooklang->setText("زبان کتاب: "+ myquery.value(4).toString());
    }

    if(myquery.value(7).toString()==""){
        ui->lblviewbookformat->hide();
    }else {
        ui->lblviewbookformat->setText("نوع فایل: "+ myquery.value(7).toString());
    }

    if(myquery.value(8).toString()==""){
        ui->lblviewbooksize->hide();
    }else {
        ui->lblviewbooksize->setText("حجم فایل: "+ myquery.value(8).toString() + myquery.value(14).toString());
    }

    if(myquery.value(5).toString()==""){
        ui->lblviewpublicdate->hide();
    }else {
        ui->lblviewpublicdate->setText("تاریخ انتشار: "+ myquery.value(5).toString());
    }

    if(myquery.value(9).toString()==""){
        ui->lblviewISBN->hide();
    }else {
        ui->lblviewISBN->setText("شابک: " + myquery.value(9).toString());
    }

    if(myquery.value(12).toString()==""){
        ui->lblviewprintnum->hide();
    }else {
        ui->lblviewprintnum->setText("تعداد چاپ: " + myquery.value(12).toString());
    }


    ui->lblviewimage->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));

}

void MainWindow::on_btnviewcancel_clicked()
{
    ui->frame_3->resize(571,91);
    ui->viewbutton1->show();
    ui->lblauthor1->show();
    ui->lblbname1->show();
    ui->lblbimage1->show();
    ui->frame_4->show();
    ui->frame_5->show();
    ui->frame_6->show();
    ui->btnnext->show();
    ui->btnpreviews->show();

    ui->lblviewimage->hide();
    ui->lblviewauthor->hide();
    ui->lblviewbookformat->hide();
    ui->lblviewbooklang->hide();
    ui->lblviewbookname->hide();
    ui->lblviewbooksize->hide();
    ui->lblviewpagenumer->hide();
    ui->lblviewpublicdate->hide();
    ui->lblviewpublisher->hide();
    ui->lblviewISBN->hide();
    ui->lblviewprintnum->hide();
    ui->btndownload->hide();
    ui->btnviewcancel->hide();
}

void MainWindow::on_viewbutton2_clicked()
{
    ui->frame_4->hide();
    ui->frame_5->hide();
    ui->frame_6->hide();
    ui->btnnext->hide();
    ui->btnpreviews->hide();
    ui->frame_3->resize(571,421);
    ui->viewbutton1->hide();
    ui->lblauthor1->hide();
    ui->lblbname1->hide();
    ui->lblbimage1->hide();

    ui->lblviewimage->show();
    ui->lblviewbookname->show();
    ui->lblviewauthor->show();
    ui->lblviewpublisher->show();
    ui->lblviewbookformat->show();
    ui->lblviewbooklang->show();
    ui->lblviewbooksize->show();
    ui->lblviewpagenumer->show();
    ui->lblviewpublicdate->show();
    ui->lblviewISBN->show();
    ui->lblviewprintnum->show();
    ui->btndownload->show();
    ui->btnviewcancel->show();

    QSqlQuery myquery;
    myquery.exec("SELECT * FROM Books WHERE ID="+QString::number(bookidviews2));
    myquery.first();

    //VIEW BOOK DETAILS
    if(myquery.value(1).toString()==""){
            ui->lblviewbookname->hide();
    }else {
        ui->lblviewbookname->setText("کتاب "+ myquery.value(1).toString());
    }

    if(myquery.value(2).toString()==""){
            ui->lblviewauthor->hide();
    }else {
        ui->lblviewauthor->setText("نویسنده: "+ myquery.value(2).toString());
    }

    if(myquery.value(10).toString()==""){
        ui->lblviewpublisher->hide();
    }else {
        ui->lblviewpublisher->setText("انتشارات: "+ myquery.value(10).toString());
    }

    if(myquery.value(3).toString()==""){
        ui->lblviewpagenumer->hide();
    }else {
        ui->lblviewpagenumer->setText("تعداد صفحات: "+ myquery.value(3).toString());
    }

    if(myquery.value(4).toString()==""){
        ui->lblviewbooklang->hide();
    }else {
        ui->lblviewbooklang->setText("زبان کتاب: "+ myquery.value(4).toString());
    }

    if(myquery.value(7).toString()==""){
        ui->lblviewbookformat->hide();
    }else {
        ui->lblviewbookformat->setText("نوع فایل: "+ myquery.value(7).toString());
    }

    if(myquery.value(8).toString()==""){
        ui->lblviewbooksize->hide();
    }else {
        ui->lblviewbooksize->setText("حجم فایل: "+ myquery.value(8).toString() + myquery.value(14).toString());
    }

    if(myquery.value(5).toString()==""){
        ui->lblviewpublicdate->hide();
    }else {
        ui->lblviewpublicdate->setText("تاریخ انتشار: "+ myquery.value(5).toString());
    }

    if(myquery.value(9).toString()==""){
        ui->lblviewISBN->hide();
    }else {
        ui->lblviewISBN->setText("شابک: " + myquery.value(9).toString());
    }

    if(myquery.value(12).toString()==""){
        ui->lblviewprintnum->hide();
    }else {
        ui->lblviewprintnum->setText("تعداد چاپ: " + myquery.value(12).toString());
    }


    ui->lblviewimage->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));
}

void MainWindow::on_viewbutton3_clicked()
{
    ui->frame_4->hide();
    ui->frame_5->hide();
    ui->frame_6->hide();
    ui->btnnext->hide();
    ui->btnpreviews->hide();
    ui->frame_3->resize(571,421);
    ui->viewbutton1->hide();
    ui->lblauthor1->hide();
    ui->lblbname1->hide();
    ui->lblbimage1->hide();

    ui->lblviewimage->show();
    ui->lblviewbookname->show();
    ui->lblviewauthor->show();
    ui->lblviewpublisher->show();
    ui->lblviewbookformat->show();
    ui->lblviewbooklang->show();
    ui->lblviewbooksize->show();
    ui->lblviewpagenumer->show();
    ui->lblviewpublicdate->show();
    ui->lblviewISBN->show();
    ui->lblviewprintnum->show();
    ui->btndownload->show();
    ui->btnviewcancel->show();

    QSqlQuery myquery;
    myquery.exec("SELECT * FROM Books WHERE ID="+QString::number(bookidviews3));
    myquery.first();

    //VIEW BOOK DETAILS
    if(myquery.value(1).toString()==""){
            ui->lblviewbookname->hide();
    }else {
        ui->lblviewbookname->setText("کتاب "+ myquery.value(1).toString());
    }

    if(myquery.value(2).toString()==""){
            ui->lblviewauthor->hide();
    }else {
        ui->lblviewauthor->setText("نویسنده: "+ myquery.value(2).toString());
    }

    if(myquery.value(10).toString()==""){
        ui->lblviewpublisher->hide();
    }else {
        ui->lblviewpublisher->setText("انتشارات: "+ myquery.value(10).toString());
    }

    if(myquery.value(3).toString()==""){
        ui->lblviewpagenumer->hide();
    }else {
        ui->lblviewpagenumer->setText("تعداد صفحات: "+ myquery.value(3).toString());
    }

    if(myquery.value(4).toString()==""){
        ui->lblviewbooklang->hide();
    }else {
        ui->lblviewbooklang->setText("زبان کتاب: "+ myquery.value(4).toString());
    }

    if(myquery.value(7).toString()==""){
        ui->lblviewbookformat->hide();
    }else {
        ui->lblviewbookformat->setText("نوع فایل: "+ myquery.value(7).toString());
    }

    if(myquery.value(8).toString()==""){
        ui->lblviewbooksize->hide();
    }else {
        ui->lblviewbooksize->setText("حجم فایل: "+ myquery.value(8).toString() + myquery.value(14).toString());
    }

    if(myquery.value(5).toString()==""){
        ui->lblviewpublicdate->hide();
    }else {
        ui->lblviewpublicdate->setText("تاریخ انتشار: "+ myquery.value(5).toString());
    }

    if(myquery.value(9).toString()==""){
        ui->lblviewISBN->hide();
    }else {
        ui->lblviewISBN->setText("شابک: " + myquery.value(9).toString());
    }

    if(myquery.value(12).toString()==""){
        ui->lblviewprintnum->hide();
    }else {
        ui->lblviewprintnum->setText("تعداد چاپ: " + myquery.value(12).toString());
    }


    ui->lblviewimage->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));
}

void MainWindow::on_viewbutton4_clicked()
{
    ui->frame_4->hide();
    ui->frame_5->hide();
    ui->frame_6->hide();
    ui->btnnext->hide();
    ui->btnpreviews->hide();
    ui->frame_3->resize(571,421);
    ui->viewbutton1->hide();
    ui->lblauthor1->hide();
    ui->lblbname1->hide();
    ui->lblbimage1->hide();

    ui->lblviewimage->show();
    ui->lblviewbookname->show();
    ui->lblviewauthor->show();
    ui->lblviewpublisher->show();
    ui->lblviewbookformat->show();
    ui->lblviewbooklang->show();
    ui->lblviewbooksize->show();
    ui->lblviewpagenumer->show();
    ui->lblviewpublicdate->show();
    ui->lblviewISBN->show();
    ui->lblviewprintnum->show();
    ui->btndownload->show();
    ui->btnviewcancel->show();

    QSqlQuery myquery;
    myquery.exec("SELECT * FROM Books WHERE ID="+QString::number(bookidviews4));
    myquery.first();

    //VIEW BOOK DETAILS
    if(myquery.value(1).toString()==""){
            ui->lblviewbookname->hide();
    }else {
        ui->lblviewbookname->setText("کتاب "+ myquery.value(1).toString());
    }

    if(myquery.value(2).toString()==""){
            ui->lblviewauthor->hide();
    }else {
        ui->lblviewauthor->setText("نویسنده: "+ myquery.value(2).toString());
    }

    if(myquery.value(10).toString()==""){
        ui->lblviewpublisher->hide();
    }else {
        ui->lblviewpublisher->setText("انتشارات: "+ myquery.value(10).toString());
    }

    if(myquery.value(3).toString()==""){
        ui->lblviewpagenumer->hide();
    }else {
        ui->lblviewpagenumer->setText("تعداد صفحات: "+ myquery.value(3).toString());
    }

    if(myquery.value(4).toString()==""){
        ui->lblviewbooklang->hide();
    }else {
        ui->lblviewbooklang->setText("زبان کتاب: "+ myquery.value(4).toString());
    }

    if(myquery.value(7).toString()==""){
        ui->lblviewbookformat->hide();
    }else {
        ui->lblviewbookformat->setText("نوع فایل: "+ myquery.value(7).toString());
    }

    if(myquery.value(8).toString()==""){
        ui->lblviewbooksize->hide();
    }else {
        ui->lblviewbooksize->setText("حجم فایل: "+ myquery.value(8).toString() + myquery.value(14).toString());
    }

    if(myquery.value(5).toString()==""){
        ui->lblviewpublicdate->hide();
    }else {
        ui->lblviewpublicdate->setText("تاریخ انتشار: "+ myquery.value(5).toString());
    }

    if(myquery.value(9).toString()==""){
        ui->lblviewISBN->hide();
    }else {
        ui->lblviewISBN->setText("شابک: " + myquery.value(9).toString());
    }

    if(myquery.value(12).toString()==""){
        ui->lblviewprintnum->hide();
    }else {
        ui->lblviewprintnum->setText("تعداد چاپ: " + myquery.value(12).toString());
    }


    ui->lblviewimage->setPixmap(QPixmap(":/bimage/web/hweb/cms/uploads/"+ myquery.value(16).toString()));
}
