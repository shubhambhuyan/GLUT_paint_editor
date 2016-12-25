#include <GL/glut.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <stdlib.h>
#define outcode int 
#define BLACK 0
#define maxx 25
#define maxy 25
#define dx 15
#define dy 10
#define true 1
#define false 0
using namespace std;
int win=0;
const int MAX_ITEMS = 10000; 
struct ItemData
{
   double x1, y1; 
   double x2, y2;
   int q,qs;
};

ItemData items[MAX_ITEMS]; 
int itemCt = 0,flag=0; 
int i,j,z;
int width;   
int height;  

int a=0; 
//GLint arr[10000][2];
int s=0;
bool dragging = false;  

int dragModifiers;    

void handleStartDraw(double x, double y, int modifiers)
{
      
   if (itemCt == MAX_ITEMS)
   {
      cout << "Can't draw more items; maximum number has been reached.\n";
      return;
   }

   dragging = true;  
   dragModifiers = modifiers;

   items[itemCt].x1 = x;   
   items[itemCt].y1 = y;   
   items[itemCt].x2 = x;   
   items[itemCt].y2 = y;
   items[itemCt].q=a;   
   items[itemCt].qs=s;  
   itemCt++;
}

void handleContinueDraw(double x, double y)
{
      
   if (!dragging)
      return;
   int current = itemCt - 1;  
   bool shifted = ((dragModifiers & GLUT_ACTIVE_SHIFT) != 0);
   if (shifted)
   {
         
      if (abs(x - items[current].x1) > abs(y - items[current].y1))
         y = items[current].y1;
      else
         x = items[current].x1;
   }
   items[current].x2 = x;  
   items[current].y2 = y;
   glutPostRedisplay();    
}

void handleFinishDraw(double x, double y)
{
      
   if (!dragging)
      return;
   dragging = false;   
   int current = itemCt - 1;  
   if (items[current].x1 == items[current].x2 &&
                  items[current].y1 == items[current].y2)
   {
          
       itemCt--;  
   }
   glutPostRedisplay();  
}


void handleMenuMouse(int x, int y, int modifiers)
{
     
   if (y > height - 50)
   {
         
      itemCt = 0;
      glutPostRedisplay();
   }
   else if (y > height - 100)
   {
         
      if (itemCt > 0)
      {
         itemCt--;
         glutPostRedisplay();
      }
   }
   else if(x>3 &&x <22 && y>100 && y<119)
   a=1;
   else if(x>25 && x <44 && y>100 && y<119)
   a=2;
   else if(x>47 && x <66 && y>100 && y<119)
   a=3;
   else if(x>69 && x <88 && y>100 && y<119)
   a=4;
   
   else if(x>3 &&x <22 && y>74 && y<95)
   a=5;
   else if(x>25 && x <44 && y>74 && y<95)
   a=6;
   else if(x>47 && x <66 && y>74 && y<95)
   a=7;
   else if(x>69 && x <88 && y>74 && y<95)
   a=8;
   
   else if(x>3 &&x <22 && y>50 && y<69)
   a=9;
   else if(x>25 && x <44 && y>50 && y<69)
   a=10;
   else if(x>47 && x <66 && y>50 && y<69)
   a=11;
   else if(x>69 && x <88 && y>50 && y<69)
   a=12;
   
   else if(x>3 &&x <22 && y>25 && y<45)
   a=13;
   else if(x>25 && x <44 && y>26 && y<45)
   a=14;
   else if(x>47 && x <66 && y>26 && y<45)
   a=15;
   else if(x>69 && x <88 && y>26 && y<45)
   a=16;
   
   else if(x>0 && x<94 && y>height-150 && y<height-100)
   s=0;
   else if(x>0 && x <50 && y>height-200 && y<height-150)
   s=1;
   else if(x>50 && x <94 && y>height-200 && y<height-150 )
   s=2;
}


void init()
{
     
}


void drawString(const char *str, double x=0, double y=0, double size=1.0)
{
   glPushMatrix();
   glTranslatef(x,y,0);
   glScalef(size/153.0,size/153.0,1.0);
   int itemCt = 0;
   int len = strlen(str);
   for (int i = 0; i < len; i++)
   {
      if (str[i] == '\n')
      {
         itemCt++;
         glPopMatrix();
         glPushMatrix();
         glTranslatef(x,y-size*1.15*itemCt,0);
         glScalef(size/153.0,size/153.0,1.0);
      }
      else
      {
         glutStrokeCharacter(GLUT_STROKE_ROMAN,str[i]);
      }
   }
   glPopMatrix();
}


void drawMenu()
{
      
   glColor3f(0.5,0.31,0.6);      
   glRectf(0,0,95,height);

   glColor3f(0,0,0);    
   glLineWidth(2);
   glBegin(GL_LINES);

      glVertex2f(1,1);    
      glVertex2f(94,1);

      glVertex2f(1,1);        
      glVertex2f(1,height);

      glVertex2f(94,1);       
      glVertex2f(94,height);

      glVertex2f(0,height-1);     
      glVertex2f(94,height-1);
      
      glVertex2f(0,height-50);   
      glVertex2f(94,height-50);

      glVertex2f(0,height-100);   
      glVertex2f(94,height-100);
      
      glVertex2f(0,height-150);      
      glVertex2f(94,height-150);
      
      glVertex2f(0,height-200);      
      glVertex2f(94,height-200);
      glVertex2f(50,height-150);      
      glVertex2f(50,height-200);
      
      glVertex2f(0,height-250); 
       glVertex2f(94,height-250);
      

      
      glEnd();
      
      glColor3f(0,0,0);       //black BOX
      glBegin(GL_QUADS);
      glVertex2f(3,100);
      glVertex2f(22,100);
      glVertex2f(22,119);
      glVertex2f(3,119);
      glEnd();
      
       glColor3f(0,0,1);       //blue BOX
      glBegin(GL_QUADS);
      glVertex2f(25,100);
      glVertex2f(44,100);
      glVertex2f(44,119);
      glVertex2f(25,119);
      glEnd();
      
       glColor3f(0,1,0);       //green BOX
      glBegin(GL_QUADS);
      glVertex2f(47,100);
      glVertex2f(66,100);
      glVertex2f(66,119);
      glVertex2f(47,119);
      glEnd();
      
       glColor3f(1,0,0);       //red
      glBegin(GL_QUADS);
      glVertex2f(69,100);
      glVertex2f(88,100);
      glVertex2f(88,119);
      glVertex2f(69,119);
      glEnd();
      
       glColor3f(0,1,1);       //g=1,b=1
      glBegin(GL_QUADS);
      glVertex2f(3,95);
      glVertex2f(22,95);
      glVertex2f(22,74);
      glVertex2f(3,74);
      glEnd();
      
       glColor3f(1,0,1);       //r=1,b=1
      glBegin(GL_QUADS);
      glVertex2f(25,95);
      glVertex2f(44,95);
      glVertex2f(44,74);
      glVertex2f(25,74);
      glEnd();
      
       glColor3f(1,1,0);       //r=1,g=1
      glBegin(GL_QUADS);
      glVertex2f(47,95);
      glVertex2f(66,95);
      glVertex2f(66,74);
      glVertex2f(47,74);
      glEnd();
      
       glColor3f(1,1,1);       //white
      glBegin(GL_QUADS);
      glVertex2f(69,95);
      glVertex2f(88,95);
      glVertex2f(88,74);
      glVertex2f(69,74);
      glEnd();
      
       glColor3f(0.5,0.5,0.5);       //all light
      glBegin(GL_QUADS);
      glVertex2f(3,69);
      glVertex2f(22,69);
      glVertex2f(22,50);
      glVertex2f(3,50);
      glEnd();
      
       glColor3f(0.5,0.5,0);       //r,g light
      glBegin(GL_QUADS);
      glVertex2f(25,69);
      glVertex2f(44,69);
      glVertex2f(44,50);
      glVertex2f(25,50);
      glEnd();
      
       glColor3f(0.5,0,0.5);       //r,b light
      glBegin(GL_QUADS);
      glVertex2f(47,69);
      glVertex2f(66,69);
      glVertex2f(66,50);
      glVertex2f(47,50);
      glEnd();
      
       glColor3f(0,0.5,0.5);       //b,g light
      glBegin(GL_QUADS);
      glVertex2f(69,69);
      glVertex2f(88,69);
      glVertex2f(88,50);
      glVertex2f(69,50);
      glEnd();
      
       glColor3f(0.1,0.6,0.2);       //
      glBegin(GL_QUADS);
      glVertex2f(3,45);
      glVertex2f(22,45);
      glVertex2f(22,26);
      glVertex2f(3,26);
      glEnd();
      
      glColor3f(0.1,0.3,0.7);       //
      glBegin(GL_QUADS);
      glVertex2f(25,45);
      glVertex2f(44,45);
      glVertex2f(44,26);
      glVertex2f(25,26);
      glEnd();
      
       glColor3f(0.6,0.1,0.3);       //
      glBegin(GL_QUADS);
      glVertex2f(47,45);
      glVertex2f(66,45);
      glVertex2f(66,26);
      glVertex2f(47,26);
      glEnd();
      
       glColor3f(0.2,0.2,0.6);       //
      glBegin(GL_QUADS);
      glVertex2f(69,45);
      glVertex2f(88,45);
      glVertex2f(88,26);
      glVertex2f(69,26);
      glEnd();
      



   glLineWidth(1);  // Restore line width to 1.
   glColor3f(0,0,0);
   drawString("Clear",10,height-35,25);  
   drawString("Undo",10,height-85,25);
   drawString("lines",10,height-135,25);
   drawString("fill rect rect",3,height-185,16);
   drawString("pencil",10,height-235,25);
   
}


void drawItems()
{
     for (int i = 0; i < itemCt; i++)
     {
     
   if(items[i].q==1)
   glColor3f(0,0,0);  
    if(items[i].q==2)
   glColor3f(0,0,1);
    if(items[i].q==3)
   glColor3f(0,1,0);
    if(items[i].q==4)
   glColor3f(1,0,0);
   
   if(items[i].q==5)
   glColor3f(0,1,1);  
    if(items[i].q==6)
   glColor3f(1,0,1);
    if(items[i].q==7)
   glColor3f(1,1,0);
    if(items[i].q==8)
   glColor3f(1,1,1);
   
   if(items[i].q==9)
   glColor3f(0.5,0.5,0.5);  
    if(items[i].q==10)
   glColor3f(0.5,0.5,0);
    if(items[i].q==11)
   glColor3f(0.5,0,0.5);
    if(items[i].q==12)
   glColor3f(0,0.5,0.5);
   
   if(items[i].q==13)
   glColor3f(0.1,0.6,0.2); 
    if(items[i].q==14)
     glColor3f(0.1,0.3,0.7);
    if(items[i].q==15)
    glColor3f(0.6,0.1,0.3);
    if(items[i].q==16)
     glColor3f(0.2,0.2,0.6); 
   
   if(items[i].qs==0)
   {
       glBegin(GL_LINE_LOOP);
             glVertex2f(items[i].x1, items[i].y1);
             glVertex2f(items[i].x2, items[i].y2);
       glEnd();
   }
   
   if(items[i].qs==1) 
      glRectd(items[i].x1, items[i].y1,items[i].x2, items[i].y2);
      
   if(items[i].qs==2)
   {
       glBegin(GL_LINE_LOOP);
             glVertex2f(items[i].x1, items[i].y1);
             glVertex2f(items[i].x1, items[i].y2);
             glVertex2f(items[i].x2, items[i].y2);
             glVertex2f(items[i].x2, items[i].y1);
          glEnd();
   }
  
    }
      
      
      
 
}



void initTransformation(double x1, double x2, double y1, double y2)
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(x1,x2,y1,y2);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}



void display() {
   glClearColor(1.0,1.0,1.0,1.0);  
   glClear(GL_COLOR_BUFFER_BIT);   

   glViewport(94,0,width-94,height);  

   initTransformation(0,1,0,1);  
   drawItems();  
   
   glViewport(0,0,94,height);  
   initTransformation(0,94,0,height);  
   drawMenu();  

   glutSwapBuffers();  
}



void reshape(int new_width, int new_height) {
   height = new_height;
   width = new_width;
   glViewport(0,0,width,height);
}



void mouse(int button, int state, int x, int y)
{
   if (x < 94 && state == GLUT_DOWN)
   {  
      handleMenuMouse(x,height-y,glutGetModifiers());
   }
   else if (button == GLUT_LEFT_BUTTON)
   {
      double wx, wy; 
      wx = (double)(x-94)/(width-94);
      wy = (double)(height-y)/height;
      if (state == GLUT_DOWN)
         {
                handleStartDraw(wx,wy,glutGetModifiers());
                //flag=1;
         }
      else
        {
                 handleFinishDraw(wx,wy);
                 //flag=0;
        }
   }
}



void motion(int x, int y) {
   if (dragging) {
      double wx, wy;  
      wx = (double)(x-94)/(width-94);
      wy = (double)(height-y)/height;
      handleContinueDraw(wx,wy);      
   }
   
}


void keyboard(unsigned char key, int x, int y) {
   if (key == 27)  
      exit(0);
}


//-----------------------------------------------MESH-------------------//
GLfloat x[]={0.0},y[]={0.0};
GLfloat x_0=-1,y_0=-1;
char strx[1000];
char stry[1000];
int state = 0;

void init1()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,800.0,0.0,700.0);
	//glutPostRedisplay();
}
void drawString1(const char *str, double x, double y, double size) { 
	glPushMatrix(); 
	glTranslatef(x,y,0); 
	glScalef(size,size,1.0); 
	glColor3f(0, 0, 0);
	int itemCt = 0; 
	int len = strlen(str); 
	for ( i = 0; i < len; i++) { 
		glutStrokeCharacter(GLUT_STROKE_ROMAN,str[i]);  
	} 
	glPopMatrix(); 
}

void display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(x_0 <= 0 || y_0 <= 0) {
		if(x_0 <= 0)
			drawString1(strx, 10, 100, 1.0/5.0);
		else
			drawString1(stry, 10, 50, 1.0/5.0);
	}
	else {
	glColor3f(1.0,0.0,0.0);
	for(i=0;i<x_0;i++)
	x[i]=150+i*dx;
	for(j=0;j<y_0;j++)
	y[j]=150+j*dy;

	glColor3f(1.0,0.0,0.0);
	for(i=0;i<x_0;i++)
	for(j=0;j<y_0-1;j++)
	{
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(x[i],y[j]);
		glVertex2f(x[i],y[j+1]);
		glVertex2f(x[i+1],y[j+1]);
		glVertex2f(x[i+1],y[j]);
		glEnd();
		
	}
	}
	glFlush();
}

void mykey1(unsigned char a, int x, int y) {
	int len;
	if(state == 0) {
		if(!isgraph(a)) {
			x_0 = atoi(strx+16);
			state = 1;
		}
		else {
		len = strlen(strx);
		strx[len] = a;
		strx[len+1] = '\0';
		}
	}
	else {
		if(!isgraph(a)) {
			y_0 = atoi(stry+19);
			state = 1;
		}
		else {
		len = strlen(stry);
		stry[len] = a;
		stry[len+1] = '\0';
		}
	}
	glutPostRedisplay();
}
//-----------------------------------------MESH END--------------------------//

//-----------------------------------------color cube--------------------//
GLfloat vertices[][3] = {{-1.0,-1.0,1.0},{-1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,-1.0,1.0} ,
{-1.0,-1.0,-1.0},{-1.0,1.0,-1.0},{1.0,1.0,-1.0}, {1.0,-1.0,-1.0}};

 GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0}, 
						{0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,1.0,0.0},{1.0,0.0,1.0}, 
						{0.0,1.0,-1.0},{1.0,1.0,-1.0} };
static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;

void polygon(int a, int b, int c, int d)
{	
	glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
		glVertex3fv(vertices[a]);
		glColor3fv(colors[b]);
		glVertex3fv(vertices[b]);
		glColor3fv(colors[c]);
		glVertex3fv(vertices[c]);
		glColor3fv(colors[d]);
		glVertex3fv(vertices[d]);
	glEnd();
}
void colorcube()
{	
	polygon(0,3,2,1);
	polygon(2,3,7,6);
	polygon(0,4,7,3);
	polygon(1,2,6,5);
	polygon(4,5,6,7);
	polygon(0,1,5,4);
}
void display2()
{ 
   
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	colorcube();
	glFlush();
	glutSwapBuffers();
}

void spinCube()
{
	theta[axis] += 0.1;
	if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
	glutPostRedisplay();	
}
void mouse2(int btn, int state, int x, int y)
{	
	if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 0;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 2;
}
void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
            2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
            2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

////////////////////////////////////////////////colorcube-end//////////////////////////////////////////////////////


/////////////////////////////////////////////tea pot-----------------------------------
void wall(double thickness)
{
     glPushMatrix();
     glTranslated(0.5,0.5*thickness,0.5);
     glScaled(1.0,thickness,1.0);
     glutSolidCube(1.0);
     glPopMatrix();
}
void tl(double thick,double len)
{
     glPushMatrix();
     glTranslated(0,len/2,0);
     glScaled(thick,len,thick);
     glutSolidCube(1.0);
     glPopMatrix();
}
void table(double tw,double tt,double lt,double ll)
{
     glPushMatrix();
     glTranslated(0,ll,0);
     glScaled(tw,tt,tw);
     glutSolidCube(1.0);
     glPopMatrix();
     double dist=0.95*tw/2.0-lt/2.0;
     glPushMatrix();
     glTranslated(dist,0,dist);
     tl(lt,ll);
     glTranslated(0.0,0.0,-2*dist);
     tl(lt,ll);
     glTranslated(-2*dist,0,2*dist);
     tl(lt,ll);
     glTranslated(0,0,-2*dist);
     tl(lt,ll);
     glPopMatrix();
}
void display3(void)
{
     GLfloat ma[]={1.0f,0.0f,0.0f,0.0f};
     GLfloat md[]={0.5f,0.5f,0.5f,1.0f};
     GLfloat ms[]={1.0f,1.0f,1.0f,1.0f};
     GLfloat msh[]={50.0f};
     glMaterialfv(GL_FRONT,GL_AMBIENT,ma);
     glMaterialfv(GL_FRONT,GL_DIFFUSE,md);
     glMaterialfv(GL_FRONT,GL_SPECULAR,ms);
     glMaterialfv(GL_FRONT,GL_SHININESS,msh);
     GLfloat li[]={0.9f,0.9f,0.9f,1.0f};
     GLfloat lp[]={2.0f,6.0f,3.0f,0.0f};
     glLightfv(GL_LIGHT0,GL_POSITION,lp);
     glLightfv(GL_LIGHT0,GL_DIFFUSE,li);
     
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     double w=1.0;
     glOrtho(-w*64/48.0,w*64/48.0,-w,w,0.1,100.0);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     gluLookAt(2.3,1.3,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
     
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
    glPushMatrix ();
    glTranslated(0.4,0.4,0.6);
    glRotated(45,0,0,1);
    glScaled(0.08,0.08,0.08);
    glPopMatrix();
     
     glPushMatrix ();
     glTranslated(0.4,0.38,0.4); 
     glRotated(30,0,1,0);
     glutSolidTeapot(0.08);
     glPopMatrix();
     
     glPushMatrix ();
     glTranslated(0.4,0,0.4);
     table(0.6,0.02,0.02,0.3);
     glPopMatrix();
     wall(0.02);
     
     glPushMatrix();
     glRotated(90.0,0.0,0.0,1.0);
     wall(0.02);
     glPopMatrix();
     
     glPushMatrix();
     glRotated(-90.0,1.0,0.0,0.0);
     wall(0.02);
     glPopMatrix();     
     glFlush();
     
}

////////////////////////////////////////////////teapot-end/////////////////////////////////////////////////////////

////////////////////////////////////////////////// Cylinder and parallelopiped///////////////////////////////

GLint xa=-1,ya=-1;
char strx1[1000];
char stry1[1000];
int st = 0;

void mykey4(unsigned char a, int x, int y) {
	int len;
	if(st == 0) {
		if(!isgraph(a)) {
			xa = atoi(strx1+14);
			st = 1;
		}
		else {
		len = strlen(strx1);
		strx1[len] = a;
		strx1[len+1] = '\0';
		}
	}
	else {
		if(!isgraph(a)) {
			ya = atoi(stry1+15);
			st = 1;
		}
		else {
		len = strlen(stry1);
		stry1[len] = a;
		stry1[len+1] = '\0';
		}
	}
	glutPostRedisplay();
}


void draw_pixel(GLint cx, GLint cy)
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2f(cx, cy);
	glEnd();
}

void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
	draw_pixel(x+h, y+k);
	draw_pixel(-x+h, y+k);
	draw_pixel(x+h, -y+k);
	draw_pixel(-x+h, -y+k);
	draw_pixel(y+h, x+k);
	draw_pixel(-y+h, x+k);
	draw_pixel(y+h, -x+k);
	draw_pixel(-y+h, -x+k);
}

void circle_draw(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0,y=r;
	while(y>x)
	{
		plotpixels(h, k, x, y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h, k, x, y);
}

void cylinderdraw()
{
	GLint xc=100,yc=100,r=50; 
GLint i;
	for(i=0;i<xa;i+=ya)
	{
          	glPointSize(1.5);               
		circle_draw(xc, yc+i, r);
	}
}

void parallelpiped(int x1, int x2, int y1, int y2)
{
	glColor3f(0.0,0.0,1.0);
	glPointSize(1.5);
	glBegin(GL_LINE_LOOP);
		glVertex2i(x1,y1);
		glVertex2i(x2,y1);
		glVertex2i(x2,y2);
		glVertex2i(x1,y2);
	glEnd();
}

void parallelpiped_draw()
{
	int x1=200,x2=300,y1=100,y2=175;
	GLint i;
	for(i=0;i<xa;i+=ya)
	{
		parallelpiped(x1+i,x2+i,y1+i,y2+i);
	}
}

void init4(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,400.0,0.0,300.0);
}

void display4(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1,1,1);
	if(xa <= 0 || ya <= 0) {
		if(xa <= 0)
			drawString1(strx1, 10, 50, 1.0/5.0);
		else
			drawString1(stry1, 10, 25, 1.0/5.0);
	}
	else {
	glColor3f(1.0,0.0,0.0);
	cylinderdraw();
	parallelpiped_draw();
	
    
    }   
    glFlush();
}
/////////////////////////////////cylinder and parallelopiped-end///////////////////////////////////////

/////////////////////////////////camera perspective view///////////////////////////////////////////////

GLfloat ver[][3] = {{-1.0,-1.0,1.0},{-1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,-1.0,1.0},{-1.0,-1.0,-1.0},
{-1.0,1.0,-1.0},{1.0,1.0,-1.0}, {1.0,-1.0,-1.0}};
GLfloat col[][3]={{0.0,0.0,0.0},{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,0.0},{1.0,0.0,1.0},{0.0,1.0,1.0},{1.0,1.0,1.0}};
void polygon6(int a,int b,int c,int d)
{
	glBegin(GL_POLYGON);
	glColor3fv(col[a]);
	glVertex3fv(ver[a]);
	glColor3fv(col[b]);
	glVertex3fv(ver[b]);
	glColor3fv(col[c]);
	glVertex3fv(ver[c]);
	glColor3fv(col[d]);
	glVertex3fv(ver[d]);
	glEnd();
}
void colorcube6()
{
	polygon6(0,3,2,1);polygon6(2,3,7,6);polygon6(0,4,7,3);
	polygon6(1,2,6,5);polygon6(4,5,6,7);polygon6(0,1,5,4);
}
GLfloat the[]={0.0,0.0,0.0};
GLint ax=2;
GLdouble view[]={0.0,0.0,5.0};

void spincube6()
{
	the[ax]+=0.5;
	if(the[ax]>360.0) the[ax]-=360.0;
	glutPostRedisplay();
}
void display6()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(view[0],view[1],view[2],0.0,0.0,0.0,0.0,1.0,0.0);
	glRotatef(the[0],1.0,0.0,0.0);
	glRotatef(the[1],0.0,1.0,0.0);
	glRotatef(the[2],0.0,0.0,1.0);
	colorcube6();
	glFlush();
	glutSwapBuffers();
}
void mymouse6(int btn,int state,int x,int y)
{	
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN) ax=0;
	if(btn==GLUT_MIDDLE_BUTTON&&state==GLUT_DOWN) ax=1;
	if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN) ax=2;
	the[ax]+=2.0;
	if(the[ax]>360.0) the[ax]-=360.0;
	display6();
}
void keys6(unsigned char key,int x,int y)
{
		if(key=='X') view[0]-=1.0;
		if(key=='x') view[0]+=1.0;
		if(key=='Y') view[1]-=1.0;
		if(key=='y') view[1]+=1.0;
		if(key=='Z') view[2]-=1.0;
		if(key=='z') view[2]+=1.0;
		display6();
}
void myReshape6(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
	glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else
	glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);

	gluPerspective(50.0,w/h,1.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}
//////////////////////////////camera view end//////////////////////////////////////////////

///////////////////////////////tetrahedron//////////////////////////////////////////////
GLfloat v[4][3]={{0.0,0.0,1.0},{0.0,0.9,-0.3},{-0.8,-0.4,-0.3},{0.8,-0.4,-0.3}};
GLfloat colors1[4][3]={{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.0,0.0,0.0}};
int n = -1;
char strx2[1000] = {'\0'};
int w1, w2;


void mykey7(unsigned char a, int x, int y)
{
	int len;
		if(!isgraph(a))
        {
			n = atoi(strx2+21);
		}
		else
        {
		len = strlen(strx2);
		strx2[len] = a;
		strx2[len+1] = '\0';
		}
	
	glutPostRedisplay();
}

void init7()
{    
   	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2,2,-2,2,-2,2);
	glMatrixMode(GL_MODELVIEW);	
 }
void triangle(GLfloat *va,GLfloat *vb,GLfloat *vc)
{
     glBegin(GL_TRIANGLES);
	glVertex3fv(va);
	glVertex3fv(vb);
	glVertex3fv(vc);
    glEnd();
	glFlush();
}
void tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d)
{
	glColor3fv(colors1[0]);
	triangle(a,b,c);
	glColor3fv(colors1[1]);
	triangle(a,c,d);
	glColor3fv(colors1[2]);
	triangle(a,d,b);
	glColor3fv(colors1[3]);
	triangle(b,d,c);
}
void divide_tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,int m)
{
	GLfloat mid[6][3];
	int j;
	if(m>0)
	{
		for(j=0;j<3;j++) mid[0][j]=(a[j]+b[j])/2;
		for(j=0;j<3;j++) mid[1][j]=(a[j]+c[j])/2;
		for(j=0;j<3;j++) mid[2][j]=(a[j]+d[j])/2;
		for(j=0;j<3;j++) mid[3][j]=(b[j]+d[j])/2;
		for(j=0;j<3;j++) mid[4][j]=(d[j]+c[j])/2;
		for(j=0;j<3;j++) mid[5][j]=(b[j]+c[j])/2;

		divide_tetra(a,mid[0],mid[1],mid[2],m-1);
		divide_tetra(mid[0],b,mid[3],mid[5],m-1);
		divide_tetra(mid[1],mid[4],c,mid[5],m-1);
		divide_tetra(mid[2],mid[3],mid[4],d,m-1);
	}
	else
		tetra(a,b,c,d);
}


void display7()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	divide_tetra(v[0],v[1],v[2],v[3],n);
	glEnd();
	glFlush();
}

void display71()
{
	glColor3f(1, 0, 0);
	
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1,1,1);

	drawString1(strx2, 10, 100, 1.0/5.0);

	if(n != -1) {
		glutDestroyWindow( win); 
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
        	glutInitWindowSize(800,700);
        	glutInitWindowPosition(105,0);
        	win = glutCreateWindow("3DGasKet");
       	    //glutKeyboardFunc(mykey1);
            glutDisplayFunc(display7);
         
        	init7();
        	glEnable(GL_DEPTH_TEST);
        	glClearColor(1.0,1.0,1.0,1.0);
        	glutMainLoop();
	}
	glFlush();
}

void init71()
{    
   	glClearColor(1,1,1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,799,0.0,799);
 }

//////////////////////////////////////////////////tetrahedron-end/////////////////////////////////////////////////
 
//////////////////////////////////////////////liang barsky-----------------------------------------

GLint arr1[2][2];
int z1=0,fl=0;
char sy[1000];

void mousex(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
               fl=1;
               
                  
   }
   if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)  
   {
            fl=0;
   }
   if(fl)
     {
        y=(700-y);
        arr1[z1][0]=x;
        arr1[z1][1]=y;
        z1++;
     }
}
void draw_Points()
{
     i=0;
  
    glBegin( GL_LINES);
    glColor3f( 0.0,0.0,0.0 );
    for (; i < z1 && i<2; i++)
    {
		if(arr1[i][0] == s && arr1[i][1] == s)
        {
                     i++;
                     break;
        }
        glVertex2f( arr1[i][0], arr1[i][1]);
    }
    glEnd();
	
}


double xmin=50,ymin=50,xmax=150,ymax=150;
double xvmin=300,yvmin=300,xvmax=600,yvmax=600;
float X0,Y0,X1,Y1;

int cliptest(double p,double q,double *t1,double *t2)
{
    double t=q/p;
    if(p<0.0)
    {
             if(t>*t1) *t1=t;
             if(t>*t2) return(false);
    }
    else
        if(p>0.0)
        {
                 if(t<*t2) *t2=t;
                 if(t<*t1) return(false);
        }
        else
            if(p==0.0)
            {
                          if(q<0.0) return(false);
            }
            return(true);
}
void Liang(double x0,double y0, double x1, double y1)
{
     double dz=x1-x0,da=y1-y0,te=0.0,t1=1.0;
     glColor3f(1.0,0.0,0.0);
             
                            glBegin(GL_LINE_LOOP);
                            glVertex2f(xvmin,yvmin);
                            glVertex2f(xvmax,yvmin);
                            glVertex2f(xvmax,yvmax);
                            glVertex2f(xvmin,yvmax);
                            glEnd();
     if(cliptest(-dz,x0-xmin,&te,&t1))
      if(cliptest(dz,xmax-x0,&te,&t1)) 
       if(cliptest(-da,y0-ymin,&te,&t1))
        if(cliptest(da,ymax-y0,&te,&t1))
        {
                                      if(t1<1.0)
                                      {
                                                    x1=x0+t1*dz;
                                                    y1=y0+t1*da;
                                      }
                                      if(te>0.0)
                                      {
                                                    x0=x0+te*dz;
                                                    y0=y0+te*da;
                                      }
                                      //printf("\n%f  %f:  %f  %f",x0,y0,x1,y1);
                                      double sx=(xvmax-xvmin)/(xmax-xmin);
                                      double sy=(yvmax-yvmin)/(ymax-ymin);
                                      double vx0=xvmin+(x0-xmin)*sx;
                                      double vy0=yvmin+(y0-ymin)*sy;
                                      double vx1=xvmin+(x1-xmin)*sx;
                                      double vy1=yvmin+(y1-ymin)*sy;
                                      glColor3f(0.0,0.0,1.0);
                                      glBegin(GL_LINES);
                                      glVertex2d(vx0,vy0);
                                      glVertex2d(vx1,vy1);
                                      glEnd();
      }
}
void display10()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0,0.0,0.0);
     drawString1(sy, 100, 660, 1.0/5.0);
     glBegin(GL_LINES);
     glEnd();
     draw_Points();
     glColor3f(0.0,0.0,1.0);
     glBegin(GL_LINE_LOOP);
     glVertex2f(xmin,ymin);
     glVertex2f(xmax,ymin);
     glVertex2f(xmax,ymax);
     glVertex2f(xmin,ymax);
     glEnd();
     Liang(arr1[0][0],arr1[0][1],arr1[1][0],arr1[1][1]);
     glutSwapBuffers();
    glutPostRedisplay();
     glFlush();
}
void myinit10()
{
     glClearColor(1.0,1.0,1.0,1.0);
     glColor3f(1.0,0.0,0.0);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,800.0,0.0,700.0);
     	glMatrixMode(GL_MODELVIEW);
	for(i=0;i<2;i++)
    {
        arr1[i][0]=0;
        arr1[i][1]=0;
    }
    glPointSize(2.0);
}
///////////////////////////////Liang-barskey-end//////////////////////////////////////////////////////


//////////////////////////////////////////////// house///////////////////////////////////////////////////////////
GLfloat house[3][9] = {{200.0,200.0,275.0,350.0,350.0,250.0,250.0,300.0,300.0},{200.0,300.0,350.0,300.0,200.0,200.0,250.0,250.0,200.0},{1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0}};
GLfloat rot_mat[3][3]={{0},{0},{0}};
GLfloat result[3][9]={{0},{0},{0}};
GLfloat h=200.0;
GLfloat k=200.0;
GLfloat theta1;
char strxh[1000];

void multiply()
{
     int i,j,l;
     for(i=0;i<3;i++)
     for(j=0;j<9;j++)
     {
                     result[i][j]=0;
                     for(l=0;l<3;l++)
                     result[i][j]=result[i][j]+rot_mat[i][l]*house[l][j];
     }
}
int rotate()
{
      theta1=theta1*(3.14/180);
	GLfloat m,n;
	m=-h*(cos(theta1)-1)+k*(sin(theta1));
	n=-k*(cos(theta1)-1)-h*(sin(theta1));
    rot_mat[0][0]=cos(theta1);
    rot_mat[0][1]=-sin(theta1);
    rot_mat[0][2]=m;
    rot_mat[1][0]=sin(theta1);
    rot_mat[1][1]=cos(theta1);
    rot_mat[1][2]=n;
    rot_mat[2][0]=0;
    rot_mat[2][1]=0;
    rot_mat[2][2]=1;
    multiply();
     return 0;
 }
     

void rhouse()
{
     glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(result[0][0],result[1][0]);
	glVertex2i(result[0][1],result[1][1]);
	glVertex2i(result[0][3],result[1][3]);
	glVertex2i(result[0][4],result[1][4]);
	glEnd();
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(result[0][5],result[1][5]);
	glVertex2i(result[0][6],result[1][6]);
	glVertex2i(result[0][7],result[1][7]);
	glVertex2i(result[0][8],result[1][8]);
	glEnd();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(result[0][1],result[1][1]);
	glVertex2i(result[0][2],result[1][2]);
	glVertex2i(result[0][3],result[1][3]);
	glEnd();
}
void dhouse()
{
     glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(house[0][0],house[1][0]);
	glVertex2i(house[0][1],house[1][1]);
	glVertex2i(house[0][3],house[1][3]);
	glVertex2i(house[0][4],house[1][4]);
	glEnd();
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(house[0][5],house[1][5]);
	glVertex2i(house[0][6],house[1][6]);
	glVertex2i(house[0][7],house[1][7]);
	glVertex2i(house[0][8],house[1][8]);
	glEnd();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(house[0][1],house[1][1]);
	glVertex2i(house[0][2],house[1][2]);
	glVertex2i(house[0][3],house[1][3]);
	glEnd();
}

void mykey8(unsigned char a, int x, int y) {
	int len;
		if(!isgraph(a)) 
        {
			theta1 = atoi(strxh+19);
		}
		else
        {
    		len = strlen(strxh);
    		strxh[len] = a;
    		strxh[len+1] = '\0';
        }
	glutPostRedisplay();
}

void display8()
{
	glClear(GL_COLOR_BUFFER_BIT);
			drawString1(strxh, 10, 100, 1.0/5.0);
	dhouse();
	rotate();
	rhouse();
	glFlush();
}
void myinit8()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
	
}


//////////////////////////////////////////////////house -end/////////////////////////////////////////////

//////////////////////////////////////////////cohen sutherland-----------------------------------------
GLint arr2[2][2];
int z2=0,f2=0;
char sz[1000];

void mousex2(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
               f2=1;
               
                  
   }
   if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)  
   {
            f2=0;
   }
   if(f2)
     {
        y=(700-y);
        arr2[z2][0]=x;
        arr2[z2][1]=y;
        z2++;
     }
}
void draw_Points2()
{
     i=0;
  
    glBegin( GL_LINES);
    glColor3f( 0.0,0.0,0.0 );
    for (; i < z2 && i<2; i++)
    {
		if(arr2[i][0] == s && arr2[i][1] == s)
        {
                     i++;
                     break;
        }
        glVertex2f( arr2[i][0], arr2[i][1]);
    }
    glEnd();
	
}



const int RIGHT = 8;
const int LEFT = 2;
const int TOP = 4;
const int BOTTOM = 1;


outcode ComputeOutCode (double x, double y);

void CohenSutherlandLineClipAndDraw (double x0, double y0,double x1, double y1)
{
	outcode outcode0, outcode1, outcodeOut;
	int accept = 0, done = 0;

	outcode0 = ComputeOutCode (x0, y0);
	outcode1 = ComputeOutCode (x1, y1);

	do{
		if (!(outcode0 | outcode1))  
		{
			accept = true;
			done = true;
		}
		else if (outcode0 & outcode1)  
			done = true;
		else
		{
			double x, y;
			outcodeOut = outcode0? outcode0: outcode1;
			if (outcodeOut & TOP)          
			{
				x = x0 + (x1 - x0) * (ymax - y0)/(y1 - y0);
				y = ymax;
			}
			else if (outcodeOut & BOTTOM)  
			{
				x = x0 + (x1 - x0) * (ymin - y0)/(y1 - y0);
				y = ymin;
			}
			else if (outcodeOut & RIGHT)  
			{
				y = y0 + (y1 - y0) * (xmax - x0)/(x1 - x0);
				x = xmax;
			}
			else                          
			{
				y = y0 + (y1 - y0) * (xmin - x0)/(x1 - x0);
				x = xmin;
			}

			if (outcodeOut == outcode0)
			{
				x0 = x;
				y0 = y;
				outcode0 = ComputeOutCode (x0, y0);
			}
			else 
			{
				x1 = x;
				y1 = y;
				outcode1 = ComputeOutCode (x1, y1);
			}
		}
	}while (!done);

	if (accept)
	{               
		double sx=(xvmax-xvmin)/(xmax-xmin); 
		double sy=(yvmax-yvmin)/(ymax-ymin);
		double vx0=xvmin+(x0-xmin)*sx;
		double vy0=yvmin+(y0-ymin)*sy;
		double vx1=xvmin+(x1-xmin)*sx;
		double vy1=yvmin+(y1-ymin)*sy;
		
		glColor3f(0.0,0.0,1.0); 
		glBegin(GL_LINES);
			glVertex2d (vx0, vy0);
			glVertex2d (vx1, vy1);
		glEnd();
	}
}


outcode ComputeOutCode (double x, double y)
{
	outcode code = 0;
	if (y > ymax)             
		code |= TOP;
	else if (y < ymin)         
		code |= BOTTOM;
	if (x > xmax)              
		code |= RIGHT;
	else if (x < xmin)         
		code |= LEFT;
	return code;
}


void display11()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0,0.0,0.0);
     drawString1(sz, 60, 660, 1.0/5.0);
     glBegin(GL_LINES);
     glEnd();
     draw_Points2();
     glColor3f(0.0,0.0,1.0);
     glBegin(GL_LINE_LOOP);
     glVertex2f(xmin,ymin);
     glVertex2f(xmax,ymin);
     glVertex2f(xmax,ymax);
     glVertex2f(xmin,ymax);
     glEnd();
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_LINE_LOOP);
			glVertex2f(xvmin, yvmin);
			glVertex2f(xvmax, yvmin);
			glVertex2f(xvmax, yvmax);
			glVertex2f(xvmin, yvmax);
		glEnd();
     CohenSutherlandLineClipAndDraw(arr2[0][0],arr2[0][1],arr2[1][0],arr2[1][1]);
     glutSwapBuffers();
    glutPostRedisplay();
     glFlush();
}
void myinit11()
{
     glClearColor(1.0,1.0,1.0,1.0);
     glColor3f(1.0,0.0,0.0);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,800.0,0.0,700.0);
     	glMatrixMode(GL_MODELVIEW);
	for(i=0;i<2;i++)
    {
        arr2[i][0]=0;
        arr2[i][1]=0;
    }
    glPointSize(2.0);
}
///////////////////////////////cohen-sutherland end//////////////////////////////////////////////////////

/////////////////////////////////////////////////Area filling algo///////////////////////////////////
GLint a1[4][2];
int g=0; 
float xo1,x2,x3,x4,yo1,y2,y3,y4;

void edgedetect(GLfloat xo1, GLfloat yo1, GLfloat x2, GLfloat y2,GLint *le,int *re)
{
	float mx,x,temp;
	int i;
	if((y2-yo1)<0)	
	{
		temp=yo1;yo1=y2;y2=temp;
		temp=xo1;xo1=x2;x2=temp;
	}
	if((y2-yo1)!=0)	
		mx=(x2-xo1)/(y2-yo1);
	else
		mx=x2-xo1;
	x=xo1;
	for(i=yo1;i<=y2;i++)
	{
		if(x<(float)le[i])
			le[i]=(int)x;
		if(x>(float)re[i])
			re[i]=(int)x;
		x+=mx;
	}
}
void draw_ppixel(GLint x, GLint y, GLfloat v)
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}
void scanfill(float xo1,float yo1, float x2, float y2,float x3, float y3,float x4, float y4)
{
	int le[800],re[800];
	int i,scanline;
	for(i=0;i<800;i++)
	{
		le[i]=800;
		re[i]=0;
	}
    edgedetect(xo1,yo1,x2,y2,le,re);	
    edgedetect(x2,y2,x3,y3,le,re);	
    edgedetect(x3,y3,x4,y4,le,re);	
    edgedetect(x4,y4,xo1,yo1,le,re);	
	for(scanline=0; scanline<800; scanline++)
	{
		if(le[scanline]<=re[scanline])
		    for(i=(int)le[scanline];i<(int)re[scanline];i++)
		     if(scanline%2!=0)
			                  draw_ppixel(i,scanline,BLACK);
          		
	}

}
void drawSquare()
{
	if(g<4) return;
	glPointSize(1);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(a1[0][0] ,a1[0][1] );
	glVertex2f(a1[1][0] ,a1[1][1] );
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(a1[1][0] ,a1[1][1] );
	glVertex2f(a1[2][0] ,a1[2][1] );
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(a1[2][0] ,a1[2][1] );
	glVertex2f(a1[3][0] ,a1[3][1] );
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(a1[3][0] ,a1[3][1] );
	glVertex2f(a1[0][0] ,a1[0][1] );
	glEnd();

}
void mouser(int bin, int state , int x , int y)
{
	if(bin == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
    	y=700-y;
    	a1[g][0]=x;
    	a1[g][1]=y;
    	g++;
    }
    glutPostRedisplay();
}
char sx[1000];
void display9()
{
     xo1=a1[0][0];yo1=a1[0][1];x2=a1[1][0];y2=a1[1][1];x3=a1[2][0];y3=a1[2][1];x4=a1[3][0];y4=a1[3][1];
	glClear(GL_COLOR_BUFFER_BIT);
    drawString1(sx, 70, 10, 1.0/5.0);	
	glColor3f(1.0,1.0,1.0);
	drawSquare();
	if(g==4)
	scanfill(xo1,yo1,x2,y2,x3,y3,x4,y4);
	glutSwapBuffers();
	glFlush();
}
void myinit9()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glViewport( 0,0, 800, 700 );
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho( 0.0, 800.0, 0.0, 700.0, 1.0, -1.0 );
	glLoadIdentity();
	gluOrtho2D(0.0,800.0,0.0,700.0);
}
/////////////////////////////////////////////////line scanning algo end////////////////////////////////

void select_fig(int id)         // select figure to draw menu
{
    switch(id)
    {
        case 1:
             if(win!=0)
            glutDestroyWindow(win); 
        strcpy(strx, "Enter max rows: ");
    	strcpy(stry, "Enter max columns: ");
    	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    	glutInitWindowSize(800,700);
    	glutInitWindowPosition(108,0);
    	win=glutCreateWindow("Rectangular mesh");
    	glutKeyboardFunc(mykey1);
    	glutDisplayFunc(display1);
    	init1();
    	glutMainLoop();
                       break;
        
        case 3:
             if(win!=0)
            glutDestroyWindow(win); 
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(800, 700);
        glutInitWindowPosition(105,0);
        win=glutCreateWindow("colorcube");
        glutReshapeFunc(myReshape);
        glutDisplayFunc(display2);
        glutIdleFunc(spinCube);
        glutMouseFunc(mouse2);
        glEnable(GL_DEPTH_TEST); /* Enable hidden-surface removal */
        glutMainLoop();
            break;
            
        case 4:
             if(win!=0)
            glutDestroyWindow(win); 
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    	glutInitWindowSize(800,700);
    	glutInitWindowPosition(105,0);
    	win=glutCreateWindow("TEAPOT");
    	glutDisplayFunc(display3);
    	glEnable(GL_LIGHTING);
    	glEnable(GL_LIGHT0);
    	glShadeModel(GL_SMOOTH);
    	glEnable(GL_DEPTH_TEST);
    	glEnable(GL_NORMALIZE);
    	glClearColor(0.1,0.1,0.1,0.0);
		glViewport(0,0,700,600);
	    glutMainLoop();
                      break;
        case 5:
             if(win!=0)
            glutDestroyWindow(win); 
         strcpy(strx1, "Enter Height: ");
	     strcpy(stry1, "Enter spacing: ");
         glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    	glutInitWindowPosition(105,0);
    	glutInitWindowSize(800, 700);
    	win=glutCreateWindow("Cylinder & ParalelPiped");
    	glutKeyboardFunc(mykey4);
    	init4();
    	glutDisplayFunc(display4);
	                          break;
	
	
        case 6:
             if(win!=0)
            glutDestroyWindow(win); 
    	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    	glutInitWindowSize(800,700);
    	glutInitWindowPosition(105,0);
    	win=glutCreateWindow("colorCube");
    	glutReshapeFunc(myReshape6);
    	glutDisplayFunc(display6);
       	 glutIdleFunc(spincube6);
    	glutMouseFunc(mymouse6);
    	glutKeyboardFunc(keys6);
    	glEnable(GL_DEPTH_TEST);
	    glutMainLoop();
                       break;
        case 7:
             if(win!=0)
            glutDestroyWindow(win); 
             strcpy(strx2, "Enter max divisions: ");
            glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        	glutInitWindowSize(800,700);
        	glutInitWindowPosition(105,0);
        	win = glutCreateWindow("3DGasKet");
       	    glutKeyboardFunc(mykey7);
            glutDisplayFunc(display71);
         
        	init71();
        	//glEnable(GL_DEPTH_TEST);
        	//glClearColor(1.0,1.0,1.0,1.0);
        	glutMainLoop();
             break;
             
        case 8:
             if(win!=0)
            glutDestroyWindow(win); 
             strcpy(strxh, "Enter inclination: ");
           	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
           	glutInitWindowSize(800,700);
           	glutInitWindowPosition(105,0);
           	win=glutCreateWindow("House");
           	glutDisplayFunc(display8);
           	glutKeyboardFunc(mykey8);
           	myinit8();
           	glutMainLoop();
             break;
        case 9:
             if(win!=0)
            glutDestroyWindow(win); 
            strcpy(sx, "click mouse 4 times to form a quadrilateral ");
              glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    	glutInitWindowSize(800,700);
    	glutInitWindowPosition(105,0);
    	win=glutCreateWindow("Filling a Polygon using Scan-line Algorithm");
    	glutDisplayFunc(display9);
    		glutMouseFunc(mouser);
    	myinit9();
    	glutMainLoop();
             break;
            
            
    }
    
}


void line_menu(int id)          // sub menu
{
    switch (id)
    {
        case 2:
             if(win!=0)
            glutDestroyWindow(win);
            strcpy(sy, "liang barsky-click mouse twice to make a line "); 
             glutInitDisplayMode( GLUT_DOUBLE| GLUT_RGB|GLUT_DEPTH);
            glutInitWindowPosition(105, 0);
            glutInitWindowSize(800,700);
            win=glutCreateWindow("liang barsky");
            myinit10();
            glutMouseFunc(mousex); 
            glutDisplayFunc( display10);
            glutMainLoop();
                           break;

        case 3:
             if(win!=0)
            glutDestroyWindow(win); 
            strcpy(sz, "cohen sutherland-click mouse twice to make a line "); 
             glutInitDisplayMode( GLUT_DOUBLE| GLUT_RGB|GLUT_DEPTH);
            glutInitWindowPosition(105, 0);
            glutInitWindowSize(800,700);
            win=glutCreateWindow("cohen sutherland");
            myinit11();
            glutMouseFunc(mousex2); 
            glutDisplayFunc( display11);
            glutMainLoop();
                           break;
    }
}


void special(int key, int x, int y) {
}



void idle() {
}


int main(int argc, char **argv) 
{
    int line_sub;
 
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
   glutInitWindowSize(900,700);       
   glutInitWindowPosition(0,0);    
   glutCreateWindow("OpenGL Drawing Pad"); 
   
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);

   glutMouseFunc(mouse);       
   glutMotionFunc(motion);     
   glutKeyboardFunc(keyboard); 
   glutCreateMenu(select_fig);
   
    line_sub = glutCreateMenu(line_menu);
    glutAddMenuEntry("liang barsky", 2);
    glutAddMenuEntry("cohen sutherlan", 3);
   
    glutCreateMenu(select_fig);
    glutAddMenuEntry("rectangular mesh", 1);
    glutAddSubMenu("line clipping", line_sub);
    glutAddMenuEntry("rotating color cube", 3);
    glutAddMenuEntry("tea pot", 4);
    glutAddMenuEntry("Cylinder & ParalelPiped", 5);
    glutAddMenuEntry("cube view in camera motion", 6);
    glutAddMenuEntry("3D gasket", 7);
    glutAddMenuEntry("rotated house", 8);
    glutAddMenuEntry("scan line area filling", 9);
    glutAttachMenu(GLUT_RIGHT_BUTTON);        
   init();
   glutMainLoop();
   return 0;
}

