/*
 *
 * @author PONCIANO Jean-Jacques et PRUDHOMME Claire
 * Copyright  2014  PONCIANO Jean-Jacques et PRUDHOMME Claire
 * Contact: ponciano.jeanjacques@gmail.com
 * Créé le 13 Mars 2014
 *
 * Cette oeuvre, création, code, site ou texte est sous licence Creative Commons  Attribution - Pas d’Utilisation Commerciale - 
 * Partage dans les Mêmes Conditions 4.0 International. Pour accéder à une copie de cette licence, merci de vous rendre à l'adresse suivante 
 * http://creativecommons.org/licenses/by-nc-sa/4.0/deed.fr ou envoyez un courrier à Creative Commons, 444 Castro Street, Suite 900,
 * Mountain View, California, 94041, USA.
 */

#include "Point.h"

PointGL::PointGL() {
    rad=3.14159265/180.0;
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

PointGL::PointGL(float x, float y,float z) {
    rad=3.14159265/180.0;
    this->x = x;
    this->y = y;
    this->z = z;
}

PointGL::PointGL(const PointGL& orig) {
    rad=3.14159265/180.0;
    this->x = orig.x;
    this->y = orig.y;
    this->z = orig.z;
}

PointGL::~PointGL() {
}
void PointGL::setNormalMoyenne(std::vector<float> n){
    this->normalMoyenne.clear();
    float z=n[2];
    float y=n[1];
    float x=n[0];
    this->normalMoyenne.push_back(x);
    this->normalMoyenne.push_back(y);
    this->normalMoyenne.push_back(z);
}
void PointGL::setNormalMoyenne(float x, float y, float z){
     this->normalMoyenne.clear();
    this->normalMoyenne.push_back(x);
    this->normalMoyenne.push_back(y);
    this->normalMoyenne.push_back(z);
}
float PointGL::getX() const {
    return this->x;
}
std::vector<float> PointGL::getNormal() const{
    return this->normalMoyenne;
}
float PointGL::getY() const {
    return this->y;
}

float PointGL::getZ() const {
    return this->z;
}

void PointGL::setX(float a) {
    this->x=a;
}

void PointGL::setY(float a) {
    this->y=a;
}

void PointGL::setZ(float a) {
    this->z=a;
}

void PointGL::rotation(float a, int x, int y, int z){
     if(x==1){
        float ay=this->getY();
        float az=this->getZ();
    this->setY(ay*cos(a*rad)-sin(a*rad)*az);
    this->setZ(ay*sin(a*rad)+az*cos(a*rad));
    }
    
    if(y==1){
        float ax=this->getX();
        float az=this->getZ();
    this->setX(ax*cos(a*rad)+az*sin(a*rad));
    this->setZ(-ax*sin(a*rad)+az*cos(a*rad));
    }
    
    if(z==1){
        float ax=this->getX();
        float ay=this->getY();
    this->setX(ax*cos(a*rad)-ay*sin(a*rad));
    this->setY(ax*sin(a*rad)+ay*cos(a*rad));
}
}
void PointGL::translation(float tx, float ty, float tz){
    this->x=this->x+tx;
    this->y=this->y+ty;
    this->z=this->z+tz;
}

void PointGL::scale(float sx, float sy, float sz){
    this->x=this->x*sx;
    this->y=this->y*sy;
    this->z=this->z*sz;
}