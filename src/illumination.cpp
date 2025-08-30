/*
 * Lesson4 課題　回答
 * parking_modeから呼ばれる、
 * LEDをクリスマスイルミネーション風に
 * 次から次へと色が変わる関数を作成し、
 * 停止時にLEDの色がカラフルに
 * 変更されるようにしなさい。
 */
#include "Arduino.h"
#include <driver/ledc.h>
#include "led.hpp"
static int Time_counter = 0;
static int Lcolor = 0;
static int Hcolor = 1;
static int precolor = Hcolor;

CRGB color[] ={
    WHITE, BLUE, RED, YELLOW, GREEN, PERPLE, 
    POWEROFFCOLOR, FLIPCOLOR
};

void led_illumination2(void){
    onboard_led1(color[Lcolor], 1);
    onboard_led2(color[Lcolor], 1);

     if (Time_counter > 400 - 1) {
        Lcolor++;
        if (Lcolor > 7) {   // 配列は 0～7 の8色
            Lcolor = 0;
        }
        Time_counter = 0;
    }
    else Time_counter++;
}

void led_illumination(void){
    onboard_led1(color[Lcolor], 1);
    onboard_led2(color[Lcolor], 1);

     if (Time_counter > 400 - 1) {
        while (Lcolor == precolor)
        {
            Lcolor = rand() % 8;
        }
        precolor = Lcolor;
        Time_counter = 0;
    }
    else Time_counter++;
}