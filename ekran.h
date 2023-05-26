#ifndef EKRAN_H
#define EKRAN_H

#include <QWidget>
#include <QVector>

struct colorAtPixel
{
    int x;
    int y;
    uchar red;
    uchar green;
    uchar blue;
};

struct coord
{
    int x;
    int y;
};

class Ekran : public QWidget
{
    Q_OBJECT
public:
        explicit Ekran(QWidget *parent = nullptr);
protected:
        void paintEvent(QPaintEvent *);
        void mouseMoveEvent(QMouseEvent *);
        void mousePressEvent(QMouseEvent *);
private:
        QImage im;
        void drawPixel(int x,int y, int r,int g,int b);
        coord p1;
        coord p2;
        QVector<colorAtPixel> vector;
signals:

};

#endif // EKRAN_H
