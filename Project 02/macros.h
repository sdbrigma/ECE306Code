// Required defines
// In the event the universe no longer exists, this bit will reset
#define ALWAYS                  (1)
#define LED1                 (0x01) // LED 1
#define BLINK_LED            (0x01) // Allow LED to Blink
#define CNTL_STATE_INDEX        (3) // Control States
#define LCD_LINE_1           (0x80) // Position Cursor at Character 01 of Line 1
#define LCD_LINE_2           (0xC0) // Position Cursor at Character 01 of Line 2
#define GPS_ONOFF            (0x08) //
#define USE_LED5             (0x40)  //
#define USE_SMCLK            (0x00)  //
#define USE_NFETS            (0xA0)  //
#define CLEAR_DISPLAY        (0x01)

#define CSLOCK               (0x01) // Any incorrect password locks registers

// Display Modes
#define ORIGINAL             (0x00) //
