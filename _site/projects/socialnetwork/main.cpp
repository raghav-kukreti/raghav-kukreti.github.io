//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (|--_--|)
//                      0 \ = /0
//                    ___/`--  \___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               May The Buddha Bless you.
//

#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define max 20;
using namespace std;
class account {
    int id, active; //auto increment this
    char user[80], pass[42], fname[80], lname[80], email[1024], messname[100], budname[100], status[1000];
    public:
        account(){
            active = 0;
        }
        void login();
        void reg();
        void getdata__reg();
        void getdata__log();
        void getpass();
        void disp();

        void activate_session(char*, char*, char* , char*, char*, char*);
        char* rfname() {return fname;}
        char* rlname() {return lname;}
        char* remail() {return email;}
        char* rmessname() {return messname;}
        char* rbudname() {return budname;}
        char* rusername() {return user;}
        void edit_username() {cout << "Enter your new username: ";cin>>user;}
        void edit_email() {cout << "Enter your new email address: ";cin>>email;}
};
void d_lay();
void make_line();

class stat_us {
    char stat[1000];

    public:
        void take_status() {
            cin.get();
            cout << "Enter status: ";
            gets(stat);
        }
        void display() {
            cout << "Current status: ";
            cout << stat;
        }
};

class frndz {
    char f_name[80], l_name[80];
    public:
        void input(char fname[80], char lname[80]){
            strcpy(f_name, fname);
            strcpy(l_name, lname);
        }
        void display(){
            cout << f_name << " "<< l_name;
            cout << endl;
        }
};
class mess {
    char message[3000], sender_email[1024];
    public:
        void getmessage(char email[1024]) {cout << "\n\tEnter message contents: "; gets(message); strcpy(sender_email, email);}
        void display() {
            cout << "\n\t\tFrom: "<<sender_email<<endl;
            cout << "\t\t"<<message<<"\n";
            cout << "\t\t";make_line();
        }
};
void delay(unsigned int mseconds){clock_t goal = mseconds + clock(); while (goal > clock());}
/*I did not write the above function and have copied it from an online source.*/

void cls() {
    system("cls");
}
void d_lay() {
    cls();
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tLoading ";
    for(int x=0;x<20;x++) {
        delay(10);
        cout<<"." ;
    }
    cls();
}
void gen_random(char *s, const int len) {
    static const char alphanum[] = "0123456789"
                                    "!@%^&*()_+-={}[]|\?/>.<,:;"
                                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                    "abcdefghijklmnopqrstuvwxyz";
    srand((int) time(0));
    for (int i=0; i<len; ++i) {
        s[i] = alphanum[rand()%(sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}
void add_to_frndz(account acc, char *budname) {
    fstream fil;
    fil.open(budname, ios::out | ios::app |ios::binary);
    frndz frnd;

    frnd.input(acc.rfname(), acc.rlname());
    fil.write((char*)&frnd, sizeof(frnd));
}
void hLine(int n) {
    int i;
    for (i=0; i<n; i++) {
        cout << "*";
    }
}

void account::getpass() {
    char ch;
    int i=0;
    do {
        ch=getch();
        pass[i++] = ch;
        cout << "*";
    }while(ch != 13);

    pass[i-1] = '\0';
}

void send_message(char sender_email[1024]) {
    char tosend[1024], recip_mess[3000];
    char lol = '3';
    fstream fil1, fil2;
    fil1.open("users.dat", ios::binary | ios::in);
    account acc;
    mess message;
    cout <<"\n\n\n\t";
    cin.get();
    cout << "Enter recipient (E-mail address): ";
    gets(tosend);

    while(fil1.read((char*)&acc, sizeof(acc))) {
        if (strcmp(tosend, acc.remail()) == 0) {
            message.getmessage(sender_email);
            strcpy(recip_mess, acc.rmessname());
            fil2.open(recip_mess, ios::out| ios::app |ios::binary);
            fil2.write((char*)&message, sizeof(message));

        }

    }
    fil2.clear();
    fil2.seekg(0, ios::beg);
}

void up_status(char *username) {
    fstream fil;
    stat_us stat;
    fil.open(username, ios::out| ios::app |ios::binary);
    stat.take_status();
    fil.clear();
    fil.seekg(0, ios::beg);
    fil.write((char*)&stat, sizeof(stat));
    fil.clear();
    fil.seekg(0, ios::beg);
    fil.close();
}
void search_friends(char *budname) {
    fstream fil;
    int found = 0;
    fil.open("users.dat", ios::in | ios::binary);
    account acc;
    char ch;
    cin.get();
    char fname_data[90];
    cout << "Enter friend's first name: ";
    gets(fname_data);

    while(fil.read((char*)&acc, sizeof(account))) {
        if (strcmpi(acc.rfname(), fname_data) == 0) {
            acc.disp();
            cout <<endl;
            cout <<"Add person to circle? (Y/n)";
            cin>>ch;
            if (ch == 'y') {
                add_to_frndz(acc, budname);
            }
            found ++;
        }
    }
    if (!found) {
        cout << "No users present...";
    }fil.write((char*)&acc, sizeof(acc));
}

void editer_user() {
    fstream fil;
    fil.open("users.dat", ios::in | ios::out | ios::binary);
    account acc;
    char user_name[40];
    int found=0;
    cin.get();
    cout << "Enter existing username: ";
    gets(user_name);
    while(!found && fil.read((char*)&acc, sizeof(acc))) {
        if(strcmpi(user_name, acc.rusername())==0 ){
            found++;
        }
    }
        if(found) {
            acc.edit_username();
            int n = fil.tellg()-sizeof(acc);
            fil.seekp(n);
            fil.write((char*)&acc, sizeof(acc));
        }
        else {
            cout << "Oops! something went wrong...";
        }
        fil.close();
    }
void editer_paas() {
    fstream fil;
    fil.open("users.dat", ios::in | ios::out | ios::binary);
    account acc;
    char user_name[40];
    int found=0;
    cin.get();
    cout << "Enter existing username: ";
    gets(user_name);
    while(!found && fil.read((char*)&acc, sizeof(acc))) {
        if(strcmpi(user_name, acc.rusername())==0 ){
            found++;
        }
    }
        if(found) {
            acc.edit_username();
            int n = fil.tellg()-sizeof(acc);
            fil.seekp(n);
            fil.write((char*)&acc, sizeof(acc));
        }
        else {
            cout << "Oops! something went wrong...";
        }
        fil.close();
    }
void editer_email() {
    fstream fil;
    fil.open("users.dat", ios::in | ios::out | ios::binary);
    account acc;
    char email[1024];
    int found=0;
    cin.get();
    cout << "Enter existing username: ";
    gets(email);
    while(!found && fil.read((char*)&acc, sizeof(acc))) {
        if(strcmpi(email, acc.rusername())==0 ){
            found++;
        }
    }
        if(found) {
            acc.edit_email();
            int n = fil.tellg()-sizeof(acc);
            fil.seekp(n);
            fil.write((char*)&acc, sizeof(acc));
        }
        else {
            cout << "Oops! something went wrong...";
        }
        fil.close();
    }


    //https://www.reddit.com/r/needforspeed/comments/3ld9bi/what_songs_would_you_like_to_see/
/***************************************************************/
/***************************************************************
 .d8888b.   .d88888b.  8888888b.        .d8888b.  888             d8888  .d8888b.   .d8888b.
d88P  Y88b d88P" "Y88b 888  "Y88b      d88P  Y88b 888            d88888 d88P  Y88b d88P  Y88b
888    888 888     888 888    888      888    888 888           d88P888 Y88b.      Y88b.
888        888     888 888    888      888        888          d88P 888  "Y888b.    "Y888b.
888  88888 888     888 888    888      888        888         d88P  888     "Y88b.     "Y88b.
888    888 888     888 888    888      888    888 888        d88P   888       "888       "888
Y88b  d88P Y88b. .d88P 888  .d88P      Y88b  d88P 888       d8888888888 Y88b  d88P Y88b  d88P
 "Y8888P88  "Y88888P"  8888888P"        "Y8888P"  88888888 d88P     888  "Y8888P"   "Y8888P"



***************************************************************/
/***************************************************************/
void account::activate_session(char *user, char *fname, char *lname, char *email, char *messname, char *budname) {
    cls();
    cout << endl;
    fstream fil, fil1, fil2, fil3;
    fil.open(budname, ios::in | ios::binary);
    fil1.open(messname, ios::in | ios::binary);
    fil2.open(user, ios::in | ios::binary);
    fil3.open("users.dat", ios::in | ios::out | ios::binary);
    stat_us st;
    frndz frnd;
    mess message;
    account acc;
    int no_of_frndz = 0;

    int no_of_mess = 0;
    while(fil1.read((char*)&message, sizeof(message))) {
        no_of_mess++;
    }
    fil.clear();
    fil.seekg(0, ios::beg);
    int ch;
    /*
    cout << "Account Details:\n" ;
    cout << "Username: "<<user<<endl;
    cout <<"First Name: "<<fname<<endl;
    cout << "Last name: "<<lname<<endl;
    cout <<"Email: "<<email<<endl;
    cout <<"Messname: "<<messname<<endl;
    cout <<"Buddynames: "<<budname;
*/

//cout << "\n\n\n\n\tHello, "<< fname<<endl;

do {
    int found = 0;
    no_of_frndz = 0;
    while(fil.read((char*)&frnd, sizeof(frnd))) {
        no_of_frndz++;
    }
    cout << "\n\n\n\n\tHello, "<< fname<<endl;
    cout << "\t";
    int n = 0;
    while(fil3.read((char*)&acc, sizeof(acc))) {
        n++;
    }
    fil3.clear();
    fil3.seekg(0, ios::beg);
    if (strcmpi(user, "admin") == 0) {
        cout << "There are currently "<<n<<" Ello members";
    }
    //fil2.seekg(0, ios::end);
    //int nor = fil2.tellg()/sizeof(st);

    //cout << nor;
    while(fil2.read((char*)&st, sizeof(st)) && found==0) {
        fil2.seekp(sizeof(st), ios::cur);
        st.display();
        found++;
    }

cout << "\n\t";
cout << "1. Edit Profile\n";
cout << "\t2. Send a message\n";
cout << "\t3. Inbox ["<<no_of_mess<<"] \n";
cout << "\t4. Friend List ["<<no_of_frndz<<"] \n";
cout << "\t5. Update your status\n";
cout << "\t6. Find friends\n";
cout << "\t7. Log Out\n";
    if (strcmpi(user, "admin") == 0) {
        cout << "\t8. Delete an account\n";
    }
cout << "\tYour choice: ";
cout << "\t";cin >> ch;
if (ch == 1) {
    d_lay();
    cout << "Account Details:\n" ;
    cout << "Username: "<<user<<endl;
    cout <<"First Name: "<<fname<<endl;
    cout << "Last name: "<<lname<<endl;
    cout <<"Email: "<<email<<endl;
    cout <<"Messname: "<<messname<<endl;
    cout <<"Buddynames: "<<budname;

    cout << "\nEnter the choice of editing field: \n";
    cout << "1. Username\t2.E-mail\t3.Password";
    int li;
    cin>> li;

    if(li == 1) {
        editer_user();
    }
    else if (li==2) {
        editer_email();
    }
}
else if(ch == 2){
    d_lay();
    send_message(email);
}
else if(ch ==3) {

    cout << "Your messages \n";
    fil1.clear();
    fil1.seekg(0, ios::beg);
    d_lay();
    while(fil1.read((char*)&message, sizeof(message))) {
        message.display();
        cout << endl;
    }
    cin.get();
    cout << "Press any key to continue...";
    cin.get();
    d_lay();
}
else if (ch == 4) {
    d_lay();
    cout <<"Your friends: \n";
    fil.clear();
    fil.seekg(0, ios::beg);
    while (fil.read((char*)&frnd, sizeof(frnd))) {
        frnd.display();
    }
    cin.get();
    fil.clear();
    fil.seekg(0, ios::beg);
    cout << "Press any key to continue...";
    cin.get();
    d_lay();
}
else if(ch == 5) {
    up_status(user);
}
else if (ch==6) {

    search_friends(budname);
    while(fil.read((char*)&frnd, sizeof(frnd))) {
        no_of_frndz++;
    }

    fil.clear();
    fil.seekg(0, ios::beg);
}
else if (ch == 7) {
    d_lay();
    cout << "\n\n\n";
}
}while(ch !=7);
}

void make_line() {
    int i;
    for (i=1; i<40; i++) {
        cout << "_";
    }
}
void account::login() {
    int check=0;
    fstream fil;
    fil.open("users.dat", fstream::in | fstream::binary);
    account acc;
    getdata__log();

    while(fil.read((char*)&acc, sizeof(acc))) {
       if (strcmp(user, acc.user) == 0) {
            cout << acc.pass<<"  "<<pass;
            if (strcmpi(acc.pass, pass) == 0) {
                cout << "You were successfully logged in.";
                char *fname,*lname, *email, *messname, *budname;
                fname = acc.rfname();
                lname = acc.rlname();
                email = acc.remail();
                messname = acc.rmessname();
                budname = acc.rbudname();
                activate_session(user, fname, lname, email, messname, budname);
            }
            else
                cout << "\nThe username or password entered is wrong.\n";
            check++;
       }
    }

    if (check == 0) {
        cout << "\nThe username or password entered is wrong.\n";
    }

}

void account::getdata__reg() {
    fstream mess, budz, statuses;
    d_lay();
    cout<<"https://www.ello.co/reg.php";
    //randomize();
    cout<<"\n\n\t\tYour Unique Network ID is:\t"<<" "<<rand()<<"-"<<rand()<<"-"<<rand()<<"-"<<rand()<<endl;
    cin.get();
    cout << "\n\n\t\tEnter username: ";
    gets(user);
    cout << "\n\n\t\tEnter password: ";
    getpass(); cout <<endl;
    cout << "\n\n\t\tEnter first name: ";
    gets(fname);
    cout << "\n\n\t\tEnter last name: ";
    gets(lname);
    cout << "\n\n\t\tEnter email address: ";
    gets(email);
    cout << "\n\n\t\tCreate your personal message box (Name of file): ";
    cin >> messname;
    cout << "\n\n\t\tName your friend list: ";
    cin >> budname;

    mess.open(messname, ios::out);
    budz.open(budname, ios::out);
    statuses.open(user, ios::out);
}

void account::getdata__log() {

    cout << "\n\n\n\n\t";
    cin.get();
    cout << "Enter username: ";
    gets(user);
    cout << "\n\tEnter password: ";
    getpass();
}
void account::reg() {
    fstream fil;
    char sy[20], sx[20];
    fil.open("users.dat", fstream::out | fstream::app |fstream::binary);
    account acc;
    acc.getdata__reg();
    // Checking the entered data and sanitizing etc.
    d_lay();
    cout << "\n\n\n\tPlease verify you are a hooman: ";
    gen_random(sy, 6);
    cout <<"\t\n\t" <<sy<<"\n\n\t";
    cin >> sx;
    if(strcmp(sx, sy)==0) {
        fil.write((char*)&acc, sizeof(acc));
    }
    else {
        cout << "\tThe captcha was incorrect...";
        cin.get();
    }
}
/*void frndz::makes() {
    fstream fil;
    fil.open("myFriends", fstream::out | fstream::app | fstream::binary);
    frndz frnd;

    frnd.getname();
    // Checking the entered data and sanitizing etc.
    fil.write((char*)&frnd, sizeof(frnd));
}*/

void account::disp() {
    cout << "Name: "<<fname<<" "<<lname<<"\n";
    cout << "Email address: "<<email;
}

void display() {
    fstream fil;
    fil.open("users.txt", ios::in);

    account acc;
    while(fil.read((char*)&acc, sizeof(acc))) {
        acc.disp();
    }
}
void vLine(int n) {
    int i;
    for (i=0; i<n; i++) {
        cout << "*";
        cout << endl;
    }
}


void s() {
        cout << endl;
}


void show_ascii() {
    fstream fil;
    fil.open("ascii.txt", ios::in);
    char lin[1000];

    while(fil.getline(lin, 1000)){
        cout << "\t "<<lin;
        cout << endl;
    }
    cout <<"\t  Connecting the world.\t\t\t By Raghav Kukreti\n\n";
}

void show_ascii_startup() {
    fstream fil;
    fil.open("ascii2.txt", ios::in);
    char lin[1000];

    while(fil.getline(lin, 1000)){
        cout << "\t "<<lin;
        cout << endl;
    }
    delay(3400);
    cls();
    //cout <<"\t  Connecting the world.\t\t\t By Raghav Kukreti\n\n";
}


int main() {
    system("color 0A");
    account acc;

    int ch;
    //frndz frnd;

    char check;
    show_ascii_startup();
    cout << "\n\n\n\n\n\n";
    show_ascii();
    cout << "\t  Enter Ello? (y/n)";
    cin >> check;

    if (check == 'y') {
        d_lay();
    }
    else {
        exit(0);
    }
    cout << setw(30);
    hLine(30);
    cout << endl;
    cout << setw(50) <<"Ello Network";
    cout <<endl;
    cout << setw(55)<< "Connecting the world.\n";
    cout << setw(30);
    hLine(30);
    s();
    cout << "\n\tWelcome to Ello.\n";
    cout << "\tLogin or Sign Up to get started. \n";

    do {
        cout << "\t1. Login\n";
        cout << "\t2. Sign Up\n";
        cout << "\t3. Exit\n";

        cout << "\n\tYour choice: ";cin >> ch;

        if(ch == 1) {
            d_lay();
            acc.login();
        }
        else if (ch==2) {
            acc.reg();
            d_lay();
        }
        if (ch == 3) {
            system("color 7D");
        }
    }while(ch !=3);
}

