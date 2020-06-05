#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Navi.h"
#include <QVector>
#include <QtWidgets>

const int sitenum = 107;//��ͼ�ϵ������
const int maxv = 65535;//�������ֵ��maxv��MaxValue

typedef int PathMatrix[sitenum][sitenum];   // ·�����󣬶�ά����
typedef int ShortPathTable[sitenum];               // ��̾����һά����

//ͼ���ṹ��
typedef struct MapNode {
	int id;//�ص���
	int x;//�ص�x����
	int y;//�ص�y����
}MapNode;

//ͼ�ṹ��
typedef struct MapGraph {
	MapNode mpn[sitenum];//mapnodes������ͼ�����Ϣ
	int arcs[sitenum][sitenum];//����·����Ϣ
	int vexnum;//ͼ�����
	int arcnum;//ͼ����
}MapGraph;

//��������
class Navi : public QMainWindow{
	Q_OBJECT

	public:
		Navi(QWidget *parent = Q_NULLPTR);//���캯��
		void createComboBox();//���������˵�
		void Clear();//����ѻ��Ƶ�·
		void Creatmap();//����ͼ�ṹ
		void Dijkstra(int startPos);//�Ͻ�˹�����㷨
		void DrawPath(QVector<int> v);//����·��
		//�ҵ��ɵϽ�˹�����㷨�����õĵ�Դ���·��ͼ�ҵ���endPos���·������ ������endPos�����·
		QVector<int> GetDijkstraPath(int endPos);
		
	private:
		MapGraph Map;//ͼ
		int Start;//��ʼ����
		int End;//Ŀ�ĵر��
		int prev[sitenum];  //���·�ϵ�ǰ������
		int d[sitenum];     //��ʾ��e = (u,v)��Ȩֵ(������ʱΪmaxv,�Լ�d[i][i]=0)
		bool used[sitenum]; //�Ѿ����ʹ��Ľ��
		QGraphicsScene *scene;//ͼ�񳡾�
		QGraphicsView *view;//ͼ����ͼ
		Ui::NaviClass ui;	//UI����

	//��
	public slots:
		void Action();//�����ʼ�Ĳ���
};
