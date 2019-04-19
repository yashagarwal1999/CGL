



/*Drawing 3D cube using specified vertices for its coordinate. In this example we define the six surfaces of the 3d cube. We use glBegin(GL_QUADS) and glEnd(). Animation (Transformation 3D) and different color at each surface.
Code:*/

#include <GL/glut.h>
 GLfloat xRotated, yRotated, zRotated; //float type
void init(void) //intitailise
{
glClearColor(0,0,0,0); //(r,g,b,alpha) alpha for transperency
 
}

void DrawCube(void)
{

     glMatrixMode(GL_MODELVIEW); //2 matrix mode projection(ur rmovinng not the object) and model view(object changed to animation)
    // clear the drawing buffer.full caps are constant
    glClear(GL_COLOR_BUFFER_BIT); //clear this buffer glcolordeptbuffer,color buffer and many more
   glLoadIdentity(); //loads ideentity matrix in buffer
        glTranslatef(0.0,0.0,-10.5);  //f is for float d for double. xtrans,ytrans,ztrans
    glRotatef(xRotated,1.0,0.0,0.0);  //(angle in degree,x,y,z of vector) when xotated x=1
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
  glBegin(GL_QUADS);        // Draw The Cube Using quads 
    glColor3f(0.0f,1.0f,0.0f);    // Color Blue color3 is 3 colors are given f is for float rgb
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top) 3 coz x,y,z
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)
    glColor3f(1.0f,0.5f,0.0f);    // Color Orange
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Bottom)
    glColor3f(1.0f,0.0f,0.0f);    // Color Red    
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
    glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Top Right Of The Quad (Back)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Top Left Of The Quad (Back)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Bottom Left Of The Quad (Back)
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Bottom Right Of The Quad (Back)
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
    glColor3f(1.0f,0.0f,1.0f);    // Color Violet
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Right)
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Right)
  glEnd();            // End Drawing The Cube specfies drawing over
glFlush();  //flushes all values ie reset zero
}


void animation(void)
{
 
     yRotated += 0.01;  //speed
     xRotated += 0.02;
    DrawCube();
}


void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0
     
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0); // everything else is gl except this viewing angle,  ,near clipping plane distance from me and far clipping
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering  where to see on screen corner values left and right render=to show
}

int main(int argc, char** argv){

glutInit(&argc, argv);
//we initizlilze the glut. functions
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //glut single ie only one mode bitwise or
glutInitWindowPosition(100, 100); 
glutCreateWindow(argv[0]); //argv is name
init();
glutDisplayFunc(DrawCube); //drawing function passed
glutReshapeFunc(reshape); //
//Set the function for the animation.
glutIdleFunc(animation); //when idle start  animation
glutMainLoop(); //infinte loop for calling recursive main
return 0;
}
 




