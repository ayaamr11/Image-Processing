// FCI � Programming 1 � 2018 - Assignment 4
// Program Name: project4.cpp
// Last Modification Date: 13/4/2018
// Author and ID and Group:Aya Amr Mohamed         G:14   20170359
// Teaching Assistant: Eng.Ata & Eng.Ibrahim
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE];

void loadImage ();
void saveImage ();
//individual task - 20170370
void BandW();
void flip();
void detect_edge();
void mirror();   // bonus
//individual task - 20170217
void Invert();
void Rotation();
void Enlarge();
void Shuffling();
//individual task - 20170359
void mergeimage();
void bright_dark ();
void shrink_image();
void saveImageshrink ();

int main()
{
int choise;
loadImage();
cout<<"Please select a filter to apply or 0 to exit:\n1-Black&White Filter\n2-Invert Filter\n3-Merge Filter\n4-Flip Image\n5-Darken and Lighten Image\n6-Rotate Image\n7-Detect Image Edges\n8-Enlarge Image\n9-Shrink Image\n10-Mirror Image\n11-Shuffle Image\n12-Blur Image\n0-Exit\n";
cin>>choise;
switch(choise){
case 0:
    cout<<"Thanks for using our program!!";
    break;
case 1:
    BandW();
    break;
case 2:
    Invert();
    break;
case 3:
    mergeimage();
    break;
case 4:
    flip();
    break;
case 5:
    Rotation();
    break;
case 6:
    bright_dark ();
    saveImage();
    break;
case 7:
    detect_edge();
    break;
case 8:
   Enlarge();
   break;
case 9:
    shrink_image();
    saveImageshrink ();
    break;
case 10:
    mirror();
    break;
case 11:
    Shuffling();
    break;
}
saveImage();
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_________________________________________
///Black & White
void BandW(){
float aver,sum=0;
int num=0;
for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      sum=sum+image[i][j];
      num=num+1;}}
aver=sum/num;
for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      if(image[i][j]>aver){image[i][j]=255;}
      else{image[i][j]=0;}
         }}
}
/*for(int i =0;i<SIZE;++i){
        for(int j=0;j<SIZE-1;++j)
        {swap(image[i][j],image[SIZE-j][SIZE-i]);
        }
    }}*/
//_________________________________________
///Inversion Filter
void Invert()
{
    unsigned char image2[SIZE][SIZE];
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            image2[i][j] = (SIZE - image[i][j]);
        }
    }
    char imageFileName2[100];
    cout << "Write the name of the image in which you want to save the output\n";
    cin >> imageFileName2;
    strcat (imageFileName2, ".bmp");
    writeGSBMP(imageFileName2, image2);
}

void mergeimage() {
    unsigned char image20[SIZE][SIZE];
    unsigned char mergeresult[SIZE][SIZE];
    char imageFileName2[100];

    cout << "Enter the other image source file name: ";
    cin >> imageFileName2;

    strcat (imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image20);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            mergeresult[i][j]=(image[i][j]+image20[i][j])/2;
        }
    }
    char imageresult[100];

    cout << "Enter the new image file name: ";
    cin >> imageresult;

    strcat (imageresult, ".bmp");
    writeGSBMP(imageresult,mergeresult );
}

///Flip Image Filter
void flip(){
int x;
cout<<"flip the image:\n1-horizontally\n2-vertically\n";
cin>>x;
unsigned char temp[SIZE][SIZE];
switch (x){
case 1:
    for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      temp[i][j]=image[SIZE-i][j];
         }}
    break;
case 2:
    for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
       temp[i][j]=image[i][SIZE-j];
         }}
    break;
    }
for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
swap(temp[i][j],image[i][j]);}}
}
//_________________________________________

void Rotation()
{
    unsigned char image2[SIZE][SIZE];
    int choose;
    cout << "Please choose :\n-1 for 90 degrees\n-2 for 180 degrees\n-3 for 270 degrees";
    cin >> choose;
    switch(choose){
    case 1:
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                image2[i][j] = image[SIZE - 1 - j][i];
            }
        }
    case 2:
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                image2[i][j] = image[SIZE - 1 - i][SIZE - 1 - j];
            }
        }
    case 3:
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                image2[i][j] = image[SIZE - 1 - j][i];
            }
        }
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                image2[i][j] = image[SIZE - 1 - i][SIZE - 1 - j];
            }
        }
    }
    char imageFileName2[100];
    cout << "Write the name of the image in which you want to save the output\n";
    cin >> imageFileName2;
    strcat (imageFileName2, ".bmp");
    writeGSBMP(imageFileName2, image2);
}

void bright_dark (){
    int k;
    cout<<"Enter (1 to darken) or  (2 to lighten)";
    cin>>k;
    if(k==2){
        for(int i=0;i<SIZE;i++){
            for (int j = 0; j< SIZE; j++) {
                if(image[i][j]<=191)
                    image[i][j]=image[i][j]+64;
            }
        }
    }
    else if(k==1){
        for(int i=0;i<SIZE;i++){
            for (int j = 0; j< SIZE; j++) {
                if(image[i][j]>=191)
                    image[i][j]=image[i][j]-64;
            }
        }
    }
}

/// Detect Image Edges Filter
void detect_edge(){
bool arr[SIZE][SIZE];
for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
        arr[i][j]=false;}}
BandW();
for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      if(image[i][j]==0&&image[i+1][j]==0&&image[i-1][j]==0&&image[i][j+1]==0&&image[i][j-1]==0){
        arr[i][j]=true;}}}
for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
        if(arr[i][j]==true){image[i][j]=255;}
    }}
}
//_________________________________________

void Enlarge()
{
    unsigned char image1[SIZE][SIZE];
    unsigned char image2[SIZE][SIZE];
    unsigned char image3[SIZE][SIZE];
    unsigned char image4[SIZE][SIZE];
    unsigned char imageEnlarge[SIZE][SIZE];

    for(int i=0; i < (SIZE/4); i++)
    {
        for(int j=0; j < (SIZE/4); j++)
        {
            image1[i][j] = image[i][j];
        }
    }
    for(int i=64; i < (SIZE/2);i++)
    {
        for(int j=64; j <(SIZE/2);j++)
        {
            image2[i][j] = image[i][j];
        }
    }
    for(int i=128; i < ((SIZE * 3)/4);i++)
    {
        for(int j=128; j <((SIZE * 3)/4);j++)
        {
            image3[i][j] = image[i][j];
        }
    }
    for(int i=192; i < (SIZE);i++)
    {
        for(int j=192; j < (SIZE);j++)
        {
            image4[i][j] = image[i][j];
        }
    }

    int choose;
    cin >> "Choose which quadrant to enlarge :\n-1 First\n2- Second\n-3 Third\n-4 Fourth";
    switch(choose){
    case 1:
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                imageEnlarge[i][j] = image1[i][j];
                imageEnlarge[i+1][j] = image1[i][j];
                imageEnlarge[i][j+1] = image1[i][j];
                imageEnlarge[i+1][j+1] = image1[i][j];
            }
        }
    case 2:
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                imageEnlarge[i][j] = image2[i][j];
                imageEnlarge[i+1][j] = image2[i][j];
                imageEnlarge[i][j+1] = image2[i][j];
                imageEnlarge[i+1][j+1] = image2[i][j];
            }
        }
    case 3:
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                imageEnlarge[i][j] = image3[i][j];
                imageEnlarge[i+1][j] = image3[i][j];
                imageEnlarge[i][j+1] = image3[i][j];
                imageEnlarge[i+1][j+1] = image3[i][j];
            }
        }
    case 4:
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                imageEnlarge[i][j] = image4[i][j];
                imageEnlarge[i+1][j] = image4[i][j];
                imageEnlarge[i][j+1] = image4[i][j];
                imageEnlarge[i+1][j+1] = image4[i][j];
            }
        }
    }

    char imageFileName2[100];
    cout << "Write the name of the image in which you want to save the output\n";
    cin >> imageFileName2;
    strcat (imageFileName2, ".bmp");
    writeGSBMP(imageFileName2, imageEnlarge);
}

void shrink_image(){

    int k;
    cout<<"Enter (1 to shrink to 1/4) or  (2 to shrink to 1/3) or (3 to shrink to 1/2)";
    cin>>k;
    if (k==1){
        for(int i=0;i<SIZE;i++){
            for (int j = 0; j< SIZE; j++) {
                imagetoshrink[i][j]=255;
            }
        } for(int i=0;i<SIZE;i++){
            for (int j =0; j< SIZE; j++) {
                imagetoshrink[i/4][j/4]=image[i][j];
            }
        }


    }else if(k==2){
        for(int i=0;i<SIZE;i++){
            for (int j = 0; j< SIZE; j++) {
                imagetoshrink[i][j]=255;
            }
        } for(int i=0;i<SIZE;i++){
            for (int j =0; j< SIZE; j++) {
                imagetoshrink[i/3][j/3]=image[i][j];
            }
        }


    }else if (k==3){
        for(int i=0;i<SIZE;i++){
            for (int j = 0; j< SIZE; j++) {
                    imagetoshrink[i][j]=255;
            }
        } for(int i=0;i<SIZE;i++){
            for (int j =0; j< SIZE; j++) {
                imagetoshrink[i/2][j/2]=image[i][j];
            }
        }
    }

}

void saveImageshrink () {

   char imageFileName[100];

   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, imagetoshrink);
}

///Mirror Image Filter
void mirror(){
int x;
cout<<"This filter mirrors 1/2 of the image:\n1-Right\n2-Left\n3-Lower\n4-Upper\n";
cin>>x;
unsigned char temp[SIZE][SIZE];
switch (x){
case 1: //Right
    for(int i=0;i<SIZE;i++){
    for(int j=0;j<127;j++){
       image[i][j]=image[i][SIZE-j];
         }}
    break;
case 2: //left
    for(int i=0;i<SIZE;i++){
    for(int j=127;j<SIZE;j++){
      image[i][j]=image[i][SIZE-j];
         }}
    break;
case 3: //lower
    for(int i=0;i<127;i++){
    for(int j=0;j<SIZE;j++){
      image[i][j]=image[SIZE-i][j];
         }}
    break;
case 4: //upper
    for(int i=127;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      image[i][j]=image[SIZE-i][j];
         }}
    break;
    }
}

void Shuffling()
{
    unsigned char image1[SIZE][SIZE];
    unsigned char image2[SIZE][SIZE];
    unsigned char image3[SIZE][SIZE];
    unsigned char image4[SIZE][SIZE];
    unsigned char imageShuffle[SIZE][SIZE];

    for(int i=0; i < (SIZE/4); i++)
    {
        for(int j=0; j < (SIZE/4); j++)
        {
            image1[i][j] = image[i][j];
        }
    }
    for(int i=64; i < (SIZE/2);i++)
    {
        for(int j=64; j <(SIZE/2);j++)
        {
            image2[i][j] = image[i][j];
        }
    }
    for(int i=128; i < ((SIZE * 3)/4);i++)
    {
        for(int j=128; j <((SIZE * 3)/4);j++)
        {
            image3[i][j] = image[i][j];
        }
    }
    for(int i=192; i < (SIZE);i++)
    {
        for(int j=192; j < (SIZE);j++)
        {
            image4[i][j] = image[i][j];
        }
    }



    char imageFileName2[100];
    cout << "Write the name of the image in which you want to save the output\n";
    cin >> imageFileName2;
    strcat (imageFileName2, ".bmp");
    writeGSBMP(imageFileName2, imageShuffle);
}

