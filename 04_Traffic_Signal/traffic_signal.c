#include<reg51.h>
void delay(int a){
	int i,j;
	for(i=0;i<a;i++){
		for(j=0;j<700;j++);
	}
}
void seven_segment(int a, int b){
		unsigned char seg_code[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x98};
		unsigned char i;
		for(i=a;i<b;i++){
			P3 = seg_code[i];
			delay(100);
		}
	}
void main(){

	while(1){
		P2=0x01;
		seven_segment(0,4);
		P2=0x02;
		seven_segment(4,7);
		P2=0x04;
		seven_segment(7,10);
	}
}
