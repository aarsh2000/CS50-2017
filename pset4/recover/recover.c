#include <stdio.h>
#include <cs50.h>
//#include "bmp.h"
/**
 * BMP-related data types based on Microsoft's own.
 */

#include <stdint.h>

/**
 * Common Data Types
 *
 * The data types in this section are essentially aliases for C/C++
 * primitive data types.
 *
 * Adapted from https://msdn.microsoft.com/en-us/library/cc230309.aspx.
 * See http://en.wikipedia.org/wiki/Stdint.h for more on stdint.h.
 */
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

/**
 * BITMAPFILEHEADER
 *
 * The BITMAPFILEHEADER structure contains information about the type, size,
 * and layout of a file that contains a DIB [device-independent bitmap].
 *
 * Adapted from https://msdn.microsoft.com/en-us/library/dd183374(v=vs.85).aspx.
 */
typedef struct
{
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} __attribute__((__packed__))
BITMAPFILEHEADER;

/**
 * BITMAPINFOHEADER
 *
 * The BITMAPINFOHEADER structure contains information about the
 * dimensions and color format of a DIB [device-independent bitmap].
 *
 * Adapted from https://msdn.microsoft.com/en-us/library/dd183376(v=vs.85).aspx.
 */
typedef struct
{
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} __attribute__((__packed__))
BITMAPINFOHEADER;

/**
 * RGBTRIPLE
 *
 * This structure describes a color consisting of relative intensities of
 * red, green, and blue.
 *
 * Adapted from https://msdn.microsoft.com/en-us/library/dd162939(v=vs.85).aspx.
 */
typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;



int main (void)
{
    //open
    FILE* crd = fopen("card.raw", "r");


   if (crd == NULL){
       printf("Could not open %s.\n", "card.raw");
       return 1;
    }


    //read
    BYTE buffer[512]; //512 bytes per image
    int counter = 0;
    bool found = false;
    FILE* jpg;

    while(fread(buffer,1,512,crd)!=0x00)
    {
        if(buffer[0]==0xff&&buffer[1]==0xd8&&buffer[2]==0xff&&(buffer[3]&0xf0)==0xe0){
            //if first is not image looking for
            if(!found){
                found = true;

                char filename[8];
                sprintf(filename,"%03i.jpg", counter++);
                jpg = fopen(filename,"w");
                if(jpg== NULL)
                return 2;
                //write from buffer
                fwrite(buffer,1,512 ,jpg);
            }

                else{
                 fclose(jpg);
                 char filename[8];
                 sprintf(filename,"%03i.jpg", counter++);

                jpg = fopen(filename,"w");
                if(jpg == NULL)
                return 2;
                fwrite(buffer,1,512 ,jpg);

                }

            }
            else{

                if(found){
                fwrite(buffer,1,512 ,jpg);
                }

            }
        }




    fclose(jpg);
    fclose(crd);

}