#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
float t=0;
int i =0;
float xt = 0.5,yt = 0.5,x2,y2;
float angle;
float up_sider;
float g=0,c=0;
float k=0;
float v=0;
float temp=0;
int FLAG=0;
int rt = 45;
float carx=6,cary=6,am=0;
double radius=0.55;
GLuint texture_id[10];
//int KeyDown[256]={0};
float hand_rot=0;
int HAND=0;
float sx=0,sy=0;
float tx=0,ty=8;
float sun_y=0;
float vel1x=0,vel1y=0,vel1=0;
float car1x=10,car1y=10;
float temp1=0;
float wheelrot = 0.0;
float steerrot=0.0;
float back=0;
int BACK=0;
float wall = 0;
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
	glEnable (GL_LIGHTING);
	GLfloat density = 0.01;
	GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};
	glEnable (GL_FOG);
	glFogi (GL_FOG_MODE, GL_EXP2);
	glFogfv (GL_FOG_COLOR, fogColor);
	glFogf (GL_FOG_DENSITY, density); 
	glHint (GL_FOG_HINT, GL_NICEST);
	GLfloat light_ambient[] = { 0.0+am, 0.0+am, 0.0+am, 0.3 };
	GLfloat spec_color[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat ambient[] = { 0.0,0.0,0.0,0.0 };

	GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 1.0 };
   	GLfloat mat_shininess[] = { 50.0 };
	GLfloat pos[] = { 0.0, 4.0, -2.0, 0.3 }; 
   	GLfloat light_position[] = { 1.0, 10.0, -6.0, 0.5 };
	
	GLfloat light_position1[] = { 10.0, 0.0, -4.0, 1.0 };

   //	glClearColor (0.0, 0.0, 0.0, 0.0);
   	glShadeModel (GL_SMOOTH);

  	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   	

	glLightfv(GL_LIGHT2, GL_AMBIENT, ambient);
//	glLightfv(GL_LIGHT1, GL_POSITION, pos);
	glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, spec_color);
	glLightfv(GL_LIGHT3, GL_POSITION, light_position);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.5);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.05);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.0);

	GLfloat color[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[4] = {0.0,0.0,-4.0,0.0};
	float LightDir[3] = {0.0f, 0.0f, -1.0f}; // towards the viewer
	glLighti(GL_LIGHT0, GL_SPOT_CUTOFF, 30); 
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, LightDir);
	//glLightfv(GL_LIGHT0, GL_AMBIENT, color);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, color);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, color);
	
//	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 20.0);
//	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
//	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 2.0);


	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHT1);
//	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_COLOR_MATERIAL);
//	loadTexture(0,"monitor.bmp",texture_id);
	loadTexture(1,"grass.bmp",texture_id);
	
	loadTexture(2,"road.bmp",texture_id);
	
//	loadTexture(2,"key.bmp",texture_id);
	loadTexture(3,"building.bmp",texture_id);
}

float R = 75;
float theta = 3.14;
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
                	vel = vel + .08;}}
	if(keystate['a'] == 1){
                HAND=1;
                temp += 0.05;
		if(ani<60)
                	ani +=1;
		anir=ani;
                hand_rot += 0.05;
                }
        if(keystate['d'] == 1){
                HAND=0;
                temp -= .05;
		if(ani > -60)
                	ani -= 1;
		anir=ani;
                hand_rot -= 0.05;
                }
	if(keystate['d'] == 0 && keystate['a'] == 0){
		ani =0;
		anir=0;
		}
	if(keystate['i'] == 1){
                if(vel1<7 || vel1 >= 0){
                        vel1 = vel1 + .08;}}
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

void clash(float carx,float cary){

	if((carx-0.4) > 12  || (cary-0.4) > 10 || (carx-0.4) < -12 || (cary-0.4) < -10){
		CLASH=0;
		carx = carx - 2*sin(temp);
		cary = cary - 2*cos(temp);
		temp = temp - (.4*(3.14/180));}
	else 
		CLASH=1;
}

void sun(void){
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
*/
	glPushMatrix();
//	GLfloat mat_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);

	glColor3f(1.0,1.0,0);
	glTranslatef(0.0,20,-2);
	glutSolidSphere(2.0,30,30);
	glPopMatrix();
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
		glVertex3f(-17.0,-27.0,-0.1);
		glTexCoord2i(0,1);
		glVertex3f(-11.0,-27.0,-0.1);
		glTexCoord2i(1,1);
		glVertex3f(-11.0,20.0,-0.1);
		glTexCoord2i(1,0);
		glVertex3f(-17.0,20.0,-0.1);
	
      
		glTexCoord2i(0,0);
		glVertex3f(-14.0,-13.0,-0.05);
		 glTexCoord2i(0,1);
		glVertex3f(-14.0,-7.0,-0.05);
		 glTexCoord2i(1,1);
		glVertex3f(10.0,-7.0,-0.05);
		 glTexCoord2i(1,0);
		glVertex3f(10.0,-13.0,-0.05);
	

	/// elvated roof

		//****upper surface*****
		glColor3f(0.0,0.0,0.0);
		glVertex3f(-8.0,-12.5,-3.1);
	
		glVertex3f(-8.0,-7.5,-3.1);
		glVertex3f(7.0,-7.5,-3.1);
		glVertex3f(7.0,-12.5,-3.1);

		//*****side surfaces*****
		glVertex3f(-8.0,-7,-0.1);
		glVertex3f(-8.0,-7.5,-3.1);
		glVertex3f(7.0,-7.5,-3.1);
		glVertex3f(7.0,-7,-0.1);


		glVertex3f(-8.0,-13,-0.1);
		glVertex3f(-8.0,-12.5,-3.1);
		glVertex3f(7.0,-12.5,-3.1);
		glVertex3f(7.0,-13,-0.1);

///done
		glColor3f(1.0,1.0,1.0);
		glTexCoord2i(0,0);
		glVertex3f(16.0,-7.3,-0.1);
		glTexCoord2i(0,1);
		glVertex3f(10.0,-7.3,-0.1);
		glTexCoord2i(1,1);
		glVertex3f(10.0,20.4,-0.1);
		glTexCoord2i(1,0);
		glVertex3f(16.0,20.4,-0.1);

		glTexCoord2i(0,0);
		glVertex3f(16.0,20,-0.1);  
		glTexCoord2i(0,1);
		glVertex3f(16.0,26.0,-0.1);
		glTexCoord2i(1,1);
		glVertex3f(26.0,26.0,-0.1);
		glTexCoord2i(1,0);
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
	glPushMatrix();
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
	M=0;
	glLineWidth(1.0);
}
void buildings(void){
	glPushMatrix();
		glColor3f(1.0,1.0,1.0);
		 glEnable(GL_TEXTURE_2D);
        	glBindTexture(GL_TEXTURE_2D,texture_id[3]);

		glBegin(GL_QUADS);
			for(i=20;i>-24;i=i-2){
				glTexCoord2i(0,0);
				glVertex3f(-17.1,i,0.0);
				glTexCoord2i(0,1);
				glVertex3f(-17.1,i,-8.0);  
				glTexCoord2i(1,1);
				glVertex3f(-17.1,i+2,-8.0);
				glTexCoord2i(1,0);
				glVertex3f(-17.1,i+2,0.0);

 				glTexCoord2i(0,0);
                                glVertex3f(-18.1,i,0.0);
                                glTexCoord2i(0,1);
                                glVertex3f(-18.1,i,-8.0);
                                glTexCoord2i(1,1);
                                glVertex3f(-18.1,i+2,-8.0);
                                glTexCoord2i(1,0);
                                glVertex3f(-18.1,i+2,0.0);

				glTexCoord2i(0,0);		
				glVertex3f(-17.1,i,0.0);
				glTexCoord2i(0,1);
                               glVertex3f(-17.1,i,-8.0);
				glTexCoord2i(1,1);
                                glVertex3f(-18.1,i,-8.0);
				glTexCoord2i(1,0);
                                glVertex3f(-18.1,i,0.0);


	                        glTexCoord2i(0,0);
                                glVertex3f(-17.1,i+2,0.0);
                                glTexCoord2i(0,1);
                               glVertex3f(-17.1,i+2,-8.0);
                                glTexCoord2i(1,1);
                                glVertex3f(-18.1,i+2,-8.0);
                                glTexCoord2i(1,0);
                                glVertex3f(-18.1,i+2,0.0);

				i = i -1.0;
		}
	glEnd();
	glBegin(GL_QUADS);
			for(i=20;i>-7;i=i-2){
				glTexCoord2i(0,0);
                                glVertex3f(-11.1,i,0.0);
                                glTexCoord2i(0,1);
                                glVertex3f(-11.1,i,-8.0);
                                glTexCoord2i(1,1);
                                glVertex3f(-11.1,i+2,-8.0);
                                glTexCoord2i(1,0);
                                glVertex3f(-11.1,i+2,0.0);

                                glTexCoord2i(0,0);
                                glVertex3f(-10.1,i,0.0);
                                glTexCoord2i(0,1);
                                glVertex3f(-10.1,i,-8.0);
                                glTexCoord2i(1,1);
                                glVertex3f(-10.1,i+2,-8.0);
                                glTexCoord2i(1,0);
                                glVertex3f(-10.1,i+2,0.0);

                                glTexCoord2i(0,0);
                                glVertex3f(-11.1,i,0.0);
                                glTexCoord2i(0,1);
                               glVertex3f(-11.1,i,-8.0);
                                glTexCoord2i(1,1);
                                glVertex3f(-10.1,i,-8.0);
                                glTexCoord2i(1,0);
                                glVertex3f(-10.1,i,0.0);

                                glTexCoord2i(0,0);
                                glVertex3f(-11.1,i+2,0.0);
                                glTexCoord2i(0,1);
                               glVertex3f(-11.1,i+2,-8.0);
                                glTexCoord2i(1,1);
                                glVertex3f(-10.1,i+2,-8.0);
                                glTexCoord2i(1,0);
                                glVertex3f(-10.1,i+2,0.0);

				
				i = i - 1.0;
			}
			 for(i=-15;i>-24;i=i-2){
                                glTexCoord2i(0,0);
                                glVertex3f(-11.1,i,0.0);
                                glTexCoord2i(0,1);
                                glVertex3f(-11.1,i,-8.0);
                                glTexCoord2i(1,1);
                                glVertex3f(-11.1,i+2,-8.0);
                                glTexCoord2i(1,0);
                                glVertex3f(-11.1,i+2,0.0);

                                glTexCoord2i(0,0);
                                glVertex3f(-10.1,i,0.0);
                                glTexCoord2i(0,1);
                                glVertex3f(-10.1,i,-8.0);
                                glTexCoord2i(1,1);
                                glVertex3f(-10.1,i+2,-8.0);
                                glTexCoord2i(1,0);
                                glVertex3f(-10.1,i+2,0.0);

                                glTexCoord2i(0,0);
                                glVertex3f(-11.1,i,0.0);
                                glTexCoord2i(0,1);
                               glVertex3f(-11.1,i,-8.0);
                                glTexCoord2i(1,1);
                                glVertex3f(-10.1,i,-8.0);
                                glTexCoord2i(1,0);
                                glVertex3f(-10.1,i,0.0);

                                glTexCoord2i(0,0);
                                glVertex3f(-11.1,i+2,0.0);
                                glTexCoord2i(0,1);
                               glVertex3f(-11.1,i+2,-8.0);
                                glTexCoord2i(1,1);
                                glVertex3f(-10.1,i+2,-8.0);
                                glTexCoord2i(1,0);
                                glVertex3f(-10.1,i+2,0.0);


                                i = i - 1.0;
                        }

		glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void draw(void)
{
	back = back + .1;
	printf("back : %f",back);
	if(back > 40){
		BACK =1;}
	glDisable(GL_TEXTURE_2D);
	up_sider = up_sider + .05;
	sx = carx + (x_sl*cos(-temp) - 0.5*sin(-temp));
	sy = cary + (x_sl*sin(-temp) + 0.5*cos(-temp));

	tx = carx + (0.6*cos(temp) - 0.5*sin(-temp));	
	ty = cary + (0.6*sin(temp) + 0.5*cos(-temp));	

	r_tx = carx + (0.8*cos(temp) - 0.5*sin(-temp));	
	r_ty = cary + (0.8*sin(temp) + 0.5*cos(-temp));	

	keydown();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	if(FLAG==1)
		gluLookAt(R*cos(alpha)*sin(theta),R*sin(alpha)*sin(theta),-4 +R*cos(theta),0,0,-4,0,0,-1);
	if(FLAG==2)
		gluLookAt(carx - 3*sin(temp),cary - 3*cos(temp) ,-5.5,carx + 5*sin(temp) ,cary + 5*cos(temp) ,-4,0,0,-1);
	if(FLAG==3){
		gluLookAt(carx + 0.14*sin(temp) ,cary + 0.14*cos(temp) ,-5.02,carx + 2*sin(temp) ,cary + 2*cos(temp) ,-4.9,0,0,-1);
	}	
	if(FLAG==4){
		gluLookAt(sx ,sy ,-5.51,sx + 3*sin(temp) ,sy + 3*cos(temp) ,-4.6,0,0,-1);	
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
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture_id[1]);

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
//	 glEnable(GL_TEXTURE_2D);
//	 glBindTexture(GL_TEXTURE_2D,texture_id[1]); 
		for(i=-200;i<200;i++){
			for(p=-200;p<200;p++){
		 glTexCoord2i(0,0);

		glVertex3f(i,p,0.0);	
		 glTexCoord2i(1,0);

		glVertex3f(i+1,p,0.0);
		 glTexCoord2i(1,1);

		glVertex3f(i+1,p+1,0.0);
		 glTexCoord2i(0,1);

		glVertex3f(i,p+1,0.0);
		}
	}
//	 glDisable(GL_TEXTURE_2D);
	glEnd();	
	glDisable(GL_TEXTURE_2D);		
		
	car();
	car1();
	glPushMatrix();
	sun();

//    ******new track formation***********
	track();
	buildings();		
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
