#include <iostream>
using namespace std;
class shape
{
  int radius;
  public:
       void set_radius(int r)

       {
          radius = r ;
       }
       int get_radius(){
           return radius;
       }
};
class circle : public shape{
    float area;
public:
    void process()
    {
        area=3.14 * get_radius() * get_radius() ;
        cout<<"\nThe area of circle with radius " <<get_radius()<<" is :" <<area;
    }
};
int main()
{
    circle c[20];
    int n,i,r;
    cout<<"Enter the no. of circles ";
    cin>>n;
    for(int i=0 ; i<n ;i++)
    {

        cout<<"\n\nEnter the radius of circle : " <<i+1<<":";
        cin>>r;
        c[i].set_radius(r);
        c[i].process();
    }

    return 0;
}
