#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define LENGTH (512UL*1024*1024)
#define INTERVAL 5



static void write_bytes(char *addr)
{
	unsigned long i,count,point;

	point = LENGTH / 20;
	count = 0;
	for (i = 0; i < LENGTH; i++){
		*(addr + i) = (unsigned int)i;
		count++;
		if( count >= point ){
			sleep(1);
			count=0;
		}
	}
	return;
}

static int read_bytes(char *addr)
{
	unsigned long i,count,point;

	point = LENGTH / 20;
	count = 0;
	for (i = 0; i < LENGTH; i++){
		(void)(addr + i);
		count++;
		if( count >= point ){
			sleep(1);
			count=0;
		}
	}	
	return 0;
}

int main(void)
{
	void *addr;
	int ret;

	printf("メモリ管理\n");
	sleep(INTERVAL);

	printf("step1 プログラムでメモリをアロケート 512Mバイト\n");
    addr = malloc(LENGTH);

	sleep(INTERVAL);
	printf("step2 読み込みを開始　何も変わらないはず\n");
	ret = read_bytes(addr);
	printf("step2 読み込みを終了\n");

	sleep(INTERVAL);
	printf("step3 書き込みを開始　usedが上昇し　availableが減少する\n");
	write_bytes(addr);
	printf("step3 書き込みを終了\n");

	sleep(INTERVAL);
	printf("step4 読み込みを開始　何も変わらないはず\n");
	ret = read_bytes(addr);
	printf("step4 読み込みを終了\n");

	sleep(INTERVAL);
	printf("step5 メモリを開放　usedが開放され availableが復活\n");
	free(addr);

	sleep(INTERVAL);
	printf("メモリ管理　完\n");

	return ret;
}