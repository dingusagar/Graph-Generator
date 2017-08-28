#include <iostream.h>
#include <graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>

class GRAPH
{
    int origin_X,origin_Y,no_of_elements,width,Y_scale;
    int Yfield_value[10],plot[10];
    char Xfield_name[25],Yfield_name[25],Xfield_value[10][10];

public:
    GRAPH();
    void get_origin_cordinates();
    void get_details();
    void draw_axis();
    void display_Xfield();
    void display_Yfield();
    void calculate_Yscale();
    void show_units();
    void calculate_plotting_points();
    void point_graph();
    void GRAPH :: Bar_graph();
    void Set_up_graph();

};

 GRAPH :: GRAPH()
{
    no_of_elements=5;
    width=40;
    origin_X=50;
    origin_Y=450;


}

void GRAPH ::get_origin_cordinates()
{
    cout<<"Give cordinates of origin . "<<endl;
    cout<<"X cordinate = ";cin>>origin_X;
       cout<<"Y cordinate = ";cin>>origin_Y;
       cout<<endl;
}

void GRAPH::point_graph()
{
   for(int i=1;i<=no_of_elements;i++)
   {
      outtextxy(origin_X+width*i,plot[i],"*");

   }

}
void GRAPH ::draw_axis()
{

    int maxx=getmaxx();

    line(origin_X,origin_Y,origin_X,1);
      line(origin_X,origin_Y,maxx-1,origin_Y);

      gotoxy(origin_X,0); cout<<'^';
      gotoxy (origin_Y,maxx); cout<<'>';

      for(int i =1;i<=no_of_elements;i++)
      {
	 circle(origin_X+width*i,origin_Y,2);
	 circle(origin_X,origin_Y-i*width,2);

	   }

}


void GRAPH::get_details()
{

    cout<<"Getting details for the  graph...."<<endl;
    cout<<"\n X axis stands for : "; gets(Xfield_name);
    cout<<"\n Y axis stands for : "; gets(Yfield_name);

    cleardevice();

    gotoxy(5,5); cout<<Xfield_name;
    gotoxy(5,7);cout<<Yfield_name;
    int xl=strlen(Xfield_name);
    int yl=strlen(Yfield_name);

    int w=(xl>yl)?xl:yl;

	for (int i =1;i<=no_of_elements;i++)
    {

	gotoxy(5+w+10*i,5);
	gets(Xfield_value[i]);

	gotoxy(5+w+10*i,7);
	 cin>>(Yfield_value[i]);

    }

}

void GRAPH ::display_Xfield()
{
	char *text;
    for(int i =1;i<=no_of_elements;i++)
    {

	 outtextxy(origin_X+width*i,origin_Y+(width/3),Xfield_value[i]);


    }

}



void GRAPH ::display_Yfield()
{
	char * text;
    for(int i =1;i<=10;i++)
    {
	itoa (Y_scale*i,text,10);
	 outtextxy(origin_X-width,origin_Y-width*i,text);

    }

}

void GRAPH ::calculate_Yscale()
{

    int max_value_Y=Yfield_value[0];

    for(int i =1;i<no_of_elements;i++)
	if(Yfield_value[i]>max_value_Y)
	    max_value_Y= Yfield_value[i];
       /**< maximum value of y found... */

       if (max_value_Y<=10)
	    Y_scale=1;
	else if (max_value_Y<=20)
	    Y_scale=2;

	else if (max_value_Y<=50)
	    Y_scale=5;

	else if (max_value_Y<=100)
	    Y_scale=10;

	else
	    Y_scale=max_value_Y/10;

}


void GRAPH ::calculate_plotting_points()
{
    int t1,t2;

    for(int i =1;i<=no_of_elements;i++)
    {

	t1= Yfield_value[i]/Y_scale;
	t2=Yfield_value[i]%Y_scale;

	float t3=(float)((t2*width)/Y_scale);

	plot[i]=origin_Y-(width*t1 +t3);

    }


}

void GRAPH ::show_units()
{
    gotoxy(25,5);
    cout<<" Y axis : 1 unit = "<< Y_scale <<" "<< Yfield_name;
}



void GRAPH :: Bar_graph()
{
    for(int i=1;i<=no_of_elements;i++)
    {
	rectangle(origin_X+width*i-(width/2),plot[i],origin_X+width*(i+1)-(width/2),origin_Y);
    }


}

void GRAPH :: Set_up_graph()
{

    void calculate_Yscale();
    void calculate_plotting_points();
    void draw_axis();
    void display_Xfield();
    void display_Yfield();
    void show_units();



}

void message1()
{
    cleardevice();
     outtextxy(210,210,"Information Received.")  ;
     delay(10);
     cleardevice();
      outtextxy(210,210,"Processing Graph .....")  ;
      delay(10);

}



void main()
{
  clrscr();

   /* request auto detection */
int gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "");

/* read result of initialization */
errorcode = graphresult();

if (errorcode != grOk)  /* an error occurred */
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1);             /* return with error code */
}


   char ch;

   GRAPH g;
   g.get_details();
 //  g.get_origin_cordinates();
   message1();

   menu:
    cleardevice();
   outtextxy(200,180,"Give your choice .");
    outtextxy(200,190," 1.  Display Bar Graph ");
    outtextxy(200,200," 2.  Display Line Graph ");
    outtextxy(200,210," 3.  Quit ");
    cin>>ch;


   cleardevice();

   g.draw_axis();
   g.display_Xfield();
   g.calculate_Yscale();
   g.display_Yfield();
   g.calculate_plotting_points();

   if(ch==1)
  {   g.Bar_graph();
     getch();
   }
   else if(ch==2)
    { g.point_graph();
      getch();
      }
   else if (ch==3)
     exit(1);

   else
    { outtextxy(200,184," Invalid choice ..try again ");
      goto menu;
     }
   g.show_units();
   outtextxy(200,184," Press any key to go to Main Menu ");
   getch();
   goto menu;
    getch() ;

}
