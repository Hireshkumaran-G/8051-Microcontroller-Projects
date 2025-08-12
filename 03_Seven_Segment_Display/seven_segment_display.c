#include<reg51.h>
void delay(){
	int i,j;
	for(i=0;i<250;i++){
		for(j=0;j<750;j++);
	}
}
void main(){
	unsigned char seg_code_Anode[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x98};//Anode
	unsigned char seg_code_Cathode[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//Cathode
	unsigned char i;
	while(1){
		for(i=0;i<10;i++){
			P2 = seg_code_Cathode[i];
			P3 = seg_code_Anode[i];
			delay();
		}
	}
}