#ifndef ULTRALCD_H
#define ULTRALCD_H

#include "Marlin.h"

#ifdef ULTRA_LCD

void lcd_update();
void sd_init();
void lcd_setstatus(const char* message);
void lcd_setstatuspgm(const char* message);
void lcd_setalertstatuspgm(const char* message);
void lcd_reset_alert_level();
void lcd_preheat_abs();
void lcd_preheat_pla();
void lcd_cooldown();
void lcd_unload_filament();
void lcd_load_filament();
void lcd_sdcard_pause();
void lcd_sdcard_resume();
void lcd_sdcard_stop();
void raise_Z_E(int Z, int E);
bool strISAscii(String str);

#ifdef TENLOG_CONTROLLER
void sdcard_tlcontroller();
#endif

#ifdef DOGLCD
extern int lcd_contrast;
void lcd_setcontrast(uint8_t value);
#endif

static unsigned char blink = 0;	// Variable for visualisation of fan rotation in GLCD

#define LCD_MESSAGEPGM(x) lcd_setstatuspgm(PSTR(x))
#define LCD_ALERTMESSAGEPGM(x) lcd_setalertstatuspgm(PSTR(x))

#define LCD_UPDATE_INTERVAL 100
#define LCD_TIMEOUT_TO_STATUS 15000

#ifdef ULTIPANEL
    void lcd_buttons_update();
    extern volatile uint8_t buttons;  //the last checked buttons in a bit array.
    #ifdef REPRAPWORLD_KEYPAD
        extern volatile uint8_t buttons_reprapworld_keypad; // to store the keypad shiftregister values
    #endif
    #else
        FORCE_INLINE void lcd_buttons_update() {}
    #endif

    extern int plaPreheatHotendTemp;
    extern int plaPreheatHPBTemp;
    extern int plaPreheatFanSpeed;

    extern int absPreheatHotendTemp;
    extern int absPreheatHPBTemp;
    extern int absPreheatFanSpeed;

    void lcd_buzz(long duration,uint16_t freq);
    bool lcd_clicked();


#else //no lcd
    FORCE_INLINE void lcd_update() {}
    FORCE_INLINE void sd_init() {}
    FORCE_INLINE void lcd_setstatus(const char* message) {}
    FORCE_INLINE void lcd_buttons_update() {}
    FORCE_INLINE void lcd_reset_alert_level() {}
    FORCE_INLINE void lcd_buzz(long duration,uint16_t freq) {}

    #define LCD_MESSAGEPGM(x) 
    #define LCD_ALERTMESSAGEPGM(x) 
#endif 

char *itostr2(const uint8_t &x);
char *itostr31(const int &xx);
char *itostr3(const int &xx);
char *itostr3left(const int &xx);
char *itostr4(const int &xx);

char *ftostr3(const float &x);
char *ftostr31ns(const float &x); // float to string without sign character
char *ftostr31(const float &x);
char *ftostr32(const float &x);
char *ftostr5(const float &x);
char *ftostr51(const float &x);
char *ftostr52(const float &x);

#endif //ULTRALCD