#include "stdafx.h"
#include "Navi.h"
#include <QtWidgets/QApplication>
#include<QPushButton>
#include <QtWidgets>

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	Navi w;//��ʼ��������
	w.show();//��ʾ������
	return a.exec();//ִ��app
}
