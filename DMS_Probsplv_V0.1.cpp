//Signed by: Malak #16
//Both sides compined together sutdent and instructor 
//Droping Function is working 
//Tasks:
//1. Adding Function 
//2. Schudle generating 
//We are almost done guys ^-^!!

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <Windows.h>
#include <iostream>
#include "User.h"
//#include "Courses.cpp"
#include "Instructor.h"
#include "Instructor.cpp"
#include "FormManger.h"
#include "Student.h"
#include "Student.cpp"
#include <fstream>


User CurrentUser;
FormManger Fhndlr;


int main()
{
    //George was here
    sf::RenderWindow win(sf::VideoMode(750, 400), "Login", sf::Style::None);
    tgui::Gui gui{ win };


    gui.loadWidgetsFromFile(Fhndlr.Form.Login);


    gui.get<tgui::Button>("Button1")->onPress([&] {
        if (CurrentUser.validateLogin((gui.get<tgui::EditBox>("EditBox1")->getText()).toStdString(), (gui.get<tgui::EditBox>("EditBox2")->getText()).toStdString()))
        {
            gui.removeAllWidgets();
            std::cout << "Login success\n";
            win.create(sf::VideoMode(750, 750), "Student Advising System");
            Fhndlr.Setscreen(win, gui, CurrentUser.getUsr(), CurrentUser.getUserType(), CurrentUser.getUserID());

        }

        else
        {
            int MboxFailLogin1 = MessageBoxA(NULL, (LPCSTR)"Login failed\n Username or Password incorrect", (LPCSTR)"Login Error", MB_ICONWARNING | MB_RETRYCANCEL | MB_DEFBUTTON1);

            switch (MboxFailLogin1)
            {
            case IDCANCEL:
                win.close();
            default:
                break;
            }
        }

        });


    while (win.isOpen())
    {
        sf::Event ev;

        while (win.pollEvent(ev))
        {
            gui.handleEvent(ev);
            if (ev.type == sf::Event::Closed)
            {
                win.close();
            }


        }

        win.clear();
        gui.draw();
        win.display();

    }
}
//Signed #16