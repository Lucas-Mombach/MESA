#include "fx.cpp"

#define LED_PIN 6
#define LED_COUNT 144


Adafruit_NeoPixel LED(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
int mov = 0;
int aux = 0;


void setup()
{
	LED.begin();
	LED.show();
	
}
void loop()
{
	LED.clear();
	
	int olhos[4] = {52,55,67,64};
 	int corpoPar[25] = {15,16,17,18,19,38,41,44,62,65,68,86,87,88,89,90,91,92,110,111,112,113,114,115,116};
	int corpoImpar[32] = {5,6,7,28,29,30,31,32,51,54,57,75,76,77,78,79,80,81,99,100,101,102,103,104,105,123,124,125,126,127,128,129};
	int calda[4] = {134,136,138,140};
	
	
	for(int i = 0; i < 32; i++) // corpo impar
	{
		LED.setPixelColor(corpoImpar[i]-mov, 150, 0, 0);
		LED.show();
	}

		for(int i = 0; i < 25; i++) // corpo par
	{
		LED.setPixelColor(corpoPar[i]+mov, 150, 0, 0);
		LED.show();
	}
		for(int i = 0; i < 4; i++) // calda
	{
		LED.setPixelColor(calda[i]+mov, 150, 0, 0);
		LED.show();
	}
		for(int i = 0; i < 4; i++)//olhos
	{
		if(mov%2==0){
				if (olhos[i]==52 ||olhos[i]==55 ){ //impar
								LED.setPixelColor(olhos[i]-mov, 51, 150, 150);
								LED.show();
							}
							else{ //par
								LED.setPixelColor(olhos[i]+mov, 51, 150, 150);
								LED.show();
							}

		}
		else{
				if (olhos[i]==52 ||olhos[i]==55 ){ //impar
				LED.setPixelColor(olhos[i]-mov+1, 51, 150, 150);
				LED.show();
			}
			else{ //par
				LED.setPixelColor(olhos[i]+mov-1, 51, 150, 150);
				LED.show();
			}
		}
		
	}
if(aux<3){
	mov++;
	aux++;
}
else{
	mov--;
	if(mov==-2){
		aux = -2;
	}
}

delay(500);

}


