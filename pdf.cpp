/* A simple pdf viewer.
 * Name: Benjamin Baka.
 * Date: Tue 16 Aug 2011 09:12:54 PM GMT
 */
#include <QColor>
#include <QPainter>
#include <QtGui>
#include <poppler-qt4.h>
#include <QApplication>
#include <QWidget>
#include <QString>
#include <QImage>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QPalette>
#include <QMainWindow>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QMainWindow window;
	//QVBoxLayout *layout = new QVBoxLayout(&window);
	
	QString filename = "python.pdf";
	QLabel label;
	Poppler::Document* document = Poppler::Document::load(filename);

	Poppler::Page *pdfPage = document->page(1);
	
	QImage image = pdfPage->renderToImage(1*label.physicalDpiX(),1*label.physicalDpiY(),0,0);

	label.setPixmap(QPixmap::fromImage(image));
	
//	QScrollArea *scrollArea = new QScrollArea();
//	scrollArea->setBackgroundRole(QPalette::Dark);
//	scrollArea->setWidget(&label);
	window.setCentralWidget(&label);	
	window.resize(500,500);

//	layout->addWidget(&label);
	//scrollArea->show();

	window.show();
	return a.exec();

}
