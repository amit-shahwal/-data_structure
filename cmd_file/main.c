#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{FILE *fp;char ch;FILE *fp2;
if(argc!=3){exit(0);}
fp=fopen(argv[1],"r");
fp2=fopen(argv[2],"w");
ch=getc(fp);
while(ch!=EOF){
	putc(ch,fp2);
	ch=getc(fp);
}
fclose(fp);fclose(fp2);
    return 0;
}
