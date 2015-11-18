#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include "glm/glm/glm.h"

float t=20;
int i =0;
float xt = 0.5,yt = 0.5,x2,y2;
float angle;
float up_sider;
float g=0,c=0;
float k=0;
float v=0;
int SHADE=0;
int I=0;
float temp=0;
int FLAG=0;
int HEAD=0;
int rt = 45;
int LIGHT=0;
float carx=6,cary=6,am=0;
double radius=0.55;
GLuint texture_id[10];
//int KeyDown[256]={0};
float hand_rot=0;
int HAND=0;
float sx=0,sy=0;
float tx=0,ty=8;
float sun_y=0;
float vel1x=10,vel1y=0,vel1=0;
float car1x=10,car1y=10;
float temp1=0;
float wheelrot = 0.0;
float steerrot=0.0;
float back=0;
int BACK=0;
float wall = 0;
float alt,alt_a=300;
GLMmodel* pmodel1 = NULL;
GLMmodel* tree = NULL;
GLMmodel* terrain = NULL;
GLMmodel* building = NULL;
GLMmodel* car2 = NULL;
GLMmodel* grass1 = NULL;
GLMmodel* lamp = NULL;
void drawmodel_box(void)
{


	glEnable (GL_LIGHTING);
//	glEnable(GL_LIGHT0);
	GLfloat lightColor1[] ={0.1,0.1,0.1};
            glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);

	glEnable(GL_LIGHT1);
//	glEnable(GL_LIGHT3);
    glmDraw(pmodel1, GLM_SMOOTH| GLM_MATERIAL);
	glDisable(GL_LIGHTING);
//	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);

}
 
void lamp_1(){
	glEnable (GL_LIGHTING);
	GLfloat lightColor1[] ={1,1,1};
            glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);

//        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
//      glEnable(GL_LIGHT3);
    glmDraw(lamp, GLM_SMOOTH| GLM_MATERIAL);
        glDisable(GL_LIGHTING);
//        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
}
void nw_building(void)
{
	glEnable (GL_LIGHTING);
	GLfloat lightColor1[] ={1,1,1};
            glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);

//        glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
//        glEnable(GL_LIGHT3);
    	glmDraw(terrain, GLM_SMOOTH| GLM_MATERIAL | GLM_TEXTURE);
        glDisable(GL_LIGHTING);
//        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
}
void building_2(void)
{
	 glEnable (GL_LIGHTING);
	GLfloat lightColor1[] ={0.8,0.8,0.8};
            glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);

//        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
//        glEnable(GL_LIGHT3);
        glmDraw(building, GLM_SMOOTH| GLM_MATERIAL | GLM_TEXTURE);
        glDisable(GL_LIGHTING);
//        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
}
/*
void car_2(void){
	glEnable (GL_LIGHTING);
	GLfloat lightColor1[] ={1,1,1};
            glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);

//        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
//        glEnable(GL_LIGHT3);
        glmDraw(car2, GLM_SMOOTH| GLM_MATERIAL | GLM_TEXTURE);
        glDisable(GL_LIGHTING);
//        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
}*/
void grass(void){
	  glEnable (GL_LIGHTING);
	GLfloat lightColor1[] ={1,1,1};
            glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
//        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
//        glEnable(GL_LIGHT3);
        glmDraw(grass1, GLM_SMOOTH| GLM_MATERIAL | GLM_TEXTURE);
        glDisable(GL_LIGHTING);
//        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
}
/*

void nw_building(void){
//	glPushMatrix();
//	glTranslatef(0,0,-10.0);
//	glScalef(10,10,10);
	glmDraw(terrain, GLM_SMOOTH| GLM_MATERIAL | GLM_TEXTURE);
//	glPopMatrix();
}*/
void circle()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for(int i=0; i<360; i++)
	{
		glVertex3f(0.12*cos(i*3.14/180),0.12*sin(i*3.14/180) , 0.0);
	}
	glEnd();
}

void car1()
{
	
	vel1x = vel1*sin(temp1);
	vel1y = vel1*cos(temp1);
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
//	glTranslatef(0.0,0.0,-1.0);
//	glRotatef(180,0.0,1,0);
	car1x = car1x + vel1x*0.01;
	car1y = car1y + vel1y*0.01;
	glTranslatef(0.0,0.0,-1.0);
        glRotatef(180,0.0,1,0);

	glTranslatef(car1x, car1y, -0.5);
	glRotatef(-temp1*180/3.14,0.0, 0.0, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
    glPushMatrix();// body
    glScalef(2.5,.5,1);
    glutSolidCube(1.01);
	glColor3f(1.0,1.0,0.0);
	glutWireCube(1);
    glPopMatrix();
	glPushMatrix();
	glColor3f(1.0,1.0,0.0);
	glTranslatef(0.0, 0.5, -0.0);
	glBegin(GL_QUADS);

	glVertex3f(-1.25,-0.25,-0.5);
	glVertex3f(-1.25,0.25,-0.5);
	glVertex3f(0.6,0.25,-0.5);
	glVertex3f(.9,-0.25,-0.5);
	
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1,-0.2,-0.52);
	glVertex3f(-1,0.22,-0.52);
	glVertex3f(-0.1,0.22,-0.52);
	glVertex3f(-0.1,-0.2,-0.52);
	glVertex3f(0.1,-0.2,-0.52);
	glVertex3f(0.1,0.22,-0.52);
	glVertex3f(0.5,0.22,-0.52);
	glVertex3f(.8,-0.2,-0.52);
	
	
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-1.25,-0.25,0.5);
	glVertex3f(-1.25,0.25,0.5);
	glVertex3f(0.6,0.25,0.5);
	glVertex3f(0.9,-0.25,0.5);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1,-0.2,0.52);
	glVertex3f(-1,0.22,0.52);
	glVertex3f(-0.1,0.22,0.52);
	glVertex3f(-0.1,-0.2,0.52);
	glVertex3f(0.1,-0.2,0.52);
	glVertex3f(0.1,0.22,0.52);
	glVertex3f(0.5,0.22,0.52);
	glVertex3f(.8,-0.2,0.52);
	
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.6,0.25,-0.5);
	glVertex3f(0.6,0.25,0.5);
	glVertex3f(-1.25,.25,0.5);
	glVertex3f(-1.25,0.25,-0.5);
	
	glColor3f(1.0, 0.0, 0.0);
	
	glVertex3f(-1.25,.25,0.5);
	glVertex3f(-1.25,0.25,-0.5);
	glVertex3f(-1.25,-0.25,-0.5);
	glVertex3f(-1.25,-0.25,0.5);
	
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.8, 0.25, 0.0);
	glScalef(0.1, 0.2, 1.0);
	glColor3f(0.0, 1.0, 1.0);
	glutSolidCube(1.0);//Dock
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.7, 0.38, -0.25);
	glRotatef(90, 0.0, 1.0, 0.0);
	//printf("steerrot=%f\n",steerrot);
	glRotatef(steerrot, 0.0, 0.0, 1.0);
	glLineWidth(8.0);
	circle();//Steering
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f( 0.12, 0.0,0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f( 0.12*cos(2*3.14/3), 0.12*sin(2*3.14/3),0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f( 0.12*cos(4*3.14/3), 0.12*sin(4*3.14/3),0.0);
	glEnd();
	glPointSize(10);
	glBegin(GL_POINT);
	glVertex3f(0.0, 0.1, 0.0);
	glEnd();
	glPopMatrix();
	glLineWidth(1.0);

	
    glPushMatrix();
	glColor3f(0.5,0.5,0.5);
	
	
    glTranslatef(-.75,-.25,-0.5);
	glRotatef(wheelrot, 0.0, 0.0, 1.0);
    glutSolidTorus(0.09, 0.17, 20, 20); // wheel
	//////glColor3f(1,1,1);
	glLineWidth(4.0);
   	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, -0.1);
	glVertex3f(0.08,0.0,-0.1);
	glVertex3f(0.0, 0.0, -0.1);
	glVertex3f(0.08*cos(4*3.14/3),0.08*sin(4*3.14/3),-0.1);
	glVertex3f(0.0, 0.0, -0.1);
	glVertex3f(0.08*cos(2*3.14/3),0.08*sin(2*3.14/3),-0.1);
	glEnd();
	glPopMatrix();
	
	glColor3f(0.5,0.5,0.5);
	glPushMatrix();
	glTranslatef(.75,-.25,-0.5);
	glRotatef(wheelrot, 0.0, 0.0, 1.0);
    glutSolidTorus(0.09, 0.17, 20, 20);// wheel 
	//////glColor3f(1,1,1);
   	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, -0.1);
	glVertex3f(0.08,0.0,-0.1);
	glVertex3f(0.0, 0.0, -0.1);
	glVertex3f(0.08*cos(4*3.14/3),0.08*sin(4*3.14/3),-0.1);
	glVertex3f(0.0, 0.0, -0.1);
	glVertex3f(0.08*cos(2*3.14/3),0.08*sin(2*3.14/3),-0.1);
	glEnd();
    glPopMatrix();
	
	
	glColor3f(0.5,0.5,0.5);
	glPushMatrix();
	glTranslatef(.75,-.25,0.5);
	glRotatef(wheelrot, 0.0, 0.0, 1.0);
	glutSolidTorus(0.09, 0.17, 20, 20);// wheel
	//////glColor3f(1,1,1);
   	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.1);
	glVertex3f(0.08,0.0,0.1);
	glVertex3f(0.0, 0.0, 0.1);
	glVertex3f(0.08*cos(4*3.14/3),0.08*sin(4*3.14/3),0.1);
	glVertex3f(0.0, 0.0, 0.1);
	glVertex3f(0.08*cos(2*3.14/3),0.08*sin(2*3.14/3),0.1);
	glEnd();
    glPopMatrix();
	
	glColor3f(0.5,0.5,0.5);
	glPushMatrix();
	glTranslatef(-.75,-.25,0.5);
   	glRotatef(wheelrot, 0.0, 0.0, 1.0);
	glutSolidTorus(0.09, 0.17, 20, 20);// wheel 
	//////glColor3f(1,1,1);
   	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.1);
	glVertex3f(0.08,0.0,0.1);
	glVertex3f(0.0, 0.0, 0.1);
	glVertex3f(0.08*cos(4*3.14/3),0.08*sin(4*3.14/3),0.1);
	glVertex3f(0.0, 0.0,0.1);
	glVertex3f(0.08*cos(2*3.14/3),0.08*sin(2*3.14/3),0.1);
	glEnd();
	glPopMatrix();

	
    glPopMatrix();
	
//    glPopMatrix();
	glLineWidth(1.0);
	
	
}
void loadTexture(int i,char *filename,GLuint *texture)
{
	FILE *image;
	char *data;
	int width,height,j;
	char temp;
	if((image=fopen(filename,"rb"))==NULL)
	{
		fprintf(stderr,"Error: Texture file \"%s\" could not be read\n",filename);
		return;
	}
	fseek(image,18,SEEK_SET);
	if((fread(&width,4,1,image))!=1)
	{
		fprintf(stderr,"Error: Could not read image width\n");
		return;
	}
	if((fread(&height,4,1,image))!=1)
	{
		fprintf(stderr,"Error: Could not read image height\n");
		return;
	}
	if((data=(char *)malloc(3*width*height*sizeof(char)))==NULL)
	{
		fprintf(stderr,"Error: Not enough memory for texture\n");
		return;
	}
	fseek(image,54,SEEK_SET);
	if((fread(data,3*width*height,1,image))!=1)
	{
		fprintf(stderr,"Error: Image format seems not to be valid\n");
		return;
	}
	fclose(image);
	for(j=0; j<3*width*height; j=j+3)
	{
		temp=data[j];
		data[j]=data[j+2];
		data[j+2]=temp;
	}
	glGenTextures(1,&texture[i]);
	glBindTexture(GL_TEXTURE_2D,texture[i]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D,0,3,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
//	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
}
void initialize(void)
{
//	if(BACK==0){
	glClearColor(0,0.2,0.4,0);
//	if(BACK==1){
//	glClearColor(1.0,1.0,0.0,0);};
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,1,0.5,100);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	GLfloat density = 0.01;
	GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};
	glEnable (GL_FOG);
	glFogi (GL_FOG_MODE, GL_EXP2);
	glFogfv (GL_FOG_COLOR, fogColor);
	glFogf (GL_FOG_DENSITY, density); 
	glHint (GL_FOG_HINT, GL_NICEST);

	GLfloat mat_specular[] = { 0.1, 0.1, 0.1, 1.0 };
   	GLfloat mat_shininess[] = { 50.0 };

   //	glClearColor (0.0, 0.0, 0.0, 0.0);
   //	glShadeModel (GL_SMOOTH);

 	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   	

	GLfloat color[4] = { 0.1, 0.1, 0.1, 1.0 };
/*	GLfloat position[4] = {11.0,11.0,-8.0,0.0};
	GLfloat LightDir[4] = {11.0f, 11.0f, -0.0f,1}; // towards the viewer
*/

	glLightfv(GL_LIGHT4, GL_AMBIENT, color); 
//	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 90); 
//	glLightfv(GL_LIGHT0, GL_POSITION, position);
//	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, LightDir);


//	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.5); */
	//glLightfv(GL_LIGHT0, GL_AMBIENT, color);
//	glLightfv(GL_LIGHT4, GL_DIFFUSE, color);
//	glLightfv(GL_LIGHT4, GL_SPECULAR, color);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT4);
//	glEnable(GL_LIGHT1);
		
//	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 20.0);
//	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
//	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 2.0);


	glEnable(GL_COLOR_MATERIAL);
//	loadTexture(0,"monitor.bmp",texture_id);
	loadTexture(1,"grass.bmp",texture_id);
	
	loadTexture(2,"road.bmp",texture_id);
	
//	loadTexture(2,"key.bmp",texture_id);
	loadTexture(3,"building.bmp",texture_id);
        
	pmodel1 = glmReadOBJ("car.obj");
        glmFacetNormals(pmodel1);
        glmVertexNormals(pmodel1, 90.0,1);
	tree = glmReadOBJ("tree.obj");
        glmFacetNormals(tree);
        glmVertexNormals(tree, 90.0,1);

	terrain = glmReadOBJ("building.obj");
        glmFacetNormals(terrain);
        glmVertexNormals(terrain, 90.0,1);

	building = glmReadOBJ("building2.obj");
        glmFacetNormals(building);
        glmVertexNormals(building, 90.0,1);
	
	car2 = glmReadOBJ("car2.obj");
        glmFacetNormals(car2);
        glmVertexNormals(car2, 90.0,1);

	grass1 = glmReadOBJ("grass.obj");
        glmFacetNormals(grass1);
        glmVertexNormals(grass1, 90.0,1);

	lamp = glmReadOBJ("lamp.obj");
        glmFacetNormals(lamp);
        glmVertexNormals(lamp, 90.0,1);




}

     void sun()
       {
            alt=alt_a/360*6.28;
 	     GLfloat lightColorA[] ={0.4,0.4,0.4}; 
//            GLfloat lightColor1[] ={0.8,0.8,0.8};
//	    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
            GLfloat lightPos1[]={0.0,200*sin(alt),-200*cos(alt),0.0};
	    glLightfv(GL_LIGHT1, GL_AMBIENT, lightColorA);
//            glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
            glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
       // 	alt+=1;    
	}

void street_light1(){
	glEnable(GL_LIGHTING);
	GLfloat spotwidth			= 15.0;
	GLfloat spotfocus			= 2.0;
	GLfloat constatt			= 2.0;
	GLfloat linatt				= 1.0;
	GLfloat quadatt				= 0.5;

	GLfloat light_ambient[]		= {0.2,		0.2,	0.2,	1.0};
	GLfloat light_diffuse[]		= {1.0,		1.0,	1.0,	1.0};
	GLfloat light_specular[]	= {1.0,		1.0,	1.0,	1.0};

	GLfloat spot1_position[]	= {1.7,	0.0,	-10.0,	1.0};
	GLfloat spot1_direction[]	= {1.7,	0.0,	1.0};

//	glEnable(GL_LIGHT0);
//	 if(LIGHT==1){
//                glEnable(GL_LIGHT0);}
        
  //           glDisable(GL_LIGHT0);}

	glLightfv(GL_LIGHT0,	GL_AMBIENT,					light_ambient);
	glLightfv(GL_LIGHT0,	GL_DIFFUSE,					light_diffuse);
	glLightfv(GL_LIGHT0,	GL_SPECULAR,				light_specular);
	glLightfv(GL_LIGHT0,	GL_POSITION,				spot1_position);
	glLightf(GL_LIGHT0,		GL_SPOT_CUTOFF,				spotwidth);
	glLightfv(GL_LIGHT0,	GL_SPOT_DIRECTION,			spot1_direction);
	glLightf(GL_LIGHT0,		GL_SPOT_EXPONENT,			spotfocus);

	
}
void street_light2(){
	 GLfloat spotwidth                       = 15.0;
        GLfloat spotfocus                       = 2.0;
        GLfloat constatt                        = 2.0;
        GLfloat linatt                          = 1.0;
        GLfloat quadatt                         = 0.5;

        GLfloat light_ambient[]         = {0.9,         0.9,    0.9,    1.0};
        GLfloat light_diffuse[]         = {1.0,         1.0,    1.0,    1.0};
        GLfloat light_specular[]        = {1.0,         1.0,    1.0,    1.0};

        GLfloat spot1_position[]        = {1.7, 0.0,    -10.0,  1.0};
        GLfloat spot1_direction[]       = {1.7, 0.0,    1.0};

	 GLfloat spot1_position1[]        = {-1.8, 0.0,    -10.0,  1.0};
        GLfloat spot1_direction1[]       = {-1.8, 0.0,    1.0};

//      glEnable(GL_LIGHT0);
//       if(LIGHT==1){
//                glEnable(GL_LIGHT0);}

  //           glDisable(GL_LIGHT0);}

        glLightfv(GL_LIGHT3,    GL_AMBIENT,                                     light_ambient);
        glLightfv(GL_LIGHT3,    GL_DIFFUSE,                                     light_diffuse);
        glLightfv(GL_LIGHT3,    GL_SPECULAR,                            light_specular);
        glLightfv(GL_LIGHT3,    GL_POSITION,                            spot1_position1);
        glLightf(GL_LIGHT3,             GL_SPOT_CUTOFF,                         spotwidth);
        glLightfv(GL_LIGHT3,    GL_SPOT_DIRECTION,                      spot1_direction1);
        glLightf(GL_LIGHT3,             GL_SPOT_EXPONENT,                       spotfocus);

}
void head_light1(){
	glPushMatrix();
	glRotatef(-30,0,0,1);
	glEnable(GL_LIGHTING);
        GLfloat spotwidth2                       = 20.0;
        GLfloat spotfocus2                       = 3.0;
        GLfloat constatt2                        = 2.0;
        GLfloat linatt2                          = 1.0;
        GLfloat quadatt2                         = 0.5;

        GLfloat light_ambient2[]         = {0.2,         0.2,    0.2,    1.0};
        GLfloat light_diffuse2[]         = {1.0,         1.0,    1.0,    1.0};
        GLfloat light_specular2[]        = {1.0,         1.0,    1.0,    1.0};

        GLfloat spot1_position2[]        = {carx/5 , cary/5 ,    -4.0,  1};
        GLfloat spot1_direction2[]       = {carx/5 + 2*cos(0.5) ,cary/5 + 2*sin(0.5),    -1};   

  //      glEnable(GL_LIGHT2);
        glLightfv(GL_LIGHT2,    GL_AMBIENT,                                     light_ambient2);
        glLightfv(GL_LIGHT2,    GL_DIFFUSE,                                     light_diffuse2);
        glLightfv(GL_LIGHT2,    GL_SPECULAR,                            light_specular2);
        glLightfv(GL_LIGHT2,    GL_POSITION,                            spot1_position2);
        glLightf(GL_LIGHT2,             GL_SPOT_CUTOFF,                         spotwidth2);
        glLightfv(GL_LIGHT2,    GL_SPOT_DIRECTION,                      spot1_direction2);
        glLightf(GL_LIGHT2,             GL_SPOT_EXPONENT,                       spotfocus2);
	glPopMatrix();

}
float R = 50;
float theta = 4;
float th = 3.14;
float alpha = 3.14;
//float carx = 6,cary=6;
float velx=0,vely=0,vel = 4;
float z=0;
//float c=0;
float b=0;
int CLASH=1;
float ani=0;
float anir=0;
int BAR=0,SUN=0,SU=0;
float x_sl=0,sun_p=0;
float S=0;
int keystate[256];

void keydown(void){
	if(keystate['w'] == 1){
		if(vel<7 || vel >= 0){
                	vel = vel + 1;}}
	if(keystate['a'] == 1){
                HAND=1;
                temp += 0.1;
		if(ani<60)
                	ani +=1;
		anir=ani;
                hand_rot += 0.05;
                }
	if(keystate['m'] == 1){
		SHADE = 1;}
	if(keystate['M'] == 1){
                SHADE = 0;}


        if(keystate['d'] == 1){
                HAND=0;
                temp -= .1;
		if(ani > -60)
                	ani -= 1;
		anir=ani;
                hand_rot -= 0.05;
                }
	if(keystate['d'] == 0 && keystate['a'] == 0){
		ani =0;
		anir=0;
		}
	if(keystate['o'] == 1){
                LIGHT = 1;
                }
	if(keystate['f'] == 1){
                LIGHT = 0;
                }
	if(keystate['H'] == 1){
		HEAD = 1;}
	if(keystate['h'] == 1){
		HEAD = 0;}

	if(keystate['i'] == 1)
               
                        vel1 = vel1 + 1;
	 if(keystate['j'] == 1){
		temp1 -= .05;
		}
	 if(keystate['l'] == 1){
                temp1 += .05;
                }

	 if(keystate['c'] == 1){
                am += .1;
                }
	
	 if(keystate['C'] == 1){
                am -= .1;
                }
	if(keystate['9'] == 1){
		alt_a +=10;
		}



	if (keystate['1'] == 1)
                FLAG=1;
        if(keystate['2'] == 1)
                FLAG=2;
        if(keystate['3'] == 1)
                FLAG=3;
        if(keystate['4'] == 1)
                FLAG=4;
	if(keystate['5'] == 1)
		FLAG=5;
	if(keystate['6'] == 1)
		FLAG=6;
	 if(keystate['7'] == 1)
                FLAG=7;

        if (keystate['z'] == 1)
                th += 0.1;
        if(keystate['r'] == 1)
                alpha += 0.04;
        if(keystate['R'] == 1)
                alpha -= 0.04;
        if (keystate['t'] == 1) {
                theta += 0.01;
        }
        if (keystate['T'] == 1) {
                theta -= 0.01;
        }
        else if (keystate['y'] == 1) {
                R -= 0.4;
        }
        else if (keystate['Y'] == 1) {
                R += 0.4;
        }

}

void car(){
	vel = vel*.998;
	glPushMatrix();	
	velx = vel*sin(temp);
        vely = vel*cos(temp);
//	carx = carx + velx*0.01;
 //       cary = cary + vely*0.01;
//	printf("inside : %f\n",carx);

	glColor3f(0,0,1);
	glTranslatef(carx,cary,-0.8);
	carx = carx + velx*0.01;
        cary = cary + vely*0.01;
	glRotatef(-temp*(180/3.14),0,0,1);
	glPushMatrix();
	glScalef(.8,.8,.8);
	glTranslatef(0.0,0.0,-0.1);
	glScalef(1.0,2.0,1.0);
	glutWireCube(1.0);
	glColor3f(0.5,0.0,0.0);
//	glutSolidTorus(1,2,30,30);
	glBegin(GL_QUADS);
		glVertex3f(0.5,-0.5,0.5);
		glVertex3f(0.5,-0.5,0.0);
//	glEnable (GL_LIGHTING);
		glVertex3f(0.5,0.5,0.0);
		glVertex3f(0.5,0.5,0.5);//base

		glVertex3f(0.5,-0.1,-0.5);
		glVertex3f(0.5,-0.1,0.0);
		glVertex3f(0.5,0.1,0.0);
		glVertex3f(0.5,0.1,-0.5);//center line
		
		glVertex3f(0.5,-0.5,-0.5);
		glVertex3f(0.5,-0.5,0.0);
		glVertex3f(0.5,-0.45,0.0);
		glVertex3f(0.5,-0.45,-0.5);

		
		glVertex3f(0.5,0.5,-0.5);
		glVertex3f(0.5,0.5,0.0);
		glVertex3f(0.5,0.45,0.0);
		glVertex3f(0.5,0.45,-0.5);

		//upper surface done
		//one side done
		
		glVertex3f(-0.5,-0.5,0.5);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(-0.5,0.5,0.0);
		glVertex3f(-0.5,0.5,0.5);
		
		glVertex3f(-0.5,-0.1,-0.5);
		glVertex3f(-0.5,-0.1,0.0);
		glVertex3f(-0.5,0.1,0.0);
		glVertex3f(-0.5,0.1,-0.5);

		
		glVertex3f(-0.5,-0.5,-0.5);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(-0.5,-0.45,0.0);
		glVertex3f(-0.5,-0.45,-0.5);

		
		glVertex3f(-0.5,0.5,-0.5);
		glVertex3f(-0.5,0.5,0.0);
		glVertex3f(-0.5,0.45,0.0);
		glVertex3f(-0.5,0.45,-0.5);
		
		//second side done

		glVertex3f(-0.5,0.5,0.0);
		glVertex3f(-0.5,0.8,0.3);
		glVertex3f(-0.5,0.8,0.5);
		glVertex3f(-0.5,0.5,0.5);



		glVertex3f(0.5,0.5,0.0);
		glVertex3f(0.5,0.8,0.3);
		glVertex3f(0.5,0.8,0.5);
		glVertex3f(0.5,0.5,0.5);


		
		glColor3f(0.23,0.46,1);
		glVertex3f(-0.5,0.8,0.5);
		glVertex3f(-0.5,-0.5,0.5);
		glVertex3f(0.5,-0.5,0.5);
		glVertex3f(0.5,0.8,0.5);
		//bottom surface done

		
//		glBindTexture(GL_TEXTURE_2D,texture_id[2]);
//		glTexCoord2i(0,0);
		glVertex3f(-0.5,0.5,-0.5);
//		glTexCoord2i(1,0);
		glVertex3f(-0.5,-0.5,-0.5);
//		glTexCoord2i(1,1);
		glVertex3f(0.5,-0.5,-0.5);
//		glTexCoord2i(0,1);
		glVertex3f(0.5,0.5,-0.5);
		//upper surface done

		glColor3f(1.0,1.0,1.0);
		glVertex3f(-0.5,-0.5,0.5);
		glVertex3f(-0.5,-0.5,-0.5);
		glVertex3f(0.5,-0.5,-0.5);
		glVertex3f(0.5,-0.5,0.5);

		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.3,-0.51,0.5);
		glVertex3f(0.3,-0.51,-0.5);
		glVertex3f(0.4,-0.51,-0.5);
		glVertex3f(0.4,-0.51,0.5);
		
		//back surface done


		glColor3f(.8,0,0);
		
//		glBindTexture(GL_TEXTURE_2D,texture_id[1]);
//		glTexCoord2i(0,0);
		glVertex3f(-0.5,0.8,0.3);
//		glTexCoord2i(1,0);
		glVertex3f(-0.5,0.5,0.0);
//		glTexCoord2i(1,1);
		glVertex3f(0.5,0.5,0.0);
//		glTexCoord2i(0,1);
		glVertex3f(0.5,0.8,0.3);

		glColor3f(0.5,0.0,0.0);	
		glVertex3f(-0.5,0.8,0.5);
		glVertex3f(-0.5,0.8,0.3);
		glVertex3f(0.5,0.8,0.3);
		glVertex3f(0.5,0.8,0.5);



	glEnd();
		glColor3f(0.0,0.0,0.0);
		glPushMatrix();
				glRotatef(-ani,0,1,0);
		
				
	//		glColor3f(1.0,1.0,1.0);
			glBegin(GL_LINES);
				glColor3f(0.0,0.0,0.0);
			glEnd();
			glBegin(GL_LINE_LOOP);
//				glColor3f(0.8,0.8,0.8);
//				glBegin(GL_LINES);
//					glVertex3f(
				while(b<.03){
				for(i=0;i<360;i++){
					if((i>80 && i<100) || (i>260 && i<280))
						glColor3f(0.0,0.0,0.0);
					else 
						glColor3f(0.8,0.8,0.8);
					glVertex3f((0.12+b)*sin(i*(3.14/180)),0.46,(0.12+b)*cos(i*(3.14/180)));
				}
				b = b + .0001;
				}
			b=0;
			glEnd();
		glPopMatrix();
	
	glPushMatrix();//slider foramtion
//		glScalef(1.0,2.0,1.0);	
		glColor3f(0.0,0.0,1.0);
		glTranslatef(x_sl,0.5,-0.58);
//                glTranslatef(x_sl,0.0,0.0);
                if(BAR==1){
                        x_sl = x_sl + .04;}
                if((0.35-x_sl)<0.01)
                        BAR = 0;
                if(BAR == 0){
                        x_sl = x_sl - .04;}
                if((0.35+x_sl)< 0.01){
                        BAR = 1;}
//		glTranslatef(0.0,0.5,-0.65);
		glutSolidCube(0.15);
		glPushMatrix();
			glTranslatef(0.0,0.0,-0.25);
			glScalef(0.4,0.4,4);
			glutSolidCube(0.08);
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(1.0,1.0,1.0);
			glTranslatef(0.0,0.1,-0.35);
			glRotatef(30,1,0,0);
			glRotatef(up_sider*180/3.14,0,0,1);
			glScalef(0.5,1.0,0.5);
			glutSolidCube(0.15);
		glPopMatrix();	
	glPopMatrix();
	
	glColor3f(1.0,0.0,0.0);
	glPushMatrix();///tyre formation
		glScalef(1.0,0.5,1.0);
		glTranslatef(0.501,-.7,0.60);
//		glRotatef(anir,0,0,1);
		while(S > -0.1){
		glBegin(GL_TRIANGLE_FAN);
			glColor3f(1.0,0.0,0.0);
			for(i=0;i<360;i++){
				glVertex3f(0.0+S,0.2*sin((i*3.14)/180),0.2*cos((i*3.14)/180));
				}
		glEnd();
		S = S - .001;
		}
		S=0;
		glColor3f(0.0,0.0,0.0);
		glLineWidth(5.0);
		glBegin(GL_LINES);
			glVertex3f(0.0,0.15,0.15);

			glVertex3f(0.0,-0.15,-0.15);
			glVertex3f(0.0,-0.15,0.15);


			glVertex3f(0.0,0.15,-0.15);

		glEnd();
		glLineWidth(1.0);
	glPopMatrix();
	glPushMatrix();
		glScalef(1.0,0.5,1.0);
		glTranslatef(-0.501,-.7,0.60);
//		glRotatef(anir,0,0,1);
		while(S < 0.1){
		glBegin(GL_TRIANGLE_FAN);
			glColor3f(1.0,0.0,0.0);
			for(i=0;i<360;i++){
				glVertex3f(0.0+S,0.2*sin((i*3.14)/180),0.2*cos((i*3.14)/180));
			}
		glEnd();
		S = S + .001;
		}
		S=0;
		glLineWidth(5.0);
		glBegin(GL_LINES);
			glColor3f(0.0,0.0,0.0);
			glVertex3f(0.0,0.15,0.15);

			glVertex3f(0.0,-0.15,-0.15);
			glVertex3f(0.0,-0.15,0.15);


			glVertex3f(0.0,0.15,-0.15);
		glEnd();
		glLineWidth(1.0);

	
	glPopMatrix();
	
	glPushMatrix();///tyre formation
		glScalef(1.0,0.5,1.0);
		glTranslatef(0.501,.7,0.60);
		glRotatef(-anir,0,0,1);
		while(S > -0.1){
		glBegin(GL_TRIANGLE_FAN);
			glColor3f(1.0,0.0,0.0);
			for(i=0;i<360;i++){
				glVertex3f(0.0+S,0.2*sin((i*3.14)/180),0.2*cos((i*3.14)/180));
			}
		glEnd();
		S = S - .001;
		}
		S=0;

		glLineWidth(5.0);
		glBegin(GL_LINES);
			glColor3f(0.0,0.0,0.0);
			glVertex3f(0.0,0.15,0.15);

			glVertex3f(0.0,-0.15,-0.15);
			glVertex3f(0.0,-0.15,0.15);


			glVertex3f(0.0,0.15,-0.15);
		glEnd();
		glLineWidth(1.0);
	glPopMatrix();

	glPushMatrix();///tyre formation
		glScalef(1.0,0.5,1.0);
		glTranslatef(-0.501,.7,0.60);
		glRotatef(-anir,0,0,1);
		while(S < 0.1){
		glBegin(GL_TRIANGLE_FAN);
			glColor3f(1.0,0.0,0.0);
			for(i=0;i<360;i++){
				glVertex3f(0.0+S,0.2*sin((i*3.14)/180),0.2*cos((i*3.14)/180));
			}
		glEnd();
		S = S + .001;
		}
		S =0;
		glLineWidth(5.0);
		glBegin(GL_LINES);
			glColor3f(0.0,0.0,0.0);
			glVertex3f(0.0,0.15,0.15);

			glVertex3f(0.0,-0.15,-0.15);
			glVertex3f(0.0,-0.15,0.15);


			glVertex3f(0.0,0.15,-0.15);
		glEnd();
		glLineWidth(1.0);
	glPopMatrix();
	glPopMatrix();
		
//	glPopMatrix();
		
	glPopMatrix();
	

}
/*
void clash(float carx,float cary){

	if((carx-0.4) > 12  || (cary-0.4) > 10 || (carx-0.4) < -12 || (cary-0.4) < -10){
		CLASH=0;
		carx = carx - 2*sin(temp);
		cary = cary - 2*cos(temp);
		temp = temp - (.4*(3.14/180));}
	else 
		CLASH=1;
}*/

void sol(void){
/*	if(SUN==1){
              sun_p = sun_p + .2;}
        if((5.0-sun_p)<0.1)
              SUN = 0;
        if(SUN == 0){
              sun_p = sun_p - .2;}
        if((30.0+sun_p)< 0.01){
              SUN = 1;}
	if(SU==1){
              sun_y = sun_y + .2;}
        if((30.0+sun_y)<0.1)
              SU = 1;
        if(SU == 0){
              sun_y = sun_y - .2;}
        if((-30.0+sun_y)< 0.01){
              SU = 0;}
*/	glEnable (GL_LIGHTING);
        GLfloat lightColor1[] ={1,1,1};
            glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);

//        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);

	glPushMatrix();
	if(SHADE==1){
		 glShadeModel (GL_SMOOTH);}
	if(SHADE==0){
		 glShadeModel (GL_FLAT);}
	GLfloat mat_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	
	glColor3f(1.0,1.0,0);
	glTranslatef(0.0,20,-2);
	glutSolidSphere(2.0,30,30);
	glPopMatrix();
	glDisable(GL_LIGHT1);
	}
float r_tx=0,r_ty=0,M=0;
int p=0;
void track(void){
	glColor3f(1.0,1.0,1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture_id[2]);
//	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
//		glBindTexture(GL_TEXTURE_2D,texture_id[2]);

		glTexCoord2i(0,0);
		glNormal3f(0,0,-1);
		glVertex3f(-17.0,-27.0,-0.1);
		glTexCoord2i(0,1);
		glNormal3f(0,0,-1);
		glVertex3f(-11.0,-27.0,-0.1);
		glTexCoord2i(1,1);
		glNormal3f(0,0,-1);
		glVertex3f(-11.0,20.0,-0.1);
		glTexCoord2i(1,0);
		glNormal3f(0,0,-1);
		glVertex3f(-17.0,20.0,-0.1);
	
      
		glTexCoord2i(0,0);
		 glNormal3f(0,0,-1);
		glVertex3f(-14.0,-13.0,-0.05);
		 glTexCoord2i(0,1); 
		glNormal3f(0,0,-1);
		glVertex3f(-14.0,-7.0,-0.05);
		 glTexCoord2i(1,1);
		 glNormal3f(0,0,-1);
		glVertex3f(10.0,-7.0,-0.05);
		 glTexCoord2i(1,0);
		 glNormal3f(0,0,-1);
		glVertex3f(10.0,-13.0,-0.05);
	

	/// elvated roof

		//****upper surface*****
		glColor3f(0.0,0.0,0.0);
		 glNormal3f(0,0,-1);
		glVertex3f(-8.0,-12.5,-3.1);
		 glNormal3f(0,0,-1);
		glVertex3f(-8.0,-7.5,-3.1);
		 glNormal3f(0,0,-1);
		glVertex3f(7.0,-7.5,-3.1);
		 glNormal3f(0,0,-1);
		glVertex3f(7.0,-12.5,-3.1);

		//*****side surfaces*****
		glNormal3f(0,-1,0);	
		glVertex3f(-8.0,-7,-0.1);
		 glNormal3f(0,-1,0);
		glVertex3f(-8.0,-7.5,-3.1);
		 glNormal3f(0,-1,0);
		glVertex3f(7.0,-7.5,-3.1);
		 glNormal3f(0,-1,0);
		glVertex3f(7.0,-7,-0.1);

		 glNormal3f(0,1,0);
		glVertex3f(-8.0,-13,-0.1);
		 glNormal3f(0,1,0);
		glVertex3f(-8.0,-12.5,-3.1);
		 glNormal3f(0,1,0);
		glVertex3f(7.0,-12.5,-3.1);
		 glNormal3f(0,1,0);
		glVertex3f(7.0,-13,-0.1);

///done
		glColor3f(1.0,1.0,1.0);
		glTexCoord2i(0,0);
		 glNormal3f(0,0,-1);
		glVertex3f(16.0,-7.3,-0.1);
		glTexCoord2i(0,1);
		 glNormal3f(0,0,-1);
		glVertex3f(10.0,-7.3,-0.1);
		glTexCoord2i(1,1);
		 glNormal3f(0,0,-1);
		glVertex3f(10.0,20.4,-0.1);
		glTexCoord2i(1,0);
		 glNormal3f(0,0,-1);
		glVertex3f(16.0,20.4,-0.1);

		glTexCoord2i(0,0);
		 glNormal3f(0,0,-1);
		glVertex3f(16.0,20,-0.1);  
		glTexCoord2i(0,1);
		 glNormal3f(0,0,-1);
		glVertex3f(16.0,26.0,-0.1);
		glTexCoord2i(1,1);
		 glNormal3f(0,0,-1);
		glVertex3f(26.0,26.0,-0.1);
		glTexCoord2i(1,0);
		 glNormal3f(0,0,-1);
		glVertex3f(26.0,20.0,-0.1);

		glTexCoord2i(0,0);	
		glVertex3f(29.0,20,-0.1);
		glTexCoord2i(0,1);
		glVertex3f(23.0,20.0,-0.1);
  		glTexCoord2i(1,1);
		glVertex3f(23.0,-30.0,-0.1);
		glTexCoord2i(1,0);
		glVertex3f(29.0,-30.0,-0.1);
		
		glTexCoord2i(0,0);
		glVertex3f(23.0,-30,-0.1);
		glTexCoord2i(0,1);
		glVertex3f(23.0,-24,-0.1);
		glTexCoord2i(1,1);
		glVertex3f(-12.0,-24.0,-0.1);
		glTexCoord2i(1,0);
		glVertex3f(-12.0,-30.0,-0.1);
		
	
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glDisable(GL_TEXTURE_2D);
	glPushMatrix(); //turn
	glTranslatef(-14.0,-10.0,-0.01);
	glBegin(GL_TRIANGLE_FAN);
		for(i=0;i<360;i++){
			glVertex3f(6*cos(i*3.14/180),6*sin(i*3.14/180),-0.0);
			}
	glEnd();
	glPopMatrix();
		
	glPushMatrix(); //turn
	glTranslatef(10.0,-7.0,-0.01);
	glBegin(GL_TRIANGLE_FAN);
		for(i=0;i<180;i++){
			glVertex3f(6*cos(i*3.14/180),-6*sin(i*3.14/180),-0.0);
			}
	glEnd();
	glPopMatrix();
	

	glPushMatrix(); //turn
	glTranslatef(16.0,20.0,-0.01);
	glBegin(GL_TRIANGLE_FAN);
		for(i=0;i<180;i++){
			glVertex3f(-6*cos(i*3.14/180),6*sin(i*3.14/180),-0.0);
			}
	glEnd();
	glPopMatrix();
	

	glPushMatrix(); //turn
	glTranslatef(26.0,20.3,-0.01);
	glBegin(GL_TRIANGLE_FAN);
		for(i=0;i<180;i++){
			glVertex3f(6*cos(i*3.14/180),-6*sin(i*3.14/180),-0.0);
			}
	glEnd();
	glPopMatrix();
	
	glPushMatrix(); //turn
	glTranslatef(26.0,25.7,-0.01);
	glBegin(GL_TRIANGLE_FAN);
		for(i=0;i<180;i++){
			glVertex3f(-6*cos(i*3.14/180),6*sin(i*3.14/180),-0.0);
			}
	glEnd();
	glPopMatrix();


	glPushMatrix(); //turn
	glTranslatef(-11.0,-26,-0.01);
	glBegin(GL_TRIANGLE_FAN);
		for(i=0;i<180;i++){
			glVertex3f(6*cos(i*3.14/180),-6*sin(i*3.14/180),-0.0);
			}
	glEnd();
	glPopMatrix();


	glLineWidth(5.0);
/*	glPushMatrix();
	glTranslatef(10.0,-30.0,-0.01);
	while(M<6.0){
	glBegin(GL_LINE_LOOP);
		for(i=0;i<180;i++){
			glVertex3f((13+M)*cos(i*3.14/180),-(13+M)*sin(i*3.14/180),0.0);
			}
		
	glEnd();
	M = M + .005;
	}
	glPopMatrix();
	M=0;*/
	glLineWidth(1.0);
}
float nx=0,ny=0;
void clash(void){
	if(fabs(carx - car1x) < .01){
		car1x = car1x - 4*cos(temp1);
		carx = carx - 4*sin(temp);
	}
	  if( fabs(cary - car1y) < .01){
                car1y = car1y - 4*sin(temp1);
                cary = cary - 4*cos(temp);
        }
}
void draw(void)
{
//	glEnable(GL_LIGHT1);
	glPushMatrix();
//	head_light1();
	glPopMatrix();
	glPushMatrix();
	street_light1();
	street_light2();
	glPopMatrix();
	 if(LIGHT==1){
		glEnable(GL_LIGHT3);
                glEnable(GL_LIGHT0);}
        if(LIGHT==0){
		glDisable(GL_LIGHT3);
                glDisable(GL_LIGHT0);}
	if(HEAD==1){
		glEnable(GL_LIGHT2);}
	if(HEAD==0){
		glDisable(GL_LIGHT2);}
	sun();
	glDisable(GL_TEXTURE_2D);
	up_sider = up_sider + .05;
	sx = carx + (x_sl*cos(-temp) - 0.5*sin(-temp));
	sy = cary + (x_sl*sin(-temp) + 0.5*cos(-temp));
	nx = carx + (0.2*cos(-temp) - 0.0*sin(-temp));
	nx = cary + (0.2*sin(-temp) + 0.0*cos(-temp));

	tx = carx + (0.6*cos(temp) - 0.5*sin(-temp));	
	ty = cary + (0.6*sin(temp) + 0.5*cos(-temp));	

	r_tx = carx + (0.8*cos(temp) - 0.5*sin(-temp));	
	r_ty = cary + (0.8*sin(temp) + 0.5*cos(-temp));	

	keydown();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//	  glEnable(GL_LIGHT1);
	glLoadIdentity();
	if(FLAG==1)
		gluLookAt(R*cos(alpha)*sin(theta),R*sin(alpha)*sin(theta),-4 +R*cos(theta),0,0,-4,0,0,-1);
	if(FLAG==2)
		gluLookAt(carx - 4*sin(temp),cary - 4*cos(temp),-5.5,carx + 5*sin(temp) ,cary + 5*cos(temp) ,-4,0,0,-1);
	if(FLAG==3){
		gluLookAt(carx - sin(temp-0.5) ,cary - cos(temp-0.5),-5.25,carx + 8*sin(temp) ,cary + 8*cos(temp) ,-4.0,0,0,-1);
	}	
	if(FLAG==4){
		 gluLookAt(car1x - 4*cos(temp1),car1y - 4*sin(temp1),-5.5,car1x + 5*cos(temp1) ,car1y + 5*sin(temp1) ,-4,0,0,-1);
	}
	if(FLAG==5){

		gluLookAt(sx ,sy,-6.00,sx + 2*sin(up_sider),sy + 2*cos(up_sider) ,-5.3,0,0,-1);
	}
	if(FLAG==6){
		gluLookAt(tx,ty,-4.5,r_tx ,r_ty,-4.5,0,0,-1);}
	if(FLAG==7){
		gluLookAt(car1x - 3*cos(temp1),car1y - 3*sin(temp1) ,-5.5,car1x + 5*cos(temp1) ,car1y + 5*sin(temp1) ,-4,0,0,-1);
	}
	glPushMatrix();
	clash();
	glTranslatef(0,0,-4);
	glPushMatrix();
	
	sol();
	glPopMatrix();
	glPushMatrix();
	vel = vel*.98;
        velx = vel*sin(temp);
        vely = vel*cos(temp);

        glColor3f(0,0,1);
        glTranslatef(carx,cary,-0.4);
        carx = carx + velx*0.01;
        cary = cary + vely*0.01;
         glRotatef(-temp*(180/3.14),0,0,1);
//      glTranslatef(20,0.0,0.0);
        glRotatef(90,0,0,1);
        glScalef(0.005,0.005,0.005);
//	car_2();
	  glPushMatrix();
              head_light1();
        glPopMatrix();
        drawmodel_box();
        glPopMatrix();

//	clash();
//////2nd car drawn    

	 glPushMatrix();
        vel1 = vel1*.98;
        vel1x = vel1*cos(temp1);
        vel1y = vel1*sin(temp1);

        glColor3f(0,0,1);
        glTranslatef(car1x,car1y,-0.4);
        car1x = car1x + vel1x*0.01;
        car1y = car1y + vel1y*0.01;
         glRotatef(temp1*(180/3.14),0,0,1);
//      glTranslatef(20,0.0,0.0);
        glRotatef(0,0,0,1);
        glScalef(0.005,0.005,0.005);
	glPushMatrix();
//		head_light1();
	glPopMatrix();
//	glRotatef(-90,1,0,0);
//      car_2();
        drawmodel_box();
        glPopMatrix();



        glPushMatrix();
	glTranslatef(-9,0,0);
	glRotatef(90,0,0,1);
        glRotatef(-90,1,0,0);
        glScalef(0.2,0.2,0.2);
        nw_building();
        glPopMatrix();

	glPushMatrix();
        glTranslatef(-18,0,0);
        glRotatef(-90,0,0,1);
        glRotatef(-90,1,0,0);
        glScalef(0.2,0.2,0.2);
        nw_building();
        glPopMatrix();

	  glPushMatrix();
	 glScalef(0.4,0.7,0.8);
        glTranslatef(20,0,0);
        glRotatef(-90,0,0,1);
        glRotatef(-90,1,0,0);
//        glScalef(1.2,1.2,1.8);
        lamp_1();
        glPopMatrix();


	   glPushMatrix();
         glScalef(0.4,0.7,0.8);
        glTranslatef(-39,0,0);
        glRotatef(-90,0,0,1);
        glRotatef(-90,1,0,0);
//        glScalef(1.2,1.2,1.8);
        lamp_1();
        glPopMatrix();

/*	glPushMatrix();
	glTranslatef(-0,0,0);
        glRotatef(-90,0,0,1);
        glRotatef(-90,1,0,0);
        glScalef(0.2,0.2,0.2);
        building_2();
        glPopMatrix();*/

	glPushMatrix();
	glScalef(2.0,2.0,0.1);
	glTranslatef(-5,0,2);
        glRotatef(-90,0,0,1);
        glRotatef(-90,1,0,0);
//        glScalef(0.4,0.4,1.0);
        grass();
        glPopMatrix();

 	glPushMatrix();
        glScalef(2.0,2.0,0.1);
        glTranslatef(-30,0,2);
        glRotatef(-90,0,0,1);
        glRotatef(-90,1,0,0);
//        glScalef(0.4,0.4,1.0);
        grass();
        glPopMatrix();




/*	glPushMatrix();
        glTranslatef(-30,0,0);
        glRotatef(-90,0,0,1);
        glRotatef(-90,1,0,0);
        glScalef(0.3,0.3,0.3);
        car_2();
        glPopMatrix();*/

	
	glPopMatrix();
	

		
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0,0,-4);
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D,texture_id[1]);
//            glTexCoord2i(0,0);
//	glEnable(GL_TEXTURE_2D);
/*	if(BACK==0){
		glColor3f(0.0,0.0,0.0);}
	if(BACK==1){
		glColor3f(1.0,1.0,1.0);}
	while(wall > - 50.0){
	glBegin(GL_LINE_LOOP);
		for(i=0;i<360;i++){
			glVertex3f(100*sin(i*3.14/180),100*cos(i*3.14/180),wall);}
	glEnd();
	wall = wall - .05;}
	wall=0;*/
/*	glPushMatrix();
	velx = vel*sin(temp);
        vely = vel*cos(temp);
//      carx = carx + velx*0.01;
 //       cary = cary + vely*0.01;
//      printf("inside : %f\n",carx);

        glColor3f(0,0,1);
        glTranslatef(carx,cary,-0.4);
        carx = carx + velx*0.01;
        cary = cary + vely*0.01;
	 glRotatef(-temp*(180/3.14),0,0,1);
//	glTranslatef(20,0.0,0.0);
	glRotatef(-90,1,0,0);
	glScalef(0.5,0.5,0.5);
	drawmodel_box();
	glPopMatrix();	
	for(i=0;i<30;i=i+20){
	glPushMatrix();
	glTranslatef(10,i,0.0);
	glScalef(0.6,0.6,0.6);
	glRotatef(-90,1,0,0.0);
	draw_tree();
	glPopMatrix();
	}
	glPushMatrix();	
	glRotatef(-90,1,0,0);
	glScalef(0.2,0.2,0.2);
//	nw_building();
	glPopMatrix();*/

//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D,texture_id[1]);



	glPushMatrix();
	glTranslatef(0,0,0.3);
	glColor3f(0.0,0.3,0.0);
	glBegin(GL_QUADS);
//	 glEnable(GL_TEXTURE_2D);
//	 glBindTexture(GL_TEXTURE_2D,texture_id[1]); 
		for(i=-200;i<200;i++){
			for(p=-200;p<200;p++){
//		 glTexCoord2i(0,0);
		glNormal3f(0,0,-1);
		glVertex3f(i,p,0.0);	
//		 glTexCoord2i(1,0);

		glNormal3f(0,0,-1);	
		glVertex3f(i+1,p,0.0);
//		 glTexCoord2i(1,1);
		       glNormal3f(0,0,-1); 
		glVertex3f(i+1,p+1,0.0);
//		 glTexCoord2i(0,1);
		 glNormal3f(0,0,-1); 

		glVertex3f(i,p+1,0.0);
		}
	}
//	 glDisable(GL_TEXTURE_2D);
	glEnd();	
	glPopMatrix();




//	glDisable(GL_TEXTURE_2D);		
//	glmDraw(terrain, GLM_SMOOTH| GLM_TEXTURE);
		
//	car1();
	glPushMatrix();

//    ******new track formation***********
	track();
//	buildings();		
//	glTranslatef(0,0,-4);
	glPopMatrix();

	//glRotatef(-60,1,0,0);
	//glRotatef(t,0,0,1);
	glPopMatrix();
//	pc();
	//t+=0.01;
	glutSwapBuffers();
}
void keyboard (unsigned char key, int x1, int y1) {
	keystate[key]=1;
}
void keyup (unsigned char key, int x1, int y1) {
		keystate[key]= 0;
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(1,1);
	glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
	glutCreateWindow("PC");
	glutDisplayFunc(draw);
	glutIdleFunc(draw);
	glutKeyboardUpFunc(keyup);
	glutKeyboardFunc(keyboard);
//	glutSetKeyCallback(handleKeypress);
//	glutSetKeyCallback(handleKeypress);
//	glutFullScreen();
	initialize();
	glutMainLoop();
	return 0;
}
