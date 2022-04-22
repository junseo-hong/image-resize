#include "processing.h"
#include <iostream> 
#include <fstream>


using namespace std; 

int main(int argc, char *argv[]) {

ifstream infile(argv[1]);
ofstream outfile(argv[2]);

ifstream infile2(argv[1]);

string p3=""; 
int og_width=0;
int og_height=0;
infile2 >> p3 >> og_width >> og_height; 
if (argc != 4 && argc != 5) {
    cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
     return 1;
}
else if (!(infile.is_open())) {
    cout << "Error opening file: " << (argv[1]) << endl;
    return 1;
}

else if (argc ==4 && (atoi(argv[3])<0 || atoi(argv[3])>og_width)) {
    cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
     return 1;
}

else if (argc ==5 && (atoi(argv[3])<0 || atoi(argv[3])>og_width || atoi(argv[4])<0 || atoi(argv[4])>og_height)) {
    cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
     return 1;
}

else if (argc == 4) {
    int desired_width = atoi(argv[3]);

    Image *img = new Image;
    Image_init(img,infile);
    seam_carve_width(img,desired_width);
    Image_print(img,outfile);
    delete img;
    return 0;
}

else if (argc == 5) {
    int desired_width = atoi(argv[3]);
    int desired_height = atoi(argv[4]);
    Image *img = new Image;
    Image_init(img,infile);
    seam_carve(img,desired_width,desired_height);
    Image_print(img,outfile);
    delete img;
    return 0;
}

else {
    return 0;
}

}