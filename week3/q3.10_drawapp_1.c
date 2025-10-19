#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fptr;

int width = 40;
int height = 60;

int cur_x = 10;
int cur_y = 10;

int w_width = 1000;
int w_height = 1000;

int digits[10];

typedef enum colour {BLACK, RED, BLUE, YELLOW, GREEN, CYAN, DARK_GRAY, GRAY, LIGHT_GRAY, MAGENTA, ORANGE} colour;

void setRGBColour(int red, int green, int blue)
{
  fprintf(fptr, "RG %i %i %i\n", red, green, blue);
}

void setColour(colour colourName)
{   
    switch (colourName)
    {
        case BLACK: setRGBColour(0, 0, 0); break;
        case RED: setRGBColour(255, 0, 0); break;
        case BLUE: setRGBColour(0, 0, 255); break;
        case YELLOW: setRGBColour(255, 255, 0); break;
        case GREEN: setRGBColour(0, 255, 0); break;

        case CYAN: setRGBColour(0, 255, 255); break;
        case DARK_GRAY: setRGBColour(169, 169, 169); break;
        case GRAY: setRGBColour(120, 120, 120); break;
        case LIGHT_GRAY: setRGBColour(211, 211, 211); break;
        case MAGENTA: setRGBColour(255, 0, 255); break;
        
        case ORANGE: setRGBColour(255, 165, 0); break;
    }
}

void setWindowSize(int width, int height)
{
    fprintf(fptr, "SW %i %i\n", width, height);
}

void fillRect(int x1, int x2, int x3, int x4)
{
  fprintf(fptr, "FR %i %i %i %i\n", x1, x2, x3, x4);
}

void insert_digits(int num)
{
    if(num == 0)
    {
        digits[0] = 0;
        return;
    }
    int idx = 0;
    while(num!=0)
    {
        digits[idx] = num % 10;
        idx += 1;
        num = num / 10;
    }
}

int len_num(int num)
{
    if(num==0)
    {
        return 1;
    }
    int counter = 0;
    while(num!=0)
    {
        counter += 1;
        num = num / 10;
    }
    return counter;

}

void draw_minus(int x, int y)
{   
    setColour(ORANGE);
    fillRect(x+(int)(width/5.0), y+(int)(height*2.0/5.0), (int)(width*3.0/5.0), (int)(height/5.0));
}

void draw0(int x, int y)
{
    setColour(BLACK);
    fillRect(x, y, width, (int)(height/5.0));
    fillRect(x, y+(int)(height*4.0/5.0), width, (int)(height/5.0));
    fillRect(x+(int)(width*4.0/5.0), y, (int)(width/5.0), height);
    fillRect(x, y, (int)(width/5.0), height);
}

void draw1(int x, int y)
{   
    setColour(RED);
    fillRect(x+(int)(width/5.0), y, (int)(width/5.0), (int)(height/5.0));
    fillRect(x+(int)(width*2.0/5.0), y, (int)(width/5.0), height);
    fillRect(x, y+(int)(height*4.0/5.0), width, (int)(height/5.0));
}

void draw2(int x, int y)
{   
    setColour(BLUE);
    fillRect(x, y, width, (int)(height/5.0));
    fillRect(x+(int)(width*4.0/5.0), y, (int)(width*1.0/5.0), (int)(height*3.0/5.0));
    fillRect(x, y+(int)(height*2.0/5.0), width, (int)(height/5.0));
    fillRect(x, y+(int)(height*2.0/5.0), (int)(width/5.0), (int)(height*3.0/5.0));
    fillRect(x, y+(int)(height*4.0/5.0), width, (int)(height/5.0));
}

void draw3(int x, int y)
{   
    setColour(YELLOW);
    fillRect(x, y, width, (int)(height/5.0));
    fillRect(x, y+(int)(height*2.0/5.0), width, (int)(height/5.0));
    fillRect(x, y+(int)(height*4.0/5.0), width, (int)(height/5.0));
    fillRect(x+(int)(width*4.0/5.0), y, (int)(width/5.0), height);
}

void draw4(int x, int y)
{   
    setColour(GREEN);
    fillRect(x, y, (int)(width/5.0), (int)(height*3.0/5.0));
    fillRect(x, y+(int)(height*2.0/5.0), width, (int)(height/5.0));
    fillRect(x+(int)(width*4.0/5.0), y, (int)(width/5.0), height);
}

void draw5(int x, int y)
{   
    setColour(CYAN);
    fillRect(x, y, width, (int)(height/5.0));
    fillRect(x, y+(int)(height*2.0/5.0), width, (int)(height/5.0));
    fillRect(x, y+(int)(height*4.0/5.0), width, (int)(height/5.0));
    fillRect(x, y, (int)(width/5.0), (int)(height*3.0/5.0));
    fillRect(x+(int)(width*4.0/5.0), y+(int)(height*2.0/5.0), (int)(width/5.0), (int)(height*3.0/5.0));
}

void draw6(int x, int y)
{   
    setColour(DARK_GRAY);
    fillRect(x, y, width, (int)(height/5.0));
    fillRect(x, y, (int)(width/5.0), height);
    fillRect(x, y+(int)(height*2.0/5.0), width, (int)(height/5.0));
    fillRect(x, y+(int)(height*4.0/5.0), width, (int)(height/5.0));
    fillRect(x+(int)(width*4.0/5.0), y+(int)(height*2.0/5.0), (int)(width/5.0), (int)(height*3.0/5.0));
}

void draw7(int x, int y)
{   
    setColour(GRAY);
    fillRect(x, y, width, (int)(height/5.0));
    fillRect(x+(int)(width*4.0/5.0), y, (int)(width/5.0), height);
}

void draw8(int x, int y)
{   
    setColour(LIGHT_GRAY);
    fillRect(x, y, width, (int)(height/5.0));
    fillRect(x, y+(int)(height*2.0/5.0), width, (int)(height/5.0));
    fillRect(x, y+(int)(height*4.0/5.0), width, (int)(height/5.0));
    fillRect(x, y, (int)(width/5.0), height);
    fillRect(x+(int)(width*4.0/5.0), y, (int)(width/5.0), height);
}

void draw9(int x, int y)
{   
    setColour(MAGENTA);
    fillRect(x, y, width, (int)(height/5.0));
    fillRect(x, y+(int)(height*2.0/5.0), width, (int)(height/5.0));
    fillRect(x, y, (int)(width/5.0), (int)(height*3.0/5.0));
    fillRect(x+(int)(width*4.0/5.0), y, (int)(width/5.0), height);
    fillRect(x, y+(int)(height*4.0/5.0), width, (int)(height/5.0));

}

void choice(int x)
{
    switch (x)
    {
        case 0: draw0(cur_x, cur_y); break;
        case 1: draw1(cur_x, cur_y); break;
        case 2: draw2(cur_x, cur_y); break;
        case 3: draw3(cur_x, cur_y); break;
        case 4: draw4(cur_x, cur_y); break;
        case 5: draw5(cur_x, cur_y); break;
        case 6: draw6(cur_x, cur_y); break;
        case 7: draw7(cur_x, cur_y); break;
        case 8: draw8(cur_x, cur_y); break;
        case 9: draw9(cur_x, cur_y); break;
    }
}

void clearFile()
{
    fptr = fopen("q3.10.txt", "w");
}

int move_cursor(int w_width, int w_height)
{
    if (w_width - (cur_x+50) >= 50)
    {
        cur_x += 50;
    }
    else if (w_height - (cur_y+70) >= 70)
    {
        cur_y += 70;
        cur_x = 10;
    }
    else
    {
        return 0;
    }
    return 1;
}


int main()
{
    clearFile();

    setWindowSize(w_width, w_height);

    fopen("q3.10.txt", "a");

    setColour(BLACK);
    
    int num;
    printf("Input an integer: ");
    scanf("%d", &num);

    if (num < 0)
    {
        draw_minus(cur_x, cur_y);
        move_cursor(w_width, w_height);
    }
    num = -1 * num;
    insert_digits(num);
    for (int i=len_num(num)-1; i>=0; i--)
    {
        choice(digits[i]);
        move_cursor(w_width, w_height);
    }

    fclose(fptr);
    return 0;
}