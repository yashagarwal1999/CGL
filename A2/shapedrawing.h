#ifndef SHAPEDRAWING_H
#define SHAPEDRAWING_H


class ShapeDrawing
{
public:
    ShapeDrawing();
    void bres(int x1,int y1,int x2,int y2);
    int sign(int x);
    QImage getimage();
    void draw(int x,int y,int x1,int y1);
    void bcircle(int x1,int y1,int r);
void ddac(int xc,int yc,int r);

};

#endif // SHAPEDRAWING_H
