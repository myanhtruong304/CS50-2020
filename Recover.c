#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *input_im;
    FILE *output_im;
    int count = 0;
    int isFound = 0;
    unsigned char buffer[512];

    if(argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    //open file for reading
    input_im = fopen(argv[1],"r");

    if(input_im == NULL)
    {
        printf("COULD NOT BE READ");
        return 1;
    }
    while(fread(buffer, 512, 1, input_im) == 1)
    
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if(isFound == 1)
            {
                fclose(output_im);
            }
            else
            {
                isFound = 1;
            }
        
        char fileName [8];
        sprintf(fileName,"%03d.jpg", count);
        count++;
        output_im = fopen(fileName,"a");
        }
        
        if(isFound == 1)
        {
            fwrite(buffer, 512, 1, output_im);
        }
    }

    fclose(output_im);
    fclose(input_im);
}
