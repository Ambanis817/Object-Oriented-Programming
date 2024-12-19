
// Samuel Ambani 1001694453
#include <iostream>
#include<gtkmm.h>
//#include "Code7_1001694453.h"

//using namespace std;

class MyWindow: public Gtk :: Window 
{
    public : 
        MyWindow();
        void Ok (Gtk :: Entry*);
        void Cancel ();
};

MyWindow::MyWindow ()
{
    set_default_size(800,500);
    set_title("Welcome to My Guessing Game");
    set_position(Gtk::WIN_POS_CENTER);
    set_border_width(30);
    Gtk::Box *VBox = Gtk::manage(new Gtk:: Box (Gtk:: ORIENTATION_VERTICAL,0));
    add(*VBox);
    // first menu
    Gtk::MenuBar *MyMenuBar = Gtk :: manage(new Gtk::MenuBar());
    VBox -> pack_start(*MyMenuBar,Gtk::PACK_SHRINK,0);
    Gtk:: MenuItem *hint = Gtk:: manage(new Gtk ::MenuItem("_ Show Hints",true));
    MyMenuBar -> append(*hint);
    // second menu
    Gtk:: MenuItem *second = Gtk:: manage(new Gtk ::MenuItem("_ Genre Hint ",true));
    MyMenuBar -> append(*second);

    // thrid menu 
    Gtk:: MenuItem *thrid = Gtk:: manage(new Gtk ::MenuItem("_ Other Hints",true));
    MyMenuBar -> append(*thrid);

    //  first submenus
    Gtk::Menu *Mysub = Gtk :: manage(new Gtk :: Menu ());
    hint -> set_submenu(*Mysub);
    
    Gtk :: MenuItem *sub_netflix= Gtk:: manage(new Gtk::MenuItem("_NETFLIX",true));
    Mysub -> append(*sub_netflix);

    Gtk :: MenuItem *sub_anime= Gtk:: manage(new Gtk::MenuItem("_ANIME",true));
    Mysub -> append(*sub_anime);

    Gtk :: MenuItem *sub_hunter= Gtk:: manage(new Gtk::MenuItem("_SHONIN",true));
    Mysub -> append(*sub_hunter);


    // second submenus
    Gtk::Menu *Mydub = Gtk :: manage(new Gtk :: Menu ());
    second -> set_submenu(*Mydub);

    Gtk :: MenuItem *dub_netflix= Gtk:: manage(new Gtk::MenuItem("_SUB",true));
    Mydub-> append(*dub_netflix);

    Gtk :: MenuItem *dub_anime= Gtk:: manage(new Gtk::MenuItem("_DUB",true));
    Mydub -> append(*dub_anime);

    Gtk :: MenuItem *dub_hunter= Gtk:: manage(new Gtk::MenuItem("_JAPANESE",true));
    Mydub -> append(*dub_hunter);


    // thrid submenus
    Gtk::Menu *Mythrid = Gtk :: manage(new Gtk :: Menu ());
    thrid -> set_submenu(*Mythrid);

    Gtk :: MenuItem *thrid_netflix= Gtk:: manage(new Gtk::MenuItem("_GREEN JACKET",true));
    Mythrid -> append(*thrid_netflix);

    Gtk:: Label *MyLabel = Gtk:: manage (new Gtk :: Label{"What anime ?/n/n"});
    VBox-> pack_start(*MyLabel);



    Gtk:: Image *MyImage = Gtk:: manage (new Gtk :: Image{"image.png"});
    VBox -> pack_start(*MyImage);

    Gtk :: Box *Hbox = Gtk :: manage (new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL,0));
    VBox -> add(*Hbox);

    Gtk :: Box *firstvbox = Gtk :: manage (new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0));
    Hbox -> pack_end(*firstvbox);

    Gtk :: Box *secondvbox = Gtk :: manage (new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0));
    Hbox -> pack_end(*secondvbox);

    //Gtk :: Button *ok = Gtk :: manage(new Gtk :: Button ("Ok"));
    //Hbox -> add(*ok);

   // Gtk :: Button *cancel = Gtk :: manage(new Gtk :: Button ("Cancel"));
   // Hbox -> add(*cancel);


    Gtk :: Entry *MyEntry = Gtk :: manage (new Gtk :: Entry ());
    Gtk :: Button *Cbutton = Gtk :: manage(new Gtk :: Button ("Cancel"));
    MyEntry -> set_text("Enter your guess here");
    MyEntry -> set_max_length(50);
    MyEntry -> show();
    MyEntry->set_hexpand(true);
    Gtk :: Button *Obutton = Gtk :: manage(new Gtk :: Button ("Ok"));
    secondvbox ->pack_start(*Obutton);
    secondvbox -> pack_start(*Cbutton);

    Cbutton -> set_border_width(3);
    Cbutton -> signal_clicked ().connect(sigc:: mem_fun(*this,&MyWindow::Cancel));

    Obutton -> set_border_width(3);
    Obutton->signal_clicked().connect(sigc::bind<Gtk::Entry*>(sigc::mem_fun(this, &MyWindow::Ok),MyEntry));

    firstvbox ->add(*MyEntry);

    MyEntry -> set_activates_default(true);
    Obutton -> set_can_default();
    Obutton -> grab_default();
    
    MyEntry -> set_can_focus(true);
    MyEntry->grab_focus();
    VBox -> show_all();

}


void  MyWindow::Ok (Gtk  :: Entry *entry)
{
    if(entry->get_text().compare("gon") == 0 || entry->get_text().compare("Gon") == 0)
    {
    Gtk::MessageDialog correct{"You guess correctly ",true,Gtk::MESSAGE_WARNING,Gtk::BUTTONS_OK,true};
    correct.run();
    hide();
    }
    else
    {
         Gtk::MessageDialog incorrect{"You guess incorrectly ",true,Gtk::MESSAGE_ERROR,Gtk::BUTTONS_OK,true};
         incorrect.run();
    }

}

void MyWindow :: Cancel()
{
    hide();
}

int main (int argc ,char *argv[])
{
    auto app = Gtk :: Application :: create(argc,argv,"");

     MyWindow Window;

    app -> run (Window);

    return 0;


}