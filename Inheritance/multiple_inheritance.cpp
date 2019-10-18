/* This program aims to describe the use of multiple inheritance
 to derive properties of base classes to derived classes.
 Here we have used vector class which derives two_d and three_d classes
 to find vector projection of one vector on other vector
 */
 
#include<bits/stdc++.h>
using namespace std;
class two_d{
  float x,y;
public:
  two_d(){
    x=0;
    y=0;
  }
  two_d(float x,float y){
    this->x=x;
    this->y=y;
  }
  void setx(float x){
    this->x=x;
  }
  void sety(float y){
    this->y=y;
  }
  float getx(){
    return x;
  }
  float gety(){
    return y;
  }
};

class three_d: public two_d{
private:
  float z;
public:
  three_d(){
    z=0;
    two_d::setx(0);
    two_d::sety(0);
  }
  three_d(float x,float y){
    z=0;
    two_d::setx(x);
    two_d::sety(y);
  }
  three_d(float x,float y,float z){
    this->z=z;
    two_d::setx(x);
    two_d::sety(y);
  }
  void setz(float z){
    this->z=z;
  }
  float getz(){
    return z;
  }
};

class vectors: public three_d{
public:
  vectors(){
    two_d::setx(0);
    two_d::sety(0);
    three_d::setz(0);
  }
  vectors(float x,float y,float z){
    two_d::setx(x);
    two_d::sety(y);
    three_d::setz(z);
  }
  vectors(float x1,float y1,float z1,float x2,float y2,float z2){
    two_d::setx(x1-x2);
    two_d::sety(y1-y2);
    three_d::setz(z1-z2);
  }
  vectors(vectors &v){
    two_d::setx(v.getx());
    two_d::sety(v.gety());
    three_d::setz(v.getz());
  }
  void setiComponent(float x){
    two_d::setx(x);
  }
  float getiComponent(){
    return two_d::gety();
  }
  void setjComponent(float y){
    two_d::sety(y);
  }
  float getjComponent(){
    return two_d::gety();
  }
  void setkComponent(float z){
    three_d::setz(z);
  }
  float getkComponent(){
    return three_d::getz();
  }
  void crossmultiply(vectors v2){
    float x1,y1,z1,x2,y2,z2;
    x1=getiComponent();
    y1=getjComponent();
    z1=getkComponent();
    x2=v2.getiComponent();
    y2=v2.getjComponent();
    z2=v2.getkComponent();
    setiComponent(y1*z2-z1*y2);
    setjComponent(x2*z1-x1*z2);
    setkComponent(x1*y2-x2*y1);
  }
  float dotmultiply(vectors v2){
    float x1,y1,z1,x2,y2,z2;
    x1=getiComponent();
    y1=getjComponent();
    z1=getkComponent();
    x2=v2.getiComponent();
    y2=v2.getjComponent();
    z2=v2.getkComponent();
    return ((x1*x2)+(y1*y2)+(z1*z2));
  }
  float getvectorlength(){
    float x1,y1,z1;
    x1=getiComponent();
    y1=getjComponent();
    z1=getkComponent();
    return sqrt(x1*x1+y1*y1+z1*z1);
  }
};

int main(){
  vectors v1,v2;
  cout<<"Enter the first vector";
  float x1,y1,z1,x2,y2,z2;
  cin>>x1>>y1>>z1;
  v1.setiComponent(x1);
  v1.setjComponent(y1);
  v1.setkComponent(z1);
  cout<<"Enter the second vector";
  cin>>x2>>y2>>z2;
  v2.setiComponent(x2);
  v2.setjComponent(y2);
  v2.setkComponent(z2);
  float projection=v1.dotmultiply(v2);
  float length=v2.getvectorlength();
  vectors v3;
  cout<<"length"<<length;
  v3.setiComponent(projection*v2.getiComponent()/(length*length));
  v3.setjComponent(projection*v2.getjComponent()/(length*length));
  v3.setkComponent(projection*v2.getkComponent()/(length*length));
  cout<<"The vector projection of first vector on the second vector is";
  cout<<"x component is"<<v3.getiComponent()<<endl;
  cout<<"y component is"<<v3.getjComponent()<<endl;
  cout<<"z component is"<<v3.getkComponent()<<endl;
  return 0;
}
