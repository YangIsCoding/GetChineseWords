#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//回傳取完字元
char *getUTFchar(char *text,char *ch){
	unsigned char *ptr,*qtr;
	ptr = text;
	

	if(*text == '\0'){
		return NULL;
	}
	qtr = ch;
	if(*ptr >= 240){  //11110 開頭 11110xxx 10 yyyyyy 10yyyyyy 10 yyyyyy	
		*qtr++=*ptr++;
		if(*ptr<128 || *ptr >= 192){
			ch[0]='\0';
			ptr++;
			return NULL;
		}
		*qtr++=*ptr++;
		if(*ptr<128 || *ptr >= 192){
                        ch[0]='\0';
                        ptr++;
                        return NULL;
                }
		*qtr++=*ptr++;
		if(*ptr<128 || *ptr >= 192){
                        ch[0]='\0';
                        ptr++;
                        return NULL;
                }
		*qtr++=*ptr++;
		*qtr='\0';
	}
	if(*ptr >= 224){	//1110xxxx 10 yyyyyy 10yyyyyy
		*qtr++ = *ptr++;
		if(*ptr<128 || *ptr >= 192){
                        ch[0]='\0';
                        ptr++;
                        return NULL;
                }
		*qtr++ = *ptr++;
		if(*ptr<128 || *ptr >= 192){
                        ch[0]='\0';
                        ptr++;
                        return NULL;
                }
		*qtr++ = *ptr++;
		*qtr = '\0';
	}
	else if(*ptr >= 192){  //110xxxxx 10yyyyyy
		*qtr++ = *ptr++;
		if(*ptr<128 || *ptr >= 192){
                        ch[0]='\0';
                        ptr++;
                        return NULL;
                }
		*qtr++ = *ptr++;
		*qtr = '\0';
	}
	else if(*ptr >= 128){//error
		*ch = '\0';
		ptr++;
	}
	else{//ascii
		*qtr++= *ptr++;
		*qtr = '\0';
	}
	return ptr;
}


int main(){
	unsigned char line[1024];
	unsigned char *ptr;
	char ch[5];
	while(fgets(line,1024,stdin)){
		ptr = line;
		while((ptr = getUTFchar(ptr,ch))){
			if(ch[0] == '\0'){
			//	printf("illegal code\n");
				continue;
			}
			else{
				printf("%s\n",ch);
			}
		}
	}
}
