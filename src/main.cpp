#include "test.h"

void setup()
{
    Serial.begin(115200);
    test_init();
    Serial.print(CIRCUIT_NAME);
    Serial.println(F(" init done"));
}

void loop()
{
    test_routine();
}