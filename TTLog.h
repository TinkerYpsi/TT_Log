#ifndef TTLog_h
#define TTLog_h

#define DEFAULT_CS_PIN  10
#define NO_DATA   "NO_DATA"

#include <Arduino.h>

#include <SPI.h>
#include <SD.h>
#include <Time.h>
#include <TimeLib.h>


/*
* SD card attached to SPI bus as follows:
** MOSI - pin 11
** MISO - pin 12
** CLK - pin 13
*/

class TTLog
{
  public:
    static TTLog* log();

    /* by default, user sets time using Serial.read()
       but user can also enter time manually as params */
    static void setDateTime(int iHour = -1, int iMinute = -1, int iDay = -1,
                            int iMonth = -1, int iYear = -1);

    /* prints message to sFilename on SD card and serial by default */
    static void entry(const char *rgMessage, String &sFilename,
                      bool bPrintSerial = true, bool bPrintSDCard = true);

    /* concatenates string with current time and/or date */
    static void printDateTime(String &sDateTime);
    static void printTime(String &sTime);
    static void printDate(String &sDate);
    static void initializeSD();
    static void setChipSelect(int iCS_pin);

  private:
    static int g_iCS_pin;
    TTLog();                      // prevents copying a singleton
    TTLog(TTLog const&){};             // prevents copying a singleton
    void operator=(TTLog const&){};    // prevents copying a singleton
    static TTLog* m_pInstance;      // ensures only one instance is created
};

#endif
