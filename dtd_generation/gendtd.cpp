#include<iostream>
#include<fstream>

using namespace std;

ofstream opfile;

string* type;
string** ele;

int tcount=0;
int *ecount;

void start(string version="1.0") {
    opfile << "<?xml version=\"" << version <<"\"?>\n\n";
}
int main(int argc,char** argv) {

    //file for output...

    char* filename;
    if(argc>1) {
        filename = argv[1];
    }
    else {
        filename = new char[20];
        cout << "Enter the output filename : ";
        cin >> filename;
    }

    opfile.open(filename);

    //start generation...

    start();

    //menu listings ....

    int num_of_type;

    cout << "Enter the number of type you want in the document : ";
    cin >> num_of_type;
    type = new string[num_of_type];
    ele = new string* [num_of_type];
    ecount = new int[num_of_type];

    for(int i=0;i<num_of_type;i++) {

        cout << "Name the type : ";
        cin >> type[i];

            opfile << "<!DOCTYPE " << type[i] << " [";
        int elements;

        cout << "Enter the number of elements : ";
        cin >> elements;

        ele[i]= new string[elements];

        cout << "Enter the elements : ";

        opfile << "\n<!ELEMENT " << type[i] << " (";

        for(int j=0;j<elements;j++) {
            cin >> ele[i][j];
            opfile << ele[i][j];
            if(j!=elements-1) {
                opfile << ",";
            }

        } opfile << ") >\n";

        for(int j=0;j<elements;j++) {
            opfile << "<!ELEMENT " << ele[i][j] << " (#PCDATA) > \n";
        }

        opfile << " ] >";

        tcount++;
        ecount[i]=elements;

        }


    //now data ntry...

    char iter;
    cout << "do you wish to do data entry [y/n] : ";
    cin >> iter;

    if(iter=='n' || iter=='N') {
        goto stop;
    }

    int seltype;

    do {

    cout << "Enter the datatype for entry : <press -1 for exit>";

    for (int i=0 ; i<tcount;i++) {
        cout << i << " : " << type[i] << "\n";
    }

    cin >> seltype;

    if(seltype==-1) {
        goto stop;
    }

    opfile << "\n\n";
    opfile << "<" << type[seltype] << ">\n";
    string data;
    for(int i=0;i<ecount[seltype];i++) {

        opfile << "<" << ele[seltype][i] << "> ";
        cout << "Enter data for type " << type[seltype] << "and attribute " << ele[seltype][i] << " : ";
        cin >> data;
        opfile << data << "</" << ele[seltype][i] << "> ";

    }

    opfile << "</" << type[seltype] << ">";
    } while(seltype!=-1);
    //exit close the file and return...

    stop : opfile.close();
    return 0;


}
