
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//必要ありません
//int mode;

#define debug 0
//debug モード

void sort_ass(int n,int data[]){
    int i,j,m,tmp;

    for(i=0;i<n;i++){
        m=i;

        for(j=i+1;j<n;j++){
            if(data[j]<data[m])
            {
                m=j;
            }
        }
        tmp=data[i];
        data[i]=data[m];
        data[m]=tmp;
    }

    //debugのため
    if(debug){

    printf("\t");
    for(j=0;j<n;j++){
        printf("%d\t",data[j]);
    }
    printf("\n");
    }
}


void sort_dis(int n,int data[]){
    int i,j,m,tmp;
    for(i=0;i<n;i++){
        m=i;
        for(j=i+1;j<n;j++){
            if(data[j]>data[m])
                m=j;
        }

        if(m!=i){
            tmp=data[i];
            data[i]=data[m];
            data[m]=tmp;
        }
    }
}

#define MAX 1000
#define SIZE 100

int main(int argc,char *argv[]){
    //debug方法
    //main関数を３つ部分に分ける

    int i,n,mode;
    // int  seed;
    int data[SIZE];

    //準備
    if(!debug && argc<2){
        printf("error:参照足りない!\n");
        exit(0);
    }

    if(debug){
        //簡単にdubugため、数値を固定にします
        n=4;
        mode=1;
    }else{

        n=atoi(argv[1]);
        mode=atoi(argv[2]);
    }
    //準備完了

    //1 データの準備(乱数でデータを作成)
    srand((unsigned int)time(NULL));

    for(i=0;i<n;i++){
        //data[i]=(int)(rand()/(RAND_MAX+1.0)*MAX);
        data[i]=(int)(rand()%MAX);

        if(debug){
            //作成したデータを確認する
            printf("%d\t",data[i]);
        }
    }

    //printf("\n");

    //2 ソートの関す
    if (mode==1){
        sort_ass(n,data);
    }else{
        sort_dis(n,data);
    }

    //3 data結果を書き出す。
    for(i=0;i<n;i++){
        printf("%d\t",data[i]);
    }

    printf("\n");

    return 0;
}

