#ifndef LINEDRAWING_H
#define LINEDRAWING_H


class LineDrawing
{
public:
    LineDrawing();
    void dda(float x1,float y1,float x2,float y2);
    void bres(int x1,int y1,int x2,int y2,int f);
    int sign(int x);
QImage getimage();
};

#endif // LINEDRAWING_H
