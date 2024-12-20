#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MQTTClient.h"
#include "PWM.h"
using namespace exploringBB;
using namespace std;

#define ADDRESS     "tcp://io.adafruit.com:1883"
#define CLIENTID    "Beagle2"
#define TOPIC       "CamGrav/feeds/weather.slider"
#define AUTHMETHOD  "CamGrav"
#define AUTHTOKEN   "aio_upMS014n0bTL6fsMyBHcJlcPITIZ"
#define QOS         1
#define TIMEOUT     10000L
#define LED_GPIO    "/sys/class/gpio/gpio60/"
#define THRESHOLD   30

// Use this function to control the LED
void writeGPIO(string filename, string value){
   fstream fs;
   string path(LED_GPIO);
   fs.open((path + filename).c_str(), fstream::out);
   fs << value;
   fs.close();
}

volatile MQTTClient_deliveryToken deliveredtoken;

void delivered(void *context, MQTTClient_deliveryToken dt) {
    printf("Message with token value %d delivery confirmed\n", dt);
    deliveredtoken = dt;
}

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message) {
    int i;
    char* payloadptr;
    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: ");
    printf("Writing to LED\n");
    payloadptr = (char*) message->payload;
    printf("Payload Pointer: %s\n", payloadptr);

  PWM pwm("pwm-1:0");
  pwm.setPeriod(20000000);
  pwm.setPolarity(PWM::ACTIVE_LOW);
  pwm.setDutyCycle(1460000u);

    string payLoad(payloadptr);
    if(payLoad == "0") {
        pwm.setDutyCycle(10000u);
    } else if (payLoad == "10") {
        pwm.setDutyCycle(570000u);
    } else if (payLoad == "20") {
        pwm.setDutyCycle(1140000u);
    } else if (payLoad == "30") {
        pwm.setDutyCycle(1710000u);
    } else if (payLoad == "40") {
        pwm.setDutyCycle(2280000u);
    } else if (payLoad == "50") {
        pwm.setDutyCycle(3000000u);
    }
    
    pwm.run();
//    pwm.stop();

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

void connlost(void *context, char *cause) {
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
}

int main(int argc, char* argv[]) {
    MQTTClient client;
    MQTTClient_connectOptions opts = MQTTClient_connectOptions_initializer;
    int rc;
    int ch;
    writeGPIO("direction", "out");

    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    opts.keepAliveInterval = 20;
    opts.cleansession = 1;
    opts.username = AUTHMETHOD;
    opts.password = AUTHTOKEN;
    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);
    if ((rc = MQTTClient_connect(client, &opts)) != MQTTCLIENT_SUCCESS) {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);
    }
    printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n"
           "Press Q<Enter> to quit\n\n", TOPIC, CLIENTID, QOS);
    MQTTClient_subscribe(client, TOPIC, QOS);

    do {
        ch = getchar();
    } while(ch!='Q' && ch != 'q');
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return rc;
}

