#include<iostream>
#include<cmath>
using namespace std;
// operators overloaded ~,+,-,=
class coordinate{
private:
float xnum,ynum;
public:
coordinate(float a = 0,float b = 0 ){//default point would be 0
    xnum = a;
    ynum = b;
}
void set(){
    cout<<"enter x coordinate "<<endl;
    cin>>xnum;
    cout<<"enter y coordinate"<<endl;
    cin>>ynum;
}
void display(){
    cout<<"the point is : "<<"("<<xnum<<","<<ynum<<")"<<endl;

}
float length(){
    return sqrt(xnum+ynum);
    
}
coordinate   operator -(coordinate b){
    coordinate temp;
    temp.xnum = pow(xnum-b.xnum,2);
    temp.ynum = pow(ynum-b.ynum,2);
    return temp;
    
}
int operator +(coordinate b){
    coordinate temp;
    int x = temp.length() + b.length();
    return x;
}
void operator ~(){
    if (xnum <0){
        xnum = -xnum;
    }
    else{
        xnum = xnum;
    }
    if (ynum <0){
        ynum = -ynum;
    }
    else{
        ynum = ynum;
    }
}

int operator =(int x){
    coordinate temp;
   if  (pow(temp.length(),2) == x){
    return 1;

   }
   else{
    return 0;
   }

}
};

void menu(){
    cout<<"******MENU******"<<endl;
    cout<<"1.set point"<<endl;
    cout<<"2.display point"<<endl;
    cout<<"3.display length( first point will be main set point and can SET 2ND POINT  inside this option)\n if you wont  enter 1st point distance between origin and entered point is calculated"<<endl;
    cout<<"4.check rigth angle triangle"<<endl;
    cout<<"5.exit"<<endl;
    cout<<"enter your choice"<<endl;  
}

int main(){
coordinate c,c1,c2,c3;
int a;
menu();
cin>>a;
while(1)
{
    switch(a){
    case 1:
    c.set();
    ~c;
    menu();
    cin>>a;
    break;
    /////////
    case 2:
    c.display();
    menu();
    cin>>a;
    break;
    /////////
    case 3:
    c1.set();
    ~c1;
    cout<<"distance between two pts is "<<(c-c1).length()<<endl;
    menu();
    cin>>a;
    break;
    /////////
    case 4:
    c.set();
    c1.set();
    c2.set();
    ~c;
    ~c1;
    ~c2;
    if (((c2-c)=((c2-c1)+(c-c1))) == 1 || ((c1-c)=((c2-c1)+(c-c2))) == 1 || ((c2-c1)=((c2-c)+(c-c1))) == 1){
        cout<<"given triangle is rigth angled triangle"<<endl;

    }
    else{
        cout<<"it is not rigth angled triangle"<<endl;
    }
    menu();
    cin>>a;
    break;
    /////////
    case 5 :
    return 0;
    break;
}
}




    return 0;
}
